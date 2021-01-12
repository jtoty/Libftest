#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    core.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 11:27:13 by jtoty             #+#    #+#              #
#    Updated: 2019/11/19 13:28:44 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

source ${PATH_TEST}/srcs/variables/functions/part_1.sh
source ${PATH_TEST}/srcs/variables/functions/part_2.sh
source ${PATH_TEST}/srcs/variables/functions/bonus.sh
source ${PATH_TEST}/srcs/variables/functions/additional.sh
source ${PATH_TEST}/srcs/variables/options.sh
source ${PATH_TEST}/srcs/variables/display.sh


###################################################
#                  Core variables                 #
###################################################

tab_all_part=('Part1_func' 'Part2_func' 'Bonus_func' 'Additional_func')

num_sys_func=('1' '2' '4')
system_func=('void' 'malloc' 'free' 'printf' 'write')

TMP_TESTS_DIR="tmp_tests_dir"
