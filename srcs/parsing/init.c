/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:42:20 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/01 00:06:20 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	init_parsing(char *str, t_data *data)
{
	if (!str)
		return (2);
	if (!*str)
		return (free(str), 1);
	add_history(str);
	if (syntax(data, str) == 1)
		return (1);
	if (syntax(data, str) == 2)
		return (2);
	str = ft_space(str);
	ft_expand(&str, &data->env, data->exit_code);
	if (!str || !*str)
		return (1);
	ft_quote(str);
	data->str = str;
	if (str)
		data->split = ft_split(str, '|');
	return (0);
}*/
