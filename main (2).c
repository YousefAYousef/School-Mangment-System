/***************************************/
/* Description : Main Function          /
/* Author      : Yousef Ali				/
/* Version     : 0.1v					/
/* Date        : 12 DEC 2022			/
/***************************************/

#include "STD_types.h"
#include "student.h"
#include <stdio.h>
int main()
{
	uint32 choice;
	printf("==================================================================== \n");
	printf("===========================  WELCOME SIR  ========================== \n");
	printf("==================================================================== \n \n \n");

	printf("\t ******************************************** \n");
	printf("\t *********   School Mangment System  ******** \n");
	printf("\t *********         Yousef Ali        ******** \n");
	printf("\t ******************************************** \n \n");
	while (1)
	{
		printf("\t ------------------------------------------------\n");
		printf("\t Choose one of the following options: \n");
		printf("\t To add a New Student to the list     \t Enter '1' \n");
		printf("\t To view all Students in the list     \t Enter '2' \n");
		printf("\t To Delete a student from list        \t Enter '3' \n");
		printf("\t To Update student information        \t Enter '4' \n");
		printf("\t To Rank Students according to grade  \t Enter '5' \n");  
		printf("\t To Edit Student Score                \t Enter '6' \n");
		printf("\t To Exit the school App               \t Enter '7' \n");
		printf("\t ------------------------------------------------\n");

		printf("---> Your choice is:");
		scanf_s("%d", &choice);
		struct Node NewNode;
		switch (choice)
		{
		case 1:
			addNewStudent();
			break;
		case 2:
			ViewAll();
			break;
		case 3:
			DeleteStudent();
			break;
		case 4:
			UpdateStudent();
			break;
		case 5:
			RankStudent();
			break;
		case 6:
			StudentScore();
			break;
		case 7:
			return 0;
			break;
		default:
			printf("You entered wrong input, please try again !");
			break;
		}
	}
}


