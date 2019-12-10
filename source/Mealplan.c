#include "Mealplan.h"

/* Function that generates a mealplan for 7 days */
Recipe *GenerateMealplan(Recipe *recipes, int amount_of_recipes){

    Recipe *mealplan = (Recipe *) chkMalloc(sizeof(Recipe) * 7, "mealplan allokation");

    mealplan[0] = getRandomRecipe(recipes, amount_of_recipes);

    



    return mealplan;
}