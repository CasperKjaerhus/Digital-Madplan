#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"

int main(void){
    int recipe_amount;
    Recipe *recipes;
    Shoppinglist *shoppingliste = malloc(sizeof(Shoppinglist)*8)
    srand(time(NULL));

    recipes = readRecipes(&recipe_amount);
    //printRecipes(recipes, recipe_amount);
    
    GenerateMealplan(recipes, recipe_amount);
    

    shoppingeliste = shopping_list(recipes, 8);

    for(i = 0; i < 8; i++)
        printf("Ingredients: %s Amount: %d", shoppingliste[i].ingredient_name, shoppingliste[i].amount);

    free(shoppingliste);
    freeRecipes(&recipes, recipe_amount);
    return 0;
}