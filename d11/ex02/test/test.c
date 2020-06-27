/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void	ft_putchar(char c)				/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void	ft_putstr(char *str)			/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/* ************************************************************************** */

void	ft_put_struct(t_list **tab_list)	/* Функция печатает данные одного из элементов каждого экземпляра связаных между собой вглубь экземпляров */
{
	ft_putstr((char *)((*tab_list)->data));	/* Приводим получаемый адрес к типу 'char' и отравляем на печать. Так мы печатаем данные одного из элеменетов 
											 * первого экземпляра структуры */
	while((*tab_list)->next)				/* Запускаем цикл, который пройдется вглубь связаных между собой экземпляров структур и напечатает данные одного из 
											 * элеменетов каждого экземпляра связаных между собой структрур */
	{
		ft_putstr((char *)((*tab_list)->next->data));/* Приводим получаемый адрес к типу 'char' и отравляем на печать. Так мы печатаем данные одного из элеменетов 
													  * текущего экземпляра структуры */
		(*tab_list)->next = (*tab_list)->next->next; /* Для того чтобы дойти до самого последнего эземпляра структуры типа 't_list' мы cохраняем в указателе
													  * предыдущей структуры типа t_list адрес хранящийся в одном из элементов(указатель структуры типа t_list)
													  * текущего экземпляра структуры типа t_list */

	/*	Еще несколько способов чтобы получить данные экземпляра структуры на которую ссылается адрес из указателя текущей структуры
		ft_putstr((char *)((*tab_list).next->data));
		ft_putstr((char *)((*(**tab_list).next).data));

		ft_putstr((char *)((*tab_list[0]).next->data));
		ft_putstr((char *)((*(*tab_list[0]).next).data));

		ft_putstr((char *)(tab_list[0][0].next->data));
		ft_putstr((char *)(tab_list[0][0].next[0].data));

		ft_putstr((char *)((*tab_list)->next->data));
		ft_putstr((char *)(tab_list[0]->next->data));
	*/
	}
}

/* ************************************************************************** */


t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адресс из указателя data в первый элемент экземпляра
										 * структуры, нулевой адрес во второй элемент экземпляра структуры. И в конце функция его возвращает адрес созданого экземпляра 
										 * структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адресс выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адресс принятого в аргументах элемента 
										 * неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}


void	ft_list_push_front(t_list **begin_list, void *data)	/* Функция, которая в первом экземпляре структуры, среди связаных между собой последовательно 
									 * экземпляров структур, создаст экземпляр структуры типа t_list и сохранит его адрес в элементе(указатель на
									 * экземпляр структуры типа 't_list') первого экземпляра структуры(который является указателем на экземпляр
									 * структуры типа t_list) */
{
	t_list	*list;					/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	if (*begin_list)				/* Проверяем хранится ли в 'указателе на указатель' принятом в рагументах функции адресс 'экземпляра структуры типа t_list' */
	{
		list = ft_create_elem(data);/* Создадим экземпляр структуры типа t_list, заполняет его данными из указателя data */
		list->next = *begin_list;	/* Адресс экземпляра структуры типа t_list мы сохраняем в одном из элементов(указателе на экземпляр структуры типа 't_list') 
									 * созданного нами экземпляра структуры чтобы сдвинуть позицию текущей структуры среди связаных между собой последовательно 
									 * экземпляров структур, на второе место */
		*begin_list = list;			/* В указателе на экземпляр структуры типа 't_list' сохраняем созданый нами новый экземпляр структуры типа 't_list' */
	}
	else									/* Если мы дошли до сюда значит в 'указателе' принятом в рагументах функции не хранится адрес экземпляра структуры типы 't_list' */
		*begin_list = ft_create_elem(data);	/* Тогда, мы просто создаем экземпляр структуры типа 't_list' и сохраняем его адресс в указателе на экземпляр структуры типа 't_list' */
}



int			main(void)
{
	t_list	**tab_list;						/* Обьявим указатель на указатель структуры типа t_list для хранения адреса указателя хранящего адресс экземпляра 
											 * структуры типа t_list */
	t_list	*list;							/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	list = ft_create_elem("Bro ");			/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
											 * данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list,
											 * который мы сохраним в указателе на экземпляр структуры типа t_list */

	list->next = ft_create_elem("Hey ");	/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
											 * данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list 
											 * И сохранит этот адресс в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
											 * текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	tab_list = &list;						/* Сохраняем адресс указателя на экземпляр структуры типа t_list  в указателе на указатель структуры типа t_list */


	ft_list_push_front(tab_list, "Hello");	/* Запускаем функцию, которая в первом экземпляре структуры, среди связаных между собой последовательно 
											 * экземпляров структур, создаст экземпляр структуры типа t_list и сохранит его адрес в элементе(указатель на
											 * экземпляр структуры типа 't_list') последнего экземпляра структуры(который является указателем на экземпляр
											 * структуры типа t_list) */


	ft_put_struct(tab_list);				/* Чтобы проверить что у нас получислось мы напечатем данные одного из элементов каждого экземпляра связаных между
											 * собой вглубь экземпляров */
	ft_putchar('\n');						/* Печатаем символ переноса строки для кореектного отображения вывода */

	free(list);								/* Освобождаем Память, которую мы выделили для хранения экземпляра структуры */


	return (0);								/* Завершаем функцию и возвращаем ноль */
}