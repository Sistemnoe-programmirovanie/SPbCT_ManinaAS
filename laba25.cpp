/* 
  процесс 1 открывает файл и после этого порождает потомка 2, 
  который в свою очередь порождает потомка 3. 
  Процесс 2 пишет N байт в общий файл, посылает сигнал процессу 3, 
  который тоже пишет N байт в файл и посылает сигнал процессу 1, 
  который считывает данные из файла и выводит их на экран.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define fatal(msg) ({fprintf(stderr, "Fatal <%ld> %s: %m\n", (long)getpid(), (msg)); exit(-1);})

void
fhand (int sig)
{
  //  printf ("pid: %ld catch: %d\n", (long)getpid(), sig);
}

FILE *f;
sigset_t mask;

pid_t
proc3 (pid_t p1)
{
  pid_t p = fork();

  if (p)
    return p;
  // код процесса 3
  sigsuspend(&mask); // ждем команды продолжить работу

  fseek(f, 0, SEEK_END);
  fprintf (f, "Proc3 <%ld> started...\n", (long)getpid());
  fflush(f);
  kill(p1, SIGUSR1); // даем команду процессу 1 продолжить работу

  exit (0);
}

pid_t
proc2 ()
{
  pid_t p = fork(), p3;

  if (p)
    return p;
  // код процесса 2
  p3 = proc3(getppid());  // запускаем процесс 3, сообщим ему PID процесса 1

  fprintf (f, "Proc2 <%ld> started...\n", (long)getpid());
  fflush(f);
  kill(p3, SIGUSR1);  // даем команду процессу 3 продолжить работу

  exit (0);
}

int
main (int ac, char *av[])
{
  char *fname = av[1] ? av[1] : (char *)"3proc.dat";
  if (!(f = fopen(fname, "w+")))
    fatal(fname);

  sigset_t bmask;
  sigemptyset(&bmask);
  sigaddset(&bmask, SIGUSR1);
  sigprocmask(SIG_BLOCK, &bmask, &mask);
  signal(SIGUSR1, fhand);

  proc2(); // запускаем процесс 2
  sigsuspend(&mask);     // ждем команды продолжить от процесса 3

  rewind(f);
  int c;
  while ((c = fgetc(f)) != EOF)
    putchar(c);

  int st;
  printf ("Parent: <%ld> exits\n", (long)wait(&st));

  exit (WEXITSTATUS(st));
}

