/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:29:23 by tnamir            #+#    #+#             */
/*   Updated: 2022/04/02 18:54:29 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_charjoin(char	*str, char c)
{
	char	*p;
	int		x;

	p = malloc(ft_strlen(str) + 2);
	x = -1;
	while (str[++x])
		p[x] = str[x];
	p[x++] = c;
	p[x] = 0;
	free(str);
	return (p);
}

// void	keep_handling(char *str, t_minishell *minish, char *buff, int *x)
// {
// 	*x += 1;
// 	while (str[*x] && str[*x] != '\"')
// 	{
// 		if (str[*x] == '$')
// 			buff = var_handler(buff, str, minish, x);
// 		else
// 		{
// 			buff = ft_charjoin(buff, str[*x]);
// 			*x += 1;
// 		}
// 	}
// 	*x += 1;
// }

char	*quotes_handler(char *str, t_minishell *minish)
{
	char	*buff;
	int		x;

	buff = ft_calloc(ft_strlen(str) + 1, 1);
	x = 0;
	while (str[x])
	{
		if (str[x] == '$')
			buff = var_handler(buff, str, minish, &x);
		else if (str[x] == '\'')
		{
			x++;
			while (str[x] && str[x] != '\'')
				buff = ft_charjoin(buff, str[x++]);
			x++;
		}
		else if (str[x] == '\"')
		{
			x += 1;
			while (str[x] && str[x] != '\"')
			{
				if (str[x] == '$')
					buff = var_handler(buff, str, minish, &x);
				else
				{
					buff = ft_charjoin(buff, str[x]);
					x += 1;
				}
			}
			x += 1;
		}
		else
			buff = ft_charjoin(buff, str[x++]);
	}
	return (buff);
}

char	**quotes_presence(char	*input, t_minishell	*minish)
{
	int		i;
	char	*str;

	i = -1;
	minish->options = cpy_it(input, minish->options);
	while (minish->options[++i])
	{
		str = minish->options[i];
		// printf("%s\n", str);
		minish->options[i] = quotes_handler(minish->options[i], minish);
		
		free(str);
	}
	return (minish->options);
}
