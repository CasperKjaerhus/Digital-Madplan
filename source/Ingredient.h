#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum category{MEAT, VEGETABLES, FRUIT, CARBOHYDRATES, SPICES}Category;

typedef struct Ingredient{
    char *name;
    float amount;
    Category cType;
    char *unit;
} Ingredient;
#endif