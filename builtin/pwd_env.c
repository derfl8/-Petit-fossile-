/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/04/08 15:53:10 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>

int ft_pwd(void)
{
    char    buffer[PATH_MAX];
    
    if(getcwd(buffer, PATH_MAX) == NULL)
        return(1);
    printf("%s\n", getcwd(buffer, PATH_MAX));
    return (0);
}

int ft_cd(void)
{
    char    buffer[PATH_MAX];

    printf("%s\n", );
    
}

int main(void)
{
    ft_pwd();
}