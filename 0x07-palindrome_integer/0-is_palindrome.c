/**
 * is_palindrome - checks if a number is a palindrome
 * @n: number to check
 *
 * Return: 1 if true, 0 if false
 */

int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, temp;

	temp = n;

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	if (rev == temp)
		return (1);

	return (0);
}
