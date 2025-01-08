#include "os.h"

int main(){
    int rc = fork();
    printf("hello %d\n",getpid());
    if(rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if(rc == 0){
        printf("hello child %d\n",getpid());
        int child_wait = wait(NULL);
        printf("%d\n",child_wait);
    }else{
        int rc_wait = wait(NULL);
        printf("%d",rc_wait);
    }
}
// wait 會return child process的pid
// 在child 中的wait不會觸發,並且值為-1,猜測是因為child process已經結束了所以不會wait任何底下的process