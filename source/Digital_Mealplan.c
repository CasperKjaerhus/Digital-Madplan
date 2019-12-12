#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount, mealplan_recipe_amount = 7;
    int i, n = 0;
    char m;
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
                printf("Press the number of the meal, of which you would like to change");
                printRecipes(mealplan, mealplan_recipe_amount);
                scanf(" %d", &i);
                if(i == 1){
                    mealplan[0] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
                else if( i == 2){
                    mealplan[1] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
                else if( i == 3){
                    mealplan[2] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
                else if( i == 4){
                    mealplan[3] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
                else if( i == 5){
                    mealplan[4] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
                else if( i == 6){
                    mealplan[5] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
                else if( i == 7){
                    mealplan[6] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                    printRecipes(mealplan, mealplan_recipe_amount);
                }
            }else if(m == 'n'){
                break;
        }
    }
    freeRecipes(&mealplan, mealplan_recipe_amount);
    freeRecipes(&recipes, recipe_amount);
}