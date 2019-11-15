#include <stdio.h>

/*This function returns whether a file exist or not*/
int doesFileExist(char fileLocation[]){

    FILE *file = fopen(fileLocation, "r");
    if(file == NULL){
        return 0;
    }
    return 1;
}

