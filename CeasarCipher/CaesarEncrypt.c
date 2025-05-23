#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "\e[0;31m" "ERROR: " "\e[0m" "Incorrect amount of arguments, please run again with a filename in the command line");
        exit(EXIT_FAILURE);
    }
    FILE *message = fopen(argv[1], "r");
    if(message != NULL){   
        char ch;
        int shift;
        printf("Enter the number of times each letter should be shifted: ");
        scanf("%d", &shift);
        int max = 'z' - shift;

        while((ch = fgetc(message)) !=EOF){
            ch = tolower(ch);
            if(!isalpha(ch)){
            printf("%c", ch);
            }else if(ch > max){
                printf("%c", ch-(26-shift));
            } else {
                printf("%c", ch+shift);
            }
        }
        fclose(message);
        return 0;
    } else{
        fprintf(stderr, "\e[0;31m" "ERROR: " "\e[0m" "File is unreadable, please try again.");
        exit(EXIT_FAILURE);
    }
}