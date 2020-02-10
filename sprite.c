/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:52:58 by ade-temm          #+#    #+#             */
/*   Updated: 2020/02/10 19:59:15 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        ft_draw_sprite(t_map *tab)
{
    
}

int     ft_set_sprite(t_map *tab)
{
    t_sprite    *sprite;

    if (!(sprite = malloc(sizeof(t_sprite))))
        return (-1);
    sprite = tab->sprite;
    while (sprite != NULL)
    {
        sprite->status = 0;
        sprite = sprite->next;
    }
    return (0);
}
void        ft_calc_dist_sprite(t_map *tab, t_sprite *sprite)
{
    float   x;
    float   y;
    
    //tab->pos_x tab->pos_y = ma pos
    //tab->map_x tab->map_y = sprite pos
    x = tab->pos_x - tab->map_x;
    y = tab->pos_y - tab->map_y;
    sprite->sprite_dist = sqrtf(x * x + y * y);
    sprite->hauteur = (int)(tab->doc->res_y / sprite->sprite_dist);
    sprite->draw_start = (int)(-(sprite->hauteur / 2) + tab->dist->res_y / 2);
    sprite->draw_end = (sprite->hauteur / 2) + tab->dist->res_y / 2;
    sprite->status = 1;
    sprite->angle = (tab->angle - 30) + (((double)tab->dist->x / tab->dist->res_x) * 60); 
    //printf("%f\t%f\t%d\t%d\t%f\n", sprite->sprite_dist, sprite->hauteur, sprite->draw_start, sprite->draw_end, sprite->angle);
}

void        ft_init_sprite(t_map *tab)
{
    t_sprite    *sprite;

    sprite = tab->sprite;
    while (sprite->pos_x != tab->map_x && sprite->pos_y != tab->map_y)
        sprite = sprite->next;
    ft_calc_dist_sprite(tab, sprite);
}

t_sprite    *ft_create_sprite(int x, int y)
{
    t_sprite *new;

    new = NULL;
    if (!(new = (t_sprite*)malloc(sizeof(t_sprite))))
        return (NULL);
    new->next = NULL;
    new->pos_x = (float)x + 0.5;
    new->pos_y = (float)y + 0.5;
    return (new);
}

int     ft_add_sprite(t_map *tab, int x, int y)
{
    t_sprite    *new;
    t_sprite    *ptr;

    ptr = tab->sprite;
    if (ptr == NULL)
    {
        new = ft_create_sprite(x, y);
        tab->sprite = new;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = ft_create_sprite(x, y);
    }
    return (0);
}

void    ft_get_sprite(t_map *tab)
{
    int     i;
    int     j;

    i = 0;
    while (tab->map[i])
    {
        j = 0;
        while (tab->map[i][j])
        {
            if (tab->map[i][j] == '2')
                ft_add_sprite(tab, i, j);
            j++;
        }
        i++;
    }
}