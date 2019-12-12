#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"
#include "TerminalInterface.h"
#define WEEK 7



int main(void){
    int recipe_amount, mealplan_recipe_amount = 7;
    int n = 0;
    Recipe *recipes;
    Recipe *mealplan;

    srand(time(NULL));

    /*recipes = readRecipes(&recipe_amount);
    mealplan = GenerateMealplan(recipes, recipe_amount);
    printRecipes(mealplan, 7);

    printf("\n\n");

    print_shoppinglist(mealplan, 7);*/
    /*printRecipes(recipes, recipe_amount); */

    recipes = readRecipes(&recipe_amount, "files/recipes.txt");
    
    while(n >= 0 && n <= 3){
        printf("\nMealplan Generator\n");
        printf("Choose an option:\n");
        printf("1) To create a new Mealplan.\n");
        printf("2) To access your previous Mealplan.\n");
        printf("3) To get Shoppinglist.\n");
        scanf(" %d", &n);

        if(n == 1){
            new_mealplan(recipes, recipe_amount);
        }
        else if(n == 2){
            previous_mealplan(mealplan);
        }
        else if(n == 3){
            mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
            print_shoppinglist(mealplan, mealplan_recipe_amount);
            free(mealplan);
        }
    }
    freeRecipes(recipes, recipe_amount);

return EXIT_SUCCESS;
}