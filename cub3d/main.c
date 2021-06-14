/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void 	check_flags(t_cub *cub)
{
	if (cub->p_flag != 1 || cub->s_flag != 1 || cub->e_flag != 1 || cub->w_flag
		!= 1 || cub->sp_flag != 1 || cub->f_flag != 1 || cub->r_flag != 1
		|| cub->height_f != 1 || cub->width_f != 1 || cub->c_flag != 1)
		error_map("wrong number of texture or sprites");
}

void	check_map(char *argv, int *fd)
{
	if (ft_strlen(argv) > 0)
	{
		if (ft_strlen(argv) == ft_strlen("map.cub")
			&& ft_strncmp(argv, "map.cub", ft_strlen(argv)) == 0)
		{
			*fd = open(argv, O_RDONLY);
		}
		else
			error_map("wrong argument");
	}
	else
		error_map("wrong");
}

void	check_save(t_cub *cub, char **argv)
{
	cub->save = 0;
	if (ft_strlen(argv[1]) > 0)
	{
		if (ft_strlen(argv[1]) == ft_strlen("--save")
			&& ft_strncmp(argv[1], "--save", ft_strlen(argv[1])) == 0)
			cub->save = 1;
		else
			error_map("wrong argument");
	}
	else
		cub->save = 0;
}

void 	file_check(t_cub *cub, int arg, char **argv, int *fd)
{
	if (arg < 2 || arg > 3)
		error_map("wrong number of argument");
	if (arg == 2)
		check_map(argv[1], fd);
	else if (arg == 3)
	{
		check_map(argv[2], fd);
		check_save(cub, argv);
	}
}

int	main(int arg, char **argv)
{
	t_cub	cub;
	int		fd;
	char	*line;
	t_list	*head;

	file_check(&cub, arg, argv, &fd);
	if (fd < 0)
		error_map("can't open file");
	line = NULL;
	head = NULL;
	initilaze_var(&cub);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head), &cub);
	check_flags(&cub);
	check_res(&cub);
	cub.mlx = mlx_init();
	texbuf_mall(&cub);
	load_texture(&cub);
	cub.win = mlx_new_window(cub.mlx, cub.width, cub.height, "mlx");
	mlx_loop_hook(cub.mlx, &cube_loop, &cub);
	mlx_hook(cub.win, 2, 0, &key_press, &cub);
	mlx_hook(cub.win, 17, 0, close_win, &cub);
	mlx_loop(cub.mlx);
}
