/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:21:58 by marvin            #+#    #+#             */
/*   Updated: 2024/11/16 07:16:16 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	str = malloc(ft_strlen_line(s1) + ft_strlen_line(s2) + 1);
	if (!str)
		return (free_gnl(s1));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = s2[j];
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	check_and_clear(char *line)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (flag == 1)
			line[j++] = line[i];
		if (line[i] == '\n')
			flag = 1;
		line[i++] = '\0';
	}
	return (flag);
}

char	*free_gnl(char *gnl)
{
	if (gnl)
		free(gnl);
	return (NULL);
}

//VERIFICAR USO DE STRDUP QUANDO !s1 ou !s2
//free necessario quando strjoin(null, line[fd]);
