# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 11:26:19 by jtoty             #+#    #+#              #
#    Updated: 2019/11/30 11:26:20 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

copying_files()
{
	if [ -d ${PATH_TEST}/${TMP_TESTS_DIR} ]
	then
		rm -rf ${PATH_TEST}/${TMP_TESTS_DIR}
	fi
	printf "Copying files...\nPlease wait a moment.\n"
	mkdir ${PATH_TEST}/${TMP_TESTS_DIR}
	cp -r ${PATH_LIBFT}/* ${PATH_TEST}/${TMP_TESTS_DIR}
	#find ${PATH_LIBFT} -type f -name "*.[ch]" -print | xargs cp -t ${PATH_TEST}/dirlibft
	find ${PATH_LIBFT} -type f -name "*.[ch]" -exec cp {} ${PATH_TEST}/${TMP_TESTS_DIR}  \;
	PATH_LIBFT=${PATH_TEST}/${TMP_TESTS_DIR}
}

set_makefile_var()
{
	if [ -e ${PATH_LIBFT}/Makefile ]
	then
		MAKEFILE_VAR="Makefile"
	elif [ -e ${PATH_LIBFT}/makefile ]
	then
		MAKEFILE_VAR="makefile"
	else
		MAKEFILE_VAR="missing_makefile"
	fi
}

init_deepthought()
{
	if [ -e ${PATH_DEEPTHOUGHT}/deepthought ]
	then
		rm -f ${PATH_DEEPTHOUGHT}/deepthought
	fi
	text="= Host-specific information "
	printf "${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "\n$> hostname; uname -msr\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	hostname >> ${PATH_DEEPTHOUGHT}/deepthought
	uname -msr >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "$> date\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	date >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "$> gcc --version\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	gcc --version >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "$> clang --version\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	clang --version >> ${PATH_DEEPTHOUGHT}/deepthought
}

rm_files()
{
	if [ -e ${PATH_TEST}/a.out ]
	then
		rm ${PATH_TEST}/a.out
	fi

	if [ -e ${PATH_TEST}/libft.h ]
	then
		rm ${PATH_TEST}/libft.h
	fi

	if [ -e ${PATH_TEST}/main_check_forbidden_function.c ]
	then
		rm ${PATH_TEST}/main_check_forbidden_function.c
	fi

	if [ -d ${PATH_TEST}/${TMP_TESTS_DIR} ]
	then
		rm -rf ${PATH_TEST}/${TMP_TESTS_DIR}
	fi
}
