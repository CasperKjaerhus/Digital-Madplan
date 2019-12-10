#include "Recipe.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct shoppinglist{
    char *ingredient_name;
    int amount;
} Shoppinglist;

Shoppinglist *shopping_list(Recipe *recipe_input, int list_size);