/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/04/17 16:55:37 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//// update by cd if PWD unset
int ft_pwd(void)
{
    char    buffer[PATH_MAX];
    
    if(getcwd(buffer, PATH_MAX) == NULL)
    {
        perror("pwd");
        return(1);
    }
    printf("%s\n", buffer);
    return (0);
}

int ft_env(char **envp)
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

int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    ft_pwd();
    // ft_env(envp);
    return (0);
}