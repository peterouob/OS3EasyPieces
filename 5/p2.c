#include "os.h"

int main(){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        printf("hello, I am child of %d (pid:%d)\n",rc, (int) getpid());
    }else{
        int rc_wait = wait(NULL);
        // if have wailt here, the parent will wait for the child to finish and continue excute parent process
        // even the parent process run first, it will wait the child process to finish and return wait 
        printf("hello, I am parent of %d (rc_wait = %d) (pid:%d)\n", rc,rc_wait, (int) getpid());
    }
}