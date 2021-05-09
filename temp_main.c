#working and go through of the whole project

int main()
{
    Enter N,M,K // N=>no of stations, M=>no of roads ,K=>no of people

    For the next M lines: Enter U,V,W // Indicating there is a bidirectional road between U,V of length W

  ---->  Call the function which Adds Edge between the Edge U,V OF length W

    For the next K lines enter i , where ith station is intial station no. of person[i]

  ----> Call the function which  insert information about each person in the empty personArray


LINE 16
************************************************************************************************************************************************
   int choice1;//choice1 is entered by user to implement task 1,2,3.
   char choice2[5];//will be used if user chooses choice as 2.
  printf("Enter 1 --->To Feed List OF Covid Positive People And Print The List Of Their Primary and Secondary Contacts\n");
  printf("Enter 2 --->To Make The Person Travel If He Desires, To A Station Of His Choice Through a Safe And A Short Route\n");
  printf("Enter 3 --->To Print The Status Of a Given city of your choice\n");
  printf("Enter 4 --->To Print The Status Of a Given Persom of your choice\n");
  printf("Enter 0 --->To Exit The Programme\n");
  scanf("%d",&choice1);


   while(choice!=0)
   {
     
     if(choice == 1)
     
     {
          // For a day D, feed the list of covid postive people
    ------>Call the function which takes input for the whole list

    //The below function is done simultaneously while feeding the list
    ------>Call the function which prints the list of primary and secondary contacts of covid positive people

    ------>Call the function which updates the covid status for every person and updates the primary and secondary contacts of it.

    ------>Call the function which updates the covid status for a particular city in which covid positive people are living.
     
     }


     else if(choice == 2)
     
     {  
        // User will decide the station S2 he needs to go if its current station is S 
        printf("Enter ''YES'' Or  ''NO'' Without Inverted Comma  If You Want To Travel Or Not");
        scanf("%s",&choice2);
        
        if(choice2 == 'YES')
        
        {

            // Algo portion 
  ------> Call the function which calculates the danger value for each path 

  ----->Call the function which provides the user with 3 SAFEST and SHORTEST PATH(safest > shortest) and asks him whether he wants to go or not
        

  ----->Call the function which updates the information regarding the status of a city based on the station S2 and 
        movement of person from S to S2 .

  ----->Call the function which updates the status of a person and its primary and secondary contacts.

        }

        else 

        {

          continue;
        }
     
     }

     else if(choice == 3)
     {

       -----> Call the function which prints the updated status of each city

     }

     else if(choice = 4)
     {

        ----->Call the function which prints the updated status of each person

     }

     else
     {

      printf("ERROR : The Entered Choice Is Invalid");
      continue;

     }

    printf("Enter 1 --->To Feed List OF Covid Positive People And Print The List Of Their Primary and Secondary Contacts\n");
    printf("Enter 2 --->To Make The Person Travel If He Desires, To A Station Of His Choice Through a Safe And A Short Route\n");
    printf("Enter 3 --->To Print The Status Of a Given city of your choice\n");
    printf("Enter 4 --->To Print The Status Of a Given Persom of your choice\n");
    printf("Enter 0 --->To Exit The Programme\n");
    scanf("%d",&choice1);
     
   }
 ************************************************************************************************************************************************
LINE 110

REPEAT all the steps between the LINE 16 AND LINE 110 untill user desires
 


}
   
   

  
  
  
  

   




  









}