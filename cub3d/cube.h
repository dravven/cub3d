/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include "minilibx_mms_20200219/mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

typedef struct s_sprite
{
	double	x;
	double	y;
}	t_sprite;

typedef struct s_cub
{
	void		*img;
	int			*addr;
	char		*adr;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	void		*mlx;
	void		*win;
	double		moveSpeed;
	double		rotSpeed;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			**texture;
	double		*zBuffer;
	int			img_width;
	int			img_height;
	int			p_flag;
	int			e_flag;
	int			w_flag;
	int			sp_flag;
	int			s_flag;
	int			f_flag;
	int			c_flag;
	int			r_flag;
	char		p_north[255];
	char		p_south[255];
	char		p_west[255];
	char		p_east[255];
	char		sprite[255];
	int			texWidth;
	int			texHeight;
	char		butt[255];
	int			ht;
	int			wd;
	char		**worldmap;
	int			height_f;
	int			width_f;
	t_sprite	*sprites;
	int			hit;
	int			side;
	int			stepX;
	int			stepY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			mapX;
	int			mapY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			texNum;
	double		wallX;
	int			texX;
	double		step;
	double		texPos;
	int			texY;
	int			color;
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			vMoveScreen;
	int			spriteHeight;
	int			drawStartY;
	int			drawStartX;
	int			drawEndY;
	int			drawEndX;
	int			spriteWidth;
	int			dir_flag;
	int			rgb_f;
	int			rgb_c;
	int			*spriteOrder;
	double		*spriteDistance;
	int			numSprites;
	int			uDiv;
	int			vDiv;
	double		vMove;
	int			save;
}				t_cub;

typedef struct s_pair
{
	double	first;
	int		second;
}	t_pair;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	draw_fc(t_cub *cub);
void	texbuf_mall(t_cub *cub);
void	initilaze_var(t_cub *cub);
void	my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void	calc(t_cub *cub);
void	calc_help(t_cub *cub);
void	calc_sprites(t_cub *cub);
void	calc_sprite1(t_cub *cub);
void	calc_sprites11(t_cub *cub);
void	calc_sprites2(t_cub *cub);
void	calc_sprites2_help(t_cub *cub, int	texX, int stripe);
void	calc_draw(t_cub *cub, int x);
void	calc_draw_side(t_cub *cub);
void	sort_order(t_pair *orders, int amount);
void	sortSprites(int *order, double *dist, int amount);
void	calc_hit(t_cub *cub);
void	calc_side(t_cub *cub);
void	key_forward(t_cub *cub);
void	key_backward(t_cub *cub);
void	key_left(t_cub *cub);
void	key_right(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
int		key_press(int key, t_cub *cub);
void	load_image_png(t_cub *info, int *texture, char *path);
void	load_texture(t_cub *info);
int		cube_loop(t_cub *cub);
void	error_map(char *str);
void	sprite_mall(t_cub *cub);
void	sprite_posmall(t_cub *cub);
void	parser_res(const char *map, int x, t_cub *cub);
void	parser_color(const char *map, int x, t_cub *cub, char color);
void	parser_path_tex(char direction, int x, t_cub *cub, const char *map);
void	error(char *str, char c);
void	size_map(char **map, int y, t_cub *cub);
int		parser_tex(char **map, int y, t_cub *cub);
void	parser_map(char **map, int y, t_cub *cub);
void	check_dir(t_cub *cub, char s);
void	parser_map_er(t_cub *cub);
void	make_map(t_list **head, int size, t_cub *cub);
void	ft_screenshot(t_cub *cub);
void	check_res(t_cub *cub);
int		close_win(int i, t_cub *cub);
int		get_next_line(int fd, char **line);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t size);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *string1, const char *string2, size_t num);
size_t	ft_strlenn(const char *s);
int		weeknd(char *str);
char	*ft_strdup_2(char *src);

#endif //CUBE_CUBE_H
