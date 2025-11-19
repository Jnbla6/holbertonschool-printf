#include "main.h"

#define BUF 1024
static char buffer[BUF];
static int buf_index = 0;
static int total_count = 0;



void fulsh(void)
{
if (buf_index > 0)
total_count += write(1, buffer, buf_index);
buf_index = 0;
}

int buffer_char(char c)
{
if (buf_index >= BUF)
flush();
buffer[buf_index] = c;
buf_index++;
return (1);
}

int _putchar(char c)
{
    return (buffer_char(c));
}