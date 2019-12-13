#include "ShoppingList.h"

Ingredient *shopping_list(Recipe *recipe_array_input, int amount_of_recipes){
   int i, z, j = 0, total_ingredients = getIngredientsInRecipes(recipe_array_input, amount_of_recipes);
   Ingredient *shoppinglist = (Ingredient *) chkMalloc(sizeof(Ingredient)*total_ingredients, "Shopping List");
   
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
   Ingredient *summed_shoplist = summed_shopping_list(shoplist, total_ingredients);

   uniques = get_uniques(shoplist, total_ingredients);

   if(!doesFileExist("Shopping_list.txt"))
      createFile("Shopping_list.txt");
   
   FILE *shoppinglist_file = openFile("Shopping_list.txt", "w+");
   fprintf(shoppinglist_file, "Shopping List:\n");
   fprintf(shoppinglist_file, "_________________\n");
   fprintf(shoppinglist_file, "ingredient name:\t\tamount:\n\n");
   for(i = 0; i < uniques; i++){
      if(summed_shoplist[i].amount == 0.0)
         fprintf(shoppinglist_file, "%s\n", summed_shoplist[i].name);
      else
         fprintf(shoppinglist_file, "%-31s %-.1f %s\n", summed_shoplist[i].name, summed_shoplist[i].amount, summed_shoplist[i].unit);
   }

   fclose(shoppinglist_file);
   free(summed_shoplist);
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
   int uniques = get_uniques(original_shoppinglist, total_ingredients), i, currentUniqueAmount = 0;
   Ingredient *summed_shoplist = chkCalloc(sizeof(Ingredient)*uniques, "Summed shopping list");

   for(i = 0; i < total_ingredients; i++){
      if(isUniqueIngredient(summed_shoplist, currentUniqueAmount, original_shoppinglist[i])){
         summed_shoplist[currentUniqueAmount].name = original_shoppinglist[i].name;
         summed_shoplist[currentUniqueAmount].unit = original_shoppinglist[i].unit;
         summed_shoplist[currentUniqueAmount].amount = original_shoppinglist[i].amount;
         currentUniqueAmount++;
      } else{
         summed_shoplist[currentUniqueAmount-1].amount += original_shoppinglist[i].amount;
      }

   }

   return summed_shoplist;
}

int isUniqueIngredient(Ingredient *unique_array, int unique_amount, Ingredient ingredient){
   int i;
   
   for(i = 0; i < unique_amount; i++){
      if(strcmp(unique_array[i].name, ingredient.name) == 0){
         return 0;
      }
   }

   return 1;
}
int getIngredientsInRecipes(Recipe *recipes, int amount_of_recipes){
    int amount = 0;
    for(int i = 0; i < amount_of_recipes; i++){
        amount += recipes[i].amount_of_ingredients;
    }
    return amount;
}