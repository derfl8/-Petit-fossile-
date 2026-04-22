/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:09:40 by aldecour          #+#    #+#             */
/*   Updated: 2025/11/08 16:16:07 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = ft_strlen(dest);
	if (n > size)
		n = size;
	n += ft_strlcpy(dest + n, src, size - n);
	return (n);
}
/*
static char	mine_buffer[2048] = {0};
static char real_buffer[2048] = {0};

static int fd = 0;
# define 	N_TEST	10000000

#include <stdio.h>
#include <fcntl.h>
#include "bsd/string.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

char	*ft_random_string(int len)
{
	if (fd == 0)
		fd = open("/dev/random", O_RDONLY);

	assert(len < 2048);
	char	*s = malloc(len + 1);
	assert(s);

	read(fd, s, len);

	s[len] = 0;
	for (int i = 0; i < len; ++i)
		s[i] = (s[i] % 26) + 'a';
	return (s);
}

bool	ft_test_strlcat(void)
{
	int	mine, real;
	int	n = rand() % 1024;
	int	n2 = rand() % 1024;

	char	*s1 = ft_random_string(n);
	char	*s2 = ft_random_string(n2);


	memset(mine_buffer, 0, sizeof(mine_buffer));
	memset(real_buffer, 0, sizeof(real_buffer));

	mine = ft_strlcat(mine_buffer, s1, n + 1);
	real = strlcat(real_buffer, s1, n + 1);

	if (memcmp(mine_buffer, real_buffer, n) != 0)
		goto end;
	if (mine != real)
		goto end;

	mine = ft_strlcat(mine_buffer, s2, n + n2 + 1);
	real = strlcat(real_buffer, s2, n + n2 + 1);

	if (memcmp(mine_buffer, real_buffer, n + n2) != 0)
		goto end;
	if (mine != real)
		goto end;

	free(s1);
	free(s2);
	return (true);
end:
	free(s1);
	free(s2);
	return (false);
}

int	main(void)
{
	int pass = 0;

	for (int i = 0; i < N_TEST; ++i)
	{
		printf("TEST [%d] -----------\n", i);
		pass += ft_test_strlcat();
	}
	
	printf("%d / %d tests passed !\n", pass, N_TEST);
}*/
