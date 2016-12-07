#!/bin/bash

display_help()
{
	printf "USAGE\n"
	printf "\tbash grademe.sh [options]\n\n"

	printf "OPTIONS\n"

	printf "\t-h, --help\n"
	printf "\t\tDisplay help and exit\n\n"

	printf "\t-c\n"
	printf "\t\tDisable color\n\n"

	printf "\t-s\n"
	printf "\t\tDisable searching Makefile, author and header file\n\n"

	printf "\t-q\n"
	printf "\t\tWhen compiling library, do only 'make re'\n\n"

	printf "\t-l\n"
	printf "\t\tDisable compiling library\n\n"

	printf "\t-f\n"
	printf "\t\tDisable checking forbidden functions\n\n"

	printf "\t-n\n"
	printf "\t\tDisable norminette\n\n"

	printf "\t-u\n"
	printf "\t\tDisable checking updates at launch\n\n"

	printf "\t-p1\n"
	printf "\t\tDisable part 1 tests\n\n"

	printf "\t-p2\n"
	printf "\t\tDisable part 2 tests\n\n"

	printf "\t-b\n"
	printf "\t\tDisable bonus part tests\n\n"

	printf "\t-a\n"
	printf "\t\tDisable additional part tests\n\n"

	printf "\t-op1\n"
	printf "\t\tDo only part 1 tests\n\n"

	printf "\t-op2\n"
	printf "\t\tDo only part 2 tests\n\n"

	printf "\t-ob\n"
	printf "\t\tDo only bonus part tests\n\n"

	printf "\t-oa\n"
	printf "\t\tDo additional part tests\n\n"

	printf "\tft_function-name\n"
	printf "\t\tTest only this function\n\n"

	printf "\tAdd successively all options you want, in the order you want.\n"
	printf "\tFor example :\n"
	printf "\t\tbash grademe.sh ft_atoi -n ft_strlen\n"
	printf "\t\tbash grademe.sh -b -p2\n\n"

	printf "NOTE\n"
	printf "\tIf you want to do fast tests, you sould use '-n', '-f' and '-q' options"
}
