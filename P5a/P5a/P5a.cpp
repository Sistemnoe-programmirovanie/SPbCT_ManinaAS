// P5a.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
	char* some_memory = (char*)0;
	printf("A read from null %sn", some_memory);
	sprintf(some_memory, "A write to nulln");
	exit(EXIT_SUCCESS);
}
