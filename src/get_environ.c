/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:36:44 by zyasuo            #+#    #+#             */
/*   Updated: 2022/05/14 00:38:32 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_variable	*new_var(char *name, char *value)
{
	t_variable	*var;

	var = malloc(sizeof(*var));
	if (!var)
		return (NULL);
	var->name = name;
	var->value = value;
	return (var);
}

char	**read_variable(char *str)
{
	int		i;
	char	**var_array;

	var_array = malloc(2 * sizeof(*var_array));
	if (!var_array)
		return (NULL);
	i = 0;
	while (str[i] != '=')
		i++;
	var_array[0] = ft_substr(str, 0, i);
	var_array[1] = ft_substr(str, i + 1, ft_strlen(str));
	return (var_array);
}

void	destroy_var(void *p)
{
	t_variable	*var;

	var = (t_variable *)p;
	free(var->name);
	free(var->value);
	free(var);
}

void	print_variable(void *pointer)
{
	t_variable	*var;

	var = (t_variable *) pointer;
	ft_printf("name: %s, value: %s\n", var->name, var->value);
}

t_list	*get_environ(char **envp)
{
	int			i;
	char		**var_array;
	t_list		*environ;

	i = 0;
	environ = NULL;
	while (envp[i])
	{
		var_array = read_variable(envp[i]);
		if (!var_array)
		{
			ft_lstclear(&environ, destroy_var);
			return (NULL);
		}
		ft_lstadd_back(&environ,
			ft_lstnew(new_var(var_array[0], var_array[1])));
		free(var_array);
		i++;
	}
	ft_lstadd_back(&environ,
		ft_lstnew(new_var(ft_strdup("?"), ft_strdup("0"))));
	return (environ);
}
