/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:58:59 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/05 12:59:02 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include "./../libft/libft.h"
# include "./../minilibx_mms_20200219/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define TURN 0.04
# define SCL 10

typedef struct	s_frame
{
	uint8_t		flag;
	uint8_t		bfh[14];
	uint8_t		bih[40];
	uint32_t	count;
	uint32_t	size_of_file;
	uint8_t		fd;
	uint32_t	length;

}				t_frame;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_data;

typedef struct s_sprites
{
	int		x;
	int		y;
	double	dist;
	double	sprX;
	double	sprY;
	double	transX;
	double	transY;
	int		sprScreenX;
	int		sprH;
	int		sprW;
	int		drawStartX;
	int		drawEndX;
	int		drawStartY;
	int		drawEndY;
}			t_sprites;

typedef struct s_params
{
	char		*filename;
	char		*ext;
	int			save;
	int			rx;
	int			ry;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*spr_addr;
	int			fr;
	int			fg;
	int			fb;
	int			cr;
	int			cg;
	int			cb;
	int			floor;
	int			ceiling;
	char		**map;
	int			map_x;
	int			map_y;
	void		*mlx;
	void		*win;
	t_frame		screenshot;
	t_data		img;
	int			first_img_flag;
	double		pos_x;
	double		pos_y;
	double		dir;
	double		fov;
	int			flagW;
	int			flagA;
	int			flagS;
	int			flagD;
	double		curr_ray;
	t_data		tex[5];
	int			sprite_ct;
	t_sprites	*spr;
	int			*ZBuffer;
	double		invDet;
}				t_params;

typedef struct s_rays
{
	double		ray_x;
	double		ray_y;
	double		dir;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			mapX;
	int			mapY;
	double		perpWallDist;
}				t_rays;

int				get_next_line(int fd, char **line);
int				inv_args_error(void);
int				file_not_found_error(void);
int				inv_config_file(void);
int				malloc_error(void);
int				check_filename(t_params *params);
t_params		*params_init(void);
int				parser(t_params *params);
int				parser_checks(t_params *params, int fd, char *line);
int				params_work(char *line, t_params *params);
void			splfree(char **spl);
int				write_param(char **spl, t_params *params);
int				check_sym(char *str);
int				resolution_p(char **spl, t_params *params);
int				floor_p(char **spl, t_params *params);
int				ceiling_p(char **spl, t_params *params);
int				def_color(int a, int b, int c);
int				north_p(char **spl, t_params *params);
int				south_p(char **spl, t_params *params);
int				west_p(char **spl, t_params *params);
int				east_p(char **spl, t_params *params);
int				sprite_p(char **spl, t_params *params);
int				check_params(t_params *params);
int				parse_map(int fd, char *line, t_params *params);
int				new_elem(char *line, t_list **tmp);
int				make_map(t_list *tmp, t_params *params);
int				check_map(t_params *params);
int				find_length(int y, char **map);
int				modify_map(t_params *params);
int				check1(int x, int y, char **map);
int				check2(int x, int y, char **map);
int				check3(t_params *params);
void			player_init(int pos_x, int pos_y, char dir, t_params *params);
int				window(t_params *params);
void			make_screenshot(t_params *params);
void			bmp_meta_info(t_params *params);
void			screenshot_recording(t_params *params);
void			loops_hooks(t_params *params);
int				engine(t_params *params);
void			image(t_params *params);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				keys(int keycode, t_params *params);
int				win_close(t_params *params);
int				move(t_params *params);
int				check_pos_x(t_params *params);
int				check_pos_y(t_params *params);
void			new_ray0(t_data *img, t_params *params);
void			new_ray1(t_data *img, t_params *params, int x);
void			new_ray2(t_data *img, t_params *params, t_rays *ray, int x);
void			new_ray3(t_data *img, t_params *params, t_rays *ray, int x);
void			floor_ceiling(t_data *img, t_params *params);
int				load_textures(t_params *params);
int				error_textures(t_params *params);
unsigned int	get_tex_color(t_data data, int x, int y);
void			draw_world(t_data *img, t_params *params, t_rays *ray, double
					x);
int				define_side(t_rays *ray);
int				x_tex_coordinate(t_params *params, t_rays *ray, t_data *tex);
int				y_tex_coordinate(t_params *params, double height, int y,
					t_data *tex);
int				keypress(int keycode, t_params *params);
int				keyrelease(int keycode, t_params *params);
int				load_sprite_tex(t_params *params);
void			init_sprites(t_params *params);
void			sort_sprites(t_params *params);
void			draw_sprites(t_data *img, t_params *params);
void			draw_sprites2(t_params *params, int i);
void			draw_sprites3(t_data *img, t_params *params, int i);
int				sprite_texX(t_params *params, int x, int i);
int				sprite_texY(t_params *params, int y, int i);

#endif
