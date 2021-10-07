/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:27:49 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 18:10:43 by mmonarch         ###   ########.fr       */
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
	int		p;
	int		p_x;
	int		p_y;
	int		c;
	int		e;
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
int		ft_close(t_ber *ber);
#endif
