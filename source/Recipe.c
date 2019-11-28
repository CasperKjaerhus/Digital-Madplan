#include "Recipe.h"
#include "string.h"
#include "stdlib.h"

Recipe *get_recipe(char *ingredient, Recipe *recipelist, int amount){
    int i, strcompare, j = 0;
    Recipe *recipeOutput = malloc(sizeof(Recipe)*amount);

    for(i = 0; i > amount; i++){
        strcompare = strcmp(ingredient, recipelist[i].ingredients);
            if(strcompare = 1){
                recipeOutput[j] = recipelist[i];
                j++;
            }
    }

    return *recipeOutput;
}

Recipe *readRecipe(){
    FILE *file = openFile("files/recipes.txt", "r");
    char name[30];
    fscanf(file, "{\n name=\"%[^\"]\";", name);
    

    printf("name = %s\n", name);
    fclose(file);
    return NULL;
}

int Number_of_matches(Recipe recipe1, Recipe recipe2){

char str1[] = "recipe_1", str2[] = "recipe_2";

int same_ingredients;

same_ingredients = strcomp(recipe1.ingredients[], recipe2.ingredients[]);
printf("there are %d of the same ingredients\n", same_ingredients);

return same_ingredients;
}