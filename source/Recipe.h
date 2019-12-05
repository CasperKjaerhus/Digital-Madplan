#include "Ingredient.h"
#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Recipe{
    char *name;
    int calories;
    Ingredient *ingredients;
    int amount_of_ingredients;
} Recipe;

Recipe *readRecipes();
Recipe readNextRecipe(FILE **file);
int countIngredientInRecipe(char *name);
int countRecipes();
void printRecipe(Recipe recipe);