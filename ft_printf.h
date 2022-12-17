#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define HDEC "0123456789abcdef"
# define _HDEC "0123456789ABCDEF"
# define DEC "0123456789"

int	ft_printf(const char *str, ...);

#endif
