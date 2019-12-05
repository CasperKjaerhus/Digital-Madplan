#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*prototype */
void createIngredient(char *name, int amount);

int fuckdignima(void){    
    char str[500];
    //Ingredient ingredient_name[255];

    int i;

    FILE *recipe = fopen("ingredients.txt", "r");

    if(recipe == NULL){
        printf("Could not open file %s", "ingredients.txt"); 
        return 1;
    }    

    while (fgets(str, 500, recipe) != NULL){
        printf("Read from file: %s\n", str);
    }

    for(i = 0; i <= 255; i++){
        // fscanf(recipe, "{\nname=\"%[^\"]\"\n kategori= %d \n}", ingredient_name[i].name);
        // printf("%s %d", ingredient_name[i].name, cType);
    }
    fclose(recipe);

return 0;
}
/*
void createIngredient(char *name, int amount){
    Ingredient newIngredient;
    int i, strcompare;
    newIngredient.name = malloc(strlen(name));
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
    return *tempIngArr;
}
*/