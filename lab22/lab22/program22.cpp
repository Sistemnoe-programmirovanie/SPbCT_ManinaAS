#include <stdio. h>
#include <stdlib. h>
#include <unistd. h>
#include <errno.h>
#include <sys/types. h>
#include <sys / wait. h>

int main()
{

	int x, pid;
	x = 2;
	printf("одиночный процесс, x=%d\n", x);
	PID = вилка();
	если(pid = = 0)
		printf("New, x=%d\n", x); // Потомок
	иначе если(pid > > 0)
	{ // Родитель
		printf("Old, pid=%d, x=%d\n", pid, x);
		сон(5);
		x = wait(&pid);
	}
	остальное{
	perror("ошибка вилки ");
	возвращение - 1;
	}
	возврат 0;
}