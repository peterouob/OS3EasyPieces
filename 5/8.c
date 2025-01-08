#include "os.h"

int main(){
    int p[2];
    int msg_size = 5;
    if(pipe(p) < 0){
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }
    char buf[msg_size];
    write(p[1],"hello",msg_size);

    read(p[0],buf,msg_size);
    printf("%s\n",buf);

    close(p[0]);
    close(p[1]);
}