/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/04/08 19:25:17 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_pwd(void)
{
    char    buffer[PATH_MAX];
    
    if(getcwd(buffer, PATH_MAX) == NULL)
        return(1);
    printf("%s\n", getcwd(buffer, PATH_MAX));
    return (0);
}

int ft_env(char **envp)
{
    int i = 0;
    while (envp[i])
        printf("%s\n", envp[i++]);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    ft_env(envp);
    return (0);
}