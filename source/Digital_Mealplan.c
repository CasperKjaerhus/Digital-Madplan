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
    int testRecipe = 6;

    srand(time(NULL));

    recipes = readRecipes(&recipe_amount, "files/recipes.txt"); /*Reads all recipes from recipes.txt into memory*/
    Recipe TestRecipes[6] = {recipes[0], recipes[1], recipes[11], recipes[12], recipes[8], recipes[10]};
    int *counters = (int *) chkCalloc(sizeof(int) * recipe_amount, "counter allo");

    printMealplan(TestRecipes, testRecipe);
    for(int j = 0; j < recipe_amount; j++){
        int match = 0;
        for(int i = 0; i < testRecipe; i++){
            match += calcIngredientMatches(TestRecipes[i], recipes[j]);
            if(i == testRecipe-1)
                printf("%-50s Score: %d\n", recipes[j].name, match);
        }
    }
    int tries = 10000000;
    for(unsigned int i = 0; i < tries; i++){
        if(i % ((tries) / 100) == 0 && i != 0){
            long double percentage = ((double) i / (double) tries) * 100.0;
            printf("%.0lf%% finished; i:%d\n", (double) percentage, i);
        }
        Recipe new = getWeightedRecipe(recipes, recipe_amount, TestRecipes, testRecipe);
        int index = getIndex(recipes, recipe_amount, new);
        counters[index]++;
    }
    if(!doesFileExist("procenter.txt")){
        createFile("procenter.txt");
    }
    FILE *numbers = openFile("procenter.txt", "w+");
    for(int i = 0; i < recipe_amount; i++){
        printf("%s has been chosen %d times, thats %.2lf%%\n", recipes[i].name, counters[i], ((double) counters[i] / tries) * 100.0);
        fprintf(numbers, "%d\n", counters[i]);
    }

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

