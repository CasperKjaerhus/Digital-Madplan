#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000
enum category{meat, vegetables, fruit, carbohydrates, spices};

typedef struct Ingredient{
    char *name;
    int  amount;
    enum cType;
    char *unit;
}Ingredient;

/*prototype */
void createIngredient(char *name, int amount);

int main(void){    
    char str[MAXCHAR];
    Ingredient ingredient_name[255];

    int i;

    FILE *recipe = fopen("ingredients.txt", "r");

    if(recipe == NULL){
        printf("Could not open file %s", recipe);
        return 1;
    }    

    while (fgets(str, MAXCHAR, recipe) != NULL){
        printf("Read from file: %s\n", str);
    }

    for(i = 0; i <= 255; i++){
        fscanf(recipe, "{\nname=\"%[^\"]\"\n kategori= %d \n}", ingredient_name[i].name, &cType);
                printf("%s %d", ingredient_name[i].name, cType);
    }
    fclose(recipe);

return 0;
}


typedef struct Ingredient{
    char *name;
    int  amount;
    enum cType;
    char *unit;
}Ingredient;

/*prototype */
void createIngredient(char *name, int amount);

int main(void){    
    char str[MAXCHAR];
    Ingredient ingredient_name[255];

    int i;

    FILE *recipe = fopen("ingredients.txt", "r");

    if(recipe == NULL){
        printf("Could not open file %s", recipe);
        return 1;
    }    

    while (fgets(str, MAXCHAR, recipe) != NULL){
        printf("Read from file: %s\n", str);
    }

    for(i = 0; i <= 255; i++){
        fscanf(recipe, "{\nname=\"%[^\"]\"\n kategori= %d \n}", ingredient_name[i].name, &cType);
                printf("%s %d", ingredient_name[i].name, cType);
    }
    fclose(recipe);

return 0;
}

typedef struct Ingredient{
    char *name;
    int  amount;
    enum cType;
    char *unit;
}Ingredient;

/*prototype */
void createIngredient(char *name, int amount);

int main(void){    
    char str[MAXCHAR];
    Ingredient ingredient_name[255];

    int i;

    FILE *recipe = fopen("ingredients.txt", "r");

    if(recipe == NULL){
        printf("Could not open file %s", recipe);
        return 1;
    }    

    while (fgets(str, MAXCHAR, recipe) != NULL){
        printf("Read from file: %s\n", str);
    }

    for(i = 0; i <= 255; i++){
        fscanf(recipe, "{\nname=\"%[^\"]\"\n kategori= %d \n}", ingredient_name[i].name, &cType);
                printf("%s %d", ingredient_name[i].name, cType);
    }
    fclose(recipe);

return 0;
}

typedef struct Ingredient{
    char *name;
    int  amount;
    enum cType;
    char *unit;
}Ingredient;

/*prototype */
void createIngredient(char *name, int amount);

int main(void){    
    char str[MAXCHAR];
    Ingredient ingredient_name[255];

    int i;

    FILE *recipe = fopen("ingredients.txt", "r");

    if(recipe == NULL){
        printf("Could not open file %s", recipe);
        return 1;
    }    

    while (fgets(str, MAXCHAR, recipe) != NULL){
        printf("Read from file: %s\n", str);
    }

    for(i = 0; i <= 255; i++){
        fscanf(recipe, "{\nname=\"%[^\"]\"\n kategori= %d \n}", ingredient_name[i].name, &cType);
                printf("%s %d", ingredient_name[i].name, cType);
    }
    fclose(recipe);

return 0;
}



/*Function that searches for a ingredient char and finds the corresponding ingrendient struct*/
Ingredient get_ing_struct(Ingredient *ingArray, int arrSize, char *ingredient_name){
    int i, strcompare;
    Ingredient *tempIngArr = malloc(sizeof(Ingredient)*arrSize), ingredientOutput;

    for(i = 0; i < arrSize; i++){

    for(i = 0; i > arrSize; i++){
        tempIngArr[i] = ingArray[i];
    }

    for(i = 0; i < arrSize; i++){
        strcompare = strcmp(tempIngArr[i].name, ingredient_name);
            if(strcompare == 0){
                ingredientOutput = tempIngArr[i];
                free(tempIngArr);
                return ingredientOutput;
            }
    }

}
    return *tempIngArr;
}

void createIngredient(char *name, int amount){
    Ingredient newIngredient;
    
    newIngredient.name = malloc(strlen(name));
}
