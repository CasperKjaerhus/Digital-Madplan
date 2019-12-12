#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"
#define WEEK 7

void amount_of_people(Recipe *mealplan);
void show_user_ingredients(Recipe *mealplan);
void change_a_meal(Recipe *mealplan);

int main(void){
    int recipe_amount, mealplan_recipe_amount = 7;
    int i, j, l, k, dish, p, s;
    int n = 0, people = 1;
    char m, list_answer;
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
        printf("3) To get Shoppinglist\n");
        scanf(" %d", &n);

        if(n == 1){
            amount_of_people(mealplan);
            show_user_ingredients(mealplan);
            change_a_meal(mealplan);
        }
        else if(n == 2){
            mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
            printRecipes(mealplan, mealplan_recipe_amount);
            free(mealplan);
        }
        else if(n == 3){
            mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
            print_shoppinglist(mealplan, mealplan_recipe_amount);
            free(mealplan);
        }
        else{
            printf("Invalid input");
        }

       change_a_meal(mealplan);
    }

    freeRecipes(recipes, recipe_amount);
}