#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum category{MEAT, VEGETABLES, FRUIT, CARBOHYDRATES, SPICES}Category;

typedef struct Ingredient{
    char *name;
    float amount;
    enum category cType;
    char *unit;
} Ingredient;