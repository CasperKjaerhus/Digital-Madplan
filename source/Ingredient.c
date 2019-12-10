#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Ingredient.h"

/*Function that searches for a ingredient char and finds the corresponding ingrendient struct*/
/*Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
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
    
    return ingredientOutput;
}
*/