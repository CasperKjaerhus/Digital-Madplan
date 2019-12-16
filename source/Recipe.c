#include "Recipe.h"
/* 
 * Gets random number from a to b, 
 * these values are inclusive 
 * Assumes that a is smaller than b
 */
int get_random_number(int a, int b){
    return (rand() % (b+1 - a)) + a;
}

/* Function that orders recipes relative to ingredients */
Recipe getWeightedRecipe(Recipe *recipes, int amount_of_recipes, Recipe *planned_recipes, int amount_of_already_planned){
    int amount_unused, WeightedRandom, highest_match = 0, return_index = 0;
    Recipe *Unused_recipes = dif_recipes(recipes, amount_of_recipes, planned_recipes, amount_of_already_planned, &amount_unused);
    int *matches = (int *) chkCalloc(sizeof(int) * amount_unused, "getWeightedRecipe matches");
    Recipe returnRecipe;
    for(int i = 0; i < amount_unused; i++){
        for(int j = 0; j < amount_of_already_planned; j++){
            matches[i] += calcIngredientMatches(Unused_recipes[i], planned_recipes[j]);
        }
        matches[i] *= MATCH_WEIGHT; /*This increases the "match score" higher so a higher score weighs higher in final calculation*/
    }

    /*Calculates a pseudorandom recipe from a pseudorandom number with a weighted score
      aka: dishes with more ingredients common are more likely but not guaranteed!*/
    for(int i = 0; i < amount_unused; i++){
        WeightedRandom = get_random_number(0, 20) + matches[i]; /*This generates a random number between zero and amount_unused + whatever the corrospondings recipe has "scored"*/

        if(WeightedRandom > highest_match){
            return_index = i;
            highest_match = WeightedRandom;
        } else if(WeightedRandom == highest_match){
            if(get_random_number(0,1) == 0){ /*If a recipe rolls the same number, coinflip! 50/50 chance*/ 
                return_index = i;
                highest_match = WeightedRandom;
            }
        }
    }

    returnRecipe = Unused_recipes[return_index];
    free(matches);
    free(Unused_recipes);
    
    return returnRecipe;
}

/* Function that returns array of unused recipes */
Recipe *dif_recipes(Recipe *recipes, int amount_of_recipes, Recipe *mealplan_recipes, int amount_of_already_planned, int *amount_unused){
    Recipe *unplanned = (Recipe *) chkMalloc(sizeof(Recipe) * amount_of_recipes, "Unplanned recipes");
    int isPlanned, index = 0;
    for(int i = 0; i < amount_of_recipes; i++){
        isPlanned = 0;
        for(int j = 0; j < amount_of_already_planned; j++){
            if(strcmp(recipes[i].name, mealplan_recipes[j].name) == 0){
                isPlanned = 1;
            }
        }
        if(isPlanned == 0){
            unplanned[index++] = recipes[i];
        }
    }
    *amount_unused = index;
    return unplanned; 
}

int calcIngredientMatches(Recipe recipe1, Recipe recipe2){
    int count = 0;
    for(int i = 0; i < recipe1.amount_of_ingredients; i++){
        for(int j = 0; j < recipe2.amount_of_ingredients; j++){
            if(strcmp(recipe1.ingredients[i].name, recipe2.ingredients[j].name) == 0){
                count++;
            }
        }
    }
    return count;
}

void freeRecipe(Recipe recipe){
    for(int i = 0; i < recipe.amount_of_ingredients; i++){
        free(recipe.ingredients[i].name);
        free(recipe.ingredients[i].unit);
    }
    free(recipe.ingredients);
    free(recipe.name);
}

void freeRecipes(Recipe *recipes, int amount_of_recipes){
    for(int i = 0; i < amount_of_recipes; i++){
        freeRecipe(recipes[i]); /*function that frees one recipe's data*/
    }
    free(recipes); /*last frees the whole array*/
}

/*Function that returns a random recipe with a given ingredient*/
Recipe getRandomRecipe(Recipe *recipes, int amount_of_recipes){
    return recipes[get_random_number(0, amount_of_recipes-1)];
}

Recipe *readRecipes(int *amount_of_recipes, char *filePlace){
    FILE *file = openFile(filePlace, "r");
    *amount_of_recipes = countRecipes(filePlace);

    Recipe *recipes = (Recipe *) chkMalloc(sizeof(Recipe) * *amount_of_recipes, "Recipes");

    for(int i = 0; i < *amount_of_recipes; i++){
        fscanf(file, "{\n"); /*Ignore { syntax*/
        recipes[i] = readNextRecipe(&file);
        fscanf(file, "}\n"); /*Ignore } syntax*/
    }

    fclose(file);
    return recipes;
}

Recipe readNextRecipe(FILE **file){
    int i;
    char bufName[50], bufUnit[50], bufIngredientName[50];
    Recipe recipe;

    /*Scans the recipes name*/
    fscanf(*file, "name=\"%[^\"]\";\n", bufName);
    recipe.name = (char *) chkMalloc(strlen(bufName)+1, "recipe name");
    strcpy(recipe.name, bufName);

    /*Finds the amount of ingredients and creates the ingredient array*/
    recipe.amount_of_ingredients = countIngredientInRecipe(recipe.name);
    recipe.ingredients = (Ingredient *) chkMalloc(sizeof(Ingredient) * recipe.amount_of_ingredients, "Ingredient array");

    /*Fills the ingredient array*/
    for(i = 0; i < recipe.amount_of_ingredients; i++){
        fscanf(*file, "ingredient=\"%[^\"]\", amount=\"%f\", unit=\"%[^\"]\";\n", bufIngredientName, &recipe.ingredients[i].amount, bufUnit);
        recipe.ingredients[i].name = (char *) chkMalloc(strlen(bufIngredientName)+1, "Ingredient name");
        recipe.ingredients[i].unit = (char *) chkMalloc(strlen(bufUnit)+1, "Ingredient unit");

        strcpy(recipe.ingredients[i].name, bufIngredientName);
        strcpy(recipe.ingredients[i].unit, bufUnit);
    }
    return recipe;
}

/*This function counts how many ingredients a given recipe has*/
int countIngredientInRecipe(char *name){
    FILE *file = openFile("files/recipes.txt", "r");
    char line[100];
    int i;
    while(fgets(line, 100, file) != NULL){
        if(strstr(line, name) != NULL){ /*Skips all lines that don't include name*/
            for(i = 0; strncmp(line, "}", 1) != 0; i++) /*Counts all lines until } is reached*/
                fgets(line, 100, file);
            fclose(file);
            return i-1; /*-1 so to not count the line with "}" in it*/
        }
    }
    fclose(file);
    return 0;
}

int countRecipes(char *filePlace){
    FILE *file = openFile(filePlace, "r");
    char line[100];
    int opens = 0, closes = 0;
    while(!feof(file)){
        fgets(line, 100, file);
        if(strncmp(line, "{", 1) == 0)
            opens++;
        else if(strncmp(line, "}", 1) == 0)
            closes++;
    }

    if(opens != closes){
        printf("Error: %s syntax error, missing \"{\" or \"}\"", filePlace);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    return opens;
}
