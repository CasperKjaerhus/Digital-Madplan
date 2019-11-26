#include "Ingredient.h"
#include <stdlib.h>
#include <string.h>


void createIngredient(char *name, int amount){
    Ingredient newIngredient;
    
    newIngredient.name = malloc(strlen(name));
}