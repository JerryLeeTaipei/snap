#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


extern char **environ;


int main (int argc, char *argv[])
{
    pid_t parent = getpid();
    pid_t pid = fork();

    if (pid == -1){
        perror("rc\n");// error, failed to fork()
    } else if (pid > 0) {// parent
        int status;
        waitpid(pid, &status, 0);
    }else {     // we are the child
        execlp("hello","hello",(char*)NULL);
        _exit(1);   // exec never returns
    }

    while (1){
        printf ("rc\n");
        sleep(15);
    }
  return 0;
}
