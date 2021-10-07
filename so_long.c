/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:27:22 by mmonarch          #+#    #+#             */
/*   Updated: 2021/10/07 12:27:33 by mmonarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strnstr_so(const char *haystack, const char*needle, size_t len)
{
	size_t	i;
	size_t	io;
	size_t	nb;

	i = 0;
	io = 0;
	if (ft_strlen(needle) == 0 || haystack == needle)
		return (1);
	while (len > i && haystack[i] != '\0')
	{
		nb = 0;
		while (haystack[io] == needle[nb] && len > io)
		{
			io++;
			nb++;
			if (needle[nb] == '\0' && haystack[io] == '\0')
				return (1);
		}
		i++;
		io = i;
	}
	return (0);
}

static void	ft_check_arguments(int argc, char **argv)
{
	int	i;
	int	fd;

	if (argc != 2)
		error("Wrong number of arguments");
	i = (int)ft_strlen(argv[1]);
	if (!ft_strnstr_so(argv[1], ".ber", i))
		error("Invalid file extension");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("File reading error");
	else
		close(fd);
}

static void	ft_init_struct(t_ber *ber)
{
	ber->height = 0;
	ber->width = 0;
	ber->C = 0;
	ber->E = 0;
	ber->P = 0;
	ber->P_x = 0;
	ber->P_y = 0;
	ber->moove = 0;
}

static int	ft_hook(int keycode, t_ber *ber)
{
	char	*temp;

	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		ft_moove_w(ber);
	if (keycode == 0)
		ft_moove_a(ber);
	if (keycode == 1)
		ft_moove_s(ber);
	if (keycode == 2)
		ft_moove_d(ber);
	mlx_put_image_to_window(ber->mlx.mlx, ber->mlx.mlx_win,
		ber->wall.img, 0 * 64, 0 * 64);
	temp = ft_itoa(ber->moove);
	mlx_string_put(ber->mlx.mlx, ber->mlx.mlx_win, 27, 37,
		0x0000000f, temp);
	free(temp);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ber	ber;

	ft_check_arguments(argc, argv);
	ft_init_struct(&ber);
	ft_handling_map(argv, &ber);
	ber.mlx.mlx = mlx_init();
	ber.mlx.mlx_win = mlx_new_window(ber.mlx.mlx,
			ber.width * 64, ber.height * 64, "so_long");
	ft_add_image(&ber);
	mlx_key_hook(ber.mlx.mlx_win, ft_hook, &ber);
	mlx_string_put(ber.mlx.mlx, ber.mlx.mlx_win, 27, 37,
		   0x0000000f, "0");
	printf("Movements done %s\n", "0");
	mlx_loop(ber.mlx.mlx);
}
