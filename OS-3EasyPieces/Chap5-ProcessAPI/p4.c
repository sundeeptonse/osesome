#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

//With this process, we are redirecting the output from the Stdout file to the another file
//When a process runs the output goes to the STDOUT, by closing this and starting another open session.
int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { 
        // child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        // now exec "wc"...
        char *myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p4.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }
    else
    { // parent
        int wc = wait(NULL);
    }
    return 0;
}