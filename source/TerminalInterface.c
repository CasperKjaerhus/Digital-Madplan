#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"
#include "TerminalInterface.h"
#define WEEK 7

void show_user_ingredients(Recipe *mealplan){
    int s;
    char list_answer, dish;
    Recipe *recipes;
    Recipe *mealplan;

    while(list_answer != 'n'){
            printf("Would you like to see ingredient specification on a meal? (y/n)\n");
            scanf(" %c", &list_answer);
                if(list_answer == 'y'){
                    
                    printf("Please enter the number of the meal of which you would like to see the ingredient list for.\n");
                        scanf("%d", &dish);
                        
                    if(dish >= 1 && dish <= 7){
                        printf("\n%s\n", mealplan[dish - 1].name);
                        for(s = 0; s < mealplan[dish - 1].amount_of_ingredients; s++){
                            printf("%s %lf %s\n", mealplan[dish - 1].ingredients[s].name, mealplan[dish - 1].ingredients[s].amount, mealplan[dish - 1].ingredients[s].unit);
                        }
                    }
                }
    }
    free(mealplan);
}
 

void amount_of_people(Recipe *mealplan){
    int people, j, p, l;
    int recipe_amount, mealplan_recipe_amount = 7;
    Recipe *recipes;
    Recipe *mealplan;

    printf("How many people are the mealplan for?\n");
    scanf(" %d", &people);
    
    mealplan = GenerateMealplan(recipes, recipe_amount);
    for(j = 0; j < 7; j++){
        for(p = 0; p < mealplan[j].amount_of_ingredients; p++){
             mealplan[j].ingredients[p].amount = mealplan[j].ingredients[p].amount * people;
        }
    }
    /*printRecipes(mealplan, mealplan_recipe_amount);*/
    for(l = 0; l < 7; l++){
        printf("DAY %d: %s\n", l + 1, mealplan[l].name);
    }
    
    recipe_to_file(mealplan, mealplan_recipe_amount);
}


void change_a_meal(Recipe *mealplan){
    char m;
    int i, k;
    int recipe_amount, mealplan_recipe_amount = 7;
    Recipe *recipes;
    Recipe *mealplan;
     
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
            }else if(m == 'n'){
                return 0;
            }
        }       
}