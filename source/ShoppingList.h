#include "Recipe.h"
#include <stdlib.h>
#include <string.h>
#include "FileHandler.h"

Ingredient *shopping_list(Recipe *recipe_array_input, int amount_of_recipes);
void print_shoppinglist(Recipe *recipe_input, int amount_of_recipes);
Ingredient *sorted_shopping_list(Ingredient *shoplist, int total_ingredients);
int cmpfunction(const void *first, const void *second);
int get_uniques(Ingredient *shoplist, int total_ingredients);
