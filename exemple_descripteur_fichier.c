#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main( int argc, char ** argv ){

int fd = open("tutu", O_WRONLY|O_CREAT);
close(STDOUT_FILENO);

dup(fd); // renvoie 1
close(fd); // ne sert plus a rien
printf("test de sortie standart\n"); // ecrit dans tutu
	

return 0;
}
