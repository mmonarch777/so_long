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
	if (ber->map[ber->p_y - 1][ber->p_x] != '1')
	{
		if (ber->map[ber->p_y - 1][ber->p_x] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->p_x * 64, (ber->p_y - 1) * 64);
			ber->c--;
		}
		if (ber->map[ber->p_y - 1][ber->p_x] == 'E' && ber->c == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->p_y - 1][ber->p_x] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->p_x * 64, ber->p_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->up.img, ber->p_x * 64, (ber->p_y - 1) * 64);
			ber->map[ber->p_y][ber->p_x] = '0';
			ber->map[ber->p_y - 1][ber->p_x] = 'P';
			ber->p_y--;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}

void	ft_moove_a(t_ber *ber)
{
	if (ber->map[ber->p_y][ber->p_x - 1] != '1')
	{
		if (ber->map[ber->p_y][ber->p_x - 1] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, (ber->p_x - 1) * 64, ber->p_y * 64);
			ber->c--;
		}
		if (ber->map[ber->p_y][ber->p_x - 1] == 'E' && ber->c == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->p_y][ber->p_x - 1] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->p_x * 64, ber->p_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->left.img, (ber->p_x - 1) * 64, ber->p_y * 64);
			ber->map[ber->p_y][ber->p_x] = '0';
			ber->map[ber->p_y][ber->p_x - 1] = 'P';
			ber->p_x--;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}

void	ft_moove_s(t_ber *ber)
{
	if (ber->map[ber->p_y + 1][ber->p_x] != '1')
	{
		if (ber->map[ber->p_y + 1][ber->p_x] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->p_x * 64, (ber->p_y + 1) * 64);
			ber->c--;
		}
		if (ber->map[ber->p_y + 1][ber->p_x] == 'E' && ber->c == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->p_y + 1][ber->p_x] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->p_x * 64, ber->p_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->down.img, ber->p_x * 64, (ber->p_y + 1) * 64);
			ber->map[ber->p_y][ber->p_x] = '0';
			ber->map[ber->p_y + 1][ber->p_x] = 'P';
			ber->p_y++;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}

void	ft_moove_d(t_ber *ber)
{
	if (ber->map[ber->p_y][ber->p_x + 1] != '1')
	{
		if (ber->map[ber->p_y][ber->p_x + 1] == 'C')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, (ber->p_x + 1) * 64, ber->p_y * 64);
			ber->c--;
		}
		if (ber->map[ber->p_y][ber->p_x + 1] == 'E' && ber->c == 0)
			ft_win("YOU ARE WIN!)");
		if (ber->map[ber->p_y][ber->p_x + 1] != 'E')
		{
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->floor.img, ber->p_x * 64, ber->p_y * 64);
			mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
				ber->right.img, (ber->p_x + 1) * 64, ber->p_y * 64);
			ber->map[ber->p_y][ber->p_x] = '0';
			ber->map[ber->p_y][ber->p_x + 1] = 'P';
			ber->p_x++;
			ber->moove++;
			printf("Movements done %d\n", ber->moove);
		}
	}
}
