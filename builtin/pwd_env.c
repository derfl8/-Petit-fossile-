/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/04/17 18:02:36 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(void)
{
// update by cd if PWD unset
    char    buffer[PATH_MAX];
    
    if(getcwd(buffer, PATH_MAX) == NULL)
    {
        perror("pwd");
        return(1);
    }
    printf("%s\n", buffer);
    return (0);
}

int ft_env(t_env *envinfo)
{
    int     i;
    t_env   *envinfo;
       
    i = 0;
    envinfo = envp[i++];
    while (envinfo != NULL)
    {
        envinfo = envp[i];
        printf("%s\n", envp[i++]);
        envinfo = envinfo->next;
    }
    return (0);
}

t_env   *init_env(char  **envp)
{
    t_env   *envinfo;
    t_env   *new;
    int     i;
    
    envinfo = NULL;
    i = 0;
    while (envp[i])
    {
        new = ft_new_env(envp[i++]);
        if (!new)
		{
			ft_free_stack_env(&envinfo);
			return (NULL);
		}
        ft_add_back_env(&envinfo, new);
    }
    return (envinfo);
}

int main(int ac, char **av, char **envp)
{
    t_env   *envinfo;
    (void)ac;
    (void)av;
    envinfo = init_env(envp);
    ft_env();
    ft_pwd();
    // ft_env(envp);
    return (0);
}