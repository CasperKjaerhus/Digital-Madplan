#include <stdlib.h>
#include <stdio.h>
int doesFileExist(char fileLocation[]); /*This function returns whether a file exist or not*/
int createFile(char fileLocation[]);    /*This function creates a file at fileLocation and returns a success or fail*/
FILE *openFile(char *fileLocation, char *mode); /*This function opens a file and returns it*/