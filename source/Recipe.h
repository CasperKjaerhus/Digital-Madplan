#include "Ingredient.h"

typedef struct Recipe{
    char *name;
    int calories;
    Ingredient *ingredients;
    Ingredient test;
} Recipe;