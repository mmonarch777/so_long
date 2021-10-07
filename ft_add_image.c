/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:26:10 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 12:26:14 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_image(t_ber *ber)
{
	if (!ber->wall.img)
		error("Image acquisition error wall");
	if (!ber->coin.img)
		error("Image acquisition error coin");
	if (!ber->out.img)
		error("Image acquisition error out");
	if (!ber->floor.img)
		error("Image acquisition error floor");
	if (!ber->left.img)
		error("Image acquisition error left");
	if (!ber->right.img)
		error("Image acquisition error right");
	if (!ber->down.img)
		error("Image acquisition error down");
	if (!ber->up.img)
		error("Image acquisition error up");
}

static void	ft_init_path(t_ber *ber)
{
	ber->wall.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/wall.xpm",
			&ber->wall.image_w, &ber->wall.image_h);
	ber->coin.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/coin.xpm",
			&ber->coin.image_w, &ber->coin.image_h);
	ber->out.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/out.xpm",
			&ber->out.image_w, &ber->out.image_h);
	ber->floor.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/floor.xpm",
			&ber->floor.image_w, &ber->floor.image_h);
	ber->left.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/left.xpm",
			&ber->left.image_w, &ber->left.image_h);
	ber->right.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/right.xpm",
			&ber->right.image_w, &ber->right.image_h);
	ber->down.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/down.xpm",
			&ber->down.image_w, &ber->down.image_h);
	ber->up.img = mlx_xpm_file_to_image(ber->mlx.mlx, "image/up.xpm",
			&ber->up.image_w, &ber->up.image_h);
	ft_check_image(ber);
}

static void	ft_put_image(int *x, int *y, t_ber *ber)
{
	if (ber->map[*y][*x] == '1')
		mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
			ber->wall.img, *x * 64, *y * 64);
	if (ber->map[*y][*x] == '0' || ber->map[*y][*x] == 'C' ||
	ber->map[*y][*x] == 'E' || ber->map[*y][*x] == 'P')
		mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
			ber->floor.img, *x * 64, *y * 64);
	if (ber->map[*y][*x] == 'C')
		mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
			ber->coin.img, *x * 64, *y * 64);
	if (ber->map[*y][*x] == 'E')
		mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
			ber->out.img, *x * 64, *y * 64);
	if (ber->map[*y][*x] == 'P')
		mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
			ber->down.img, *x * 64, *y * 64);
}

void	ft_add_image(t_ber *ber)
{
	int	x;
	int	y;

	ft_init_path(ber);
	y = 0;
	while (y < ber->height)
	{
		x = 0;
		while (x < ber->width)
		{
			ft_put_image(&x, &y, ber);
			x++;
		}
		y++;
	}
}
