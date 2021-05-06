#ifndef Cities
#define Cities


struct city{
	int CityID;
	int DangerValue;
	int CovidPosNum;
	int PrimaryContacts;
	int SecondaryContacts;
	struct city* next; 
};




typedef struct person person;
typedef struct person* person_ptr;











#endif