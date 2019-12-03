#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"
#include "Recipe.h"
#include <time.h>

int main(void){
    srand(time(NULL));
    
    readRecipes();
    return 0;
}