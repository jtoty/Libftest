#!/bin/bash

check_makefile()
{
	printf "Makefile"
	#if [ -e ${PATH_LIBFT}/Makefile ] || [ -e ${PATH_LIBFT}/makefile ]
	if [ -e ${PATH_LIBFT}/${MAKEFILE_VAR} ]
	then
		printf "\033[15G-Wall"
		printf "\033[25G-Wextra"
		printf "\033[35G-Werror\n"
		printf "${COLOR_OK}found${DEFAULT}"
		printf "\033[15G"
		if [ -z "$(grep -w '\-Wall' ${PATH_LIBFT}/${MAKEFILE_VAR})" ]
		then
			printf "${COLOR_FAIL}missing${DEFAULT}"
		else
			printf "${COLOR_OK}ok${DEFAULT}"
		fi
		printf "\033[25G"
		if [ -z "$(grep -w '\-Wextra' ${PATH_LIBFT}/${MAKEFILE_VAR})" ]
		then
			printf "${COLOR_FAIL}missing${DEFAULT}"
		else
			printf "${COLOR_OK}ok${DEFAULT}"
		fi
		printf "\033[35G"
		if [ -z "$(grep -w '\-Werror' ${PATH_LIBFT}/${MAKEFILE_VAR})" ]
		then
			printf "${COLOR_FAIL}missing\n${DEFAULT}"
		else
			printf "${COLOR_OK}ok\n${DEFAULT}"
		fi
	else
		printf "${COLOR_FAIL}\nnot found${DEFAULT}\n"
	fi
}

check_auteur()
{
	printf "\nAuthor file"
	if [ -e ${PATH_LIBFT}/auteur ] || [ -e ${PATH_LIBFT}/author ]
	then
		if [ -e ${PATH_LIBFT}/auteur ]
		then
			AUTHOR_VAR="auteur"
		else
			AUTHOR_VAR="author"
		fi
		printf "\033[15GCheck file content\n"
		printf "${COLOR_OK}found${DEFAULT}"
		if [ $(wc -l ${PATH_LIBFT}/${AUTHOR_VAR} | tr -d ' ' | head -c 1) -gt 1 ]
		then
			printf "\033[15G${COLOR_FAIL}Too many lines in your file\n${DEFAULT}"
		elif [ $(wc -c ${PATH_LIBFT}/${AUTHOR_VAR} | tr -d ' ' | head -c 1) -eq 0 ]
		then
			printf "\033[15G${COLOR_FAIL}Empty file\n${DEFAULT}"
		elif [ "$(cat -e ${PATH_LIBFT}/${AUTHOR_VAR} | grep '\$')" != "" ]
		then
			if [ "$(norminette ${PATH_LIBFT}/${AUTHOR_VAR} 2>&1 | grep command)" != "" ]
			then
				printf "\033[15G${COLOR_OK}$(cat ${PATH_LIBFT}/${AUTHOR_VAR})${DEFAULT}\n"
			else
				if [ "$(cat ${PATH_LIBFT}/${AUTHOR_VAR})" != "$(echo $(whoami))" ]
				then
					printf "\033[15G${COLOR_FAIL}Wrong login\n${DEFAULT}"
				else
					printf "\033[15G${COLOR_OK}$(cat ${PATH_LIBFT}/${AUTHOR_VAR})${DEFAULT}\n"
				fi
			fi
		else
			printf "\033[15G${COLOR_FAIL}'\\\n' missing${DEFAULT}\n"
		fi
	else
		printf "${COLOR_FAIL}\nnot found${DEFAULT}\n"
	fi
	printf "\n"
}

check_header()
{
	printf "\nHeader file"
	if [ -e ${PATH_LIBFT}/libft.h ]
	then
		printf "\033[15GNorme\n"
		printf "${COLOR_OK}found${DEFAULT}"
		if [ ${OPT_NO_NORMINETTE} -eq 1 ]
		then
			printf "${DEFAULT}\033[15Gdisabled\n"
		else
			text="= libft.h"
			printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "$> norminette libft.h | grep -E '(Error|Warning)'\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			NORME_VAR=$(norminette ${PATH_LIBFT}/libft.h 2>&1)
			if echo "$NORME_VAR" | grep -q command
			then
				printf "${COLOR_WARNING}\033[15Gnot found${DEFAULT}\n"
				printf "norminette : command not found\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			elif echo "$NORME_VAR" | grep -qE '(Error|Warning)'
			then
				printf "${COLOR_FAIL}\033[15Gcheck failed${DEFAULT}\n"
				echo "$NORME_VAR" | grep -E '(Error|Warning)' >> ${PATH_DEEPTHOUGHT}/deepthought
				printf "Norme check failed\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			else
				printf "${COLOR_OK}\033[15Gok${DEFAULT}\n"
			fi
		fi
	else
		printf "${COLOR_FAIL}\nnot found${DEFAULT}\n"
	fi
	printf "\n"
}

func_check_file()
{
	print_header "CHECKING FILES"
	check_makefile
	# check_auteur
	check_header
}

# Check if my_config.sh file exists, otherwise create it
check_my_config_file()
{
	if [ ! -e ${PATH_TEST}/my_config.sh ]
	then
		printf "${BOLD}my_config.sh${DEFAULT} file is not found.\n"
		printf "Creating file...\n"
		if [ -e ${PATH_TEST}/srcs/config_template.sh ]
		then
			cp ${PATH_TEST}/srcs/config_template.sh ${PATH_TEST}/my_config.sh
			printf "File created with success in ${BOLD}${PURPLE}${PATH_TEST}\n${DEFAULT}"
			printf "${RED}${UNDERLINE}Edit my_config.sh file${DEFAULT} with the path of your libft project and launch script.\n"
		else
			printf "Can't create my_config.sh file, try to update or clone again the repository and retry.\n"
			exit
		fi
		exit
	fi
}


check_turned_in_functions()
{
	text="= $1 "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	if [[ -n $(echo ${LIB_CONTENT} | grep -w $(echo ${1})) ]]
	then
		retvalue=1
		return "$retvalue"
	else
		printf "\033[${NORME_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${CHEAT_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${COMPIL_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${TEST_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}"
		printf "\033[${RESULT_COL}G"
		printf "${COLOR_FAIL}NTI${DEFAULT}\n"
		printf "Nothing turned in\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		retvalue=0
		return "$retvalue"
	fi
}
