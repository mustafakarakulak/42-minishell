/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:30:35 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/06 04:18:59 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parse/parse.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>

typedef struct s_data
{
	t_arg	*list;
	t_arg	*temp_list;

	char	*line;
	char	**envp;
	char	**ex_path;
	char	**heredoc;
	char	**command;
	char	**redirection;

	int		**all_pipe_fd;
	int		fd;
	int		fd_c;
	int		status;
	int		pipe_c;
	int		p_fd[2];
	int		*pipe_id;
	int		*input_fd;
	int		*output_fd;
	int		*exit_status;

	char	*here_line;
	int		here_fd;

	char	**dollars;
	char	**dollar_line;
}	t_data;


t_data	g_data;

void	start(void);

int		ft_parse(void);
int		error_check(void);
int		initialize_pipe(void);
void	execute(void);

int		ft_strcmp(char *s1, char *s2);

char	**ft_addenv(void);
void	*ft_delenv(int i, int env_c);
void	*ft_getenv(char *name, char **args);

void	ft_cd(void);
void	ft_pwd(void);
void	ft_env(void);
void	ft_echo(void);
void	ft_unset(void);
void	ft_export(void);

int		builtin(void);

void	check_way(void);
void	ft_command_line(void);

void	ft_execve(void);
void	exec_pipe(void);
void	exec_shell(int status);
void	exec_redir(int status);

int		pipe_counter(void);
void	create_tubes(void);

void	ft_heredoc_line(void);

void	ft_dollars_line(void);
char	*ft_find_env(char *arg);

void	ft_exit(t_arg *data);

#endif