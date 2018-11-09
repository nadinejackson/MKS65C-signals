#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo)
{
  if (signo == SIGUSR1)
    {
      printf("My dad is %d.\n", getppid());
    }
  else if (signo == SIGINT)
    {
      printf("You SIGINTED you mean person\n");
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
