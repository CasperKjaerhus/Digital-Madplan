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

FILE *openFile(char *fileLocation, char *mode){
    if(!doesFileExist(fileLocation)){
        printf("Error: File %s does not exist!!", fileLocation);
        return NULL;
    }
    FILE *file = fopen(fileLocation, mode);
    if(file == NULL){
        printf("Error: should really not happen! (FileHandler.c: OpenFile() returned NULL");
    }

    return file;
}

void *chkMalloc(size_t size, char *allo_name){
    void *allo = malloc(size);
    if(allo == NULL){
        printf("%s allokation returned NULL", allo_name);
    }
    return allo;
}
void *chkCalloc(size_t size, char *allo_name){
    void *allo = calloc(size, 1);
    if(allo == NULL){
        printf("%s allokation returned NULL", allo_name);
    }
    return allo;
}