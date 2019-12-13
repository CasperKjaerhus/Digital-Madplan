#ifndef TERMINALINTERFACE_H
#define TERMINALINTERFACE_H
#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Mealplan.h"
#include "Recipe.h"
#include <time.h>
#include "ShoppingList.h"


void new_mealplan(Recipe *recipes, int amount_of_recipes);
void amount_of_people(Recipe *mealplan);
void changeMeal(Recipe *recipes, Recipe *mealplan);
void printMealplan(Recipe *mealplan, int amount);
void show_user_ingredients(Recipe *mealplan);
void last_mealplan(Recipe *recipes, Recipe *mealplan);
void previous_mealplan(int *mealplan_recipe_amount, Recipe *recipes);

#endif
