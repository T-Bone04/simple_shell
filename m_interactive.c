#include "shell.h"

/**
 * my_interact - results in true whenever shell is in interactive
 * mode.
 * @data: structure address.
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int my_interact(info_t *data)
{
	return (isatty(STDIN_FILENO) && data->readfd <= 2);
}

/**
 * is_delim - checks whether a given char is a delimeter.
 * @d: the character  to be  checked.
 * @delimtr: the delimeter string
 * Return: 1 when true, 0 when false.
 */
int delim_checker(char d, char *delimtr)
{
	for (int j = 0; delimtr[j] != '\0'; j++)
	{
		if (d == delimtr[j])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * alpha_checker - checks that a character given is an alphabet.
 * @d: the character to be checked
 * Return: 1 if d is within range, otherwise 0.
 */

int alpha_checker(int d)
{
	int j = 'a';

	while (i <= 'z')
	{
		if (d == j)
			return (1);
		j++;
	}

	j = 'A';

	while (j <= 'Z')
	{
		if (d == j)
			return (1);
		j++;
	}
		return (0);
}

/**
 * Strng_Converter - changes a string of char to an interger.
 * @strng: pointer to a char string to be converted to an int.
 * Return: 0 if the converted string doesnt have any numbers,
 * otherwise the converted interger.
 */

int Strng_Converter(char *strng)
{
	int j, sgn_n = 1, first = 0, result;
	unsigned int answer = 0;

	while (strng[j] != '\0' && first != 2)
	{
		if (strng[j] == '-')
			sgn_n *= -1;

			if (strng[j] >= '0' && strng[j] <= '9')
			{
				first = 1;
				answer *= 10;
				answer += (strng[j] - '0');
			}
			else if (first == 1)
				first = 2;

			j++;
	}

	if (sign == -1)
		result = -answer;
	else
		result = answer;
	
	return (result);
}
	
