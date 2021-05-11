//Global vars=========
int currentDate = 0;
//======================
// #include "utils/pair.h"
// #include "utils/vector.h"
// #include "utils/comb.h"
// //#include "utils/city.h"
// #include "utils/heap.h"
// #include "utils/linkedlist.h"
// #include "utils/stack.h"
// #include "algo.c"
// #include <stdio.h>
// #include <assert.h>
// typedef long long int lli;

//#include "src/pair.c"
#include "src/vector.c"
#include "src/comb.c"
//#include "utils/city.h"
#include "src/heap.c"
#include "src/linkedlist.c"
#include "src/stack.c"
#include "algo.c"
#include <stdio.h>
#include <assert.h>
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


    list graph[noOfCity + 1];                               //graph declaration
    for (int i = 0; i <= noOfCity; i++) graph[i] = NULL;    //graph initialization

    int a, b, length;
    for (int i = 0; i < noOfRoads; i++)                     //graph input starts
    {
        scanf("%d %d %d", &a, &b, &length);
        pushFront(&(graph[a]), b, 0, length);
        pushFront(&(graph[b]), a, 0, length); 
    }

    for(int i = 1; i<=noOfCity; i++)
    {
        printf("%d -> ", i);
        node* yashtrav = graph[i];
        while(yashtrav != NULL)
        {
            printf("%d, ", yashtrav->b);
            yashtrav = yashtrav->next;
        }
        printf("\n");
    }
                                                            //graph input done
    /*
     weight is zero here becuase weight of path a->b is = dangervalue of b
    and weight of path b->a is = dansgervalue of a
    during initialsing the graph, dangervalues are are all 0 becuase we dont have the list of covid people
    the length for a->b and b->a will be the same so "length" variable can be used for both insertions    
    */

    city cityArray[noOfCity + 1];                           //cityArray Declaration
    cityArrayInit(noOfCity, cityArray);         //cityArray initialization

    printf("\nPlease enter cities of residences of person 1, 2, 3 ..%d\n", noOfPerson);
    person personArray[noOfPerson + 1];                      //personArray Declaration        
    personArrayInit(personArray, noOfPerson, cityArray);     //personArray initialisation
    

                      

    int choice1;

    while(1)
    {
        printf("\n****************************************************\n");
        printf("Enter 1 --->To Feed List OF Covid Positive People And Print The List Of Their Primary and Secondary Contacts\n");
        printf("Enter 2 --->To Make a person travel\n");
        printf("Enter 3 --->To Print The Status Of a city\n");
        printf("Enter 4 --->To Print The Status Of a person\n");
        printf("Enter 5 --->To print a list of al covid people in the entire project\n");
        printf("Enter 6 --->Increment date\n");
        printf("Enter 0 --->To Exit The Programme\n");
        printf("\n****************************************************\n");
        scanf("%d",&choice1);

        if(choice1 == 0){printf("exiting program\n"); break;}

        else if(choice1 == 1)
        {
            feedList(personArray, noOfPerson, cityArray, noOfCity, graph);
        }

        else if(choice1 == 2)
        {
            int personIndex;
            printf("Which person do you want to move?\n");
            scanf("%d", &personIndex);
            int sourceCity = personArray[personIndex].location;
            printf("This person lives in city %d.\n", sourceCity);            
            printf("Where do you want him to go?\n");
            int destCity;
            scanf("%d", &destCity);
            algo(personIndex, sourceCity, destCity, noOfCity, graph, cityArray, personArray, noOfPerson);
        }

        else if(choice1 ==3)
        {
            printf("You want to know staus of which city?\n");
            int cityIndex;
            scanf("%d", &cityIndex);
            printStatusOfCity(cityArray, cityIndex);
            printf("\n");
            cityPrimSec(personArray, cityIndex, noOfPerson);
            printf("\n");
            printPositivesOfCity(personArray, cityIndex, noOfPerson);
            printf("\n");
        }

        else if(choice1 == 4)
        {
            printf("Which Person do you want to know about?\n");
            int personIndex;
            scanf("%d", &personIndex);
            getStatusOfPerson(personIndex, personArray, noOfPerson);
        }
        
        else if(choice1 == 5)
        {
            PrintCovidPosPerson(personArray, noOfPerson);
        }

        else if(choice1 == 6)
        {
            incrementDay(personArray, noOfPerson);
        }
        
        else
        {
            printf("invalid choice, enter again\n");
        }

    }

}
