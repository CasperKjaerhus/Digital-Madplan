#include "Recipe.h"

Recipe readRecipe(){
    Recipe recipe;

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
