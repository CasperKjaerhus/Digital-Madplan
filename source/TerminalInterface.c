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
    showIng_changeMeal(recipes, mealplan, amount_of_recipes);

    free(mealplan);
}

void previous_mealplan(int *mealplan_recipe_amount, Recipe *recipes, int amount_of_recipes){
    Recipe *mealplan;

    mealplan = readRecipes(mealplan_recipe_amount, "files/printmealplan.txt");
    last_mealplan(recipes, mealplan, amount_of_recipes); /*Der er noget der fejler her!*/
    recipe_to_file(mealplan, 7);
    
    free(mealplan);
}

void last_mealplan(Recipe *recipes, Recipe *mealplan, int amount_of_recipes){
    int u;
    int mealplan_recipe_amount = 7;
    int people;

    printMealplan(mealplan, 7);

    printf("\nChoose an option:\n");
    printf("0) Back to the main menu\n1) To see ingredients on af meal or to change a meal.\n2) To see current mealplan.\n3) Change amount of people, the mealplan is for.\n");
    scanf(" %d", &u);
    
    if(u == 1){
        showIng_changeMeal(recipes, mealplan, amount_of_recipes);
    }else if(u == 2){
        for(int i = 0; i < 7; i++){
            printf("%s", mealplan[i].name);
        }
    }else if(u == 3){
        printf("How many people is the mealplan for?\n");
        scanf(" %d", &people);
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < mealplan[i].amount_of_ingredients; j++){
                    mealplan[i].ingredients[j].amount *= people;
            }
        }
    }
}

void showIng_changeMeal(Recipe *recipes, Recipe *mealplan, int recipe_amount){
    int i, d, dish;
    char list_answer, m;
    int mealplan_recipe_amount = 7;

    while(d != 0){
        printf("\nChoose an option:\n");
        printf("0) Main menu.\n1) See ingredient specification on a meal.\n2) Change a current meal.\n");
        scanf(" %d", &d);

        if(d == 1){
            printf("Please enter the number of the meal of which you would like to see the ingredient list for.\n");
            scanf(" %d", &dish);

            if(dish >= 1 && dish <= 7){
                printf("\n%s\n", mealplan[dish - 1].name);
                for(int s = 0; s < mealplan[dish - 1].amount_of_ingredients; s++){
                    printf("%s %lf %s\n", mealplan[dish - 1].ingredients[s].name, mealplan[dish - 1].ingredients[s].amount, mealplan[dish - 1].ingredients[s].unit);
                }
            }
        }else if(d == 2){
            printf("Press the number of the meal, of which you would like to change!\n");
            scanf(" %d", &i);

            if(i >= 1 && i <= 7){
                mealplan[i-1] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                printMealplan(mealplan, 7);
            }
        }     
    }
}

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
    printMealplan(mealplan, 7);
    printf("Test");
    recipe_to_file(mealplan, mealplan_recipe_amount);
}

void printMealplan(Recipe *mealplan, int amount){
    for(int i = 0; i < 7; i++){
        printf("DAY %d: %s\n", i + 1, mealplan[i].name);
    }
}