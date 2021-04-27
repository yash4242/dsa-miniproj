#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct person{
	int location // Current City of the person.
	int covidStatus// 0 for healthy, 1 for Covid+ve
	int quarantineEndsOn// date on which the quaranrine ends
	int riskFactor // 2--> If is a primary contact , 1--> If is a secondary contact , 0-->If none


};

typedef struct person person;
typedef struct person* person_ptr;



struct city{
	int dangerValue;
	int Covid_pos_num;
	int Primary_contacts;
	int Secondary_contacts;
};

typedef struct city city;
typedef struct city* city_ptr;

void Print_positive(struct person peopleArr[] , int N)
{

	for(int i = 0 ; i<N ; i++)
	{
		if(peopleArr[i].covidStatus==1)
		{
			printf("person(%d)\n", i+1 );
		}
	}
    
}


void GetCurrentStatus(person A)
{
if (A.covidStatus==1)
{
	printf("Current Status = Positve\n");
	printf("Your Quaratine ends in  %d  days\n");
	printf("Stay where you are.\n Quaratine yourself in a nearby city.\n Avoid contacts with people\n");

}

else
{
	printf("Current Status = Negative\n");
	printf("Please obey all the necessary guidelines issued by the Govt. and practice all the safety measures\n");
}


printf("You are currently in City %d\n", A.location);
printf("You have a risk factor of %d\n", A.riskFactor);



}
