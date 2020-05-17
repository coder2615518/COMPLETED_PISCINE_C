/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************   

	Файлы для включения: ft_show_tab.c, ft_stock_par.h
	Разрешенные функции: ft_putchar

   **************************************************************************   

	• Создайте функцию, которая отображает содержимое массива, созданного 
	предыдущей функцией.

	• Вот как это должно быть прототипировано:

								void	ft_show_tab(struct s_stock_par *par);

	• Массив структуры должен быть размещен в своем элементе str и его последний 
	блок должен содержать 0, чтобы указать на конец массива.

	• Структура определяется в файле ft_stock_par.h, как тут:

													typedef struct	s_stock_par
													{
														int size_param;
														char *str;
														char *copy;
														char **tab;
													}				t_stock_par;

	• Для каждого поля мы будем отображать (один элемент на строку):

		◦ аргумент;
		◦ размер аргумента;
		◦ каждое слово аргумента(по одному в строке);


	• Мы проверим вашу функцию с помощью нашего ft_param_to_tab(предыдущее упражнение).
	Примите соответствующие меры, чтобы это работало!


   ************************************************************************** */
/* *******************************_V_1.0_************************************ */
/* ************************************************************************** */


#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j])
		{
			ft_putstr(par[i].tab[j++]);
			ft_putchar('\n');
		}
		i++;
	}
}





/* ************************************************************************** */
/* ***********************************_ИЛИ_********************************** */
/* ************************************************************************** */



#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}

void	ft_print_words_tables(char **tab)
{
	while (*tab != ((void *)0))
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}

void				ft_show_tab(t_stock_par *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[i].tab);
		i++;
	}
}





/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


