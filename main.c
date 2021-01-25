/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:17:01 by ahaddad           #+#    #+#             */
/*   Updated: 2021/01/25 19:26:19 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		test_strlen(char *str)
{
	int a;
	int s;

	s = strlen(str);
	printf("sys_strlen |%d| %s\n", s, str);
	a = ft_strlen(str);
	printf("asm_strlen |%d| %s\n", a, str);
}

void		test_strcmp(void)
{
	int		i;
	char	*s1[5];
	char	*s2[5];

	s1[0] = "aminehaddad";
	s1[1] = "Hello, World!";
	s1[2] = NULL;
	s1[3] = "abcdefghijklmnopqrstuvwxyz";
	s2[0] = "aminehaddad";
	s2[1] = "Hello, World!";
	s2[2] = NULL;
	s2[3] = "abcdefghijklmnopqrstuvwxyz";
	i = strcmp(s1[3], s2[3]);
	printf("sys_strcmp |%d|\n", i);
	i = ft_strcmp(s1[3], s2[3]);
	printf("asm_strcmp |%d|\n", i);
}

void		test_write(void)
{
	int		fd;
	int		fd1;
	char	*buffer;
	ssize_t	i;

	buffer = "Hello, Africa!";
	fd = open("file.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	i = write(fd, buffer, ft_strlen(buffer));
	printf("errno_sys ==> {%d}\n", errno);
	if (errno != 0)
		errno = 0;
	close(fd);
	fd1 = open("file1.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	i = ft_write(fd, buffer, ft_strlen(buffer));
	printf("my_errno ==> {%d}\n", errno);
	close(fd1);
}

void		test_read(void)
{
	int		fd;
	char	buff[5];
	ssize_t	i;

	bzero(buff,5);
	fd = open("file.txt", O_RDONLY);
	i = ft_read(fd, buff, 5);
	close(fd);
	printf("read |%zd| |%s|\n", i, buff);
}

int			main(void)
{
	char *str[5];
	char *sy_cpy;
	char *my_cpy;
	char dest[100];

	str[0] = "";
	str[2] = NULL;
	str[4] = "1337FUTUREISLOADING!";
	test_strlen(str[0]);
	strcpy(dest, str[0]);
	printf("sys_cpy |%s|, |%s|\n", str[0], dest);
	ft_strcpy(dest, str[0]);
	printf("asm_cpy |%s|, |%s|\n", str[0], dest);
	test_strcmp();
	test_write();
	test_read();
	sy_cpy = strdup("salam");
	printf("sys_copy|%s| |%zu|\n", sy_cpy, ft_strlen(sy_cpy));
	my_cpy = ft_strdup("salam");
	printf("asm_copy|%s| |%zu|\n", my_cpy, ft_strlen(my_cpy));
	free(sy_cpy);
	free(my_cpy);
	return (0);
}
