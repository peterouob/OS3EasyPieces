#include "os.h"

int main(){
    int x = 100;
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        x = 200;
        fprintf(stdout, "Child: x = %d\n", x);
    }else{
        x = 300;
        fprintf(stdout, "Parent: x = %d\n", x);
        wait(NULL);
    }
}   