/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:12:24 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/09 13:31:16 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_all(void)
{
	int	i;

	while (g_data.list)
	{
		free(g_data.list->arg);
		g_data.list = g_data.list->next;
	}
	i = 0;
	if (g_data.command)
	{
		while (g_data.command[i])
			free(g_data.command[i++]);
		free(g_data.command);
	}
	i = 0;
	if (g_data.redirection)
	{
		while (g_data.redirection[i])
			free(g_data.redirection[i++]);
		free(g_data.redirection);
	}
	i = 0;
	if (g_data.count_type)
		free(g_data.count_type);
}

void	ft_free_child(char **array)
{
	int	i;

	i = 0;
	while (g_data.list)
	{
		free(g_data.list->arg);
		g_data.list = g_data.list->next;
	}
	free(g_data.line);
	if (!g_data.redirection)
		return ;
	while (g_data.redirection[i])
		free(g_data.redirection[i++]);
}
