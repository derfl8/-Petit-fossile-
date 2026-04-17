/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:22:21 by abegou            #+#    #+#             */
/*   Updated: 2026/04/17 18:03:29 by abegou           ###   ########.fr       */
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

int					ft_pwd(void);
int					ft_env(t_env *envinfo);
void				ft_add_back_env(t_env **lst, t_env *new);
t_env				*ft_new_env(char *envinfo);
void				ft_free_stack_env(t_env **array);
t_env				*init_env(char **envp);

#endif