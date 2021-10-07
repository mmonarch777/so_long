/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:28:14 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 12:29:05 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*gnl_push_to_line(char *mass)
{
	int		i;
	char	*dest;

	if (mass == NULL)
		return (0);
	i = 0;
	while (mass[i] != '\n' && mass[i])
		i++;
	dest = malloc(sizeof (char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (mass[i] != '\n' && mass[i] != '\0')
	{
		dest[i] = mass[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	int	gnl_strchr(const char *s, int c)
{
	char	*mass;
	int		i;

	if (!s)
		return (0);
	mass = (char *)s;
	i = 0;
	while (mass[i] != '\0')
	{
		if (mass[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

static	char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*mass;
	size_t	nb;

	if (!s1)
		s1 = "";
	mass = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (mass == NULL)
		return (NULL);
	nb = 0;
	while (*s1 != '\0')
		mass[nb++] = *s1++;
	while (*s2 != '\0')
		mass[nb++] = *s2++;
	mass[nb] = '\0';
	return (mass);
}

static	char	*gnl_update_re(char *mass)
{
	char	*dast;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (mass[i] != '\n' && mass[i] != '\0')
		i++;
	if (mass[i] == '\0')
	{
		free(mass);
		return (NULL);
	}
	dast = malloc(sizeof (char) * (ft_strlen(mass) - i) + 1);
	if (!dast)
		return (NULL);
	i++;
	while (mass[i] != '\0')
		dast[nb++] = mass[i++];
	dast[nb] = '\0';
	free(mass);
	return (dast);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*last;
	char		buf[BUFFER_SIZE + 1];
	int			bwr;

	bwr = 1;
	if ((!line || fd < 0 || read(fd, 0, 0) < 0) || BUFFER_SIZE <= 0)
		return (-1);
	while (!gnl_strchr(remainder, '\n') && bwr)
	{
		bwr = read(fd, buf, BUFFER_SIZE);
		buf[bwr] = '\0';
		last = remainder;
		remainder = gnl_strjoin(remainder, buf);
		if (!remainder)
			return (-1);
		if (last != NULL)
			free(last);
	}
	*line = gnl_push_to_line(remainder);
	remainder = gnl_update_re(remainder);
	if (bwr == 0)
		return (0);
	return (1);
}
