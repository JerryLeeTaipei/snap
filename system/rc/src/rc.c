#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>

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
    setlogmask (LOG_UPTO (LOG_NOTICE));

    openlog ("rc", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    syslog (LOG_NOTICE, "Program started by User %d", getuid ());

    while (1){
        syslog (LOG_NOTICE, "running");
        sleep(15);
    }
closelog ();
  return 0;
}
