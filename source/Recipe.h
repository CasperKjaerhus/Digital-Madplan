#include "Ingredient.h"
#include "FileHandler.h"
#include <stdio.h>
#include <string.h>

typedef struct Recipe{
    char *name;
    int calories;
    Ingredient *ingredients;
    Ingredient test;
} Recipe;

Recipe *readRecipe();