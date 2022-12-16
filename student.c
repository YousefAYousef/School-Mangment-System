/*******************************************/
/* Description : Functions implemintaion    /
/* Author      : Yousef Ali				    /
/* Version     : 0.1v					    /
/* Date        : 12 DEC 2022			    /
/*******************************************/
#define _CRT_SECURE_NO_WARNINGS 
#include "Student.h"
#include "STD_types.h"
#include<string.h>
Node* head = NULL_PTR;
Node* current = NULL_PTR;
Node* prev = NULL_PTR;

void swap(Node* ptr1, Node* ptr2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->ID = ptr1->ID;
	ptr1->ID = ptr2->ID;
	ptr2->ID = temp->ID;

	strcpy(temp->phone , ptr1->phone);
	strcpy(ptr1->phone , ptr2->phone);
	strcpy(ptr2->phone , temp->phone);

	strcpy(temp->name , ptr1->name);
	strcpy(ptr1->name , ptr2->name);
	strcpy(ptr2->name , temp->name);

	strcpy(temp->address , ptr1->address);
	strcpy(ptr1->address , ptr2->address);
	strcpy(ptr2->address , temp->address);

	temp->score = ptr1->score;
	ptr1->score = ptr2->score;
	ptr2->score = temp->score;

	temp->day = ptr1->day;
	ptr1->day = ptr2->day;
	ptr2->day = temp->day;

	temp->month = ptr1->month;
	ptr1->month = ptr2->month;
	ptr2->month = temp->month;

	temp->year = ptr1->year;
	ptr1->year = ptr2->year;
	ptr2->year = temp->year;


}
void InsetData(Node* ptr)
{
	uint8 pass[2];
	printf("Enter Student ID: \n");
	scanf_s("%d", &ptr->ID);

	printf("Enter Student Phone Number: \n");
	fflush(stdin);
	gets(pass);
	gets(ptr->phone);

	printf("Enter Student Name: \n");
	fflush(stdin);
	gets(ptr->name);

	printf("Enter Student address: \n");
	fflush(stdin);
	gets(ptr->address);

	printf("Enter Student score: \n");
	scanf_s("%d", &ptr->score);

	printf("Enter student birth date: \n");
	printf("Day:");
	scanf_s("\n %d", &ptr->day);
	printf("Month:");
	scanf_s("\n %d", &ptr->month);
	printf("Year:");
	scanf_s("\n %d", &ptr->year);
	printf("\n Student added sucessfully :) \n");
}
void addNewStudent()
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	InsetData(NewNode);
	NewNode->next = NULL_PTR;
	if (head == NULL_PTR)
	{
		head = NewNode;
		return;
	}
	current = head;
	while (current->next != NULL_PTR)
	{
		current = current->next;
	}
	current->next = NewNode;
}
void UpdateStudent()
{
	if (head == NULL_PTR)
	{
		printf("Empty List ! \n");
		return;
	}

	uint32 ID;
	printf("Enter Student ID to Update his/her information: \n");
	scanf_s("%d", &ID);

	current = head;
	while (current != NULL_PTR)
	{
		if (current->ID == ID)
		{
			InsetData(current);
			return;
		}
		current = current->next;
	}
	if (current == NULL_PTR)
	{
		printf("Invalid ID ! \n");
	}
}
void ViewAll()
{
	if (head == NULL_PTR)
	{
		printf("Empty List ! \n");
		return;
	}
	Node* ptr = head;
	while (ptr != NULL)
	{
		printf("ID :: %d\n", ptr->ID);
		printf("Student's Name :: %s\n", ptr->name);
		printf("Birth Date is on :: %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
		printf("Student's Address :: %s\n", ptr->address);
		printf("Student's Phone Number :: %s\n", ptr->phone);
		printf("Student's score :: %d\n", ptr->score);
		printf("------------------------------------------------------------------------\n");
		ptr = ptr->next;
	}
}
void DeleteStudent()
{
	if (head == NULL_PTR)
	{
		printf("Empty List ! \n");
		return;
	}
	uint32 ID;
	Node* freenode = NULL_PTR;
	printf("Enter Student ID to delete: \n");
	scanf_s("%d", &ID);
	if (head->ID == ID)
	{
		freenode = head;
		head = head->next;
		free(freenode);
		return;
	}
	current = head->next;
	prev = head;
	while (current != NULL_PTR)
	{
		if (current->ID == ID)
		{
			prev->next = current->next;
			freenode = current;
			free(freenode);
			return;
		}
		prev = current;
		current = current->next;
		printf("Student deleted successfully \n");
	}
	if (freenode == NULL_PTR)
	{
		printf("Invalid ID ! \n");
	}
}
void RankStudent()
{
	uint32 swapFlag ;
	Node* ptr = NULL;
	if (head == NULL)
	{
		printf("empty List ! \n");
		return;
	}
	do {
		swapFlag = 0;
		current = head;
		while (current->next != ptr)
		{
			if (current->score < current->next->score)
			{
				swap(current, current->next);
				swapFlag = 1;
			}
			current = current->next;
		}
		ptr = current;
	} while (swapFlag == 1);

	printf("Students ranked successfuly \n");
}
void StudentScore()
{
		if (head == NULL_PTR) 
		{
			printf("Empty List ! \n");
			return;
		}
		current = head;
		while (current != NULL)
		{
			printf("Enter New Grade  for ID: %d : \n", current->ID);
			scanf_s("%d", &(current->score));
			current = current->next;
		}
}


