#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum category{meat, vegetables, fruit, carbohydrates, spices};

typedef struct Ingredient{
    char *name;
    int amount;
    enum category;
    char *unit;
} Ingredient;