#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int nb_args, char * args []){

struct stat sts;
if (nb_args != 2) {
	fprintf (stderr, "syntaxe : %s <fichier>\n", args [0]);
	exit (1);
	}
if ( stat (args [1], & sts) != 0) {
	printf (" erreur \n");
	exit (1);
	}
fprintf (stdout,"Périphérique : %d\n",sts.st_dev);
fprintf (stdout,"Noeud : %ld\n",sts.st_ino);
fprintf (stdout,"Protection : %o\n",sts.st_mode);
fprintf (stdout,"nb liens matériels: %d\n",sts.st_nlink);
fprintf (stdout,"ID propriétaire : %d\n",sts.st_uid);
fprintf (stdout,"ID groupe: %d\n",sts . st_gid);
fprintf (stdout,"Taille : %lu octets\n",sts.st_size);
fprintf (stdout,"Taille de bloc : %lu\n",sts.st_blksize);
fprintf (stdout,"Nombre de blocs : %lu\n",sts.st_blocks);
}
