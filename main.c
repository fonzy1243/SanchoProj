#include "header.h"

// student string format:
// LAST, FIRST MIDDLE INITIAL

// course string format:
// COURSE TITLE, SECTION

int main()
{
	char students[STUDENTS_MAX][STUDENT_NAME_MAX];

	strcpy(students[0], "Dela Cruz, Juan Del Rosario");
	strcpy(students[1], "Sampedro, Gabriel");
	strcpy(students[2], "Catooby, Rafael");
	strcpy(students[3], "GIAN YUMMY");
	strcpy(students[4], "Peradilla, M'nell");
	strcpy(students[5], "Queue, Jems");

	char passwords[STUDENTS_MAX][PASSWORD_MAX];

	strcpy(passwords[0], "genericPassword");
	strcpy(passwords[1], "MIA");
	strcpy(passwords[2], "curves");
	strcpy(passwords[3], "kahootPremium");
	strcpy(passwords[4], "muhNell");
	strcpy(passwords[5], "ILOVEDSTRU");     // do not believe this

	char courses[10][COURSES_TITLE_MAX];

	strcpy(courses[0], "LBOEC2A, EC1");
	strcpy(courses[1], "TITLE, CLASS");
	// ... add more //

	/*
	 * Array to store the courses of each student
	 * Maximum of 8 courses per student, you can change it under COURSES_MAX
	 */
	char studentCourses[STUDENTS_MAX][COURSES_MAX][COURSES_TITLE_MAX];

	bool exit = false;
	unsigned short userChoice;

	while (!exit)
	{
		char menuOption[MENU_OPTION_MAX];
		int userIndex;

		printf("[1] Student Profile\n"
			   "[2] Course Enrollment\n"
			   "[3] Assessment of Fees\n");
		userChoice = inputUserChoice(menuOption);

		while (userChoice < 1 || userChoice > 3)
		{
			printf("Invalid input. Please try again: ");
			userChoice = inputUserChoice(menuOption);
		}

		char username[STUDENT_NAME_MAX];
		char password[PASSWORD_MAX];

		switch (userChoice)
		{
			case 1:
				printf("Log-in Menu\n");

				printf("Enter username: ");
				input(username, STUDENT_NAME_MAX);

				printf("Enter password: ");
				input(password, PASSWORD_MAX);

				userIndex = logIn(students, passwords, username, password);

				if (userIndex != -1)
				{
					printf("Full Name: %s\n", students[userIndex]);
					// Assume each student is taking BS CPE.
					printf("Degree Program: %s\n", DEGREE_PROGRAM);
					// Assume each student is from Imus, Cavite
					printf("Permanent Address: %s\n", STUDENT_ADDRESS);
					// Assume each student has the phone # "123456789"
					printf("Permanent Telephone No.: %s\n", STUDENT_PHONE);
					// Also assume each student is dorming
					printf("Present Address: %s\n", PRESENT_ADDRESS);
				}
				else
				{
					printf("Invalid username or password.\n");
				}

				break;
			case 2:
				break;
			case 3:
				exit = true;
				break;
			default:
				// Do nothing
				break;
		}
	}

	return 0;
}
