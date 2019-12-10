#include "Recipe.h"
#include <string.h>
#include <stdlib.h>

/*Function that returns a random number. Used for get_recipe function*/
int randomGen(int max){
    
    if(max > 0){
        return (rand() % max);
    } else{
        return 0;
    }
}

/* Function that orders recipes relative to ingredients */
Recipe getWeightedRecipe(Recipe *recipes, int amount_of_recipes, Recipe *mealplan_recipes, int amount_of_already_planned){
    
}

/* Function that returns array of unused recipes */
Recipe *dif_recipes(Recipe *recipes, int amount_of_recipes, Recipe *mealplan_recipes, int amount_of_already_planned){
    Recipe *unplanned = chkMalloc(sizeof(Recipe) * amount_of_recipes, "Unplanned recipes");
    
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
    return recipes[randomGen(amount_of_recipes)];
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
    for(i = 0; i < recipe.amount_of_ingredients; i++){
        if(recipe.ingredients[i].amount != 0)
            printf("%d: %s %.0lf %s\n", i, recipe.ingredients[i].name, recipe.ingredients[i].amount, recipe.ingredients[i].unit);
        else
            printf("%d: %s %s\n", i, recipe.ingredients[i].name, recipe.ingredients[i].unit);       
    }
}

void printRecipes(Recipe *recipes, int amount_of_recipes){
    for(int i = 0; i < amount_of_recipes; i++)
        printRecipe(recipes[i]);
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