//Global vars=========
int currentDate = 0;
//======================
#include "src/person.c"
#include "src/city.c"
#include "src/heap.c"
#include "src/linkedlist.c"
#include "src/vector.c"
#include <stdio.h>
#include <assert.h>
typedef long long int lli;

void IncrementDay()
{
    currentDate++;
}
    
    
    void PrintCovidPos(person personArray[] , int noOfPerson) 
    {
        int count = 1;  // keeps a count of covid positive people
        printf("Covid Positive Population\n S.No.\t\t Person\n");
        for(int i = 0 ; i<noOfPerson+1 ; i++)
        {
            if(personArray[i].covidStatus==1 && i!=0)
            {
                printf("%d-->  person[%d]\n", count , i);
            }
            
            else
                continue;
        }
    }
    
    
    void printListOfResidents(int cityId , person personArray[] , int noOfPerson)
    {
        
        
        int count =0;
        for(int i = 0 ; i<noOfPerson+1 ; i++)
        {
            if(personArray[i].location == cityId)
            {
                count = count + 1;
                printf("%d -> person[%d]\n", count , i);
                
            }
        }
        
        if(count == 0)
        {
            printf("The city is currently has no habitants.\n");
        }
    }
    
    
    void GetStatus(int person_Id , person personArray[] , int noOfPerson)  // prints current status of a person
    {
        printf("Hello User # %d\n", person_Id);
        
        if(personArray[person_Id].covidStatus == 1)
        {
            printf("You are Covid positive.\n");
                printf("1. Stay where you are.\n 2. Quaratine yourself in a nearby city.\n 3. Avoid contacts with people\n\n");
                   printf("Your are currently in City[%d].\n", personArray[person_Id].location);
                     printf("Your Quarantine ends on %d\n", personArray[person_Id].quarantineEndsOn);
        }
        
        else 
        {
            printf("You are Covid negative.\n");
                 printf("Your are currently in City[%d].\n", personArray[person_Id].location);
                    printf("You have risk factor of %d.\n",personArray[person_Id].riskFactor);
                      
                    if(personArray[person_Id].riskFactor == 2)
                      {
                          printf("You came in direct contact with a Covid positive person. Be careful and take all the necessary precautions.\n");
                      }
                                 
                                 
                     else if(personArray[person_Id].riskFactor == 1)
                      {
                          printf("One or more of your primary contact came in direct contact with a Covid positive person. Be careful and take all the necessary precautions.\n");
                                 
                      }
                                 
                              else
                                 {
                                     printf("You are currently safe. Be careful and take all the necessary precautions.\n");
                                 }
                                 
          }    
          
                                 
                                 
      }
                                 
                        
                                 
                                 
                                 
                                 
       void GetCityStatus(int CityID , person personArray[] , int noOfPerson , city cityArray[] , int noOfCity)  // Prints people who are Covid Positive , Primary Contact of one , Secondary Contact of one.
                                 
       {    
                                     
                                     
                       printf("List of people who are Covid Positive:\n");
           
                           for(int i = 0 ; i<noOfPerson+1 ; i++)
                               {
                                  if(personArray[i].covidStatus ==1 && personArray[i].location == CityID);
                                       printf("%d ", i);
                                }
                                 
                                    printf("\n");
                                     
                                  Print_P_S( CityArray, PersonArray,  CityID, noOfPerson + 1);
                                     
                                 
       
        }
                               
                                 
                                 
                                 
                                 
    void feedList(person personArray[] , int noOfPerson , city cityArray[] , int noOfCity)
  {
      int k;
      int index;
      
      printf("Enter number of Covid positive people:");
      scanf("%d", &k);
      
      int CovidPositive[k];
      
      printf("Enter the indices of the people who are Covid Postive: \n");
      
      for(int i = 0  ; i<k ; k++)  // changes all persons covidStatus to 1 if name is in the CovidPositive List.
      {
           scanf("%d", &CovidPositive[i]);
          personArray[CovidPositive[i]].covidStatus == 1;
          
          for(int j = 0 ; j<noOfPerson ; j++) // changes the riskFactor of all the primary Contacts and Seccondray Contacts acc. to covidStatus of a person
          {
             if( personArray[CovidPosititve[i]].contacts[j].first == 2)
             {
                 if(person[j].riskFactor < 2)
                 personArray[j].riskFactor ==2;
             }
              
              else if( personArray[CovidPosititve[i]].contacts[j].first == 1)
              {
                  if(personArray[j].riskFactor < 1)
                      personArray[j].riskFactor ==1; 
              }
          }
                           
      }
      
      // isnt complete yet
        
      UpdatetoPos(cityArray[],personArray[], CovidPositive[],int k);  
      Update_P_S( cityArray[], personArray[],  noOfPerson);
        
        for(int i = 0 ; i<noOfCity ; i++)
        {
            float value = cityArray[i].covidPosNum + cityArray[i].noOfPrimary/5.0 + cityArray[i].noOfSecondary/10.0 ; 
            cityArray[i].dangerValue = value;
            cityArray[i].safetyValue = 1.0/value;
        }
        
        
        for(int i = 0 ; i<k ; i++) // prints the list of Primary and Secondary contacts if meeting date is between currentDate and currentDate - 14; 
        {
            printf(" person[%d]'s primary contcats in last 14 days :\n", CovidPositive[i]);
            for(int j = 0 ; j  < noOfPerson ; j++)
            {if(personArray[CovidPositive[i]].contacts[j].first == 2   && personArray[CovidPositive[i]].contacts[j].second > currentDate -14   &&  personArray[CovidPositive[i]].contacts[j].second <= currentDate)
            {
                printf(" person[%d] ", j);
            }
             
             for(int j = 0 ; j  < noOfPerson ; j++)
            {if(personArray[CovidPositive[i]].contacts[j].first == 1   && personArray[CovidPositive[i]].contacts[j].second > currentDate -14   &&  personArray[CovidPositive[i]].contacts[j].second <= currentDate)
            {
                printf(" person[%d] ", j);
            }
             
         }
             
             
  }                               

                      

int main()
{

    int noOfPerson, noOfCity, noOfRoads;
    printf("Enter no. of Cities: ");
    scanf("%d", &noOfCity);
    printf("\nEnter no. of People: ");
    scanf("%d", &noOfPerson);
    printf("\nEnter no. of Roads: ");
    scanf("%d", &noOfRoads);

   
    //graph is implemented like an array of linked lists.
    //so we can make list graph[noOfCity]
/*

    ____       __        __
    | N*|----> |N| ----> |N|
    |___|      __        __
    | N*|----> |N| ----> |N|
    |___|
    | N*|---->NULL (if 2nd vertec has no edges leading out of it)
    |___|
    |   |
    |___|
    
    N means the struct node
    N* means pointer to the struct node, also typedefed as list (its easier to work like this(atleast for me))
*/

    list graph[noOfCity+1];                                 //graph declaration
    for(int i = 0; i<=noOfCity; i++) graph[i] = NULL;       //graph initialization

    int a, b, length;
    for(int i = 0; i<noOfRoads; i++)                        //graph input starts
    {
        scanf("%d %d %d", &a, &b, &length);
        pushFront(&(graph[a]), b, 0, length); //weight is zero here becuase weight of path a->b is = dangervalue of b
        //and weight of path b->a is = dansgervalue of a
        //during initialsing the graph, dangervalues are are all 0 becuase we dont have the list of covid peeople
        pushFront(&(graph[b]), a, 0, length); //the length for a->b and b->a will be the same so "length" variable can be used for both insertions
    }
                                                            //graph input done
   
   
    person personArray[noOfPerson+1];                       //personArray Declaration
    //pls write personarray initialisation and input
    int location;               //personArray initialisation
    for(int i=1;i<=noOfPerson;++i)
    {
        scanf("%d",&location);
        personArray[i].location = location;
        personArray[i].covidStatus = 0;
        personArray[i].quarantineEndsOn = 0; //0 implies not in quarantine
        personArray[i].riskFactor = 0;
        personArray[i].contacts = (pair*)malloc(noOfPerson * sizeof(pair));
        assert(personArray[i].contacts != NULL);
    }

    city cityArray[noOfCity+1];                             //cityArray Declaration
    //please write initialisation (and input if any)
    for(int i=1;i<=noOfCity;++i)        //cityArray initialisation
    {
        cityArray[i].dangerValue = 0;//since initailly no one is covid +ve in the city
        cityArray[i].noOfResidents = 0;
        for(int j=1;j<=noOfPerson;++j)
        {
            if(personArray[j].location == i) ++(cityArray[i].noOfResidents);
        }
        cityArray[i].covidPosNum = 0; // same as above
        cityArray[i].noOfPrimary = 0;
        cityArray[i].noOfSecondary = 0;
    }

    
    

    //CODE OUT OF DATE initializing all the persons //NOT UPDATED, WRITE AGAIN
    // for(int i = 0; i<noOfPerson; i++)
    // {
    //     personArray[i].covidStatus = 0;
    //     personArray[i].location = i%noOfCity; //assigning people tp cities, like dealing a deck of cards
    //     personArray[i].quarantineEndsOn = -1; //-1 means not was never in quarantine
    //     personArray[i].riskFactor = 0;
        
    //  CODE IS OUT OF DATE   for(int j = 0; j<noOfPerson; j++)
    //     {
    //         if(j%noOfCity==i%noOfCity) 
    //         {
    //             personArray[i].contacts[j].first = 2;
    //             personArray[i].contacts[j].second = currentDate;
    //         }
    //         else personArray[i].contacts[j].first = 0;
    //     }
    // }


/*

Make this in a menu-like format: print the choices, ask for the choice number, scanf it and execute on its basis:

    Things we need to do:
1)feeding list of covid positive people
void feedList()
{
    ask for how many people in the list, say k
    make an array of covidList[k] length to accomodate this list
    then run a loop  k times doing this for each person in the covidList
    {   go into personArray and update those people's structs, as written in architecture.md
        and for each person in the list, update the city structs where they live 
    }

    traverse through the covidList array and for each person on the list:
        print out his primary contacts if date of meeting was within currentDay and currentDay - 14
        similarly for 2ndary contacts
    
    after this now update the entire graph's edge weights according to the formula given in the project document
    take note, the edges *leading* into city x is assigned the weight of city x's dangervalue
}

2) incrementing day
currentDay++;


3)make a person travel
ask user which person do you want to move?
user says (for eg) 9 (personIndex = 9)
then print this person in this city (for eg 7) (sourceCity = 7;)
then ask user which city do you want to shift him to? 
then scanf which city i.e. scanf("%d", &destcity); 
then call the function which has the algo==> algo(personIndex, sourceCity, destCity, noOfCity, graph, cityArray, personArray);
the function will itself print the routes, ask the user for the choice and will update the cities and people living in those cities
and also will change location of that person. will be of returntype void.


4)print list of covid positive people
thats easy no new func required, just traverse the personArray once

5)print list of which person is in which city
similar to above

6)print all info about a specific personn

7)print stats of the city :
    traverse the link list of residents and tell who is covid +ve
    who all are primary contacts of a coid +ve person
        traverse the link list of residenst and print who has risk factor ==2 but isnt ill (for primary contact thing)
    who all are secondary contacts of a covid +ve person?
        traverse the link list of residents of the city and print who has risk fact ==1 but isnt ill 


*/
    


               
           



























}
