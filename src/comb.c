#pragma once
#include "../utils/comb.h"
#include "../utils/linkedlist.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//initialises the personArray, to be run only for the first time
void personArrayInit(person personArray[], int noOfPerson, city cityArray[])
{
    int loc;
    for (int i = 1; i <= noOfPerson; ++i)
    {
        scanf("%d", &loc);
        personArray[i].location = loc;
        cityArray[loc].noOfResidents++;
        personArray[i].covidStatus = 0;
        personArray[i].quarantineEndsOn = -1; //-1 implies not in quarantine
        personArray[i].riskFactor = 0;
        personArray[i].contacts = (pair *)malloc((noOfPerson+1) * sizeof(pair));
        for(int j = 0; j<=noOfPerson; j++)
        {
            personArray[i].contacts[j].first = 0;
            personArray[i].contacts[j].second = currentDate;
        }
        assert(personArray[i].contacts != NULL);
    }

    //now updating people's primary contact lists;

    for(int i = 1; i<=noOfPerson; i++)
    {
        for(int j = i+1; j<= noOfPerson; j++)
        {
            if(personArray[i].location == personArray[j].location)
            {
                personArray[i].contacts[j].first = 2;
                personArray[j].contacts[i].first = 2;
            }
        }
    }
}


//takes control of I/O and inputs list of +ve people and does necessary updations
void feedList(person personArray[], int noOfPerson, city cityArray[], int noOfCity, list graph[])
{
    /*
    -makes people's covidStatus =1
    -sets their quarantine to be 14 days from now
    -increments their homecity's covid positive count
    -print who all are this person's prim contacts in last x days
    -informs all the people who met this person in last 14 days that they are now riskFactor 2
    -prints who all are this persons sec Contacts in the last x days
    -informs all those people who are his sec Conacts in the last 14 days
    -updates the danger value of all cities (becuase some of their residents have now become prim/sec Contacts of covid +)
    -since danger Values are updated, graph weights should also be updated
    */
    int lastXDays; 
    printf("how many days back history do you want to know? (last X days)\n");
    scanf("%d", &lastXDays);

    int k;
    int index;

    printf("Enter number of Covid positive people:");
    scanf("%d", &k);

    printf("Enter the IDs of the people who are Covid Postive: \n");

    for (int i = 0; i < k; i++) // changes all persons covidStatus to 1 if name is in the CovidPositive List.
    {
        scanf("%d", &index);
        personArray[index].covidStatus = 1;
        personArray[index].quarantineEndsOn = currentDate +14;
        
        int cityThisPersonLives = personArray[index].location;
        cityArray[cityThisPersonLives].covidPosNum++;

        printf("Primary contacts in the last %d days:\n", lastXDays);
        for (int j = 1; j <= noOfPerson; j++) // changes the riskFactor of all the primary Contacts and Seccondray Contacts acc. to covidStatus of a person
        {            
            if (personArray[index].contacts[j].first == 2 && personArray[index].contacts[j].second >= currentDate - lastXDays)
            {
                printf("%d ", j);
            }
            if (personArray[index].contacts[j].first == 2 && personArray[index].contacts[j].second >= currentDate - 14)
            {
                personArray[j].riskFactor = 2; //informing this person's primary contacts that they are vulnerable now
                cityArray[personArray[j].location].noOfPrimary++;
            }

        }

        //informing this person's secondary contacts that they are vulnerable now
        printf("\n");
        printf("Secondary Contacts:\n");
        for(int j = 1; j<=noOfPerson; j++)
        {
            
            if (personArray[index].contacts[j].first == 1 && personArray[index].contacts[j].second >= currentDate - lastXDays)
            {
                printf("%d ", j);
                if(personArray[j].riskFactor != 2)
                {
                    if(personArray[j].riskFactor != 1)
                        cityArray[personArray[j].location].noOfSecondary++;

                    personArray[j].riskFactor = 1; 
                    //if the person who is sec cont of infected person is
                    //already a reiskFactor 2 person, so better maintain it at riskFactor 2, because that is of course overriding
                } 
            }     
        }
                    
    }

    //now updating danger values of all cities
    for(int i = 1; i<= noOfCity; i++)
    {
        cityArray[i].dangerValue = (double)cityArray[i].covidPosNum + ((double) cityArray[i].noOfPrimary)/5.0 + ((double) cityArray[i].noOfSecondary)/10.0;
    }

    //now have to update edge weights in graph
    for(int i = 1; i<= noOfCity; i++)
    {
        node* trav = graph[i];

        while(trav!= NULL)
        {
            trav->weight = cityArray[trav->b].dangerValue;
            trav = trav->next;
        }
    }
}


//takes control of I/O and print all info about a person
void getStatusOfPerson(int person_Id, person personArray[], int noOfPerson) // prints current status of a person
{
    printf("Info About person #%d\n", person_Id);

    if (personArray[person_Id].covidStatus == 1)
    {
        printf("Covid positive.\n");
        printf("1. Stay where you are.\n 2. Quaratine yourself in a nearby city.\n 3. Avoid contacts with people\n");
        printf("Quarantine ends on %d\n", personArray[person_Id].quarantineEndsOn);
    }

    else
    {
        printf("Covid Negative\n");
        printf("You have risk factor of %d.\n", personArray[person_Id].riskFactor);

        if (personArray[person_Id].riskFactor == 2)
        {
            printf("You came in direct contact with a Covid positive person. Be careful and take all the necessary precautions.\n");
        }

        else if (personArray[person_Id].riskFactor == 1)
        {
            printf("One or more of your primary contact came in direct contact with a Covid positive person. Be careful and take all the necessary precautions.\n");
        }

        else
        {
            printf("You are currently safe. Be careful and take all the necessary precautions.\n");
        }
    }     
    printf("Your are currently in City #%d.\n", personArray[person_Id].location);
}

//prints list of all +ve people within the entire project
void PrintCovidPosPerson(person personArray[], int noOfPerson)
{
    int count = 0; // keeps a count of covid positive people
    printf("Covid Positive Population\n");
    for (int i = 1; i <= noOfPerson + 1; i++)
    {
        if (personArray[i].covidStatus == 1)
        {
            printf("%d\n", i);
            count++;
        }
    }
    printf("%d person(s) infected.\n", count);
}


void incrementDay(person personArray[], int noOfPerson)
{
    currentDate++;
    for(int i = 1; i<=noOfPerson; i++)
    {
        if(personArray[i].quarantineEndsOn == currentDate)
        {
            personArray[i].covidStatus = 0;
            personArray[i].quarantineEndsOn = -1;
        }

        for(int j = 1; j<=noOfPerson; j++)
        {
            if(personArray[i].contacts[j].second <currentDate-14)
                personArray[i].contacts[j].first = 0;
        }

    }
    printf("date incremented\n");
}




void cityArrayInit(int noOfCity, city cityArray[])
{
    for (int i = 1; i <= noOfCity; ++i)             //cityArray initialisation
    {
        cityArray[i].dangerValue = 0;  //since initailly no one is covid +ve in the city
        cityArray[i].noOfResidents = 0;
        cityArray[i].covidPosNum = 0; // same as above
        cityArray[i].noOfPrimary = 0;
        cityArray[i].noOfSecondary = 0;
    }

}

//for a given city, prints who are primary contacts and secondary contacts 
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

//for a given city prints the list of positive people
void printPositivesOfCity(person PersonArray[],int id_of_city,int NoOfPeople)
{
    printf("Searching for people from city %d who have covid:\n", id_of_city);
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

//does exactly what its name is
void printStatusOfCity(city C[],int city_index)
{
    city temp = C[city_index];

    printf("Total Population of city %d is %d\n",city_index,temp.noOfResidents);
    printf("Total number of people who are COVID positive are %d\n",temp.covidPosNum);
    printf("Total number of people who are Primary contacts of covid people are %d\n",temp.noOfPrimary);
    printf("Total number of people who are secondary contacts are %d\n",temp.noOfSecondary);
    printf("The Danger value of the city is %.2lf\n",temp.dangerValue);
}


//prints list of residents for a given city
void printListOfResidents(int cityId , person personArray[] , int noOfPerson)
{
     int count =0;
    for(int i = 1 ; i<=noOfPerson ; i++)
    {
        if(personArray[i].location == cityId)
        {
            count = count + 1;
            printf("person #%d\n", i);
            
        }
    }    
    printf("%d person(s) living here\n", count);    
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
        printf("this person cant travel becuase he is infected, and thus in quarantine. line %d in city.c file, quitting func\n", __LINE__);
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
    

    if(personArray[personIndex].riskFactor ==2)  cityArray[destCity].noOfPrimary++;
    
    if(personArray[personIndex].riskFactor == 1) cityArray[destCity].noOfSecondary++;

    
    

    //all the resident of the new city become this new entrant's primary contacts
    //and all the
    for(int i = 1; i<=noOfPerson; i++)
    {
        if(personArray[i].location != destCity) continue;

        personArray[personIndex].contacts[i].first = 2;
        personArray[personIndex].contacts[i].second = currentDate;      //new person's primary contact include city ppl

        personArray[i].contacts[personIndex].first = 2;
        personArray[i].contacts[personIndex].second = currentDate;      //city ppl's primary contact include new person
    
        if(personArray[personIndex].riskFactor ==2  && personArray[i].riskFactor ==0 )
        {personArray[i].riskFactor =1; cityArray[destCity].noOfSecondary++;}
        //if(personArray[personIndex].riskFactor ==1  && personArray[i].riskFactor <1 ){personArray[i].riskFactor =1;}
    }


    for(int i = 1; i<= noOfPerson; i++)
    {
        
        if(personArray[i].location != destCity){ continue; }
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
    }
    
    for(int i = 1; i<=noOfPerson; i++)
    {
        if(personArray[i].location != destCity){ continue; }
        //now giving primary contacts of new person to city ppl as secondary contact
        for(int j = 1; j<=noOfPerson; j++)
        {
            if(personArray[personIndex].contacts[j].first==2 && personArray[personIndex].contacts[j].second >= currentDate-14)
            {
                if(personArray[i].contacts[j].first != 2 || personArray[personIndex].contacts[j].second <= currentDate -14)
                {
                    personArray[i].contacts[j].first = 1;
                    personArray[i].contacts[j].second = currentDate;
                }
            }
        }

    }

    personArray[personIndex].location = destCity;
    cityArray[destCity].dangerValue = (double) cityArray[destCity].covidPosNum + ((double) cityArray[destCity].noOfPrimary)/5.0 + ((double) cityArray[destCity].noOfSecondary)/10.0;
    
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
    trav = graph[sourceCity];
    while(trav!= NULL)
    {
        vectorIntPushBack(vip, trav->b);
        trav = trav->next;
    }
    //obtained all neighbours of a

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
    trav = graph[destCity];
    while(trav!= NULL)
    {
        vectorIntPushBack(vip2, trav->b);
        trav = trav->next;
    }
    //obtained all neighbours of b

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