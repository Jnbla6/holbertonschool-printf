#include "main.h"
#include <unistd.h>

/* here the functions for buffer system*/

#define BUF 1024 /* the BUF size*/
static char buffer[BUF]; /*array with BUF size*/
static int buf_index = 0; /*buf index to know how muc the memory is taken*/


/**
 * flush - writes the buffer content to stdout and cleans it
 */
void flush(void)
{
if (buf_index > 0) /*if index is upper than 0 write any thing and make it 0*/
{
write(1, buffer, buf_index);
buf_index = 0;
}
}

/**
 * buffer_char - adds a character to the buffer
 * @c: character to add
 * Return: number of characters added (1)
 */

int buffer_char(char c)
{
if (buf_index >= BUF)
flush();
buffer[buf_index++] = c;
return (1);
}

/**
 * _putchar - writes a character to stdout using buffer
 * @c: character to write
 * Return: number of characters written (1)
 */
int _putchar(char c)
{
    return (buffer_char(c));
}
