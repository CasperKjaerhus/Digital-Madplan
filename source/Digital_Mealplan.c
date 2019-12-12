#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"
#define WEEK 7


int main(void){
    int recipe_amount, mealplan_recipe_amount = 7;
    int i, j,n = 0, people = 1, p;
    char m;
    Recipe *recipes;
    Recipe *mealplan;

    srand(time(NULL));

    /*recipes = readRecipes(&recipe_amount);
    mealplan = GenerateMealplan(recipes, recipe_amount);
    printRecipes(mealplan, 7);

    printf("\n\n");

    print_shoppinglist(mealplan, 7);*/
       
    recipes = readRecipes(&recipe_amount, "files/recipes.txt");
    /*printRecipes(recipes, recipe_amount); */
    
    while(n == 0||n == 1|| n == 2){
        printf("Mealplan Generator\n");
        printf("Choose an option:\n");
        printf("1) To create a new Mealplan.\n");
        printf("2) To access your previous Mealplan.\n");
        scanf(" %d", &n);

        if(n == 1){
            printf("How many people are the mealplan for?");
            scanf(" %d", &people);
            mealplan = GenerateMealplan(recipes, recipe_amount);
            for(j = 0; j < 7; j++){
                for(p = 0; p < mealplan[j].amount_of_ingredients; p++){
                    mealplan[j].ingredients[p].amount = mealplan[j].ingredients[p].amount * people;
                }
            }
            printRecipes(mealplan, mealplan_recipe_amount);
            recipe_to_file(mealplan, mealplan_recipe_amount);
        }
        else if(n == 2){
            mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
            printRecipes(mealplan, mealplan_recipe_amount);
        }
        else{
            printf("Invalid input");
        }

        printf("Would you like to change one of the daily meals? (y/n).\n");
        scanf(" %c", &m);

            if(m == 'y'){
                printf("Press the number of the meal, of which you would like to change!\n");
                scanf(" %d", &i);
                if(i >= 1 && i <= 7){
                    mealplan[i-1] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
            }else if(m == 'n'){
                break;
            }
    }
    freeRecipes(&mealplan, mealplan_recipe_amount);
    freeRecipes(&recipes, recipe_amount);
}