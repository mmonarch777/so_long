/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:27:49 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 12:27:57 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_image
{
	void	*img;
	char	*path;
	int		image_w;
	int		image_h;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_ber
{
	int		width;
	int		height;
	char	**map;
	int		P;
	int		P_x;
	int		P_y;
	int		C;
	int		E;
	int		moove;
	t_mlx	mlx;
	t_image	wall;
	t_image	out;
	t_image	coin;
	t_image	floor;
	t_image	left;
	t_image	right;
	t_image	down;
	t_image	up;
}	t_ber;

void	error(char *str);
void	ft_handling_map(char **argv, t_ber *ber);
void	ft_add_image(t_ber *ber);
void	ft_moove_w(t_ber *ber);
void	ft_moove_a(t_ber *ber);
void	ft_moove_s(t_ber *ber);
void	ft_moove_d(t_ber *ber);
#endif
