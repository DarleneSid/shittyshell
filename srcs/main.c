/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:41:15 by pferreir          #+#    #+#             */
/*   Updated: 2023/10/01 00:58:08 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data = {0};
	char	*str;
	int		i;

	(void)ac;
	(void)av;
	i = 0;
	data.env = ft_copy(env);
	allsignals();
	while (1)
	{
		str = readline("pao> ");
		if (!str)
			break ;
		if (!*str)
		{
			free(str);
			continue ;
		}
		add_history(str);
		 if (syntax(&data, str) == 1)
		 	continue ;
		if (syntax(&data, str) == 2)
			break ;
		str = ft_space(str);
		data.str = str;
		ft_expand(&str, &data.env, data.exit_code);
		if (!str || !*str)
			continue ;
		ft_quote(str);
		if (str)
			data.split = ft_split(str, '|');
		if (is_there_hrdoc(str))
		{
			here_doc(&data, str);
			// free(data.hrdoc->key);

		}
		execution(&data, data.split, &data.env);
		free(str);
		ft_freetab(data.split);
		free(data.hrdoc);
		// printf("pointer -> %p\n", data.hrdoc->key);
		// free(data.hrdoc->key);
		
	}
	free(str);
	ft_freetab(data.env);
	// ft_freetab(data.split);
}
