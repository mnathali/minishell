/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:23:32 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/15 11:42:00 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_quotestr(char *str, char del)
{
	int		i;
	char	*res;
	int		found;

	i = 1;
	found = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == del)
		{
			found = 1;
			break ;
		}
		i++;
	}
	if (found)
		res = ft_substr(str, 0, i + 1);
	return (res);
}

char	*get_space_str(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && !ft_isspace(str[i]) && str[i] != '\'' && str[i] != '\"'
		&& str[i] != '|' && str[i] != '>' && str[i] != '<')
		i++;
	res = ft_substr(str, 0, i);
	return (res);
}

char	*get_redirect_str(char *str, char del)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == del)
		i++;
	return (ft_substr(str, 0, i));
}

char	*get_new_arg(char *input)
{
	int		i;
	char	*new_arg;

	i = 0;
	if (input[i] == '\"' || input[i] == '\'')
	{
		new_arg = get_quotestr((input + i), input[i]);
		return (new_arg);
	}
	else if (input[i] == '|')
		return (ft_substr(input, i, 1));
	else if (input[i] == '>' || input[i] == '<')
		return (get_redirect_str(input + i, input[i]));
	else
		return (get_space_str(input + i));
}

t_list	*parse_args(char *input)
{
	t_list	*args;
	int		i;
	int		arg_len;

	i = 0;
	args = 0;
	while (input[i])
	{
		while (ft_isspace(input[i]) && input[i])
			i++;
		arg_len = add_arg(&args, get_new_arg(input + i));
		if (!arg_len)
			i += ft_strlen(input + i);
		i += arg_len;
	}
	ft_lstiter(args, &remove_backslash);
	return (args);
}

// void	remove_backslash(void *p)
// {
// 	char	*src;
// 	int		i;

// 	src = (char *)p;
// 	i = 0;
// 	while (src[i])
// 	{
// 		if (src[i] == '\\')
// 			ft_memmove(&src[i], &src[i + 1], ft_strlen(src) - i);
// 		i++;
// 	}
// }
