#include "ShoppingList.h"
#include "Recipe.h"
#include "Ingredient.h"
#include <stdlib.h>
#include <string.h>
/*
Shoppinglist *shopping_list(Recipe *recipe_input, int list_size){
    int i, j;
    Shoppinglist *shop_list = malloc(sizeof(Shoppinglist)*list_size);
    
    for(i = 0; i < list_size; i++){
       for(j = 0; j < recipe_input[i].amount_of_ingredients){
          strcat(shop_list[i].ingredient_name, recipe_input[i].ingredients[j].name);
          strcat(shop_list[i].ingredient_name, ",");
       }
       shop_list[i].amount = recipe_input[i].amount_of_ingredients;
    }

    return shop_list;
}

*/