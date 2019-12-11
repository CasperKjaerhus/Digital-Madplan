#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount;
    Recipe *recipes;
    Recipe *mealplan;
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    mealplan = GenerateMealplan(recipes, recipe_amount);
    printf("whatthefuck\n");

    printf("whatthefuck");
    recipe_to_file(mealplan, 7);
    printf("whatthefuck2");

    freeRecipes(&recipes, recipe_amount);
}