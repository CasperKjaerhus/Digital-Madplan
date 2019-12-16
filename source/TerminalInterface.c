#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"
#include "TerminalInterface.h"
#define WEEK 7

void new_mealplan(Recipe *recipes, int amount_of_recipes){
    Recipe *mealplan;

    mealplan = GenerateMealplan(recipes, amount_of_recipes);

    amount_of_people(mealplan);
    showIng_changeMeal(recipes, mealplan);

    free(mealplan);
}

void previous_mealplan(int *mealplan_recipe_amount, Recipe *recipes){
    Recipe *mealplan;

    mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
    last_mealplan(recipes, mealplan);
    recipe_to_file(mealplan, 7);
    
    free(mealplan);
}
/* This function assembles the functions showIng_changeMeal and amount_of_people */
void last_mealplan(Recipe *recipes, Recipe *mealplan){
    int u;
    int mealplan_recipe_amount = 7;
    int people;

    printMealplan(mealplan, 7);

    printf("\nChoose an option:\n");
    printf("1) To see ingredients on a meal OR to change a meal on the current mealplan.\n2) To see current mealplan.\n3) Change amount of people that the mealplan is for.\n");
    scanf(" %d", &u);
    
    if(u == 1){
        showIng_changeMeal(recipes, mealplan);
    }else if(u == 2){
        printMealplan(mealplan, mealplan_recipe_amount);
    }else if(u == 3){
        printf("How many people is the mealplan for?\n");
        scanf(" %d", &people);
            for(int i = 0; i < 7; i++){
                for(int j = 0; j < mealplan[i].amount_of_ingredients; j++){
                        mealplan[i].ingredients[j].amount *= people;
                }
            }
    }else
        printf("invalid input - returning to the main menu...");
}


void showIng_changeMeal(Recipe *recipes, Recipe *mealplan){
    int i, d, dish;
    char list_answer, m;
    int recipe_amount, mealplan_recipe_amount = 7;

    /* The user has the option to navigate around in the program, e.g. to see ingredientlist for a given recipe and also to change a recipe in the generated mealplan */
    while(d != 0){
        printf("\nChoose an option:\n");
        printf("0) Main menu.\n1) See ingredient specification on a meal.\n2) Change a current meal.\n");
        scanf(" %d", &d);
    
        /* The user has choosen to see ingredientlist for a recipe in the generated mealplan */
        if(d == 1){
            printf("Please enter the number of the meal of which you would like to see the ingredient list for.\n");
            scanf(" %d", &dish);
            
            /* The user chooses a number between 1 and 7 - then a for-loop is used to list the ingredients in the choosen recipe */ 
            /* We subtract with 1 becuase the mealplan array starts in index 0 */
            if(dish >= 1 && dish <= 7){
                printf("\n%s\n", mealplan[dish - 1].name);
                for(int s = 0; s < mealplan[dish - 1].amount_of_ingredients; s++){
                    printf("%s %lf %s\n", mealplan[dish - 1].ingredients[s].name, mealplan[dish - 1].ingredients[s].amount, mealplan[dish - 1].ingredients[s].unit);
                }
            }
        }else if(d == 2){
            /* The user has chosen to change a recipe in the generated mealplan - replaces a recipe with a recipe that is NOT in the current mealplan */
            printf("Press the number of the meal, of which you would like to change!\n");
            scanf(" %d", &i);

            if(i >= 1 && i <= 7){
                mealplan[i-1] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                printMealplan(mealplan, 7);
            }
        }     
    }
}

/* Function that gives the user the option to adjust the mealplan that is yet-to-be generated to a given amount of people  */
/* Ingredients are then multiplied by the amount of people that the user inputs (the recipes are premade to 1 person) */
void amount_of_people(Recipe *mealplan){
    int people, j, p, l, mealplan_recipe_amount = 7;
    Recipe *recipes;

    printf("How many people is the mealplan for?\n");
    scanf(" %d", &people);
    
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < mealplan[i].amount_of_ingredients; j++){
             mealplan[i].ingredients[j].amount *= people;
        }
    }
    /* Here we print the recipe that is now adjusted to the inputtet amount of people*/
    printMealplan(mealplan, 7);
    recipe_to_file(mealplan, mealplan_recipe_amount);
}

/* Formattet print of the whole mealplan */ 
void printMealplan(Recipe *mealplan, int amount){
    for(int i = 0; i < 7; i++){
        printf("DAY %d: %s\n", i + 1, mealplan[i].name);
    }
}

