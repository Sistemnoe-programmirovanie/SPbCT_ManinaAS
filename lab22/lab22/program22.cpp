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
	printf("��������� �������, x=%d\n", x);
	PID = �����();
	����(pid = = 0)
		printf("New, x=%d\n", x); // �������
	����� ����(pid > > 0)
	{ // ��������
		printf("Old, pid=%d, x=%d\n", pid, x);
		���(5);
		x = wait(&pid);
	}
	���������{
	perror("������ ����� ");
	����������� - 1;
	}
	������� 0;
}