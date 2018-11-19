#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define pass (void)0

#include <iostream>
#include <stack>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

struct node {
	int data;
	struct node * next;
};

void push(int data, struct node ** top) {
	struct node * temp;
	temp = (struct node*)calloc(1, sizeof(struct node));
	if (temp == NULL) {
		printf("Stack Overflow\n");
		system("PAUSE");
		exit(1);
	}
	temp->data = data;
	temp->next = *top;
	*top = temp;
}

int pop(struct node **top) {
	struct node *temp;
	int tmp;
	if (*top == NULL) {
		printf("Stack is Empty\n");
		system("PAUSE");
		exit(1);
	}
	tmp = (*top)->data;
	temp->next = *top;
	*top = temp->next;
	free(temp);
	return tmp;
}

int main(int argc, char**argv) {
	struct node * top = NULL;
	return 0;
}
