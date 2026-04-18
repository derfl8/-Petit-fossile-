/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:22:21 by abegou            #+#    #+#             */
/*   Updated: 2026/04/18 17:34:49 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <complex.h>
# include <linux/limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_env
{
	char			*envinfo;
	struct s_env	*next;

}					t_env;

int					ft_pwd(t_env *envinfo);
int					ft_env(t_env *envinfo, char **av);
void				ft_add_back_env(t_env **lst, t_env *new);
t_env				*ft_new_env(char *envinfo);
void				ft_free_stack_env(t_env **array);
t_env				*init_env(char **envp);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif