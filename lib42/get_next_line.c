/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblanche <lblanche@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:41:39 by lblanche          #+#    #+#             */
/*   Updated: 2022/04/05 12:58:58 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_to_save_gnl(int fd, char *save)
{
	char	*buff;
	int		nbr;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nbr = 1;
	while (!ft_strchr_gnl(save, '\n') && nbr != 0)
	{
		nbr = read(fd, buff, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbr] = '\0';
		save = ft_strjoin_gnl(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_to_save_gnl(fd, save);
	if (!save)
		return (NULL);
	line = ft_find_line_gnl(save);
	save = ft_new_save_gnl(save);
	return (line);
}
