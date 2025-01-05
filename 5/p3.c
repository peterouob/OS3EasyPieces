#include "os.h"

int main(int argc,char *argv[]){
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        printf("hello, I am child of %d (pid:%d)\n",rc, (int) getpid());
        char *myargs[3];
        // execvp is  guaranteed not to modify those strings so if not use strdup is ok
        // https://stackoverflow.com/questions/69505245/why-is-strdup-used-here
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p3.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldn't print out");
    }else{
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait = %d) (pid:%d)\n", rc,rc_wait, (int) getpid());
    }
}