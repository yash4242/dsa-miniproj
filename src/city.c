#include "../utils/city.h"
#include <stdio.h>
#include <stdlib.h>


void cityPrimSec(person personArray[], int cityIndex, int noOfPeople)
{
    printf("For City %d, these people are primary contacts of a covid +ve person\n", cityIndex);
    for(int i = 1; i<=noOfPeople; i++)
    {
        if(personArray[i].location== cityIndex && personArray[i].riskFactor == 2)
        {printf("%d\n", i);}
    }

    printf("For City %d, these people are secondary contacts of a covid +ve person\n", cityIndex);
    for(int i = 1; i<=noOfPeople; i++)
    {
        if(personArray[i].location== cityIndex && personArray[i].riskFactor == 1)
        {printf("%d\n", i);}
    }

}

void printPositivesOfCity(person PersonArray[],int id_of_city,int NoOfPeople)
{
    printf("Searching for people from city %d who have covid:\n");
    int flag = 0;
    for(int i = 1;i <= NoOfPeople;i++)
    {
        if(PersonArray[i].location == id_of_city && PersonArray[i].covidStatus == 1)
        {
            printf("%d\n",i);
            flag =1;
        }
    }
    if(flag == 0)
    {printf("City is covid free!\n");}
}


void printStatusOfCity(city C[],int city_index)
{
    city temp = C[city_index];

    printf("Total Population of city %d is %d\n",city_index,temp.noOfResidents);
    printf("Total number of people who are COVID positive are %d\n",temp.covidPosNum);
    printf("Total number of people who are Primary contacts of covid people are %d\n",temp.noOfPrimary);
    printf("Total number of people who are secondary contacts are %d\n",temp.noOfSecondary);
    printf("The Danger value of the city is %.2f\n",temp.dangerValue);
}

//removes person from src, updates src city, adds him to dest, updates dest city, and updates contacts lists, and graph src and dest have to be neighbours. if not then use this func in steps
void transferPerson(int personIndex, int sourceCity, int destCity, person personArray[], city cityArray[], list graph[], int noOfPerson)
{
    node* trav = graph[sourceCity];
    while(trav!= NULL)
    {
        if(trav->b == destCity){break;}
        trav= trav->next;
    }
    
    if(trav == NULL)
    {
        printf("there is no edge bw %d and %d cities, quitting func %d line in city.c file\n",sourceCity, destCity, __LINE__);
        return;
    }

    if(personArray[personIndex].location != sourceCity)
    {
        printf("person %d doesnt live in city %d, quitting func. line %d in city.c file.", personIndex, sourceCity, __LINE__);
        return;
    }

    if(personArray[personIndex].covidStatus ==1)
    {
        printf("this person cant travel becuase he is infected, and thus in quarantine line %d in city.c file, quitting func\n", __LINE__);
        return;
    }

    //person is preparing to leave
    cityArray[sourceCity].noOfResidents--;
    if(personArray[personIndex].riskFactor ==2) cityArray[sourceCity].noOfPrimary--;
    
    if(personArray[personIndex].riskFactor == 1) cityArray[sourceCity].noOfSecondary--;

    cityArray[sourceCity].dangerValue = (double) cityArray[sourceCity].covidPosNum + ((double) cityArray[sourceCity].noOfPrimary)/5.0 + ((double) cityArray[sourceCity].noOfSecondary)/10.0;
    //now the person has left;

    //now the person has arrived
    cityArray[destCity].noOfResidents++;
    personArray[personIndex].location = destCity;

    if(personArray[personIndex].riskFactor ==2)  cityArray[destCity].noOfPrimary--;
    
    if(personArray[personIndex].riskFactor == 1) cityArray[destCity].noOfSecondary--;

    cityArray[destCity].dangerValue = (double) cityArray[destCity].covidPosNum + ((double) cityArray[destCity].noOfPrimary)/5.0 + ((double) cityArray[destCity].noOfSecondary)/10.0;
    

    //all the resident of the new city become this new entrant's primary contacts
    //and all the
    for(int i = 1; i<=noOfPerson; i++)
    {
        if(personArray[i].location != destCity) continue;

        personArray[personIndex].contacts[i].first = 2;
        personArray[personIndex].contacts[i].second = currentDate;      //new person's primary contact include city ppl

        personArray[i].contacts[personIndex].first = 2;
        personArray[i].contacts[personIndex].second = currentDate;      //city ppl's primary contact include new person

        //now giving primary contact of residents to new person as secondary
        for(int j = 1; j<= noOfPerson; j++)
        {
            if(personArray[i].contacts[j].first==2 && personArray[i].contacts[j].second >= currentDate-14)
            {
                if(personArray[personIndex].contacts[j].first !=2 || personArray[personIndex].contacts[j].second <= currentDate-14)
                {
                    personArray[personIndex].contacts[j].first =1;
                    personArray[personIndex].contacts[j].second =currentDate;
                }

            }
        }

        //now giving primary contacts of new person to city ppl as secondary contact
        for(int j = 1; j<=noOfPerson; j++)
        {
            if(personArray[personIndex].contacts[j].first==2 && personArray[personIndex].contacts[j].second>= currentDate-14)
            {
                if(personArray[i].contacts[j].first != 2 || personArray[personIndex].contacts[j].second <= currentDate -14)
                {
                    personArray[i].contacts[j].first = 1;
                    personArray[i].contacts[j].second = currentDate;
                }
            }
        }

    }

    
    //now updating graph edge weights
    //for eg A----->----B edge will have a weight equal to dangervalue of B
    //and A----<------B will have edge weight equal to dangervalue of A.
    //both source city and destinationn city have to update now

    //idea: to know which all cities have edges leading to A, 
    //we check A's neighbours becuase graph has bidirectional edges
    //put those edges into a vector, then look at the vector and go to those vertex at the list in the graph
    //then look of A in the linked list via node* trav and then update the weight. 
    //doing the same for Destination vertex

    vectorInt* vip = createVectorInt(20);
    node* trav = graph[sourceCity];
    while(trav!= NULL)
    {
        vectorIntPushBack(vip, trav->b);
        trav = trav->next;
    }
    //obtained all edges of a

    for(int i = 0; i < vip->numelems; i++)
    {
        node* trav = graph[vip->arr[i]];
        while(trav!= NULL)
        {
            if(trav->b == sourceCity){break;}
            trav = trav->next;
        }
        if(trav == NULL)
        {
            printf("error on line %d of city.c, node from %d to %d exists, but not in reverse? function quitting iteration i = %d\n", __LINE__, sourceCity, vip->arr[i], i);
            return;
        }
        trav->weight = cityArray[sourceCity].dangerValue;
    }
    //now updated all edges leading to sourcecity

    //now updating weights of edges leading into destCity
    vectorInt* vip2 = createVectorInt(20);
    node* trav = graph[destCity];
    while(trav!= NULL)
    {
        vectorIntPushBack(vip2, trav->b);
        trav = trav->next;
    }
    //obtained all edges of a

    for(int i = 0; i < vip2->numelems; i++)
    {
        node* trav = graph[vip2->arr[i]];
        while(trav!= NULL)
        {
            if(trav->b == destCity){break;}
            trav = trav->next;
        }
        if(trav == NULL)
        {
            printf("error on line %d of city.c, node from %d to %d exists, but not in reverse? function quitting iteration i = %d\n", __LINE__, destCity, vip2->arr[i], i);
            return;
        }
        trav->weight = cityArray[destCity].dangerValue;
    }
    //now updated all edges leading to destCity  
    

}

