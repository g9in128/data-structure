#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *getNode(int data)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

void push(Node **stack, int data)
{
	Node *node = getNode(data);
	if (*stack == NULL)
	{
		*stack = node;
	}
	else
	{
		node->next = *stack;
		*stack = node;
	}
}

int pop(Node **stack)
{
	int ret = (*stack)->data;
	Node *tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return ret;
}

int main()
{
	int arr[] = {32, 12, 4, 9, 111, -32, 12, 0};
	Node **stack = (Node **)malloc(sizeof(Node *));
	*stack = NULL;
	for (int i = 0; i < 8; i++)
	{
		push(stack, arr[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", pop(stack));
	}
	printf("\n");
	free(stack);
}