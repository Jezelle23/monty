#include "monty.h"
/**
 * op_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
*/
void op_mul(stack_t** head, unsigned int counter)
{
	stack_t* pro;
	int mullen = 0, mulx;

	pro = *head;
	while (pro)
	{
		pro = pro->next;
		mullen++;
	}
	if (mullen < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	pro = *head;
	mulx = pro->next->n * pro->n;
	pro->next->n = mulx;
	*head = pro->next;
	free(pro);
}
/**
 * op_mod - calculates the rest of the division
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void op_mod(stack_t **head, unsigned int counter)
{
	stack_t *bmw;
	int flen = 0, car;

	bmw = *head;
	while (bmw)
	{
		bmw = bmw->next;
		flen++;
	}
	if (flen < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	bmw = *head;
	if (bmw->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	car = bmw->next->n % bmw->n;
	bmw->next->n = car;
	*head = bmw->next;
	free(bmw);
}
