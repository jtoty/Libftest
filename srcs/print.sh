# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    print.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 19:26:19 by jtoty             #+#    #+#              #
#    Updated: 2019/11/30 19:26:20 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Print header with the given string in parameter
print_header()
{
	printf "${COLOR_TITLE}"
	printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
	printf "\n${CHAR_WIDTH}\033[$(( (${TITLE_LENGTH} - ${#1}) / 2 ))G${1}\033[${TITLE_LENGTH}G${CHAR_WIDTH}\n"
	printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
	printf "\n${DEFAULT}"
}

print_part_header()
{
	printf "\n${COLOR_PART}$(echo ${part} | cut -d _ -f 1) functions\n\n"
	printf "${COLOR_TITLE}"
	printf "FUNCTION"
	printf "\033[${NORME_COL}GNORME"
	printf "\033[${CHEAT_COL}GFORBIDDEN FUNC."
	printf "\033[${COMPIL_COL}GCOMPIL."
	printf "\033[${TEST_COL}GTESTS"
	printf "\033[${RESULT_COL}GRESULT\n${DEFAULT}"
}

# Print starting tests only if at least one part is activated
print_starting_test()
{
	for part in ${tab_all_part[*]}
	do
		activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
		if [ ${!activate_part} -eq 1 ]
		then
			print_header "STARTING TESTS"
			break
		fi
	done
}

print_footer()
{
	if [ ${ACTIVATE_PART1} -eq 1 ] || [ ${ACTIVATE_PART2} -eq 1 ] || [ ${ACTIVATE_BONUS} -eq 1 ] || [ ${ACTIVATE_ADDITIONAL} -eq 1 ]
	then
		printf "Abort : ${RED}A${DEFAULT} Bus error : ${RED}B${DEFAULT} Segmentation fault : ${RED}S${DEFAULT} Timeout : ${RED}T${DEFAULT} Nothing turned in : ${RED}NTI${DEFAULT}\n"
		printf "\n"
	fi
}

print_deepthought_message_and_clean()
{
	printf "A deepthought file has been generated in ${COLOR_DEEPTHOUGHT_PATH}${PATH_DEEPTHOUGHT}\n\n${DEFAULT}"
	rm_files
	make --no-print-directory -C ${PATH_LIBFT} clean > /dev/null
}
