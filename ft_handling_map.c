/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:26:28 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 12:26:37 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_count(char **argv, t_ber *ber)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ber->height++;
		if (ber->width != 0)
		{
			if (ber->width != (int) ft_strlen(line))
				error("Map is not rectangular");
		}
		ber->width = (int)ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
}

static void	ft_check_map(t_ber *ber)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ber->height)
	{
		if (ber->map[i][0] != '1' || ber->map[i][ber->width - 1] != '1')
			error("The walls have a gap1");
		i++;
	}
	while (j < ber->width)
	{
		if (ber->map[0][j] != '1' || ber->map[ber->height - 1][j] != '1')
			error("The walls have a gap2");
		j++;
	}
}

static void	ft_parsing_map(t_ber *ber)
{
	int	x;
	int	y;

	y = -1;
	while (++y < ber->height)
	{
		x = -1;
		while (ber->map[y][++x])
		{
			if (!ft_strchr("01CEP", ber->map[y][x]))
				error("The card has extraneous symbols");
			if (ber->map[y][x] == 'P')
			{
				ber->P++;
				ber->P_y = y;
				ber->P_x = x;
			}
			if (ber->map[y][x] == 'C')
				ber->C++;
			if (ber->map[y][x] == 'E')
				ber->E++;
		}
	}
	if (ber->P != 1 || ber->E != 1 || ber->C < 1)
		error("The map must have 1 player, 1 exit and at least 1 collectible");
}

void	ft_handling_map(char **argv, t_ber *ber)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	ft_count(argv, ber);
	ber->map = malloc((ber->height + 1) * sizeof(char *));
	if (!ber->map)
		error("Memory allocation error");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ber->map[i] = line;
		i++;
	}
	ber->map[i] = line;
	free(line);
	close(fd);
	ft_check_map(ber);
	ft_parsing_map(ber);
}
