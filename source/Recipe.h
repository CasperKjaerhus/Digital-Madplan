#include "Ingredient.h"
#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Recipe{
    char *name;
    int calories;
    Ingredient *ingredients;
    int arrayLength;
} Recipe;

Recipe readRecipe();