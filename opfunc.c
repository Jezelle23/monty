#include "monty.h"
/**
* startopcode - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: 1
*/
int startopcode(char* content, stack_t** stack, unsigned int counter, FILE* file)
{
	instruction_t opst[] = {
				{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
				{"pop", op_pop},
				{"swap", op_swap},
				{"add", op_add},
				{"nop", op_nop},
				{"sub", op_sub},
				{"div", op_div},
				{"mul", op_mul},
				{"mod", op_mod},
				{"pchar", op_pchar},
				{"pstr", op_pstr},
				{"rotl", op_rotl},
				{"rotr", op_rotr},
				{"queue", op_queue},
				{"stack", op_stack},
				{NULL, NULL}
	};
	unsigned int x = 0;
	char* operat;

	operat = strtok(content, " \n\t");
	if (operat && operat[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[x].opcode && operat)
	{
		if (strcmp(operat, opst[x].opcode) == 0)
		{
			opst[x].f(stack, counter);
			return (0);
		}
		x++;
	}
	if (operat && opst[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, operat);
		fclose(file);
		free(content);
		clear_dll(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**
* clear_dll - frees a doubly linked list
* @head: head of the stack
*/
void clear_dll(stack_t *head)
{
	stack_t *freevar;

	freevar = head;
	while (head)
	{
		freevar = head->next;
		free(head);
		head = freevar;
	}
}
/**
 * op_div - divides the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: Null
*/
void op_div(stack_t** head, unsigned int counter)
{
	stack_t* x;
	int varlen = 0, xyz;

	x = *head;
	while (x)
	{
		x = x->next;
		varlen++;
	}
	if (varlen < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	x = *head;
	if (x->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		clear_dll(*head);
		exit(EXIT_FAILURE);
	}
	xyz = x->next->n / x->n;
	x->next->n = xyz;
	*head = x->next;
	free(x);
}
