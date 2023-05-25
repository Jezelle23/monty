#include "monty.h"
/**
 * op_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line number
*/
void op_add(stack_t **head, unsigned int counter)
{
	stack_t *ferrari;
	int dist = 0, jag;

	ferrari = *head;
	while (ferrari)
	{
		ferrari = ferrari->next;
		dist++;
	}
	if (dist < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	ferrari = *head;
	jag = ferrari->n + ferrari->next->n;
	ferrari->next->n = jag;
	*head = ferrari->next;
	free(ferrari);
}
/**
 * addheadst - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addheadst(stack_t** head, int n)
{

	stack_t* update_node, * sec;

	sec = *head;
	update_node = malloc(sizeof(stack_t));
	if (update_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (sec)
		sec->prev = update_node;
	update_node->n = n;
	update_node->next = *head;
	update_node->prev = NULL;
	*head = update_node;
}
