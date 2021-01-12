#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    activation.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 18:26:19 by jtoty             #+#    #+#              #
#    Updated: 2019/11/30 18:26:20 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Activate functions that will be tested
activate_functions()
{
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
					func_name=${!func_name}
					if [[ -n $(echo ${LIB_CONTENT} | grep -w $(echo ${func_name})) ]]
					then
						(( ${part}_activation[$p]=1 ))
						(( ${opt_part}=0 ))
					fi
					(( p += 1 ))
				done
			fi
		fi
	done
}

# Activate part if opt_no_part is equal to 0
activate_part()
{
	for part in ${tab_all_part[*]}
	do
		opt_part=$(echo OPT_NO_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
		activate_part=$(echo ACTIVATE_${part} | tr '[:lower:]' '[:upper:]' | rev | cut -c 6- | rev)
		if [ ${!opt_part} -eq 0 ]
		then
			(( ${activate_part}=1 ))
		fi
	done
}
