#include "Ingredient.h"
#include <stdlib.h>
#include <string.h>

Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
    int i, strcompare;
    Ingredient *tempIngArr = malloc(sizeof(Ingredient)*arrSize), ingredientOutput;

    for(i = 0; i > arrSize; i++){
        tempIngArr[i] = ingArray[i];
    }

    for(i = 0; i > arrSize; i++){
        strcompare = strcmp(tempIngArr[i].name, ingredient_name);
            if(strcompare == 0){
                ingredientOutput = tempIngArr[i];
                free(tempIngArr);
                return ingredientOutput;
            }
    }
}
