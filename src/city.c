#include "../utils/city.h"
#include <stdio.h>
#include <stdlib.h>



city_ptr Create_City_Nodes(int no_of_cities)
{
    city_ptr C = (city_ptr)malloc(no_of_cities * sizeof(city));

    for(long i = 0;i < no_of_cities + 1;i++)
    {
       
        C[i].covidPosNum = 0;         // Initialise all values to 0
        C[i].dangerValue = 0;
        C[i].noOfPrimary = 0;
        C[i].noOfResidents = 0;
        C[i].noOfSecondary = 0;
        C[i].safetyValue = 0;
    }

    return C;
}

// Only used initially, when we get input from user
void AddPeople(city C[],person P[],int NoOfPeople)
{
    for(long i = 0;i < NoOfPeople + 1;i++)
    {
        int j = P[i].location;
        C[j].noOfResidents++;
        
    }
}

// This function is to be used at initial stage only not after travelling of any person
void UpdatetoPos(city C[],person P[],int array_of_positive[],int size)
{
    for(long i = 0;i < size;i++)
    {
        int j = array_of_positive[i];
        int location = P[j].location;

        C[location].covidPosNum++;
        
    }
}
void Update_P_S(city C[],person P[],int noOfPeople)
{
    for(int i = 0;i < noOfPeople + 1;i++){
        int j = P[i].location;
        if(P[i].riskFactor == 2){
            C[j].noOfPrimary++;
        }if(P[i].riskFactor == 1){
            C[j].noOfSecondary++;
        }
    }
}

void Print_P_S(city C[],person P[], int id_of_city,int noOfPeople)
{
    printf("List of people who are Primary contacts are : \n");
    for(int i = 0;i < noOfPeople + 1;i++){
        if(P[i].location == id_of_city && P[i].riskFactor == 2){
            printf("%d ",i);
        }
    }printf("\n");

    printf("List of people who are secondary contacts are : \n");

    for(int i = 0;i < noOfPeople + 1;i++){
        if(P[i].location == id_of_city && P[i].riskFactor == 1){
            printf("%d ",i);
        }
    }printf("\n");
}

// Added to header file
void Status_of_city(city C[],int city_index)
{
    city temp = C[city_index];

    printf("Total Population of the city %d id %.0f\n",city_index,temp.noOfResidents);
    printf("Total number of people who are COVID positive are %.0f",temp.covidPosNum);
    printf("Total number of people who are Primary contacts of covid people are %f\n",temp.noOfPrimary);
    printf("Total number of people who are secondary contacts are %.0f\n",temp.noOfSecondary);
    printf("The Danger value of the city is %.2f\n",temp.dangerValue);
    printf("The safety value of this city is %f\n",temp.safetyValue);


}

// Added to header file
void Remove_from_city(city_ptr T,person P[],int Person_ID)
{
    /*People_Ptr prev = T->head,current;

    if(T->head != NULL)
        current = T->head->next;

    while(current){
        if(current->id == Person_ID){
            prev->next = current->next;
            current->next = NULL;
        }
        prev = current;
        current  = current->next;
        
    }*/

    T->noOfResidents--;
    if(P[Person_ID].covidStatus == 1)
    {
        T->covidPosNum--;
    }if(P[Person_ID].riskFactor == 2)
    {
        T->noOfPrimary--;
    }if(P[Person_ID].riskFactor == 1)
    {
        T->noOfSecondary--;
    }
    T->dangerValue = DangerValue(T);
    T->safetyValue = SafetyValue(T);
    
}

// Added to header file
float DangerValue(city_ptr T)
{
    float danger = (T->covidPosNum) + (T->noOfPrimary/5) + (T->noOfSecondary/10);

    return danger;
}

// Added to header file
float SafetyValue(city_ptr T)
{
    float safety = 1/DangerValue(T);

    return safety;
}

// Added to header file
void Add_to_city(city_ptr T,person P[],int Person_ID)
{
    /*People_Ptr temp = T->head;

    while(temp->next != NULL)
    {
       temp =  temp->next;
    }

    People_Ptr new = (People_Ptr)malloc(sizeof(People));

    temp->next = new;
    new->id = Person_ID;
    new->next = NULL;*/

    T->noOfResidents++;
    if(P[Person_ID].riskFactor == 1){
        T->noOfSecondary++;
    }if(P[Person_ID].riskFactor == 2){
        T->noOfPrimary++;
    }if(P[Person_ID].covidStatus == 1){
        T->covidPosNum++;
    }
    
    T->dangerValue = DangerValue(T);
    T->safetyValue = SafetyValue(T);
}

void Print_Positives(city C[],person P[],int id_of_city,int NoOfPeople)
{
    for(int i = 0;i < NoOfPeople + 1;i++)
    {
        if(P[i].location == id_of_city && P[i].covidStatus == 1)
        {
            printf("%d ",i);
        }
    }printf("\n");
}

void Update_City(city C[],person P[], int origin,int destination,int Person_ID)
{
    person temp = P[Person_ID];

    city T1 = C[origin];
    city T2 = C[destination];

    Remove_from_city(&T1,P,Person_ID);
    Add_to_city(&T2,P,Person_ID);

    P[Person_ID].location = destination;
}

// See header file city.h to see the usage of a function
