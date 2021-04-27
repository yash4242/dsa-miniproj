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