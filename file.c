/*********************************************************************************************************************************
**********************************************************************************************************************************
**********************************************************************************************************************************
**************************************** NAME     :  KARIM MOHAMED ABDELGALEEL ***************************************************
**************************************** PROJECT  :  STUDENT MANAGMENT SYSTEM  ***************************************************
**************************************** DATE     :        18/7/2022           ***************************************************
**************************************** VERSION  :          2.3.0             ***************************************************
**********************************************************************************************************************************
**********************************************************************************************************************************
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "define_type.h"
#define max  10
typedef struct my_struct
{
    u16 student_id;
    u16 student_year;
    u16 course1_id;
    f32 course1_grade;
    u16 course2_id;
    f32 course2_grade;
    u16 course3_id;
    f32 course3_grade;
    struct my_struct *link;

} Db;
Db* start = NULL;
void main()
{
 u8 choice;
 printf{"WELCOME TO STUDENT MANAGMENT SYSTEM \nchoose your want operation \n(1)Create students info.
  \n(2)number of students record \n(3)Add new students \n(4)Delete student \n(5)"};

}
bool SDB_GetUsedSize(void)
{
    Db* temp_1 = start;
    u8 counter = 0;
    while(temp_1 != NULL)
    {
        counter ++;
        temp_1 = temp_1->link;
    }
    printf("\nCurrent Number of entries is: %d\n", counter);
    return counter;
}
bool SDB_isFull(u8 counter)
{
  if (counter == max)
  {
      printf("database is full");
      return 1;
  }
  else
  {
      printf("its not full yet");
      return 0;
  }
}
bool SDB_AddEntry(void)
{

    if(start == NULL)
    {
        start = (Db*) malloc(sizeof(Db*));
        start->link = NULL;

        if (start == NULL)
        {
            printf("Failed to allocate!\n");
            return false;
        }

        printf("Student ID: ");
        scanf("%d", &start->student_id);
        printf("Student year: ");
        scanf("%d", &start->student_year);
        printf("course ID: ");
        scanf("%d", &start->course1_id);
        printf("course grade: ");
        scanf("%f", &start->course1_grade);
        printf("course ID: ");
        scanf("%d", &start->course2_id);
        printf("course grade: ");
        scanf("%f", &start->course2_grade);
        printf("course ID: ");
        scanf("%d", &start->course3_id);
        printf("course grade: ");
        scanf("%f", &start->course3_grade);

        return true;
    }


    else
    {
        Db* ptr = start;
        Db* temp =(Db*) malloc(sizeof(Db));


        if (temp == NULL)
        {
            printf("Failed too allocate.\n");
            return false;
        }

        if (temp != NULL)
        {
            while(ptr->link != NULL)
            {
                ptr = ptr->link;
            }

            ptr->link = temp;
            temp->link = NULL;

            printf("Student ID: ");
            scanf("%d", &start->student_id);
            printf("Student year: ");
            scanf("%d", &start->student_year);
            printf("course ID: ");
            scanf("%d", &start->course1_id);
            printf("course grade: ");
            scanf("%f", &start->course1_grade);
            printf("course ID: ");
            scanf("%d", &start->course2_id);
            printf("course grade: ");
            scanf("%f", &start->course2_grade);
            printf("course ID: ");
            scanf("%d", &start->course3_id);
            printf("course grade: ");
            scanf("%f", &start->course3_grade);

            return true;
        }
    }
}
void SDB_DeleteEntry(u16 student_id)
{
struct my_struct * temp1 = Db;
struct my_struct * temp2 = Db;
 while(temp1!=NULL)
 {
	if(temp1->student_id==student_id)
	{
	 if(temp1==temp2)
	 {		
        Db = Db->link;
        free(temp1);
        /*to delete the first node*/ 		
	 }
	 else
	  {
		  temp2->link = temp1->link; 
		  free(temp1);
		  
	  }
	  printf("\nstudent successfully deleted\n");
	  return;
	}
	  temp2 = temp1;
	  temp1 = temp1->link;
    }
   printf("\nstudent with roll number %d is not found \n", student_id);	
}


void SDB_ReadyEntry(u16 student_id)
{ 
 struct my_struct * temp = Db;
while(temp!=NULL)
 {	if(temp->student_id==student_id)
     {
		 printf("\nstudent ID:          %d", temp->student_id);
		 printf("\nstudent year:        %d", temp->student_year);
	 	 printf("\nfirst course ID:     %d", temp->course1_id);
		 printf("\nfirst course grade:  %f", temp->course1_grade);
		 printf("\nsecond course ID:    %d", temp->course2_id);
		 printf("\nsecond course grade: %f", temp->course2_grade);
		 printf("\nthird course ID:     %d", temp->course3_id);
		 printf("\nthird course grade:  %f", temp->course3_grade); 
		 return;
	 } 
	 temp = temp->next;   
	}
printf("\n %d is not exist\n", student_id);	
}

void SDB_GetIdList (void)
{
    Db* mover = start;
    u16 counter  = 1;

    if(start == NULL)
    {
        printf("\nlist is empty\n");
        return;
    }

    while (mover != NULL)
    {
        printf("(%d) %d\n", counter, mover->ID);
        counter++;
        mover = mover->link;
    }
}

bool SDB_IsIdExist (u16 data)
{
    Db* mover = start;

    while (mover != NULL)
    {
        if(mover->ID == data)
        {
            return true; 
        }
        mover = mover->link;
    }

    return false; 
}












