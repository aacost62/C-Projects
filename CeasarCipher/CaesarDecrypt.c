#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "\e[0;31m" "ERROR: " "\e[0m" "Incorrect amount of arguments, please run again with a filename in the command line");
        exit(EXIT_FAILURE);
    }
    FILE *cypher = fopen(argv[1], "r");
    if (cypher != NULL){
        int shift;
        char ch;
        int minCh;
        printf("How many times was each letter shifted: ");
        scanf("%d", &shift);
        minCh = 'a' + shift;
        while((ch = fgetc(cypher)) != EOF){
            ch = tolower(ch);
            if (!isalpha(ch)){
                printf("%c", ch);
            } else if(ch < minCh){
                printf("%c", ch+(26-shift));
            } else{
                printf("%c", ch-shift);
            }
        }
        fclose(cypher);
        exit(EXIT_SUCCESS);
    } else{
        fprintf(stderr, "\e[0;31m" "ERROR: " "\e[0m" "File is unreadable, please try again.");
        exit(EXIT_FAILURE);
    }
}