#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<time.h>

int main (int argc, char * argv[]){

int st;
struct stat infos;
char * date;
st= stat(argv[1], &infos);

if (st< 0) return (-1);
/* affichage des informations. */
if  (S_ISLNK (infos.st_mode))
	printf(" lien symbolique\n");
else if (S_ISREG (infos.st_mode))
	printf(" fichier régulier.");
else if (S_ISDIR (infos.st_mode))
	printf(" répertoire.");
else if (S_ISCHR (infos.st_mode))
	printf(" péripherique caractère.");
else if (S_ISBLK (infos.st_mode))
	printf(" périphérique blocs.");
else if (S_ISFIFO(infos.st_mode))
	printf("e FIFO.");
else if (S_ISSOCK(infos.st_mode))
	printf("e Socket\n");
printf ("liens = %d\n", (int)infos.st_nlink);
printf ("UID   = %d\n", (int)infos.st_uid);
printf ("GID   = %d\n", (int)infos.st_gid);
printf ("Taille= %d\n", (int)infos.st_size);
printf ("Accès = %s\n", (char *)ctime (& infos.st_atime));
printf ("Modif = %s\n", (char *)ctime (& infos.st_mtime));
printf ("Changé= %s\n", (char *)ctime (& infos.st_ctime));

return (0);
}
