#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Recipe.h"
#include <time.h>
#define WEEK 7


int main(void){
    int recipe_amount, i;
    Recipe *recipes;
    char answer;
    int answer1;
    char weekdays[7] = [Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday]
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    printRecipes(recipes, recipe_amount);

    printf("Do you want to generate a mealplan? Type y for yes, Type anything else for no");
    scanf("%c", &answer);

    if(answer == 'y'){
        printf("/*Mealplan for the Week*/");
        for(i = 0; i < WEEK; i++){
        printf("%s: %s", weekdays[i], recipes[i].name);
        }
    }
    else
        printf("Mealplan wasn't generated");
    /* Giver mulighed for at ændre en enkelt ret, i den genererede mealplan*/
    printf("If you wish to change a dish, please enter the number of the day, you would like to change");
    scanf("%d", &answer1);

    if(answer1 == 1)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);
    else if (answer1 == 2)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);
    else if (answer1 == 3)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);
    else if (answer1 == 4)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);
    else if (answer1 == 5)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);
    else if (answer1 == 6)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);
    else if (answer1 == 7)
        printf("%s: %s", weekdays[answer1-1], recipes[7].name);


        printf("Shopping list:");

    freeRecipes(&recipes, recipe_amount);
    return 0;
}

