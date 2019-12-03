#include "Recipe.h"

/*Function that returns a random number. Used for get_recipe function*/
int randomGen(int max){
    int random;

    if(max > 0){
        random = (rand() % max);
        return random;
    } else{
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


Recipe *readRecipe(){
    FILE *file = openFile("files/recipes.txt", "r");
    char name[30], unit[30];
    int amount;
    fscanf(file, "{\n name=\"%[^\"]\";", name);
    recipe.name = malloc(strlen(name));
    strcpy(recipe.name, name);

    recipe.ingredients = (Ingredient *) malloc(sizeof(Ingredient) * 20);
    recipe.arrayLength = 20;

    char line[100];
    for(int i = 0; strcmp(line, "}") != 0; i++){
        fgets(line, 100, file); /*Reads the whole line*/
        sscanf(line, "ingredient=\"%[^\"]\", amount=\"%d\", unit=\"%[^\"]\";", name, &amount, unit); /*scans the data from the line*/

        /*TODO: Actually insert the ingredient from list of ingredients into recipe by finding struct ingredient */
        /*recipe.ingredients[i].name = malloc(strlen(name)); */

        recipe.ingredients[i].amount = amount;
        
        recipe.ingredients[i].unit = malloc(strlen(unit));
        strcpy(recipe.ingredients[i].unit, unit);
    }
    
    printf("name = %s\n", recipe.name);
    printf("amount = %d %s\n", recipe.ingredients[0].amount, recipe.ingredients[0].unit);
    fclose(file);
    return recipe;
}

