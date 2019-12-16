#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include "ShoppingList.h"
#include "TerminalInterface.h"

void new_mealplan(Recipe *recipes, int amount_of_recipes){
    Recipe *mealplan;
    int people_amount = 1;

    mealplan = GenerateMealplan(recipes, amount_of_recipes);

    amount_of_people(mealplan, &people_amount);
    showIng_changeMeal(recipes, mealplan, amount_of_recipes);

    free(mealplan);
}

void previous_mealplan(int *mealplan_recipe_amount, Recipe *recipes, int amount_of_recipes){
    Recipe *mealplan;
    int people = 1;

    mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
    last_mealplan(recipes, mealplan, amount_of_recipes, &people);
    recipe_to_file(mealplan, 7);
    
    free(mealplan);
}

/* This function assembles the functions showIng_changeMeal and amount_of_people */
void last_mealplan(Recipe *recipes, Recipe *mealplan, int amount_of_recipes, int *people){
    int u;
    int mealplan_recipe_amount = 7;

    printMealplan(mealplan, 7);

    printf("\nChoose an option:\n");
    printf("1) To see ingredients on a meal OR to change a meal on the current mealplan.\n2) To see current mealplan.\n3) Change amount of people that the mealplan is for.\n");
    scanf(" %d", &u);
    
    if(u == 1)
        showIng_changeMeal(recipes, mealplan, amount_of_recipes);
    else if(u == 2)
        printMealplan(mealplan, mealplan_recipe_amount);
    else if(u == 3)
        amount_of_people(mealplan, people);
    else
        printf("invalid input - returning to the main menu...");
}


void showIng_changeMeal(Recipe *recipes, Recipe *mealplan, int recipe_amount){
    int i, d, dish;

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
                    if(mealplan[dish - 1].ingredients[s].amount > 0.0)
                        printf("%s %.1lf %s\n", mealplan[dish - 1].ingredients[s].name, mealplan[dish - 1].ingredients[s].amount, mealplan[dish - 1].ingredients[s].unit);
                    else
                        printf("%s %s\n", mealplan[dish - 1].ingredients[s].name, mealplan[dish - 1].ingredients[s].unit);
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
void amount_of_people(Recipe *mealplan, int *people_amount){
    int people, mealplan_recipe_amount = 7;

    printf("How many people is the mealplan for?\n");
    scanf(" %d", &people);
    
    updateAmountOfPeople(mealplan, *people_amount, people);
    *people_amount = people;
    
    printMealplan(mealplan, 7);
    recipe_to_file(mealplan, mealplan_recipe_amount);
}

void updateAmountOfPeople(Recipe *mealplan, int amount_currently, int amount_to_change){
    /*First reset amount so it can be changed to correct amount of people*/
    if(amount_currently != 1){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < mealplan[i].amount_of_ingredients; j++){
                mealplan[i].ingredients[j].amount /= amount_currently;
            }
        }
    }
    /*Now update amount!*/
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < mealplan[i].amount_of_ingredients; j++){
            mealplan[i].ingredients[j].amount *= amount_to_change;
         }
    }
}

/* Function that prints the mealplan */ 
void printMealplan(Recipe *mealplan, int amount){
    for(int i = 0; i < 7; i++){
        printf("DAY %d: %s\n", i + 1, mealplan[i].name);
    }
}