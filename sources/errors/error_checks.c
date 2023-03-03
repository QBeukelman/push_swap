/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/02 11:49:57 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2023/03/02 13:29:01 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ===== Valid Char =====
bool	ft_check_valid_char(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_char(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_valid_char(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

// ===== Duplicate =====
bool	ft_is_duplicate(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	while (i < argc)
	{
		j = 2;
		while (j < i)
		{
			len = ft_len_longest(argv[i], argv[j]);
			if (ft_strncmp(argv[i], argv[j], len) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_len_longest(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (len1);
	else
		return (len2);
}

// ===== Check overflow =====
bool	ft_int_overflow(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strtol(argv[i]) > INT_MAX || ft_strtol(argv[i]) < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}
