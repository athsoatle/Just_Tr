#include <iostream>

using namespace std;

struct node {
	struct node * pl;
	struct node * pr;
	int data;
};

void insert(int x, struct node ** pproot) {
	if (*pproot == NULL) {
		*pproot = (struct node*)calloc(1, sizeof(struct node));
		if (*pproot == NULL) {
			printf("No memory\n");
			system("PAUSE");
			exit(1);
		}
		else {
			(*pproot)->data = x;
			(*pproot)->pl = NULL;
			(*pproot)->pr = NULL;
		}
	}
	else {
		if ((*pproot)->data > x)	insert(x, &((*pproot)->pl));
		else	insert(x, &((*pproot)->pr));
	}
}

void inOrder(struct node *proot) {
	if (proot != NULL) {
		inOrder(proot->pl);
		printf("%i ", proot->data);
		inOrder(proot->pr);
	}
}

int main() {
	struct node * proot = NULL;
	insert(3, &proot);
	insert(1, &proot);
	insert(2, &proot);
	insert(12, &proot);
	insert(1, &proot);
	insert(4, &proot);
	insert(6, &proot);
	inOrder(proot);
	system("PAUSE");
	return 0;
}
