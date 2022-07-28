#include "lists.h"

/**
 * is_palindrome - checks if a linked list is a palindrome
 *
 * @head: pointer to the head of the linked list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	if (!head || !*head)
		return (1);

	return (is_palindrome_helper(head, *head));
}

/**
 * is_palindrome_helper - checks if a linked list is a palindrome w/recursion
 *
 * @left: pointer that starts at head, but stops at mid
 * @right: pointer that starts at mid, but stops at end
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome_helper(listint_t **left, listint_t *right)
{
	if (!right)
		return (1);

	if (!is_palindrome_helper(left, right->next))
		return (0);

	if ((*left)->n != right->n)
		return (0);

	*left = (*left)->next;

	return (1);
}
