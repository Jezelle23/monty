#include "monty.h"
/**
  *op_rotl- rotates the stack
  *@head: stack head
  *@counter: line number
 */
void op_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tempo = *head, *varx;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	varx = (*head)->next;
	varx->prev = NULL;
	while (tempo->next != NULL)
	{
		tempo = tempo->next;
	}
	tempo->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tempo;
	(*head) = varx;
}
/**
  *op_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line number
 */
void op_rotr(stack_t** head, __attribute__((unused)) unsigned int counter)
{
	stack_t* dupli;

	dupli = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (dupli->next)
	{
		dupli = dupli->next;
	}
	dupli->next = *head;
	dupli->prev->next = NULL;
	dupli->prev = NULL;
	(*head)->prev = dupli;
	(*head) = dupli;
}
