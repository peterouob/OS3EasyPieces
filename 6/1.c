#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <fcntl.h>
#include <sched.h>

#include <sys/time.h>
#include <sys/wait.h>

#define M 1000000
const int SIZE = 5;

int main(){
  
  struct timeval start,end;
  char *arg[3];
  arg[0] = strdup("wc");
  arg[1] = strdup("1.c");
  arg[2] = NULL;

  printf("start system call caclute");
  gettimeofday(&start,NULL);
  for(int i=0;i<100;i++){
    execv(arg[0],arg);
  }
  gettimeofday(&end,NULL);
  printf("sysyem call:%f microseconds\n\n",
		  (float)(end.tv_sec*M+end.tv_usec-
			  start.tv_sec*M+start.tv_usec)/100);
 


  struct timeval start_,end_;
  char buf[SIZE];
  cpu_set_t set;
  CPU_ZERO(&set);
  CPU_SET(sched_getcpu(),&set);
  if(sched_setaffinity(0,sizeof(cpu_set_t),&set)==-1){
  	fprintf(stderr,"sched_setaffinity\n");
  	exit(1);
  }
  
  int p1[2],p2[2];
  if(pipe(p1)<0||pipe(p2)<0){
  	fprintf(stderr,"pipe failed\n");
	exit(1);
  }

  
  int rc = fork();
  if(rc < 0){
  	fprintf(stderr,"process failed\n");
	exit(1);
  }else if(rc == 1){
	close(p1[1]);
	close(p2[0]);
	
	write(p2[1],"hello",SIZE);
	read(p1[0],buf,SIZE);
       
	close(p1[0]);
	close(p2[1]);
  }else{
	  // parent process execute first
	  // pipe one write first and pipe two read first
        printf("start context call caclute");
  
	gettimeofday(&start_,NULL);
  	close(p1[0]);
	close(p2[1]);
	write(p1[1],"hello",SIZE);
	read(p2[0],buf,SIZE);
	close(p1[1]);
	close(p2[0]);

  	gettimeofday(&end_,NULL);
  	printf("context call:%f microseconds\n\n",
		  (float)(end_.tv_sec*M+end_.tv_usec-
			  start_.tv_sec*M+start_.tv_usec));
  	}

   wait(NULL);
}
