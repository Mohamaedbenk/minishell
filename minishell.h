/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:32:40 by tnamir            #+#    #+#             */
/*   Updated: 2022/03/28 11:53:08 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_minishell
{
	int		exita;
	char	*prompt;
	char	current_dir[200];
	char	**options;
	char	**local_env;
	int		exit_status;
	int		w_fd;
	int		r_fd;
	int		p;
}	t_minishell;

void	execute(char *input, t_minishell *minish, char	**argv);
char	f_or_d(char *input);
char	*rm_late_sp(char	*s);
char	*rm_early_sp(char	*s);
char	**quotes_presence(char	*input, t_minishell	*minish);
int		count_cmds(char *input);
char	*var_handler(char *buff, char *str, t_minishell *minish, int *x);
char	**cpy_it(char	*input, char	**options);
char	*ft_charjoin(char	*str, char c);
void	conditions(t_minishell *minishell, char	*input);

// builtins commands
void	env(char	**env, t_minishell *minish);
void	echo(char	**options, t_minishell *minish);
void	cd(char *path, t_minishell *minish);
int		is_var(char	**local_env, char *var);
char	**unset_var(char *var_name, char **local_env);
char	**export(char	**local_env, t_minishell *minish);
char	**unset(char	**local_env, t_minishell *minish);
int		pipe_hand(t_minishell *minish, char *input);

#endif