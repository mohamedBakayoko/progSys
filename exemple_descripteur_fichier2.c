#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main( int argc, char ** argv ){

int fd = open("tutu", O_WRONLY|O_CREAT);

dup2(fd,STDOUT_FILENO); // renvoie 1
close(fd); // ne sert plus a rien
printf("test de sortie standart dup 2\n"); // ecrit dans tutu
	

return 0;
}
