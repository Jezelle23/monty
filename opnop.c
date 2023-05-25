#include "monty.h"
/**
  *op_nop-nop opcode
  *@head: stack head
  *@counter: line_number
 */
void op_nop(stack_t** head, unsigned int counter)
{
	(void)counter;
	(void)head;
}
/**
  *op_sub- sustration
  *@head: stack head
  *@counter: line number
 */
void op_sub(stack_t **head, unsigned int counter)
{
	stack_t *varx;
	int varz, vary;

	varx = *head;
	for (vary = 0; varx != NULL; vary++)
		varx = varx->next;
	if (vary < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	varx = *head;
	varz = varx->next->n - varx->n;
	varx->next->n = varz;
	*head = varx->next;
	free(varx);
}
/**
 * op_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line number
*/
void op_swap(stack_t** head, unsigned int counter)
{
	stack_t* x;
	int y = 0, z;

	x = *head;
	while (x)
	{
		x = x->next;
		y++;
	}
	if (y < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	x = *head;
	z = x->n;
	x->n = x->next->n;
	x->next->n = z;
}
