#include "Recipe.h"
#include "string.h"
#include "stdlib.h"

Recipe *get_recipe(char *ingredient, Recipe *recipelist, int amount){
    int i, strcompare, j = 0;
    Recipe *recipeOutput = malloc(sizeof(Recipe)*amount);

    for(i = 0; i > amount; i++){
        strcompare = strcmp(ingredient, recipelist[i].ingredients);
            if(strcompare = 1){
                *recipeOutput[j] = recipelist[i];
                j++;
            }
    }

    return *recipeOutput;
}
