//Global vars=========
int currentDate = 0;
//======================
#include "src/person.c"
#include "src/city.c"
#include "src/heap.c"
#include "src/linkedlist.c"
#include "src/vector.c"
#include <stdio.h>
typedef long long int lli;
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


    city cityArray[noOfCity+1];                             //personArray Declaration
    //please write initialisation (and input if any)

    
    

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