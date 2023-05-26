/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:04:33 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 21:36:10 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_cd(void)
{
	t_arg	*temp;

	temp = g_data.list;
	if (temp->next && ft_strcmp(temp->next->arg, "~") == 0)
	{
		if (chdir(temp->next->arg))
			perror("minishell ");
	}
	else if (chdir(getenv("HOME")))
		perror("minishell ");
}