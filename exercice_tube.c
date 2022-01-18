#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void exec1();void exec2();void exec3();//declaration des fonctions

int pid;
int pipe1[2];
int pipe2[2];

void main() {

  /* creation de pipe1 */
  if (pipe(pipe1) == -1) {
    perror("bad pipe1");
    exit(1);
  }

  // fork (cat /etc/passwd)
  if ((pid = fork()) == -1) {
    perror("bad fork1");
    exit(1);
  } else if (pid == 0) {
    // stdin --> cat --> pipe1
    exec1();
  }
  // parent

  // creation de pipe2
  if (pipe(pipe2) == -1) {
    perror("bad pipe2");
    exit(1);
  }

  // fork (grep root)
  if ((pid = fork()) == -1) {
    perror("bad fork2");
    exit(1);
  } else if (pid == 0) {
    // pipe1 --> grep --> pipe2
    exec2();
  }


  close(pipe1[0]);
  close(pipe1[1]);

  if ((pid = fork()) == -1) {
    perror("bad fork3");
    exit(1);
  } else if (pid == 0) {

    exec3();
  }


}


void exec1() {
  
  dup2(pipe1[1], 1);
  // close fds
  close(pipe1[0]);
  close(pipe1[1]);
  // exec
  execlp("cat", "cat", "/etc/passwd", NULL);
  // si exec ne marche pas, exit
  perror("mauvais exec");
  _exit(1);
}

void exec2() {
  // entrer pipe1
  dup2(pipe1[0], 0);
  // sortit to pipe2
  dup2(pipe2[1], 1);
  // close fds
  close(pipe1[0]);
  close(pipe1[1]);
  close(pipe2[0]);
  close(pipe2[1]);
  // exec
  execlp("grep", "grep", "root", NULL);
  // si exec ne marche pas, exit
  perror("mauvais exec");
  _exit(1);
}

void exec3() {
  // entrer de pipe2
  dup2(pipe2[0], 0);
  // sortit de stdout
  // close fds
  close(pipe2[0]);
  close(pipe2[1]);
  // exec
  execlp("cut", "cut", "-d:", "-f1,3,4,7", NULL);
  // si exec ne marche pas, exit
  perror("mauvais exec");
  _exit(1);
}
