/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:09:55 by abegou            #+#    #+#             */
/*   Updated: 2026/09/20 01:01:01 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"
# include <stdbool.h>

// expander.c
void	archaic_expand(t_data *shell, t_tree *tree);
char	*expand_str(t_data *shell, char *str);

// expander_utils.c
char	*exp_key_env(t_env *env, char *key_name);
char	*join_and_free(char *base, char *add);
int		get_varend(char *key, int end);
char	*get_value(t_data *shell, char *result, char *str, int start);

#endif
