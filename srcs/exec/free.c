/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:42:11 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/01 00:28:12 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmds)
{
	free(cmds->arg);
	free(cmds->type);
	free(cmds->file);
}

void	free_inchildprocess(t_data *data, t_cmd *cmds)
{
	free_cmd(cmds);
	ft_freetab(data->arg);
	ft_freetab(data->split);
	ft_freetab(data->env);
	ft_freetab(data->path);
	free(data->str);
	free(data->hrdoc->key);
	free(data->hrdoc);
}

void	free_in_fd(t_cmd *cmds)
{
	free_cmd(cmds);
	fprintf(stderr, "%s\n", strerror(errno));
	exit(1);
}
