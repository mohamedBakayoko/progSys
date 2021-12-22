#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main (void){
int i;
pid_t pid_fils;
do {
pid_fils = fork();
} while ((pid_fils == -1) && (errno == EAGAIN));
if (pid_fils == -1){
fprintf(stderr, "fork() impossible, errno=%d\n", errno);
return 1;
}
if (pid_fils == 0) {
/* processus fils */
    for( i=0; i < 1000; i++ )
        printf("\t\t\tFils %d\n", i);
fprintf(stdout, "Fils : PID=%ld, PPID=%ld\n",(long)getpid(), (long)getppid());
return 0;
} 
else {
/* parent */
        for( i=0; i < 1000; i++ )
        printf("\t\t\tPARENT %d\n", i);
fprintf(stdout, "Pere : PID=%ld, PPID=%ld, PID fils=%ld\n",(long)getpid(), (long)getppid(), (long)pid_fils);
return 0;
}
}
