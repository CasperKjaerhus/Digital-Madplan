#include "Recipe.h"
#include <string.h>
#include <stdlib.h>

/*Function that returns a random number. Used for get_recipe function*/
int randomGen(int max){
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD

    if(max > 0){
        return (rand() % max);
    } else{
    if(max > 0){
=======
    if(max > 0){
>>>>>>> fe114ef3dd46eba28d8df8f98fde0d3f6ba3c8fa
=======
    if(max > 0){
>>>>>>> fe114ef3dd46eba28d8df8f98fde0d3f6ba3c8fa
=======
    if(max > 0){
>>>>>>> fe114ef3dd46eba28d8df8f98fde0d3f6ba3c8fa
        return rand() % max;
    } else {
        return 0;
    }
}

/*Function that returns a random recipe with a given ingredient*/
Recipe get_recipe(Ingredient ingred, Recipe *recipelist, int amount){
    int i, strcompare, j = 0, randnum;
    Recipe *recipeArray = malloc(sizeof(Recipe)*amount);
    Recipe recipeOutput;
    Ingredient *ingred2 = malloc(sizeof(Ingredient)*amount);

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
    Recipe recipe;

    char name[30], unit[30];
    double amount;
    
    fscanf(file, "{\n name=\"%[^\"]\";", name); /*Reads the name of the recipe*/

    recipe.name = malloc(strlen(name));
    strcpy(recipe.name, name);

    recipe.amount_of_ingredients = countIngredientInRecipe(name);
    recipe.ingredients = (Ingredient *) malloc(sizeof(Ingredient) * recipe.amount_of_ingredients);

    char line[100];
    fgets(line, 100, file);
    for(int i = 0; strncmp(line, "}", 1) != 0; i++){
        fgets(line, 100, file); /*Reads the whole line*/
        sscanf(line, "ingredient=\"%[^\"]\", amount=\"%lf\", unit=\"%[^\"]\";", name, &amount, unit); /*scans the data from the line*/
        printf("i: %d\n", i);
        /*TODO: Actually insert the ingredient from list of ingredients into recipe by finding struct ingredient */
        /*recipe.ingredients[i].name = malloc(strlen(name)); */

        recipe.ingredients[i].amount = amount;
        
        recipe.ingredients[i].unit = (char *) malloc(strlen(unit) + 1);
        strcpy(recipe.ingredients[i].unit, unit);
    }

    printf("name = %s\n", recipe.name);
    printf("amount = %lf %s\n", recipe.ingredients[0].amount, recipe.ingredients[0].unit);
    fclose(file);
    return NULL;
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