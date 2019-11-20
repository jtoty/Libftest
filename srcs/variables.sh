# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:27:13 by jtoty             #+#    #+#              #
#    Updated: 2018/06/29 13:28:44 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

###################################################
#                 Part1 functions                 #
###################################################

Part1_func=(
	'ft_atoi.c'		\
	'ft_bzero.c'	\
	'ft_calloc.c'	\
	'ft_isalnum.c'	\
	'ft_isalpha.c'	\
	'ft_isascii.c'	\
	'ft_isdigit.c'	\
	'ft_isprint.c'	\
	'ft_memccpy.c'	\
	'ft_memchr.c'	\
	'ft_memcmp.c'	\
	'ft_memcpy.c'	\
	'ft_memmove.c'	\
	'ft_memset.c'	\
	'ft_strchr.c' 	\
	'ft_strdup.c'	\
	'ft_strlcat.c'	\
	'ft_strlcpy.c'	\
	'ft_strlen.c'	\
	'ft_strncmp.c'	\
	'ft_strnstr.c'	\
	'ft_strrchr.c'	\
	'ft_tolower.c'	\
	'ft_toupper.c'	\
)

Part1_func_authorized=(
	'0'	\
	'0'	\
	'1'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'1'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
)

Part1_func_activation=(
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
)

###################################################
#                 Part2 functions                 #
###################################################

Part2_func=(
	'ft_itoa.c'			\
	'ft_putchar_fd.c'	\
	'ft_putendl_fd.c'	\
	'ft_putnbr_fd.c'	\
	'ft_putstr_fd.c'	\
	'ft_split.c'		\
	'ft_strjoin.c'		\
	'ft_strmapi.c'		\
	'ft_strtrim.c'		\
	'ft_substr.c'		\
)

Part2_func_authorized=(
	'1'	\
	'4'	\
	'4'	\
	'4'	\
	'4'	\
	'3'	\
	'1'	\
	'1'	\
	'1'	\
	'1'	\
)

Part2_func_activation=(
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
)

###################################################
#                 Bonus functions                 #
###################################################

Bonus_func=(
	'ft_lstadd_back.c'	\
	'ft_lstadd_front.c'	\
	'ft_lstclear.c'		\
	'ft_lstdelone.c'	\
	'ft_lstiter.c'		\
	'ft_lstlast.c'		\
	'ft_lstmap.c'		\
	'ft_lstnew.c'		\
	'ft_lstsize.c'		\
)

Bonus_func_authorized=(
	'0'	\
	'0'	\
	'2'	\
	'2'	\
	'0'	\
	'0'	\
	'3'	\
	'3'	\
	'0'	\
)

Bonus_func_activation=(
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
)

###################################################
#              Additional functions               #
###################################################

Additional_func=(
	'ft_isblank.c'			\
	'ft_iscntrl.c'			\
	'ft_isgraph.c'			\
	'ft_islower.c'			\
	'ft_isspace.c'			\
	'ft_isupper.c'			\
	'ft_isxdigit.c'			\
	'ft_itoa_base.c'		\
	'ft_lstadd.c'			\
	'ft_lstdel.c'			\
	'ft_memalloc.c'			\
	'ft_memdel.c'			\
	'ft_putchar.c'			\
	'ft_putendl.c'			\
	'ft_putnbr.c'			\
	'ft_putstr.c'			\
	'ft_str_is_alpha.c'		\
	'ft_str_is_lowercase.c'	\
	'ft_str_is_numeric.c'	\
	'ft_str_is_printable.c'	\
	'ft_str_is_uppercase.c'	\
	'ft_strcapitalize.c'	\
	'ft_strcasecmp.c'		\
	'ft_strcasestr.c'		\
	'ft_strcat.c'			\
	'ft_strclr.c'			\
	'ft_strcmp.c'			\
	'ft_strcpy.c'			\
	'ft_strdel.c'			\
	'ft_strequ.c'			\
	'ft_striter.c'			\
	'ft_striteri.c'			\
	'ft_strlowcase.c'		\
	'ft_strmap.c'			\
	'ft_strncasecmp.c'		\
	'ft_strncat.c'			\
	'ft_strncpy.c'			\
	'ft_strndup.c'			\
	'ft_strnequ.c'			\
	'ft_strnew.c'			\
	'ft_strstr.c'			\
	'ft_strtok.c'			\
	'ft_strupcase.c'		\
)

Additional_func_authorized=(
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'1'	\
	'0'	\
	'2'	\
	'1'	\
	'2'	\
	'4'	\
	'4'	\
	'4'	\
	'4'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'2'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'1'	\
	'0'	\
	'0'	\
	'0'	\
	'1'	\
	'0'	\
	'1'	\
	'0'	\
	'0'	\
	'0'	\
)

Additional_func_activation=(
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
	'0'	\
)

###################################################
#                 Other variables                 #
###################################################

tab_all_part=('Part1_func' 'Part2_func' 'Bonus_func' 'Additional_func')

num_sys_func=('1' '2' '4')
system_func=('void' 'malloc' 'free' 'printf' 'write')

NORME_COL=23
CHEAT_COL=50
COMPIL_COL=38
TEST_COL=67
RESULT_COL=87
TITLE_LENGTH=92
CHAR_LENGTH="-"
CHAR_WIDTH="|"

DIRECTORY=0
OPT_NO_LIBRARY=0
OPT_FULL_MAKEFILE=0
OPT_NO_SEARCH=0
OPT_NO_COLOR=0
OPT_NO_FORBIDDEN=0
OPT_NO_NORMINETTE=0
OPT_NO_UPDATE=0
OPT_NO_PART1=0
OPT_NO_PART2=0
OPT_NO_BONUS=0
OPT_NO_ADDITIONAL=0
ACTIVATE_PART1=0
ACTIVATE_PART2=0
ACTIVATE_BONUS=0
ACTIVATE_ADDITIONAL=0
CHECK_IN_PART1=1
CHECK_IN_PART2=1
CHECK_IN_BONUS=1
CHECK_IN_ADDITIONAL=1
