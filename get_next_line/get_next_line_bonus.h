/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 18:04:51 by evoronin      #+#    #+#                 */
/*   Updated: 2023/01/31 17:14:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *temp, char *buff);
char	*get_newline(char *temp);
char	*get_next_line(int fd);
char	*ft_temptrim(char *temp, char *line);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*read_buf(int fd, char *temp);
char	*ft_free(char **str, char *str1);

#endif