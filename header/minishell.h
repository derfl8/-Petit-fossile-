/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:22:21 by abegou            #+#    #+#             */
/*   Updated: 2026/04/27 17:13:10 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <complex.h>
# include <linux/limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_env
{
	char			*envinfo;
	struct s_env	*next;

}					t_env;

// echo.c
int					ft_echo(char **av);

//pwd_env.c
int					ft_pwd(t_env *envinfo, char **av);
int					ft_env(t_env *envinfo, char **av);
t_env				*init_env(char **envp);

// lst_tools.c
void				ft_add_back_env(t_env **lst, t_env *new_node);
void				ft_free_stack_env(t_env *array);
t_env				*ft_new_env(char *envinfo);

// custom_libft.c
size_t				ft_size_cut(char *to_cut);
char				*ft_cut_env(char *to_cut);
size_t				arg_len(char **av);

// libft.c
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);

#endif