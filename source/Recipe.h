#ifndef RECIPE_H
#define RECIPE_H

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
Recipe getRandomRecipe(Recipe *recipes, int amount_of_recipes);
int countIngredientInRecipe(char *name);
int countRecipes();
void printRecipe(Recipe recipe);
void freeRecipe(Recipe *recipe);
void freeRecipes(Recipe **recipes, int amount_of_recipes);
void printRecipes(Recipe *recipes, int amount_of_recipes);
#endif