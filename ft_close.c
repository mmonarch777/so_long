/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:21:36 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 18:21:42 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_ber *ber)
{
	mlx_destroy_window(ber->mlx.mlx, ber->mlx.mlx_win);
	exit(0);
}
