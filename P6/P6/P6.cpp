// P6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)
int main() {
	char* some_memory;
	int exit_code = EXIT_FAILURE;
	some_memory = (char*)malloc(ONE_K);
	if (some_memory != NULL) {
		free(some_memory);
		printf("Memory allocated and freed againn");
		
			exit_code = EXIT_SUCCESS;
	}
	exit(exit_code);
}
