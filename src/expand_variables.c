/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:04:10 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/15 13:35:35 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_next_var_name(char *string)
{
	static int		i;
	static char		*str;
	int				j;

	if (str != string)
	{
		str = string;
		i = 0;
	}
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			j = i;
			while (str[j] && !ft_isspace(str[j]) && str[j] != '\"')
				j++;
			if (!(j - i))
				return (NULL);
			return (ft_substr(str, i, j - i));
		}
		i++;
	}
	return (NULL);
}

char	*insert_value(char *src, int part1, int part2, char *insert)
{
	char	*strpart1;
	char	*strpart2;
	int		insertlen;
	char	*newstring;

	strpart1 = ft_substr(src, 0, part1);
	strpart2 = ft_substr(src, part2, ft_strlen(src));
	insertlen = ft_strlen(insert);
	newstring = malloc(insertlen + ft_strlen(src) + 1);
	if (!newstring)
		return (NULL);
	ft_memcpy(newstring, strpart1, part1);
	ft_memcpy(&newstring[part1], insert, insertlen);
	ft_memcpy(&newstring[part1 + insertlen], strpart2, ft_strlen(strpart2));
	newstring[ft_strlen(src) + insertlen - (part2 - part1)] = '\0';
	free(strpart1);
	free(strpart2);
	return (newstring);
}

void	insert_variable(t_list *arg, t_variable *var)
{
	static int			i;
	static char			*str;
	int					j;

	if (!arg || !var)
		return ;
	if (str != arg->content)
	{
		str = arg->content;
		i = 0;
	}
	while (str[i])
	{
		if (str[i] == '$')
		{
			j = i + ft_strlen(var->name) + 1;
			arg->content = insert_value(str, i, j, var->value);
			free(str);
			str = arg->content;
			i = j;
			return ;
		}
		i++;
	}
}

// void	expand_variable(t_list *arg, t_list *var_list)
// {
// 	char	*var_name;
// 	t_list	*current_var;

// 	var_name = get_next_var_name(arg->content);
// 	if (!var_name)
// 		return ;
// 	while (var_name)
// 	{
// 		current_var = var_list;
// 		while (current_var)
// 		{
// 			if (!ft_strcmp(((t_variable *)current_var->content)->name,
// 					var_name))
// 				insert_variable(arg, current_var);
// 			current_var = current_var->next;
// 		}	
// 		free(var_name);
// 		var_name = get_next_var_name(arg->content);
// 	}
// }

void	expand_variable(t_list *arg, t_list *var_list)
{
	char		*var_name;
	t_list		*current_var;
	t_variable	*tmp;

	var_name = get_next_var_name(arg->content);
	if (!var_name)
		return ;
	while (var_name)
	{
		current_var = get_variable_by_name(var_list, var_name);
		if (current_var)
			insert_variable(arg, current_var->content);
		else
		{
			tmp = new_var(var_name, NULL);
			insert_variable(arg, tmp);
			free(tmp);
		}
		free(var_name);
		var_name = get_next_var_name(arg->content);
	}
}

void	expand_variables(t_mini *shell)
{
	t_list	*current_program;
	t_list	*current_arg;

	current_program = shell->args;
	while (current_program)
	{
		current_arg = current_program->content;
		while (current_arg)
		{
			if (ft_strchr(current_arg->content, '$')
				&& ((char *)current_arg->content)[0] != '\'')
				expand_variable(current_arg, shell->var_list);
			current_arg = current_arg->next;
		}
		current_program = current_program->next;
	}
}
