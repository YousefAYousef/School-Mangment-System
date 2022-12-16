
/*******************************************************/
/* Description : Header file for functions prottype     /
/* Author      : Yousef Ali				                /
/* Version     : 0.1v					                /
/* Date        : 12 DEC 2022			                /
/*******************************************************/

#ifndef student_h
#define student_h

#include "STD_types.h"
#include <stdio.h>
#include "stdlib.h"

typedef struct Node
{
	uint32 ID;
	uint8 name[25];
	uint8 phone[25];
	uint8 address[40];
	uint32 score;
	uint32 day;
	uint32 month;
	uint32 year;
	struct Node* next;
}Node;

void InsetData(Node* ptr);
void addNewStudent();
void UpdateStudent();
void ViewAll();
void DeleteStudent();
void RankStudent();
void StudentScore();
void swap(Node* ptr1 , Node* ptr2 );


#endif



