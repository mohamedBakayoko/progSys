#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(void){

	int fd; // Notre file descriptor
	
	if (-1 == (fd= open("alphabet.txt", O_WRONLY | O_CREAT, S_IRWXU))){
		
		perror("open() ");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}
