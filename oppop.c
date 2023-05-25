#include "monty.h"
/**
 * op_pop - prints the top
 * @head: stack head
 * @counter: line number
*/
void op_pop(stack_t** head, unsigned int counter)
{
	stack_t* popi;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	popi = *head;
	*head = popi->next;
	free(popi);
}
/**
 * op_pint - prints the top
 * @head: stack head
 * @counter: line number
*/
void op_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
