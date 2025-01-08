#include "os.h"

int main(){
    int rc = fork();
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        close(STDOUT_FILENO);
        open("./p5.output",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p5.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }else{
        close(STDOUT_FILENO);
        open("./p5.output",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
    }
}