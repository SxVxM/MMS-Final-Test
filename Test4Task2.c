//Test 4 Task 2 by Stefan Markovski
//I made the code work with 1 file and with 10 numbers
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
    int sum=0;
    FILE *myFile;
    myFile = fopen(argv[1], "r");
    int numberArray[10];
    int i;
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    for (i = 0; i < 10; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }
    for (i = 0; i < 10; i++){
        sum=sum+(numberArray[i]);
    }
    fclose(myFile);
    printf("Sum is: %d\n\n", sum);
    return 0;
}