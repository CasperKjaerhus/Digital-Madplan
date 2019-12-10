#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Ingredient.h"
/*

Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
    int i, strcompare;
    Ingredient *tempIngArr = malloc(sizeof(Ingredient)*arrSize), ingredientOutput;



        for(i = 0; i > arrSize; i++){
            tempIngArr[i] = ingArray[i];
        }

        for(i = 0; i < arrSize; i++){
            strcompare = strcmp(tempIngArr[i].name, ingredient_name);
                if(strcompare == 0){
                    free(tempIngArr);
                    return ingredientOutput;
                }
        }

    return *tempIngArr;
}

void createIngredient(char *name, int amount){
    Ingredient newIngredient;
    
    newIngredient.name = malloc(strlen(name));
}

*/