#include <stdio.h>
#include "FileHandler.h"

/*This function returns whether a file exist or not*/
int doesFileExist(char fileLocation[]){

    FILE *file = fopen(fileLocation, "r");
    if(file == NULL){
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}
/*This function creates a file at fileLocation and returns a success or fail*/
int createFile(char fileLocation[]){
    if(doesFileExist(fileLocation) == 0){
        FILE *file = fopen(fileLocation, "w");
        fclose(file);
        return 1;
    }
    printf("WARNING: \"%s\" already exists!\n", fileLocation);
    return 0;
}