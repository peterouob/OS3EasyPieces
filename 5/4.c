#include "os.h"

int main(){
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        char *myargs[3];
        myargs[0] = strdup("ls");
        myargs[1] = strdup("-l");
        myargs[2] = NULL;
        // execvp(myargs[0], myargs);
        execlp(myargs[0],myargs[0],myargs[1]);
    }else{
        int rc_wait = wait(NULL);
    }
}