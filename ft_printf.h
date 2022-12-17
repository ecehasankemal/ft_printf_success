/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:47:05 by hece              #+#    #+#             */
/*   Updated: 2022/12/17 16:47:06 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

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
