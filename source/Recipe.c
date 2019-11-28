#include "Recipe.h"

Recipe *readRecipe(){
    FILE *file = openFile("files/recipes.txt", "r");
    char name[30];
    fscanf(file, "{\n name=\"%[^\"]\";", name);
    

    printf("name = %s\n", name);
    fclose(file);
    return NULL;
}