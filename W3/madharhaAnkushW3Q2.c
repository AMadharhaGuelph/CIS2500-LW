#include <stdio.h> 
#include <stdlib.h> 
 
void lastChars (char * filename, int howMany); 
void firstChars (char * filename, int howMany); 
 
/* Main takes 2 command-line arguments – a string that stores a filename, and an int that stores 
an integer – these are the two arguments that you then use when calling functions firstChars and 
lastChars as shown  in the main below. Note that function atoi converts a string to an integer.  
*/ 

int main (int argc, char * argv[]) {      
 
   firstChars (argv[1], atoi(argv[2]));   
       
   printf ("\n"); 
 
   lastChars (argv[1], atoi(argv[2])); 
 
   return 0; 
}

void firstChars(char* filename, int howMany) {
    FILE *fp;

    char buffer[2000];

    fp = fopen(filename, "rb");

    fread(buffer, sizeof(char), howMany, fp);

    for(int i = 0; i < howMany; i++) {
        printf("%c ", buffer[i]);
    }
}

void lastChars(char* filename, int howMany) {
    FILE* fp;
    char buffer[1000];

    fp = fopen(filename, "r");

    fseek(fp, -howMany, SEEK_END);

    fread(buffer, sizeof(char), howMany, fp);

    for(int i = 0; i < howMany; i++) {
        print("%c ", buffer[i]);
    }
}