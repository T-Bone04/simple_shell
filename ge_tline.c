#include "shell.h"

/**
 *assign_line - assigns the line's variable
 *for _getline.
 *@buff_str: its a buffer that stores input
 *@buff: str used by assign_line.
 *@n: line's size.
 *@i: buffer's size.
 */
void assign_line(char **buff_str, size_t *n, char *buff, size_t i)
{
	if (*buff_str == NULL)/*checks if buff_str pointer is NULL*/
	{
		if (i > BUFSIZE)/*assigns buffer to buff_str if i is greater than BUFSIZE*/
			*n = i;

		else/*if not, assign it to n*/
			*n = BUFSIZE;
		*buff_str = buff;
	}
	else if (*n < i)/*checks if n is less than i*/
	{
		if (i > BUFSIZE)
			*n = i;
		else/*if not, assign buffer to i*/
			*n = BUFSIZE;
		*buff_str = buff;
	}
	else
	{
		_strcpy(*buff_str, buff);/*buffer's contents is copied to buff_str*/
		free(buff);/*buffer is freed*/
	}
}

/**
 *_getline: gets the next line to read
 *from STDIN.
 *@buff_str: a buffer that stores input.
 *@n: size of buffer
 *@stream: STDIN
 *Return: bytes.
 */
ssize_t _getline(char **buff_str, size_t *n, FILE *stream)
{
	/*declaration of variable*/
	int j;
	static ssize_t info;
	ssize_t r;
	char *buff;
	char s = 'z';

	if (info == 0)/*is the input(info) equal to zero?*/
		fflush(stream);
	else
		return (-1);/*if not return -1*/
	info = 0;

	buff = malloc(sizeof(char) * BUFSIZE);/*memory is allocated to the buffer*/
	if (buff == 0)
		return (-1);
	while (s != '\n')/*input must be read until a newline is reached*/
	{
		j = read(STDIN_FILENO, &S, 1);/*Reads a char from STDIN_FILENO*/
		if (j == -1 || (j == 0 && info == 0))/*is there an error while reading?*/
		{
			free(buff);
			return (-1);
		}
		if (info >= BUFSIZE)/*is the buffer full?*/
			buff = _realloc(buff, info, info + 1);
		buff[info] = s;/*char is stored in buffer*/
		info++;
	}
	buff[info] = '\0';
	assign_line(buff_str, n, buff, info);/*assign_line assigns bufferto buff_str*/
	r = info;
	if (j != 0)
		info = 0;
	return (r);
}
