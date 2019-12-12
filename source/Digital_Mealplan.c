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

            while(list_answer != 'n'){
            printf("Would you like to see ingredient specification on a meal? (y/n)\n");
            scanf(" %c", &list_answer);
                if(list_answer == 'y'){
                    
                    printf("Please enter the number of the meal of which you would like to see the ingredient list for.\n");
                        scanf("%d", &dish);
                        
                    if(dish >= 1 && dish <= 7){
                        printf("%s\n", mealplan[dish - 1].name);
                        for(s = 0; s < mealplan[dish - 1].amount_of_ingredients; s++){
                            printf("%s %lf %s\n", mealplan[dish-1].ingredients[s].name, mealplan[dish-1].ingredients[s].amount, mealplan[dish-1].ingredients[s].unit);
                        }
                    }
                }
            }
            free(mealplan);
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
            }else if(m == 'n'){
                break;
            }
    }
    freeRecipes(mealplan, mealplan_recipe_amount);
    freeRecipes(recipes, recipe_amount);
}