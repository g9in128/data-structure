#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct Queue
{
	Node *head;
	Node *tail;
} Queue;

Node *getNode(int data)
{
	Node *n = (Node *)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

Queue *newQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->head = q->tail = NULL;
	return q;
}

void enqueue(Queue *queue, int data)
{
	if (queue == NULL)
		return;
	Node *n = getNode(data);
	if (queue->head == NULL || queue->tail == NULL)
	{
		queue->head = queue->tail = n;
		return;
	}
	queue->tail->next = n;
	queue->tail = n;
}

int dequeue(Queue *queue)
{
	if (queue == NULL || queue->head == NULL || queue->tail == NULL)
	{
		return -1;
	}
	if (queue->head == queue->tail)
	{
		int ret = queue->head->data;
		free(queue->head);
		queue->head = queue->tail = NULL;
		return ret;
	}
	Node *n = queue->head;
	queue->head = queue->head->next;
	int ret = n->data;
	free(n);
	return ret;
}

int main()
{
	Queue *q = newQueue();

	int arr[15] = {0}, i = 0;
	enqueue(q, 1);
	enqueue(q, 2);
	arr[i++] = dequeue(q);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	enqueue(q, 6);
	enqueue(q, 7);
	enqueue(q, 8);
	enqueue(q, 9);
	enqueue(q, 10);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);

	for (int j = 0; j < 10; j++)
	{
		printf("%d\n", arr[j]);
	}

	free(q);
}