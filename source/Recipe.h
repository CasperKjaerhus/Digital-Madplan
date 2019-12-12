#ifndef RECIPE_H
#define RECIPE_H

#define MATCH_WEIGHT 2

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
Recipe getWeightedRecipe(Recipe *recipes, int amount_of_recipes, Recipe *planned_recipes, int amount_of_already_planned);
Recipe *dif_recipes(Recipe *recipes, int amount_of_recipes, Recipe *mealplan_recipes, int amount_of_already_planned, int *amount_unused);
int countIngredientInRecipe(char *name);
int countRecipes();
int get_random_number(int a, int b);
int getIngredientsInRecipes(Recipe *recipes, int amount_of_recipes);
void printRecipe(Recipe recipe);
void freeRecipe(Recipe recipe);
void freeRecipes(Recipe *recipes, int amount_of_recipes);
void printRecipes(Recipe *recipes, int amount_of_recipes);
int calcIngredientMatches(Recipe recipe1, Recipe recipe2);
#endif