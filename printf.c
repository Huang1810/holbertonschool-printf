#include "main.h"
#include <unistd.h>
/**
 * _printf - Emulate the original.
 *
 * @format: Format by specifier.
 *
 * Return: count of chars.
 */
int get_function(char con_spec, va_list args)
{
int count_fun = 0;
specifiers_t spec[] = {
{'c', print_char},
{'s', print_string},
{'%', print_mod},
{'d', print_digit},
{'i', print_digit},
{'r', print_rev_string},
{0, NULL}};
for (int i = 0; spec[i].specifiers; i++)
{
if (con_spec == spec[i].specifiers)
{
count_fun += spec[i].f(args);
break;
}
}
if (count_fun == 0)
{
count_fun += _putchar('%');
count_fun += _putchar(con_spec);
}
return (count_fun);
}
