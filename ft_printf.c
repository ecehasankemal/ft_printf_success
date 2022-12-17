/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:46:57 by hece              #+#    #+#             */
/*   Updated: 2022/12/17 16:46:58 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(long long data, int base, char *str, int p)
{
	int (count) = 0;
	if (str)
	{
		while (str[count])
			count++;
		return (count);
	}
	else
	{
		if (data <= 0)
			++count;
		while ((unsigned long long)data && p && ++count)
			data = (unsigned long long) data / base;
		while (data && ++count)
			data /= base;
		return (count);
	}
}

char	*ft_itoa_base(long long data, char *table, int p)
{
	int (len) = ft_numlen(data, ft_numlen(0, 0, table, 0), 0, p);
	char *(res) = malloc(sizeof(char) * (len + 1));
	int (tl) = ft_numlen(0, 0, table, 0);
	if (!res)
		return (0);
	res[len] = 0;
	if (data == 0)
		res[0] = '0';
	if (data < 0)
		res[0] = '-';
	while (data && p)
	{
		res[--len] = table[(unsigned long long)data % tl];
		data = (unsigned long long) data / tl;
	}
	while (data)
	{
		if (data > 0)
			res[--len] = table[data % tl];
		else
			res[--len] = table[data % tl * -1];
		data /= tl;
	}
	return (res);
}

int	ft_putstr(int c, char *str, int p)
{
	int (count) = 0;
	int (iter) = 0;
	if (str != NULL)
	{
		if (p == 1)
			count += ft_putstr(0, "0x", 0);
		if (str[iter] == '-' && p == 1)
			iter++;
		while (str[iter])
		{
			write(1, &str[iter], 1);
			count++;
			iter++;
		}
	}
	else
	{
		if (p)
			return (ft_putstr(0, "(null)", 0));
		write(1, &c, 1);
		count = 1;
	}
	return (count);
}

int	ft_type_control(char c, va_list arg, char *tmp)
{
	int (count) = 0;
	if (c == 'd' || c == 'i')
		count += ft_putstr(0, tmp = ft_itoa_base(va_arg(arg, int), DEC, 0), 0);
	else if (c == 'c')
		count += ft_putstr(va_arg(arg, int), 0, 0);
	else if (c == 'p')
		count += ft_putstr(0, tmp = ft_itoa_base(
					(long long)va_arg(arg, void *), HDEC, 1), 1);
	else if (c == 's')
		count += ft_putstr(0, va_arg(arg, char *), 2);
	else if (c == 'u')
		count += ft_putstr(0, tmp = ft_itoa_base(
					(va_arg(arg, unsigned int)), DEC, 0), 0);
	else if (c == 'x')
		count += ft_putstr(0, tmp = ft_itoa_base(
					(va_arg(arg, unsigned int)), HDEC, 0), 0);
	else if (c == 'X')
		count += ft_putstr(0, tmp = ft_itoa_base(
					(va_arg(arg, unsigned int)), _HDEC, 0), 0);
	else if (c == '%')
		count += ft_putstr('%', 0, 0);
	if (tmp != NULL)
		free(tmp);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list (arg);
	char *(tmp) = 0;
	int (index) = 0;
	int (jndex) = 0;
	va_start(arg, str);
	while (str[index] != '\0')
	{
		if (str[index + 1] == '\0' && str[index] == '%')
			write(1, &str[index + 1], 1);
		else if (str[index] == '%')
		{
			jndex += ft_type_control(str[index + 1], arg, tmp);
			index++;
		}
		else
			jndex += write(1, &str[index], 1);
		index++;
	}
	va_end(arg);
	return (jndex);
}
