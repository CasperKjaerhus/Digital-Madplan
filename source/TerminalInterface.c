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
    show_user_ingredients(mealplan);
    changeMeal(mealplan);

    free(mealplan);
}

void previous_mealplan(){
    Recipe *mealplan;
    mealplan = readRecipes(&mealplan_recipe_amount, "files/printmealplan.txt");
    last_mealplan(mealplan);
    free(mealplan);
}

void last_mealplan(Recipe *mealplan){
    int u, e;
    int mealplan_recipe_amount = 7;
    printf("Choose an option:\n");
            printf("1) To see ingredients on af meal.\n2) To change a meal.\n3) To see current mealplan.\n");
            scanf(" %d", &u);
            if(u == 1){
                show_user_ingredients(mealplan);
            }else if(u == 2){
                changeMeal(mealplan);
            }else if(u == 3){
                for(e = 0; e < 7; e++){
                    printf("%s", mealplan[e].name);
                }
            }else{
                printf("invalid input - returning to the main menu...");
            }
            printRecipes(mealplan, mealplan_recipe_amount);
}
void show_user_ingredients(Recipe *mealplan){
    int s;
    char list_answer, dish;
    Recipe *recipes;

    while(list_answer != 'n'){
            printf("Would you like to see ingredient specification on a meal? (y/n)\n");
            scanf(" %c", &list_answer);
                if(list_answer == 'y'){
                    printf("Please enter the number of the meal of which you would like to see the ingredient list for.\n");
                        scanf(" %d", &dish);
                        
                    if(dish >= 1 && dish <= 7){
                        printf("\n%s\n", mealplan[dish - 1].name);
                        for(s = 0; s < mealplan[dish - 1].amount_of_ingredients; s++){
                            printf("%s %lf %s\n", mealplan[dish - 1].ingredients[s].name, mealplan[dish - 1].ingredients[s].amount, mealplan[dish - 1].ingredients[s].unit);
                        }
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
    /*printRecipes(mealplan, mealplan_recipe_amount);*/
    printMealplan(mealplan, 7);
    recipe_to_file(mealplan, mealplan_recipe_amount);
}

void printMealplan(Recipe *mealplan, int amount){
    for(int i = 0; i < 7; i++){
        printf("DAY %d: %s\n", i + 1, mealplan[i].name);
    }
}

void changeMeal(Recipe *mealplan){
    char m;
    int i, k;
    int recipe_amount, mealplan_recipe_amount = 7;
    Recipe *recipes;
     
    printf("Would you like to change one of the daily meals? (y/n).\n");
    scanf(" %c", &m);

        if(m == 'y'){
            printf("Press the number of the meal, of which you would like to change!\n");
            scanf(" %d", &i);
            
            if(i >= 1 && i <= 7){
                mealplan[i-1] = getWeightedRecipe(recipes, recipe_amount, mealplan, 7);
                for(k = 0; k < 7; k++){
                    printf("DAY %d: %s\n", k + 1, mealplan[k].name);
                }
            }
        }
}