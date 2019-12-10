#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Recipe.h"
#include <time.h>

int main(void){
    int recipe_amount;
    Recipe *recipes;
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    printRecipes(recipes, recipe_amount);

    freeRecipes(&recipes, recipe_amount);
    return 0;
}