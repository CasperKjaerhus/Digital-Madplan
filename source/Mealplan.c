#include "Mealplan.h"

/* Function that generates a mealplan for 7 days */
Recipe *GenerateMealplan(Recipe *recipes, int amount_of_recipes){

    Recipe *mealplan = (Recipe *) chkMalloc(sizeof(Recipe) * 7, "mealplan allokation");
    /*Sets a starting point for the mealplan.. aka: day 1 is always completely random*/
    mealplan[0] = getRandomRecipe(recipes, amount_of_recipes);

    /*Gets weighted recipes for every other day*/
    for(int i = 1; i <= 7; i++){
        mealplan[i] = getWeightedRecipe(recipes, amount_of_recipes, mealplan, i);
    }

    return mealplan;
}