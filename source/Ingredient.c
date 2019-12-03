#include "Ingredient.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000

int main(void){    
char str[MAXCHAR];

FILE *recipe = fopen("ingredients.txt", "r");


if(recipe == NULL){
  printf("Could not open file %s", recipe);
  return 1;
}    

while (fgets(str, MAXCHAR, recipe) != NULL){


  printf("Read from file: %s\n", str);
}
fclose(recipe);
return 0;

}



void createIngredient(char *name, int amount){
    Ingredient newIngredient;
    
    newIngredient.name = malloc(strlen(name));
}

}
