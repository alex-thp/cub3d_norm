/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 11:18:10 by ade-temm          #+#    #+#             */
/*   Updated: 2020/02/10 19:58:40 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <mlx.h>

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
	int			total;
}				t_color;

typedef struct	s_doc
{
	int			res_x;
	int			res_y;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	char		*texture;
	t_color		sol;
	t_color		plafond;
	char		*map;
}				t_doc;

typedef struct	s_pos
{
	int			res_x;
	int			res_y;
	double		camera;
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	double		planX;
	double		planY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	double		WallDist;
	double		hauteur_line;
	int			draw_start;
	int			draw_end;
	int			x;
}				t_pos;

typedef struct	s_set
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*var;
}				t_set;

typedef struct	s_moove
{
	int			avancer;
	int			reculer;
	int			gauche;
	int			droite;
	int			tourner_g;
	int			tourner_d;
	double		speed;
}				t_moove;

typedef struct 	s_text
{
	void		*texture_w;
	int			*img;
	int			*width;
	int			*height;
	double		column;
	int			line;

}				t_text;

typedef struct	s_sprite
{
	int				status;
	float			pos_x;
	float			pos_y;
	float			sprite_dist;
	float			hauteur;
	int				draw_start;
	int				draw_end;
	float			angle;
	struct s_sprite	*next;
}				t_sprite;

typedef struct	s_map
{
	t_doc		*doc;
	t_pos		*dist;
	t_sprite	*sprite;
	t_set		mlx;
	t_moove		moove;
	t_text		texture[5];
	int			num;
	char		**map;
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	double		angle;
	int			first_round;
}				t_map;

void    ft_get_sprite(t_map *tab);
void    ft_init_sprite(t_map *tab);
int     ft_set_sprite(t_map *tab);
#endif