/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:37:16 by moouaamm          #+#    #+#             */
/*   Updated: 2023/01/26 01:04:18 by moouaamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*read_line(int fd, char *stv)
{
	char	*bfr;
	int		a;

	a = 55;
	bfr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bfr)
		return (free(bfr), NULL);
	while (ft_strchr(stv, '\n') == -1 && a > 0)
	{
		a = (int)read(fd, bfr, BUFFER_SIZE);
		bfr[a] = '\0';
		stv = ft_join(stv, bfr);
	}
	free (bfr);
	bfr = NULL;
	return (stv);
}

char	*set_line(char *st_v)
{
	int		i;
	int		j;
	char	*line;

	if (!st_v[0] || !st_v)
		return (NULL);
	i = 0;
	j = 0;
	while (st_v[i] != '\0' && st_v[i] != '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = st_v[j];
		j++;
	}
	if (st_v[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*skip_line(char *st_v)
{
	int		a;
	int		j;
	char	*nw_s;

	a = 0;
	j = 0;
	if (st_v[0] == '\0' || !st_v)
		return (free(st_v), NULL);
	while (st_v[j] != '\0' && st_v[j] != '\n')
		j++;
	if (st_v[j] == '\n')
		j++;
	nw_s = (char *) malloc(ft_strlen(st_v) - j + 1);
	if (!nw_s)
		return (NULL);
	while (st_v[j])
		nw_s[a++] = st_v[j++];
	nw_s[a] = '\0';
	free (st_v);
	st_v = NULL;
	return (nw_s);
}

char	*get_next_line(int fd)
{
	static char	*stv;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, NULL, 0) < 0)
		return (NULL);
	stv = read_line(fd, stv);
	ln = set_line(stv);
	stv = skip_line(stv);
	return (ln);
}
