//
// Created by Fonzy on 4/23/2023.
//

#ifndef SANCHOPROJ_INPUT_H
#define SANCHOPROJ_INPUT_H

#include "header.h"

/**
 * Gets user input from the standard input.
 * @param input String to store the input
 * @param max Maximum buffer size
 */
void input(char *input, int max)
{
	fgets(input, max, stdin);

	while (strchr(input, '\n') == NULL)
	{
		scanf("%*[^\n]");   // Discard input until '\n'
		scanf("%*c");       // Discard new line

		printf("Input is too long. Try again: ");
		fgets(input, max, stdin);
	}

	while (strcmp(input, "\n") == 0)
	{
		printf("Please add an input. Try again: ");
		fgets(input, max, stdin);
	}

	input[strcspn(input, "\n")] = 0;
}

/**
 * Gets the input of a user choice under a menu option.
 * @param menuOption String to store the user choice
 * @return User choice as a number data type
 */
unsigned short inputUserChoice(char *menuOption)
{
	input(menuOption, MENU_OPTION_MAX);
	return (unsigned short) strtoul(menuOption, NULL, 10);
}

#endif //SANCHOPROJ_INPUT_H
