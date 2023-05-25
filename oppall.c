#include "monty.h"
/**
 * op_pall - prints the stack
 * @head: stack head
 * @counter: num used
*/
void op_pall(stack_t **head, unsigned int counter)
{
	stack_t *var;
	(void)counter;

	var = *head;
	if (var == NULL)
		return;
	while (var)
	{
		printf("%d\n", var->n);
		var = var->next;
	}
}
/**
 * op_push - add node to the stack
 * @head: stack head
 * @counter: line_number
*/
void op_push(stack_t** head, unsigned int counter)
{
	int vara, varb = 0, varc = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			varb++;
		for (; bus.arg[varb] != '\0'; varb++)
		{
			if (bus.arg[varb] > 57 || bus.arg[varb] < 48)
				varc = 1;
		}
		if (varc == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			clear_dll(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	vara = atoi(bus.arg);
	if (bus.lifi == 0)
		addheadst(head, vara);
	else
		addtailst(head, vara);
}
