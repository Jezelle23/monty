#include "monty.h"
/**
 * op_pchar - prints the char at the top of the stack
 * @head: stack head
 * @counter: line_number
*/
void op_pchar(stack_t **head, unsigned int counter)
{
	stack_t *charv;

	charv = *head;
	if (!charv)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	if (charv->n > 127 || charv->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", charv->n);
}
/**
 * op_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line number
*/
void op_pstr(stack_t** head, unsigned int counter)
{
	stack_t* varx;
	(void)counter;

	varx = *head;
	while (varx)
	{
		if (varx->n > 127 || varx->n <= 0)
		{
			break;
		}
		printf("%c", varx->n);
		varx = varx->next;
	}
	printf("\n");
}
