#include "Mealplan.h"

/* Function that generates a mealplan for 7 days */
Recipe *GenerateMealplan(Recipe *recipes, int amount_of_recipes){

    Recipe *mealplan = (Recipe *) chkMalloc(sizeof(Recipe) * 7, "mealplan allokation");
    /*Sets a starting point for the mealplan.. aka: day 1 is always completely random*/
    mealplan[0] = getRandomRecipe(recipes, amount_of_recipes);

    /*Gets weighted recipes for every other day*/
    for(int i = 1; i < 7; i++){
        mealplan[i] = getWeightedRecipe(recipes, amount_of_recipes, mealplan, i);
    }

    return mealplan;
}

void recipe_to_file(Recipe *recipes, int amount_of_recipes){
    if(!doesFileExist("files/printmealplan.txt"))
        createFile("files/printmealplan.txt");
    FILE *mealplanTofile = openFile("files/printmealplan.txt", "w+");

    for(int i = 0; i < amount_of_recipes; i++){
        fprintf(mealplanTofile, "{\nname=\"%s\";\n", recipes[i].name);
        for(int j = 0; j < recipes[i].amount_of_ingredients; j++){
            fprintf(mealplanTofile, "ingredient=\"%s\", amount=\"%.1f\", unit=\"%s\";\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount, recipes[i].ingredients[j].unit);
        }

        /*Parsing syntax in file, so it types out properly*/
        if(i == amount_of_recipes-1)
            fprintf(mealplanTofile, "}");
        else
            fprintf(mealplanTofile, "}\n"); 
    }
    fclose(mealplanTofile);
}