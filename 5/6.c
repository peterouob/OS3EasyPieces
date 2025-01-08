#include "os.h"

int main(){
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        printf("hello\n");
    }else{
        waitpid(rc,NULL,0);
        printf("goodbye\n");
    }
}

// https://blog.csdn.net/Roland_Sun/article/details/32084825