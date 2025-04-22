#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int *arr;
	size_t size, top;
} Stack;

int peek(Stack *stk);
int pop(Stack *stk);

Stack *new_stack()
{
	Stack *stk = (Stack *)malloc(sizeof(Stack));
	stk->size = 1;
	stk->top = 0;
	int *arr = (int *)malloc(sizeof(int) * stk->size);
	stk->arr = arr;
	return stk;
}

void resize(Stack *stk)
{
	int *tmp = stk->arr;
	stk->arr = malloc(sizeof(int) * (stk->top * 2 + 1));
	memcpy(stk->arr, tmp, sizeof(int) * stk->top);
	free(tmp);

	stk->size = stk->top * 2 + 1;
}

void push(Stack *stk, int data)
{
	if (stk->top >= stk->size)
		resize(stk);
	stk->arr[stk->top++] = data;
}

int peek(Stack *stk)
{
	return stk->arr[stk->top - 1];
}

int pop(Stack *stk)
{
	if (stk->top > stk->size || stk->top == 0)
	{
		return 0;
	}
	int ret = stk->arr[--stk->top];
	stk->arr[stk->top] = 0;
	if (stk->top <= stk->size / 4)
		resize(stk);
	return ret;
}

int main()
{
	Stack *stk = new_stack();

	push(stk, 1);
	push(stk, 2);
	push(stk, 3);
	push(stk, 4);
	push(stk, 5);
	push(stk, 6);
	push(stk, 7);
	push(stk, 8);
	push(stk, 9);
	push(stk, 10);
	push(stk, 11);

	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d ", pop(stk));
	printf("%d\n", pop(stk));

	free(stk->arr);
	free(stk);
}