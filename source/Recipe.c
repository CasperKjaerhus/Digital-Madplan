#include "Recipe.h"
/* 
 * Gets random number from a to b, 
 * these values are inclusive 
 * Assumes that a is smaller than b
 */
int get_random_number(int a, int b){
    return (rand() % (b+1 - a)) + a;
}

int getIngredientsInRecipes(Recipe *recipes, int amount_of_recipes){
    int amount = 0;
    for(int i = 0; i < amount_of_recipes; i++){
        amount += recipes[i].amount_of_ingredients;
    }
    return amount;
}


/* Function that orders recipes relative to ingredients */
Recipe getWeightedRecipe(Recipe *recipes, int amount_of_recipes, Recipe *planned_recipes, int amount_of_already_planned){
    int amount_unused, highest_match = 0, return_index = 0;
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
        int WeightedRandom = get_random_number(0, 50 + matches[i]); /*This generates a random number between zero and 50 + whatever the corrospondings recipe has "scored"*/
        if(WeightedRandom > highest_match){
            return_index = i;
            highest_match = WeightedRandom;
        }
    }

    returnRecipe = Unused_recipes[return_index];


    free(matches);
    free(Unused_recipes);

    return returnRecipe;


}

/* Function that returns array of unused recipes */
Recipe *dif_recipes(Recipe *recipes, int amount_of_recipes, Recipe *mealplan_recipes, int amount_of_already_planned, int *amount_unused){
    Recipe *unplanned = chkMalloc(sizeof(Recipe) * amount_of_recipes, "Unplanned recipes");
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

/*This function copies a recipe and all its data to another recipe*/
void cpyRecipe(Recipe *target, Recipe *source){
    /*allocates space for name and copies it*/
    target->name = chkMalloc(strlen(source->name), "cpy Recipe name");
    strcpy(target->name, source->name);
    /*Copies the ints*/
    target->calories = source->calories;
    target->amount_of_ingredients = source->amount_of_ingredients;

    /*Makes space for all the ingredients*/
    target->ingredients = chkMalloc(sizeof(Ingredient) * source->amount_of_ingredients, "cpyRecipe");

    /*Copies the ingredient data one by one from source to target*/
    for(int i = 0; i < source->amount_of_ingredients; i++){
        target->ingredients[i].name = chkMalloc(strlen(source->name), "cpyRecipe ingredient name");
        strcpy(target->ingredients[i].name, source->ingredients[i].name);

        target->ingredients[i].amount = source->ingredients[i].amount;

        target->ingredients[i].unit = chkMalloc(strlen(source->ingredients[i].unit), "cpyRecipe ingredient unit");
        strcpy(target->ingredients[i].unit, source->ingredients[i].unit);
    }
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

void freeRecipe(Recipe *recipe){
    for(int i = 0; i < recipe->amount_of_ingredients; i++){
        free(recipe->ingredients[i].name);
        free(recipe->ingredients[i].unit);
    }
    free(recipe->ingredients);
    free(recipe->name);
}

void freeRecipes(Recipe **recipes, int amount_of_recipes){
    for(int i = 0; i < amount_of_recipes; i++)
        freeRecipe(recipes[i]);
    free(*recipes);
}

/*Function that returns a random recipe with a given ingredient*/
Recipe getRandomRecipe(Recipe *recipes, int amount_of_recipes){
    return recipes[get_random_number(0, amount_of_recipes)];
}



Recipe *readRecipes(int *amount_of_recipes){
    FILE *file = openFile("files/recipes.txt", "r");
    *amount_of_recipes = countRecipes();

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
    recipe.ingredients = chkMalloc(sizeof(Ingredient) * recipe.amount_of_ingredients, "Ingredient array");

    /*Fills the ingredient array*/
    for(i = 0; i < recipe.amount_of_ingredients; i++){
        fscanf(*file, "ingredient=\"%[^\"]\", amount=\"%f\", unit=\"%[^\"]\";\n", bufIngredientName, &recipe.ingredients[i].amount, bufUnit);
        recipe.ingredients[i].name = chkMalloc(strlen(bufIngredientName)+1, "Ingredient name");
        recipe.ingredients[i].unit = chkMalloc(strlen(bufUnit)+1, "Ingredient unit");

        strcpy(recipe.ingredients[i].name, bufIngredientName);
        strcpy(recipe.ingredients[i].unit, bufUnit);
    }
    return recipe;
}

void printRecipe(Recipe recipe){
    int i;
    printf("Name: %s\n", recipe.name);
    /*for(i = 0; i < recipe.amount_of_ingredients; i++){
        if(recipe.ingredients[i].amount != 0)
            printf("%d: %s %.0lf %s\n", i, recipe.ingredients[i].name, recipe.ingredients[i].amount, recipe.ingredients[i].unit);
        else
            printf("%d: %s %s\n", i, recipe.ingredients[i].name, recipe.ingredients[i].unit);       
    }*/
}

void printRecipes(Recipe *recipes, int amount_of_recipes){
    for(int i = 0; i < amount_of_recipes; i++){
        printRecipe(recipes[i]);
        printf("hmm");
    }
    printf("done");
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
            return i-1; /*-1 so to not count the line with "}" in it*/
        }
    }
    return 0;
}

int countRecipes(){
    FILE *file = openFile("files/recipes.txt", "r");
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
        printf("Error: files/recipes.txt syntax error, missing \"{\" or \"}\"");
        exit(EXIT_FAILURE);
    }
    return opens;
}