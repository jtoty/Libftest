# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_compilation.sh                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:19 by jtoty             #+#    #+#              #
#    Updated: 2017/01/23 18:26:20 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

compilation()
{
	if [ -e ${PATH_TEST}/user_exe ]
	then
		rm -f ${PATH_TEST}/user_exe
	fi

	COMPIL_FLAGS="-Wextra -Wall -Werror"
	MAIN_FILE="${PATH_TEST}/tests/$(echo ${part}tions)/$1/main.c"
	COMPIL_ARGS="${COMPIL_FLAGS} ${MAIN_FILE} -L${PATH_LIBFT} -lft -I${PATH_LIBFT}"

	printf "$> clang ${COMPIL_ARGS}\n\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	clang ${COMPIL_ARGS} 2>>${PATH_DEEPTHOUGHT}/deepthought -o user_exe
}

check_compilation()
{
	printf "\033[${COMPIL_COL}G"
	if [ -e ${PATH_TEST}/user_exe ]
	then
		printf "${COLOR_OK}success${DEFAULT}"
		retvalue=1
	else
		printf "${COLOR_FAIL}failure${DEFAULT}"
		retvalue=0
	fi
	return $retvalue
}
