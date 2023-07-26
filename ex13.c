#include <stdio.h>

int main(int argc, char *argv[]){
    int i = 0;

    //go thru each string in argv
    //why skip argv[0]
    for(i = 1; i < argc ; i++){
        printf("arg %d: %s\n", i , argv[i]);
    }

    //lets make our own array of strings
    char *states[] ={
        "California", "Oregon",
        "Washington", "Texas"
    };//pointer to char array is array of strings

    int num_states = 4;

    for(i=0; i < num_states; i++){
        printf("state %d: %s\n", i, states[i]);
    }
    return 0;
}