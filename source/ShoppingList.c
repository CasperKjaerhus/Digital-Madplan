#include "ShoppingList.h"

Ingredient *shopping_list(Recipe *recipe_array_input, int amount_of_recipes){
   int i, z, j = 0, total_ingredients = getIngredientsInRecipes(recipe_array_input, amount_of_recipes);
   Ingredient *shoppinglist = chkMalloc(sizeof(Ingredient)*total_ingredients, "Shopping List");
   
   for(i = 0; i < amount_of_recipes; i++){
      for(z = 0; z < recipe_array_input[i].amount_of_ingredients; z++){
         shoppinglist[j] = recipe_array_input[i].ingredients[z];
         j++;
      }
   }

   return shoppinglist;
}

void print_shoppinglist(Recipe *recipe_input, int amount_of_recipes){
   int i, uniques, total_ingredients = getIngredientsInRecipes(recipe_input, amount_of_recipes);
   Ingredient *shoplist = shopping_list(recipe_input, amount_of_recipes);
   //Ingredient *summed_shoplist = summed_shopping_list(shoplist, total_ingredients);

   uniques = get_uniques(shoplist, total_ingredients);

   printf("Amount of uniques: %d\nUNSUMMED SHOPPINGLIST\n", uniques);

   for(i = 0; i < total_ingredients; i++){
      printf("Ingredient name: %s, amount: %.1lf, unit: %s\n", shoplist[i].name, shoplist[i].amount,  shoplist[i].unit);
   }

   /*printf("\n\n");

   for(i = 0; i < uniques; i++){
      printf("Ingredient name: %s, amount: %.1lf, unit: %s\n", summed_shoplist[i].name, summed_shoplist[i].amount,  summed_shoplist[i].unit);
   }

   free(summed_shoplist);*/
   free(shoplist);
}

int get_uniques(Ingredient *shoplist, int total_ingredients){
   int i, uniques = 1;

   qsort(shoplist, total_ingredients, sizeof(Ingredient), cmpfunction);

   for(i = 0; i < (total_ingredients-1); i++){
      if(strcmp(shoplist[i].name, shoplist[i+1].name) != 0){
         uniques += 1;
      }
   }

   return uniques;
}

int cmpfunction(const void *first, const void *second){
   const Ingredient *elem1 = first;
   const Ingredient *elem2 = second;

   return strcmp(elem1->name, elem2->name);
}

Ingredient *summed_shopping_list(Ingredient *original_shoppinglist, int total_ingredients){
   int uniques = get_uniques(original_shoppinglist, total_ingredients), i, j = 0;
   Ingredient *summed_shoplist = chkCalloc(sizeof(Ingredient)*uniques, "Summed shopping list");
   qsort(original_shoppinglist, total_ingredients, sizeof(Ingredient), cmpfunction); 

   for(i = 0; i < uniques; i++){
      summed_shoplist[i].name = original_shoppinglist[j].name;
      summed_shoplist[i].unit = original_shoppinglist[j].unit;
         while(summed_shoplist[i].name == original_shoppinglist[j].name){
            summed_shoplist[i].amount += original_shoppinglist[j].amount;
            j++;
         } 
   }

   return summed_shoplist;
}
