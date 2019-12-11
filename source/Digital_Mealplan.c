#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount, i;
    Recipe *recipes;
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    printRecipes(recipes, recipe_amount);


    freeRecipes(&recipes, recipe_amount);
    return 0;
}