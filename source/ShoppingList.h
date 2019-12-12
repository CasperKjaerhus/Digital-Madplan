#include "Recipe.h"
#include <stdlib.h>
#include <string.h>
#include "FileHandler.h"

Ingredient *shopping_list(Recipe *recipe_array_input, int amount_of_recipes);
void print_shoppinglist(Recipe *recipe_input, int amount_of_recipes);
int cmpfunction(const void *first, const void *second);
int get_uniques(Ingredient *shoplist, int total_ingredients);
Ingredient *summed_shopping_list(Ingredient *original_shoppinglist, int total_ingredients);