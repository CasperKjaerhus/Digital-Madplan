#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"
#include "TerminalInterface.h"

int main(void){
    int recipe_amount;
    Recipe *recipes;

    srand(time(NULL));

    recipes = readRecipes(&recipe_amount, "files/recipes.txt"); /*Reads all recipes from recipes.txt into memory*/

    int *counters = (int *) chkCalloc(sizeof(int) * recipe_amount, "counter allo");

    printMealplan(&recipes[0], 1);

    for(int i = 1; i < recipe_amount; i++){
       int match = calcIngredientMatches(recipes[0], recipes[i]);
       printf("%-50s Score: %d\n", recipes[i].name, match);
    }

    for(unsigned int i = 0; i < 100000000; i++){
        if(i % 10000000 == 0 && i != 0){
            long double percentage = ((double) i / 100000000.0) * 100.0;
            printf("%lf%% finished; i:%d\n", (double) percentage, i);
        }
        Recipe new = getWeightedRecipe(recipes, recipe_amount, &recipes[0], 1);
        int index = getIndex(recipes, recipe_amount, new);
        counters[index]++;
    }

    for(int i = 0; i < recipe_amount; i++)
        printf("%s has been chosen %d times\n", recipes[i].name, counters[i]);

    freeRecipes(recipes, recipe_amount);

    return EXIT_SUCCESS;
}


int getIndex(Recipe *recipes, int recipe_amount, Recipe target){
    for(int i = 0; i < recipe_amount; i++){
        if(strcmp(recipes[i].name, target.name) == 0)
            return i;
    }
    return -1;
}

