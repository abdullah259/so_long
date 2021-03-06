/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:47:04 by aghazi            #+#    #+#             */
/*   Updated: 2022/05/24 18:48:17 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *img)
{
	img->check_exit = 0;
	img->for_c = 0;
	img->e = 0;
	img->p = 0;
	img->i = 0;
	img->movix = 0;
	img->moviy = 0;
	img->x = 0;
	img->y = 0;
	img->img_wid = 0;
	img->img_hei = 0;
	img->steps = 0;
}

void	ft_exit(void)
{
	write(1, "invalid argment\n", 16);
	exit(1);
}

int	main(int arc, char **argv)
{
	t_data	img;
	int		j;
	int		compa;
	char	*tmp;
	int		x;

	ft_init (&img);
	if (arc != 2)
		ft_exit();
	j = 0;
	x = 0;
	check_par (argv[1]);
	tmp = map (argv[1]);
	if (!tmp)
		return (0);
	img.map = ft_split (tmp, '\n', &x);
	free (tmp);
	if (x == 2)
		free_sp (img.map);
	compa = check_fl (&img);
	j++;
	j = check_mid (compa, j, &img);
	check_last (&img, compa, j);
	every_thing_ok (&img, img.for_c, j);
	exit(1);
}
