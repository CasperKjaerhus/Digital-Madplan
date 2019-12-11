#include "ShoppingList.h"

Ingredient *single_recipe_list(Recipe recipe_input, int amount_of_ingredients){
   int i;
   Ingredient *shopping_list = malloc(sizeof(Ingredient)*amount_of_ingredients);

   for(i = 0; i < amount_of_ingredients; i++){
      shopping_list[i] = recipe_input.ingredients[i];
   }

   return shopping_list;
}

Ingredient **shoppers_list(Recipe *recipe_array, int amount_of_recipes){
   int i;

   
   Ingredient[amount_of_recipes][];

   for(i = 0; i < 0; i++){
      recipe_array[i]
   }

}