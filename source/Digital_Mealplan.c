#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount, i,n;
    Recipe *recipes;
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    printRecipes(recipes, recipe_amount);

    printf("Mealplan Generator\n");
    printf("Choose one of the following two options:\n");
    printf("Press 1 to create a new Mealplan.\n");
    printf("Press 2 to access your previous Mealplan.\n");
    scanf("%d", &n);

    if(n == 1){
        
    }
    else if(n == 2){

    }
    else
        printf("Invalid input");
    
    freeRecipes(&recipes, recipe_amount);
    return 0;
}