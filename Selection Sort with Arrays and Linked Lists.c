#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress;

void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=1; i<n; i++) {t[i] = rand()%10;}
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n) {
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;

	
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}


void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

void printLinkedList(NodeAddress head) {
	NodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}



int findIndexOfMax(int *a, int n) {
	int imax;
	int i;


	if(n<1) {return -1;}

	imax = 0;
	for(i=1; i<n; i++) {
		if( a[i] > a[imax] ) {
			imax = i;
		}
	}

	return imax;
}

void selectionsort(int *a, int n) {
	int i, imax, t;

	for(i=n; i>1; i=i-1) {
		imax = findIndexOfMax(a, i);
		swap( &a[imax], &a[i-1] ); 
	}
}


int main(int argc, char **argv) {
	int * a;
	int n = 7;
	int maxindex;
	NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	selectionsort(a,n);
	printArray(a,n);


	free(a);
	freeLinkedList(list);

	return 0;
}
