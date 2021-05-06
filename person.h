#ifndef person
#define person




struct Contacts{
	int personID;
        int when_they_met;
	struct Contacts* Next;
};



	


struct person{
	int ID;
	int Location // Current City of the person.
	int CovidStatus// 0 for healthy, 1 for Covid+ve
	int QuarantineEndsOn// date on which the quaranrine ends
	int RiskFactor // 2--> If is a primary contact , 1--> If is a secondary contact , 0-->If none
        struct Contacts* primaryContactList;
	struct Contacts* secondaryContactList;


};


void Print_positive(struct person PeopleArr[] , int N);
void GetCurrentStatus(person A);
void UpdateList1(person_ptr A , int newContactID , int meet_date)  // Used to add people in the person's Primary Contact List
void UpdateList2(person_ptr A , int new_ContactID , int meet__date) // Used to add people in the person's Secondary Contact List


#endif



