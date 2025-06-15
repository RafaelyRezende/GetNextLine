/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:32:19 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/06/13 18:24:12 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	ft_unit_test(void)
{
	char	*file_test[] = {"one_line_nl.txt","empty.txt","41_no_nl"};
	int	fd;
	char	*tmp;
	char	*tmp2;

	fd = open(file_test[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error reading file");
		return (-1);
	}
	tmp = get_next_line(fd);
	printf("%s-------", tmp);
	tmp2 = get_next_line(fd);
	printf("%s", tmp2);
	free(tmp);
	return (0);
}

int	main(void)
{
	int	status;

	status = ft_unit_test();
	return (status);
}
