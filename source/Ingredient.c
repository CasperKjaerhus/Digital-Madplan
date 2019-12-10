#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Ingredient.h"
/*

<<<<<<< HEAD
/*Function that searches for a ingredient char and finds the corresponding ingrendient struct*/
/*Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
=======
<<<<<<< HEAD
Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
=======
/*Function that searches for a ingredient char and finds the corresponding ingrendient struct*/
/*Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
>>>>>>> 548735baa28c36e91ef634871fbf8949a818c1d5
>>>>>>> 6afbbbbbe36f82165aaf65e411b3b408274b74ea
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
<<<<<<< HEAD
    
    return ingredientOutput;
}
=======

    return *tempIngArr;
}
*/
void createIngredient(char *name, int amount){
    //Ingredient newIngredient;
    
    //newIngredient.name = malloc(strlen(name));
}

>>>>>>> 6afbbbbbe36f82165aaf65e411b3b408274b74ea
*/