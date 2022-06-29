/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lblanche <lblanche@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:42:16 by lblanche          #+#    #+#             */
/*   Updated: 2022/04/09 11:27:28 by tbrissia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *save, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!save)
	{
		save = (char *)malloc(1 * sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	str = malloc(sizeof(char) *((ft_strlen_gnl(save)+ft_strlen_gnl(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(save) + ft_strlen_gnl(buff)] = '\0';
	free(save);
	return (str);
}

char	*ft_find_line_gnl(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_save_gnl(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}
