//
// Created by Fonzy on 4/23/2023.
//

#ifndef SANCHOPROJ_LOGIN_H
#define SANCHOPROJ_LOGIN_H

/**
 * Log-in function
 * @param students Student array
 * @param passwords Password array
 * @param username Inputted username (Full name)
 * @param password Inputted password
 * @return Index of student if login successful, else returns -1
 */
int logIn(char students[STUDENTS_MAX][STUDENT_NAME_MAX],
          char passwords[STUDENTS_MAX][PASSWORD_MAX],
          char *username, char *password)
{
	int userIndex = -1;
	for (int i = 0; i < STUDENTS_MAX; i++)
	{
		if (strcmp(username, students[i]) == 0)
		{
			userIndex = i;
		}
	}

	if (userIndex == -1)
	{
		return -1;
	}

	if (strcmp(password, passwords[userIndex]) == 0)
	{
		return userIndex;
	}

	return -1;
}


#endif //SANCHOPROJ_LOGIN_H
