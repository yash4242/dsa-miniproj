
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct primaryContacts{
	int personID;
        int when_they_met;
	struct primaryContacts* Next;
};


struct secondaryContacts{
	int personID;
	int whenTheyMmet;
	struct secondaryContacts* Next;
};
	


struct person{
	int ID;
	int Location // Current City of the person.
	int CovidStatus// 0 for healthy, 1 for Covid+ve
	int QuarantineEndsOn// date on which the quaranrine ends
	int RiskFactor // 2--> If is a primary contact , 1--> If is a secondary contact , 0-->If none
        struct primaryContacts* primaryContactList;
	struct secondaryContacts* secondaryContactList;


};

typedef struct person person;
typedef struct person* person_ptr;



struct city{
	int CityID;
	int DangerValue;
	int CovidPosNum;
	int PrimaryContacts;
	int SecondaryContacts;
};

typedef struct city city;
typedef struct city* city_ptr;

void Print_positive(struct person PeopleArr[] , int N)
{

	for(int i = 0 ; i<N ; i++)
	{
		if(peopleArr[i].CovidStatus==1)
		{
			printf("person(%d)\n", i+1 );
		}
	}
    
}


void GetCurrentStatus(person A)
{
if (A.CovidStatus==1)
{
	printf("Current Status = Positve\n");
	printf("Your Quaratine ends in  %d  days\n", QuarantineEndsOn);
	printf("Stay where you are.\n Quaratine yourself in a nearby city.\n Avoid contacts with people\n");

}

else
{
	printf("Current Status = Negative\n");
	printf("Please obey all the necessary guidelines issued by the Govt. and practice all the safety measures\n");
}
	



printf("You are currently in City %d\n", A.Location);
printf("You have a risk factor of %d\n", A.RiskFactor);



}

void UpdatePrimaryList(person_ptr A , int newContactID , int meet_date)
{

	struct primaryContacts* NewContact = (struct primaryContacts*)malloc(sizeof(struct primaryContacts));

	NewContact->personID = newContactID;
	NewContact->when_they_met = meet_date;

	struct primaryContacts* temp = A->primaryContactList;

	while(temp->Next)
	{
		temp = temp->Next;
	}

	temp->Next = NewContact;
	NewContact->Next = NULL;
}


void UpdateSecondaryList(person_ptr A , int newContactID , int meet_date)
{

	struct secondaryContacts* NewContact = (struct secondaryContacts*)malloc(sizeof(struct secondaryContacts));

	NewContact->personID = newContactID;
	NewContact->when_they_met = meet_date;

	struct secondaryContacts* temp = A->secondaryContactList;

	while(temp->Next)
	{
		temp = temp->Next;
	}

	temp->Next = NewContact;
	NewContact->Next = NULL;
}
	

	


  
