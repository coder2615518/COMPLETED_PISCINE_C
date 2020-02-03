# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print_groups.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 11:29:27 by lkinzel           #+#    #+#              #
#    Updated: 2017/07/04 12:07:16 by lkinzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Создадать файл с названием testDay00 и Задать ему требуемые из скриншота свойства: 
_________________________________________________________________________________
1)Создадим файл с названием testDay00 и установим дату; 
# touch testDay00
_________________________________________________________________________________
2)Обьем документадолжен быть 40 byte, запишем в него данные;
# printf "1234567890123456789012345678901234567890" > ./testDay00
ИЛИ ТАК (если отправлять данные через "echo" нужно записать 39 символов беря во внимание что каждый из них "весит" 1 байт и то что автоматически добавляеться плюс один байт в документ) = 40
#  echo "123456789012345678901234567890123456789" >> ./tetsDay00
_________________________________________________________________________________
3)Установим дату; 
# touch -c -t 06012342 testDay00
_________________________________________________________________________________
3)Установим права чтения/записи/выполнения; 
# chmod 455 ./tetsDay00
_________________________________________________________________________________
4)Проверка;
# ls -l ./testDay00
_________________________________________________________________________________
5)Выполнив предыдущие шаги, выполним следующую команду, чтобы создать
файл для отправки: 
# tar -cf testDay00.tar testDay
_________________________________________________________________________________

##################################################################################
Документация.
##################################################################################
Создание Файлов и управление их временем:
	https://itproffi.ru/sozdanie-fajlov-v-linux-komanda-touch/
Установка прав чтения/записи/выполнения:
	https://habr.com/ru/post/469667/
Запись данных в файл:
	https://linux-notes.org/vstavit-tekst-v-fajl-v-unix-linux/
Джокеры:
	https://habr.com/ru/post/99827/
##################################################################################