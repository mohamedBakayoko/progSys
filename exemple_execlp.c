#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void){ 

char *cmd[] = {"who", "ls", "date", "pwd"};

	char c,int i;

	printf("0=who 1=ls 2=date 3=pwd : ");

	scanf("%d", &i);
	
	execlp( cmd[i], cmd[i], (char *) NULL );

	printf( "execlp failed \n" );
	
	return 0;
	
}
