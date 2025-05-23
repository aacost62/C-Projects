#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char CODE[100];
    int DATA[100];
    FILE *fileptr;
    int cindex = 0;
    int dindex = 0;
    char c;
    char in;

    fileptr = fopen(argv[1], "r");
    printf("Arturo Acosta Andrade, BrainF*uck Interpter\n\n");
    if(argc < 2){
        printf("usage: brainfuck filename.\n");
        return 0;
    }
    if(fileptr == NULL){
        printf("File %s could not be opened\n", argv[1]);
        return 0;
    }

    while(!feof(fileptr)){
        CODE[cindex] = fgetc(fileptr);
        cindex++;
    }
    
    for (int i = 0; i < cindex-1; i++){
        c = CODE[i];
        switch(c){
            //Set the value of the current data element to an integer value supplied by the user. Prompt
            //the user with a ‘?’.
            case ';':
                printf("? ");
                scanf("%d", &DATA[dindex]);
                break;

            //Print the current data element.       
            case ':':
                printf("%d ", DATA[dindex]);
                break;

            //Move the Data Pointer to the previous data element. Print an error and stop execution if
            //the Data Pointer goes negative.
            case '<':
                dindex--;
                if(dindex < 0){
                    printf("Error: Data Pointer Is Negative.\n");
                    return -1;
                }
                break;

            //Move the data pointer to the next data element. There is no largest element.
            case '>':
                dindex++;
                break;

            /*If the integer at the current data pointer is zero, move the Code Pointer to the right of
            the matching ]. Otherwise, do nothing. Print an error and stop execution if there is no
            matching brace.*/
            case '[':
                if(DATA[dindex] == 0){
                    int s = i+1;
                    while (s < cindex-1 && CODE[s] != ']'){
                        s++;
                    }

                    if(CODE[s] != ']'){
                        printf("Error: No Matching ']' Brace Found.\n");
                        return -1;
                    }
                    i = s+1;
                }
                printf("");
                break;

            //Move the Code Pointer left to the matching [. Print an error and stop execution if there
            //is no matching brace.
            case ']':
                int b = i;
                while ( (b > -1) && (CODE[b] != '[')){
                    b--;
                }
                if (CODE[b] != '['){
                    printf("Error: No Matching '[' Brace Found.\n");
                    return -1;
                }
                if(DATA[dindex] > 0){
                    i =b;
                }
                break;
                
            //Increment the current data element.
            case '+':
                DATA[dindex]+=1;
                break;

            //Decrement the current data element. Data elements can go negative.
            //Spaces, tabs and newlines are ignored.
            case '-':
                DATA[dindex]-=1;
                break;

            //Unknwon command
            default:
                //printf("\nUnrecognized character: %c\n", CODE[i]);
                break;
        }
    }


    return 0;
}