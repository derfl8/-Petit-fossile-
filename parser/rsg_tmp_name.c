/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsg_tmp_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 22:12:45 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/01 23:27:22 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static char	alnum_formatting(char *str, size_t i)
{
	if (str[i] < '0' && !ft_isalnum(str[i]))
	{
		str[i] %= 10;
		str[i] += '0';
	}
	else if (str[i] < 'A' && !ft_isalnum(str[i]))
	{
		str[i] %= 26;
		str[i] += 'A';
	}
	else if (str[i] < 'a' && !ft_isalnum(str[i]))
	{
		str[i] %= 26;
		str[i] += 'a';
	}
	return (str[i]);
}

static void	format_random_str(char	*str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == -128)
			str[i] = 0;
		else if (str[i] < 0)
			str[i] *= -1;
		str[i] %= 123;
		str[i] = alnum_formatting(str, i);
		i++;
	}
	str[i - 1] = '\0';
}

static char	*get_random_str(size_t	size)
{
	char	*str;
	int		fd;
	int		bytes_read;

	bytes_read = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
	}
	str = malloc(sizeof (char) * size);
	if (!str)
	{
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, str, size);
	if (bytes_read < 0)
	{
		free(str);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (str);
}

char	*get_random_filename(size_t random_size)
{
	char	*file_name;
	char	*random_str;
	size_t	size;

	size = 27 + random_size;
	random_str = get_random_str(random_size);
	if (random_str == NULL)
	{
		ft_putstr_fd("Petit Fossile : Failed to generate a tmp file name ", 2);
		ft_putstr_fd("for heredoc handling.\n", 2);
		return (NULL);
	}
	format_random_str(random_str, random_size);
	file_name = malloc(sizeof (char) * (size + 1));
	ft_strlcpy(file_name, "/tmp/minishell_tmp_heredoc", size);
	ft_strlcat(file_name, random_str, size);
	free(random_str);
	return (file_name);
}
