#include "monty.h"
/**
 * op_stack - prints the top
 * @head: stack head
 * @counter: line number
*/
void op_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
/**
 * op_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void op_queue(stack_t** head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addtailst - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
*/
void addtailst(stack_t** head, int n)
{
	stack_t* node_x, * varx;

	varx = *head;
	node_x = malloc(sizeof(stack_t));
	if (node_x == NULL)
	{
		printf("Error\n");
	}
	node_x->n = n;
	node_x->next = NULL;
	if (varx)
	{
		while (varx->next)
			varx = varx->next;
	}
	if (!varx)
	{
		*head = node_x;
		node_x->prev = NULL;
	}
	else
	{
		varx->next = node_x;
		node_x->prev = varx;
	}
}
