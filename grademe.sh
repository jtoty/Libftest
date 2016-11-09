#!/bin/bash

#PATH_TEST=$(dirname $(readlink -f $0))
PATH_TEST="$(cd "$(dirname "$0")" && pwd -P)"

#exec 6>&2 2>/dev/null
exec 2> /dev/null

source ${PATH_TEST}/srcs/variables.sh


for arg in ${@}
do
	case "${arg}" in
		"--no-search")		OPT_NO_SEARCH=1 ;;
		"-s")				OPT_NO_SEARCH=1 ;;
		"--quick-lib")		OPT_QUICK_LIB=1 ;;
		"-q")				OPT_QUICK_LIB=1 ;;
		"--no-library")		OPT_NO_LIBRARY=1 ;;
		"-l")				OPT_NO_LIBRARY=1 ;;
		"--no-color")		OPT_NO_COLOR=1 ;;
		"-c")				OPT_NO_COLOR=1 ;;
		"--no-forbideen")	OPT_NO_FORBIDDEN=1 ;;
		"-f")				OPT_NO_FORBIDDEN=1 ;;
		"--no-norminette")	OPT_NO_NORMINETTE=1 ;;
		"-n")				OPT_NO_NORMINETTE=1 ;;
		"--no-update")		OPT_NO_UPDATE=1 ;;
		"-u")				OPT_NO_UPDATE=1 ;;
		"--no-part1")		OPT_NO_PART1=1
							CHECK_IN_PART1=0 ;;
		"-p1")				OPT_NO_PART1=1
							CHECK_IN_PART1=0 ;;
		"--no-part2")		OPT_NO_PART2=1
							CHECK_IN_PART2=0 ;;
		"-p2")				OPT_NO_PART2=1
							CHECK_IN_PART2=0 ;;
		"--no-bonus")		OPT_NO_BONUS=1
							CHECK_IN_BONUS=0 ;;
		"-b")				OPT_NO_BONUS=1
							CHECK_IN_BONUS=0 ;;
		"--no-additional")	OPT_NO_ADDITIONAL=1
							CHECK_IN_ADDITIONAL=0 ;;
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

source ${PATH_TEST}/srcs/colors.sh
source ${PATH_TEST}/srcs/check_cheat.sh
source ${PATH_TEST}/srcs/check_compilation.sh
source ${PATH_TEST}/srcs/check_file.sh
source ${PATH_TEST}/srcs/check_norme.sh
source ${PATH_TEST}/srcs/compil_lib.sh
source ${PATH_TEST}/srcs/diff_test.sh
source ${PATH_TEST}/srcs/test_function.sh
source ${PATH_TEST}/srcs/check_update.sh

cd ${PATH_TEST}

if [ ${OPT_NO_UPDATE} -eq 0 ]
then
	func_check_update
fi

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

source ${PATH_TEST}/my_config.sh

for part in ${tab_all_part[*]}
do
	opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!opt_part} -eq 0 ]
	then
		p=0
		tab_part=$(echo ${part}[*])
		nb_func=$(echo ${!tab_part} | wc -w)
		if [ ${part} != "Additional_func" ]
		then
			while (( p < ${nb_func} ))
			do
				(( ${part}_activation[$p]=1 ))
				(( p += 1 ))
			done
		else
			(( ${opt_part}=1 ))
			while (( p < ${nb_func} ))
			do
				func_name=$(echo ${part}[$p])
				if [ -e ${PATH_LIBFT}/${!func_name} ]
				then
					(( ${part}_activation[$p]=1 ))
					(( ${opt_part}=0 ))
				fi
				(( p += 1 ))
			done
		fi
	fi
done

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

printf "${COLOR_TITLE}Credits : achauvea, jmichaud, jtoty${DEFAULT}\n"
if [ ${OPT_NO_SEARCH} -eq 0 ]
then
	func_check_file
fi
if [ ${OPT_NO_LIBRARY} -eq 0 ]
then
	func_compil_lib
fi

for part in ${tab_all_part[*]}
do
	opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!opt_part} -eq 0 ]
	then
		(( ${activate_part}=1 ))
	fi
done

for part in ${tab_all_part[*]}
do
	activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!activate_part} -eq 1 ]
	then
		text="STARTING TESTS"
		printf "${COLOR_TITLE}"
		printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
		printf "\n${CHAR_WIDTH}\033[$(( (${TITLE_LENGTH} - ${#text}) / 2 ))G${text}\033[${TITLE_LENGTH}G${CHAR_WIDTH}\n"
		printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
		printf "\n${DEFAULT}"
		break
	fi
done

if [ -e ${PATH_LIBFT}/libft.h ]
then
	cp ${PATH_LIBFT}/libft.h ${PATH_TEST}
fi

for part in ${tab_all_part[*]}
do
	activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
	if [ ${!activate_part} -eq 1 ]
	then
		test_function $(echo ${part}[*])
	fi
done

if [ -e ${PATH_TEST}/libft.h ]
then
	rm ${PATH_TEST}/libft.h
fi
if [ ${ACTIVATE_PART1} -eq 1 ] || [ ${ACTIVATE_PART2} -eq 1 ] || [ ${ACTIVATE_BONUS} -eq 1 ] | [ ${ACTIVATE_ADDITIONAL} -eq 1 ]
then
	printf "\n"
fi
printf "A deepthought file has been generated in ${COLOR_DEEPTHOUGHT_PATH}${PATH_DEEPTHOUGHT}\n\n${DEFAULT}"
make --no-print-directory -C ${PATH_LIBFT} clean > /dev/null
