#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount;
    int n = 0;
    Recipe *recipes;
    Recipe *mealplan;
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    //printRecipes(recipes, recipe_amount);
    
    while(n == 0||n == 1|| n == 2){
    printf("Mealplan Generator\n");
    printf("Choose one of the following two options:\n");
    printf("Press 1 to create a new Mealplan.\n");
    printf("Press 2 to access your previous Mealplan.\n");
    scanf("%d", &n);

    if(n == 1){
        mealplan = GenerateMealplan(recipes, recipe_amount);
        printRecipes(mealplan, 7);
        recipe_to_file(mealplan, 7);
    }
    else if(n == 2){
         /*TO DO, SCAN MEALPLANFILE*/
    }
    else
        printf("Invalid input");
    }
   
    

    

    freeRecipes(&mealplan, 7);
    freeRecipes(&recipes, recipe_amount);
}