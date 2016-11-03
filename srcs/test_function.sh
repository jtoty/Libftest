#!/bin/bash

check_turned_in_file()
{
	text="= $1 "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	if [ -e ${PATH_LIBFT}/$1 ]
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
		printf "= Nothing turned in\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		retvalue=0
		return "$retvalue"
	fi
}


test_function()
{
	printf "\n${COLOR_PART}$(echo ${part} | cut -d _ -f 1) functions\n\n"
	printf "${COLOR_TITLE}"
	printf "FUNCTION"
	printf "\033[${NORME_COL}GNORME"
	printf "\033[${CHEAT_COL}GCHEAT"
	printf "\033[${COMPIL_COL}GCOMPILATION"
	printf "\033[${TEST_COL}GTESTS"
	printf "\033[${RESULT_COL}GRESULT\n${DEFAULT}"

	let	"i=0"
	let	"success=0"
	let	"total=0"
	for function in ${!1}
	do
		if [ $(( ${part}_activation[$i] )) -eq 1 ]
		then
		let	"total += 1"
			printf "${COLOR_FUNC}"
			func_name=$(echo "$function" | cut -d . -f 1)
			printf "${func_name}"
			check_turned_in_file $function
			file=$?
			if [ $file -eq 1 ]
			then
				result=1
				if [ ${OPT_NO_NORMINETTE} -eq 0 ]
				then
					check_norme $function
					check=$?
					if [ $check -eq 0 ]
					then
						result=0
					fi
				else
					printf "\033[${NORME_COL}G${DEFAULT}disabled"
				fi
				if [ ${OPT_NO_FORBIDDEN} -eq 0 ]
				then
					check_cheating $function $(( ${part}_forbidden[$i] ))
					check=$?
					if [ $check -eq 1 ]
					then
						result=0
					fi
				else
					printf "\033[${CHEAT_COL}G${DEFAULT}disabled"
				fi
				compilation $function
				check_compilation
				check=$?
				if [ $check -eq 1 ]
				then
					diff_test $function
				else
					printf "\033[${TEST_COL}G"
					printf "${COLOR_FAIL}compilation failed${DEFAULT}"
					result=0
				fi
				check=$?
				if [ $check -eq 0 ]
				then
					result=0
				fi
				printf "\033[${RESULT_COL}G"
				if [ $result -eq 0 ]
				then
					printf "${COLOR_FAIL}KO\n${DEFAULT}"
				else
					printf "${COLOR_OK}OK\n${DEFAULT}"
					let "success += 1"
				fi
			fi
			if [ -e ${PATH_TEST}/user_exe ]
			then
				rm -f ${PATH_TEST}/user_exe
			fi
		fi
		let	"i += 1"
	done
	printf "\n${COLOR_TOTAL}Total : ${success}/${total}${DEFAULT}\n"
}
