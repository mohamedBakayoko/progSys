#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){ 

	char *cmd[] = {"who", "ls", "date", "pwd"};
	int i;
	char a[1];
	
	while( 1 ) {
		printf("0=who 1=ls 2=date 3=pwd 4=quitter: ");
		scanf("%s", a);
		sscanf(a, "%d", &i);
		if(i == 4) exit(0);
		if(i < 0 || i >4) printf("Saisir une valeur entre [0-4]");
		if(fork() == 0) {
		  /* child */
		  execlp( cmd[i], cmd[i], (char *) NULL );
		  printf( "execlp failed\n" );
		  exit(1);
		  }else {  
		  /* parent */
		  wait( (int *)0 );
		  printf( "child finished\n" );
		  }
	} 
} 
