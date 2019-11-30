# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grademe.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:01 by jtoty             #+#    #+#              #
#    Updated: 2017/02/28 11:42:36 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

#PATH_TEST=$(dirname $(readlink -f $0))
PATH_TEST="$(cd "$(dirname "$0")" && pwd -P)"

#exec 6>&2 2>/dev/null
exec 2> /dev/null

source ${PATH_TEST}/srcs/variables/core.sh

for arg in ${@}
do
	case "${arg}" in
		"--help")			man ${PATH_TEST}/srcs/help.1
							exit ;;
		"-h")				man ${PATH_TEST}/srcs/help.1
							exit ;;
		"-s")				OPT_NO_SEARCH=1 ;;
		"-m")				OPT_FULL_MAKEFILE=1 ;;
		"-l")				OPT_NO_LIBRARY=1 ;;
		"-c")				OPT_NO_COLOR=1 ;;
		"-f")				OPT_NO_FORBIDDEN=1 ;;
		"-n")				OPT_NO_NORMINETTE=1 ;;
		"-u")				OPT_NO_UPDATE=1 ;;
		"-op1")				OPT_NO_PART2=1
							OPT_NO_BONUS=1
							OPT_NO_ADDITIONAL=1
							CHECK_IN_PART1=0
							CHECK_IN_PART2=0
							CHECK_IN_BONUS=0
							CHECK_IN_ADDITIONAL=0 ;;
		"-op2")				OPT_NO_PART1=1
							OPT_NO_BONUS=1
							OPT_NO_ADDITIONAL=1
							CHECK_IN_PART2=0
							CHECK_IN_PART1=0
							CHECK_IN_BONUS=0
							CHECK_IN_ADDITIONAL=0 ;;
		"-ob")				OPT_NO_PART1=1
							OPT_NO_PART2=1
							OPT_NO_ADDITIONAL=1
							CHECK_IN_BONUS=0
							CHECK_IN_PART2=0
							CHECK_IN_PART1=0
							CHECK_IN_ADDITIONAL=0 ;;
		"-oa")				OPT_NO_PART1=1
							OPT_NO_PART2=1
							OPT_NO_BONUS=1
							CHECK_IN_ADDITIONAL=0
							CHECK_IN_BONUS=0
							CHECK_IN_PART2=0
							CHECK_IN_PART1=0 ;;
		"-p1")				OPT_NO_PART1=1
							CHECK_IN_PART1=0 ;;
		"-p2")				OPT_NO_PART2=1
							CHECK_IN_PART2=0 ;;
		"-b")				OPT_NO_BONUS=1
							CHECK_IN_BONUS=0 ;;
		"-a")				OPT_NO_ADDITIONAL=1
							CHECK_IN_ADDITIONAL=0 ;;
		*ft_*)	for part in ${tab_all_part[*]}
				do
					check_part=$(echo CHECK_IN_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
					if [ ${!check_part} -eq 1 ]
					then
						#opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
						p=0
						activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
						tab_part=$(echo ${part}[*])
						nb_func=$(echo ${!tab_part} | wc -w)
						while (( p < ${nb_func} ))
						do
							func_name=$(echo ${part}[$p])
							if [ "$(echo ${arg} | grep -ow $(echo ${!func_name} | cut -d . -f 1))" != "" ]
							then
								(( ${part}_activation[$p]=1 ))
								#(( ${opt_part}=1 ))
								#####################
								OPT_NO_PART1=1
								OPT_NO_PART2=1
								OPT_NO_BONUS=1
								OPT_NO_ADDITIONAL=1
								#############################
								(( ${activate_part}=1 ))
								break
							fi
							(( p += 1 ))
						done
					fi
				done ;;
	esac
done

source ${PATH_TEST}/srcs/variables/colors.sh
source ${PATH_TEST}/srcs/check_forbidden_function.sh
source ${PATH_TEST}/srcs/check_compilation.sh
source ${PATH_TEST}/srcs/check_file.sh
source ${PATH_TEST}/srcs/check_norme.sh
source ${PATH_TEST}/srcs/compil_lib.sh
source ${PATH_TEST}/srcs/diff_test.sh
source ${PATH_TEST}/srcs/test_function.sh
source ${PATH_TEST}/srcs/check_update.sh
source ${PATH_TEST}/srcs/activation.sh
source ${PATH_TEST}/srcs/print.sh

cd ${PATH_TEST}

if [ ${OPT_NO_UPDATE} -eq 0 ]
then
	func_check_update
fi


check_my_config_file
source ${PATH_TEST}/my_config.sh

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

copying_files



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

clear
init_deepthought

if [ -e ${PATH_LIBFT}/Makefile ]
then
	MAKEFILE_VAR="Makefile"
elif [ -e ${PATH_LIBFT}/makefile ]
then
	MAKEFILE_VAR="makefile"
else
	MAKEFILE_VAR="missing_makefile"
fi

if [ ${OPT_NO_SEARCH} -eq 0 ]
then
	func_check_file
fi
if [ ${OPT_NO_LIBRARY} -eq 0 ]
then
	func_compil_lib
fi


if [ -e ${PATH_LIBFT}/libft.a ]
then
	LIB_CONTENT=$(nm --defined-only ${PATH_LIBFT}/libft.a)
else
	print_header "STARTING TESTS"
	printf "\n${RED}Tests can't be started. Missing ${BOLD}${PURPLE}libft.a${DEFAULT}${RED} file${DEFAULT}\n\n"
	printf "A deepthought file has been generated in ${COLOR_DEEPTHOUGHT_PATH}${PATH_DEEPTHOUGHT}\n\n${DEFAULT}"
	make --no-print-directory -C ${PATH_LIBFT} clean > /dev/null
	exit;
fi


activate_functions
activate_part

print_starting_test

if [ -e ${PATH_LIBFT}/libft.h ]
then
	cp ${PATH_LIBFT}/libft.h ${PATH_TEST}
fi

printf "#include \"libft.h\"\n\nint\tmain(void)\n{\n\treturn (0);\n}" > ${PATH_TEST}/main_check_forbidden_function.c

launch_tests
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
rm_files

print_footer
printf "A deepthought file has been generated in ${COLOR_DEEPTHOUGHT_PATH}${PATH_DEEPTHOUGHT}\n\n${DEFAULT}"
make --no-print-directory -C ${PATH_LIBFT} clean > /dev/null
