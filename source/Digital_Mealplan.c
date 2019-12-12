#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount, mealplan_recipe_amount = 7;
    int n = 0;
    Recipe *recipes;
    Recipe *mealplan;
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount, "files/recipes.txt");
    //printRecipes(recipes, recipe_amount);
    
    while(n == 0||n == 1|| n == 2){
        printf("Mealplan Generator\n");
        printf("Choose an option:\n");
        printf("1) to create a new Mealplan.\n");
        printf("2) to access your previous Mealplan.\n");
        scanf(" %d", &n);

        if(n == 1){
            mealplan = GenerateMealplan(recipes, recipe_amount);
            printRecipes(mealplan, mealplan_recipe_amount);
            recipe_to_file(mealplan, mealplan_recipe_amount);
            free(mealplan);
        }
        else if(n == 2){
            mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
            printRecipes(mealplan, mealplan_recipe_amount);
            freeRecipes(mealplan, mealplan_recipe_amount);
        }
        else
            printf("Invalid input");
    }

    freeRecipes(recipes, recipe_amount);
}