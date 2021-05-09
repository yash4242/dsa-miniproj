#include "../utils/person.h"
#include <stdio.h>
#include <stdlib.h>



person_ptr CreatePersonArray(int No_Of_Persons,int Station_No)
{
    person_ptr PersonArr=(person_ptr)malloc(No_Of_Persons*sizeof(person));
    assert(PersonArr!=NULL);
    
    PersonArr->contacts= malloc(No_Of_Persons*sizeof(pair));
    assert(PersonArr->contacts!=NULL);
     // Create Empty Person Array with assigning the destinantion of each person at a station S
    for (int i = 1; i <=No_Of_Persons; i++)
    {
       PersonArr->contacts[i].first= 0;//assign the risk factor of all the person related to P as 0 as initially no one is positive
       PersonArr->contacts[i].second= 0;//assign the date of meeting of a person q meeting a person P as 0 as  initially no one met anyone
       PersonArr[i].id = i; // id denoting the index of each person as its identity
        PersonArr[i].location = Station_No; // each and every person is not in
        PersonArr[i].covidStatus = 0;// everyone is healthy intially
        PersonArr[i]. quarantineEndsOn=0 ;//since initially no one is positive therefore no quarantine
        PersonArr[i].riskFactor = 0;
    }

    return PersonArr;
    
}
