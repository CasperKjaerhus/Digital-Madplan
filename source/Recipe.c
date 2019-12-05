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

/*Function that returns a random recipe with a given ingredient*/
Recipe get_recipe(Ingredient ingred, Recipe *recipelist, int amount){
    int i, strcompare, j = 0, randnum;
    Recipe *recipeArray = (Recipe *) malloc(sizeof(Recipe)*amount);
    Recipe recipeOutput;
    Ingredient *ingred2 = (Ingredient *) malloc(sizeof(Ingredient)*amount);

    /*For-loop that stores ingredients in an ingredient-type array*/
    for(i = 0; i < amount; i++)
            ingred2[i] = *recipelist[i].ingredients;

    /*Checks if the ingredient matches ingredients in the recipe, stores them in a new recipe array if true*/
    for(i = 0; i < amount; i++){
        strcompare = strcmp(ingred.name, ingred2[i].name);
            if(strcompare == 0){
                recipeArray[j] = recipelist[i];
                j++;
            }
    }

    randnum = randomGen(j);

    /*Random recipe is chosen, so mealplans dont get too similar*/
    recipeOutput = recipeArray[randnum];

    free(ingred2);
    free(recipeArray);
    return recipeOutput;
}


Recipe *readRecipes(){
    FILE *file = openFile("files/recipes.txt", "r");
    int amount_of_recipes = countRecipes();
    printf("Found %d recipes!\n", amount_of_recipes);
    Recipe *recipes = (Recipe *) chkMalloc(sizeof(Recipe) * amount_of_recipes, "Recipes");

    for(int i = 0; i < amount_of_recipes; i++){
        fscanf(file, "{\n"); /*Ignore { syntax*/
        recipes[i] = readNextRecipe(&file);
        
        printRecipe(recipes[i]);
        fscanf(file, "}\n"); /*Ignore } syntax*/
    }

    fclose(file);
    return NULL;
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
        printf("%d: %s %lf %s\n", i, recipe.ingredients[i].name, recipe.ingredients[i].amount, recipe.ingredients[i].unit);
    }
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