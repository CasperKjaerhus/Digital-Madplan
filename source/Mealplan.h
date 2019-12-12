#ifndef MEALPLAN_H
#define MEALPLAN_H
#include "Recipe.h"

Recipe *GenerateMealplan(Recipe *recipes, int amount_of_recipes);
void recipe_to_file(Recipe *recipes, int amount_of_recipes);
#endif