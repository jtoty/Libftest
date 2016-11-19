#!/bin/bash

display_help()
{
	printf "USAGE\n"
	printf "\tbash grademe.sh [options]\n\n"

	printf "OPTIONS\n"

	printf "\t-h, --help\n"
	printf "\t\tDisplay help and exit\n\n"

	printf "\t-c, --no-color\n"
	printf "\t\tDisable color\n\n"

	printf "\t-s, --no-search\n"
	printf "\t\tDisable searching Makefile, author and header file\n\n"

	printf "\t-q, --quick-lib\n"
	printf "\t\tWhen compiling library, do only 'make re'\n\n"

	printf "\t-l, --no-library\n"
	printf "\t\tDisable compiling library\n\n"

	printf "\t-f, --no-forbidden\n"
	printf "\t\tDisable checking forbidden functions\n\n"

	printf "\t-n, --no-norminette\n"
	printf "\t\tDisable norminette\n\n"

	printf "\t-u, --no-update\n"
	printf "\t\tDisable checking updates at launch\n\n"

	printf "\t-p1, --no-part1\n"
	printf "\t\tDisable part 1 tests\n\n"

	printf "\t-p2, --no-part2\n"
	printf "\t\tDisable part 2 tests\n\n"

	printf "\t-b, --no-bonus\n"
	printf "\t\tDisable bonus part tests\n\n"

	printf "\t-a, --no-additional\n"
	printf "\t\tDisable additional part tests\n\n"

	printf "\tft_function-name\n"
	printf "\t\tTest only this function\n\n"

	printf "\tAdd successively all options you want, in the order you want.\n"
	printf "\tFor example :\n"
	printf "\t\tbash grademe.sh ft_atoi -n ft_strlen\n"
	printf "\t\tbash grademe.sh -b -p2\n\n"

	printf "NOTE\n"
	printf "\tIf you want to do fast tests, you sould use '-n', '-f' and '-q' options"
}
