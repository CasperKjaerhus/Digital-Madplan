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
    int n = 1;
    Recipe *recipes;
    Recipe *mealplan;

    srand(time(NULL));

    recipes = readRecipes(&recipe_amount, "files/recipes.txt"); /*Reads all recipes from recipes.txt into memory*/
    
    while(n >= 1 && n <= 3){
        printf("\nMealplan Generator\n");
        printf("Choose an option:\n");
        printf("1) To create a new Mealplan.\n");
        printf("2) To access your previous Mealplan.\n");
        printf("3) To print a Shoppinglist to file.\n");
        scanf(" %d", &n);

        if(n == 1){
            new_mealplan(recipes, recipe_amount);
        }
        else if(n == 2){
            previous_mealplan(&mealplan_recipe_amount, recipes);
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