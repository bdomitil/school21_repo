#include "../include/cub_header.h"

void print_cust_error(t_errors error)
{
	write(2, g_cust_errors[error], ft_strlen(g_cust_errors[error]));
	exit(error + 1);
}