/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:22:21 by abegou            #+#    #+#             */
/*   Updated: 2026/04/29 17:56:40 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include <complex.h>
# include <limits.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env	t_env;
typedef struct s_data	t_data;

typedef struct s_env
{
	char				*envinfo;
	struct s_env		*next;

}						t_env;

typedef struct s_data
{
	t_env				*env;
	int					success_or_failed;
}						t_data;

// exp_no_arg.c
void					bubble_sort(char **envtab);
int						nb_var(t_data *shell);
char					*ft_name_var(char *var);

// export.c
int						ft_export(t_data *shell, char **av);

// unset.c
int						ft_unset(t_data *shell, char **av);

// cd.c
int						ft_cd(t_data *shell, char **av);

// echo.c
int						ft_echo(t_data *shell, char **av);

// pwd.c
int						ft_pwd(t_data *shell, char **av);
void					oldpwd_update(t_data *shell, char *oldpwd);

// env.c
int						ft_env(t_data *shell, char **av);
t_env					*init_env(char **envp);
bool					update_env(t_env *env, char *key, char *value);
bool					is_in_env(t_env *env, char *key);

// exit.c
void					ft_exit(t_data *shell, char **exit_code);

// lst_tools.c
void					ft_add_back_env(t_env **lst, t_env *new_node);
void					ft_free_stack_env(t_env *array);
t_env					*ft_new_env(char *envinfo);

// custom_libft.c
char					*ft_cut_env(char *to_cut);
size_t					arg_len(char **av);
void					free_tab(char **tab);

#endif