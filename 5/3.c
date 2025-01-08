#include "os.h"

int main(){
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        printf("hello\n");
    }else{
        exit(1);
    }

    rc = fork();
    if (rc > 0){
        printf("goodbye\n");
        exit(1);
    }
    
}