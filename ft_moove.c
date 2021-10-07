/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:26:49 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 12:26:53 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_win(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	ft_moove_w(t_ber *ber)
{
	if (ber->map[ber->P_y - 1][ber->P_x] != '1')
	{
		if (ber->map[ber->P_y - 1][ber->P_x] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->P_x * 64, (ber->P_y - 1) * 64);
			ber->C--;
		}
		if (ber->map[ber->P_y - 1][ber->P_x] == 'E' && ber->C == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->P_y - 1][ber->P_x] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->P_x * 64, ber->P_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->up.img, ber->P_x * 64, (ber->P_y - 1) * 64);
			ber->map[ber->P_y][ber->P_x] = '0';
			ber->map[ber->P_y - 1][ber->P_x] = 'P';
			ber->P_y--;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}

void	ft_moove_a(t_ber *ber)
{
	if (ber->map[ber->P_y][ber->P_x - 1] != '1')
	{
		if (ber->map[ber->P_y][ber->P_x - 1] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, (ber->P_x - 1) * 64, ber->P_y * 64);
			ber->C--;
		}
		if (ber->map[ber->P_y][ber->P_x - 1] == 'E' && ber->C == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->P_y][ber->P_x - 1] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->P_x * 64, ber->P_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->left.img, (ber->P_x - 1) * 64, ber->P_y * 64);
			ber->map[ber->P_y][ber->P_x] = '0';
			ber->map[ber->P_y][ber->P_x - 1] = 'P';
			ber->P_x--;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}

void	ft_moove_s(t_ber *ber)
{
	if (ber->map[ber->P_y + 1][ber->P_x] != '1')
	{
		if (ber->map[ber->P_y + 1][ber->P_x] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->P_x * 64, (ber->P_y + 1) * 64);
			ber->C--;
		}
		if (ber->map[ber->P_y + 1][ber->P_x] == 'E' && ber->C == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->P_y + 1][ber->P_x] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->P_x * 64, ber->P_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->down.img, ber->P_x * 64, (ber->P_y + 1) * 64);
			ber->map[ber->P_y][ber->P_x] = '0';
			ber->map[ber->P_y + 1][ber->P_x] = 'P';
			ber->P_y++;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}

void	ft_moove_d(t_ber *ber)
{
	if (ber->map[ber->P_y][ber->P_x + 1] != '1')
	{
		if (ber->map[ber->P_y][ber->P_x + 1] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, (ber->P_x + 1) * 64, ber->P_y * 64);
			ber->C--;
		}
		if (ber->map[ber->P_y][ber->P_x + 1] == 'E' && ber->C == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->P_y][ber->P_x + 1] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->P_x * 64, ber->P_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->right.img, (ber->P_x + 1) * 64, ber->P_y * 64);
			ber->map[ber->P_y][ber->P_x] = '0';
			ber->map[ber->P_y][ber->P_x + 1] = 'P';
			ber->P_x++;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}
