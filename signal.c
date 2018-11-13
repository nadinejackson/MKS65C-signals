#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static void sighandler(int signo)
{
  if (signo == SIGUSR1)
    {
      printf("My daddy is %d :P\n", getppid());
    }
  else if (signo == SIGINT)
    {
      printf("NOOOOOO I'M MELTIIIIIIIIING........ (see log.txt for the message)\n");
      int opener = open("./log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

      char message[64] = "\nThe process has exited due to SIGINT.\n";
      write(opener, message, sizeof(message));

      close(opener);
      exit(0);
    }
}
int main()
{
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  while(1)
    {
      printf("Hello, I'm %d\n", getpid());
      sleep(1);
    }
}
