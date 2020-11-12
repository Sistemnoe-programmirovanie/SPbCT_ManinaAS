// P5b.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
int main() {
	char z = *(const char*)0;
	printf("I read from location zeron");
	exit(EXIT_SUCCESS);
}