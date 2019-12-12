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
    int u, e;
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
    
    while(n == 0||n == 1|| n == 2){
        printf("\nMealplan Generator\n");
        printf("Choose an option:\n");
        printf("1) To create a new Mealplan.\n");
        printf("2) To access your previous Mealplan.\n");
        scanf(" %d", &n);

        if(n == 1){
            amount_of_people(mealplan);
            show_user_ingredients(mealplan);
            change_a_meal(mealplan);
        }
        else if(n == 2){
            mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
            printf("Choose an option:\n");
            printf("1) To see ingredients on af meal.\n2) To change a meal.\n3) To see current mealplan.\n");
            scanf("%d", &u);
            if(u == 1){
                show_user_ingredients(mealplan);
            }else if(u == 2){
                change_a_meal(mealplan);
            }else if(u == 3){
                for(e = 0; e < 7; e++){
                    printf("%s", mealplan[e].name);
                }
            }else{
                printf("invalid input - returning to the main menu...");
            }
            free(mealplan);
        }
    }
    freeRecipes(recipes, recipe_amount);

return EXIT_SUCCESS;
}