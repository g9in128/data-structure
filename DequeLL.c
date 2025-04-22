#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *prev, *next;
} Node;

typedef struct Deque
{
	Node *head, *tail;
} Deque;

Node *getNode(int data)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->next = n->prev = NULL;
	return n;
}

Deque *newDeque()
{
	Deque *d = (Deque *)malloc(sizeof(Deque));
	d->head = d->tail = NULL;
	return d;
}

void addFirst(Deque *deque, int data)
{
	if (deque == NULL)
		return;
	Node *n = getNode(data);
	if (deque->head == NULL || deque->tail == NULL)
	{
		deque->head = deque->tail = n;
		return;
	}
	deque->head->prev = n;
	n->next = deque->head;
	deque->head = n;
}

int removeFirst(Deque *deque)
{
	if (deque == NULL || deque->head == NULL || deque->tail == NULL)
	{
		return -1;
	}
	if (deque->head == deque->tail)
	{
		int ret = deque->head->data;
		free(deque->head);
		deque->head = deque->tail = NULL;
		return ret;
	}
	Node *n = deque->head;
	int ret = n->data;
	deque->head = n->next;
	deque->head->prev = NULL;
	free(n);
	return ret;
}

void addLast(Deque *deque, int data)
{
	if (deque == NULL)
		return;
	Node *n = getNode(data);
	if (deque->head == NULL || deque->tail == NULL)
	{
		deque->head = deque->tail = n;
		return;
	}
	deque->tail->next = n;
	n->prev = deque->tail;
	deque->tail = n;
}

int removeLast(Deque *deque)
{
	if (deque == NULL || deque->head == NULL || deque->tail == NULL)
	{
		return -1;
	}
	if (deque->head == deque->tail)
	{
		int ret = deque->head->data;
		free(deque->head);
		deque->head = deque->tail = NULL;
		return ret;
	}
	Node *n = deque->tail;
	int ret = n->data;
	deque->tail = n->prev;
	deque->tail->next = NULL;
	free(n);
	return ret;
}

int main()
{
	Deque *d = newDeque();

	int arr[10] = {0}, i = 0;

	addFirst(d, 1);
	addFirst(d, 2);
	addFirst(d, 3);
	addFirst(d, 4);
	addLast(d, 5);
	addLast(d, 6);
	addLast(d, 7);
	addLast(d, 8);
	addLast(d, 9);
	addLast(d, 10);

	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}