#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

void push(int data, int * p, int n, int * top) {
	if (*top >= n) {
		printf("Stack overflow\n");
		system("PAUSE");
		exit(1);
	}
	else {
		p[(*top)++] = data;
	}
}

int pop(int data, int * p, int n, int * top) {
	if (*top <= 0) {
		printf("Empty stack\n");
		system("PAUSE");
		exit(1);
	}
	return(p[--(*top)]);
}

int main() {
	long long stack[100];
	int top = 0;
	return 0;
}
