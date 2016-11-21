#!/bin/bash

print_cheat()
{
	if grep -qw "${system_func[$2]}" ${PATH_LIBFT}/$1
	then
		if [ $3 -eq 0 ]
		then
			printf "${COLOR_FAIL}not clean${DEFAULT}"
			printf "Cheat detected\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		fi
		grep -wn "${system_func[$2]}" ${PATH_LIBFT}/$1 | awk '{print "Line " $0}' >> ${PATH_DEEPTHOUGHT}/deepthought
		if [ $2 -eq 3 ]
		then
			printf "\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		fi
		retvalue=1
	else
		retvalue=0
	fi
	return "$retvalue"
}

check_cheating()
{
	printf "\033[${CHEAT_COL}G"
	param2=$2
	cheat=0
	while [ $param2 -gt 0 ]
	do
		if [ $param2 -ge ${num_sys_func[2]} ]
		then
			print_cheat $1 4 $cheat
			retvalue=$?
			if [ $cheat -eq 0 ]
			then
				cheat=$retvalue
			fi
			param2=$(($param2 - ${num_sys_func[2]}))
		elif [ $param2 -ge ${num_sys_func[1]} ]
		then
			print_cheat $1 2 $cheat
			retvalue=$?
			if [ $cheat -eq 0 ]
			then
				cheat=$retvalue
			fi
			param2=$(($param2 - ${num_sys_func[1]}))
		elif [ $param2 -ge ${num_sys_func[0]} ]
		then
			print_cheat $1 1 $cheat
			retvalue=$?
			if [ $cheat -eq 0 ]
			then
				cheat=$retvalue
			fi
			param2=$(($param2 - ${num_sys_func[0]}))
		fi
	done
	print_cheat $1 3 $cheat
	retvalue=$?
	if [ $cheat -eq 0 ]
	then
		cheat=$retvalue
	fi
	if [ $cheat == 0 ]
	then
		printf "${COLOR_OK}clean${DEFAULT}"
	fi
	return $cheat
}
