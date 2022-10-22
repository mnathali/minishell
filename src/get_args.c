/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:43:12 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/15 18:58:52 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_char_in_str(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_arg_valid(t_list *arg)
{
	int		i;
	char	*str;

	str = arg->content;
	i = 0;
	if (str[i] == '>' || str[i] == '<')
	{
		if (count_char_in_str(str, str[i]) > 2)
			return (0);
	}
	return (1);
}

int	is_program_vaild(t_list *program)
{
	t_list	*arg;

	arg = program;
	while (arg)
	{
		if (arg == program && ft_strchr(program->content, '|'))
			return (0);
		if (!is_arg_valid(arg))
			return (0);
		arg = arg->next;
	}
	return (1);
}

t_list	*valid_args(t_list *args)
{
	t_list	*program;
	int		valid;

	program = args;
	valid = 1;
	while (program)
	{
		if (!is_program_vaild(program->content))
			valid = 0;
		program = program->next;
	}
	if (valid)
		return (args);
	ft_lstclear(&args, clear_content);
	return (0);
}

t_list	*get_args(t_list *input)
{
	t_list	*args;
	t_list	*current;
	t_list	*head;

	current = input;
	head = input;
	args = NULL;
	while (head && current->next)
	{
		if (ft_strchr(current->next->content, '|')
			&& ft_strlen(current->next->content) == 1)
		{
			ft_lstadd_back(&args, ft_lstnew(head));
			head = current->next->next;
			ft_lstdelone(current->next, free);
			current->next = NULL;
			current = head;
		}
		else
			current = current->next;
	}
	if (head)
		ft_lstadd_back(&args, ft_lstnew(head));
	return (valid_args(args));
}
