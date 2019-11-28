#include "Recipe.h"
#include "string.h"
#include "stdlib.h"

int randomGen(int max){
    int random;

    if(max > 0){
        random = (rand() % max);
        return random;
    } else{
        return 0;
    }
}

Recipe get_recipe(Ingredient ingred, Recipe *recipelist, int amount){
    int i, strcompare, j = 0, randnum;
    Recipe *recipeArray = malloc(sizeof(Recipe)*amount);
    Recipe recipeOutput;
    Ingredient *ingred2 = malloc(sizeof(Ingredient)*amount);

    for(i = 0; i < amount; i++)
            ingred2[i] = *recipelist[i].ingredients;

    for(i = 0; i < amount; i++){
        strcompare = strcmp(ingred.name, ingred2[i].name);
            if(strcompare == 0){
                recipeArray[j] = recipelist[i];
                j++;
            }
    }

    randnum = randomGen(j);

    recipeOutput = recipeArray[randnum];

    free(ingred2);
    free(recipeArray);
    return recipeOutput;
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
