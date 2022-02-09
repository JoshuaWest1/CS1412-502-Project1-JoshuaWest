#include <stdio.h>
#include <string.h>
// --------------------------------------------------------------------------------
// AUTHOR: Joshua Wade West
// FILENAME: Project1.cpp
// SPECIFICATION: Makes a user inputted list into alphabetical order
// FOR: CS 1412 Lab- Section 502
int main(void) {
int num;//The Number of names the user wants to input
int length;// the combined length of the first and last name(used for spacing in the output)
int varlan = 22;// just a number i came up with to find fair spacing(used for spacing in the output)
int spaceLen;// ther number of additional spacing for output(used for spacing in the output)
char Last[100][1000];// A 2d Array for Last Names
char First[100][1000];// A 2d Array for First Name
int AGETEMP;// A temperarry array for Age(Used when alphabetizing) 
int age[1000];// Array to store the ages
char NAMETEMP[1000];// The temperarry array for Names(Used when alphabetizing)
int i,j;// vars used for loops


printf("\nHow Many Names Do You Wish To Input?\n");// asks user for number of names/ages they want to input
scanf("%d", &num);

for(i = 0; i < num; i++){//the loop to input each person's info
printf("\nPlease Enter a Last Name, First Name, And Age:\n");
scanf("%s", Last[i]);// enter the last name
scanf("%s", First[i]);//enter the first name
scanf("%d", &age[i]);// enter the age
}


printf("\n\n");
printf("\nOriginal List\n");//beginning for the Original list output
printf("------------------------------------------\n");

for(i=0;i<num;i++)// loop to output the LastName, FirstName Age
  {
length = strlen(Last[i]) + strlen(First[i]);// Finds length from the combined length of First and Last Name
spaceLen = varlan - length;// Uses a Number and length to create an equal equal spacing for each output
    printf("\t%s,  %s", Last[i], First[i]);//print the last and first names
for(j=0; j < spaceLen; j++){printf(" ");}// outputs a number of spaces
    printf("%d\n", age[i]);//outputs the age
    
  }

//The Alphabetizing Array
for(i=0;i<=num;i++)// loops for the first array
      for(j=i+1;j<=num;j++)//loops for the second array
      {
           if(strcmp(Last[i],Last[j])>0)//if the first Last name is grater than the 2nd then ...
           {
              strcpy(NAMETEMP,Last[i]);// copy the 1st last name into a temp array
              strcpy(Last[i],Last[j]);// move the 2nd last name into the 1st
              strcpy(Last[j],NAMETEMP);//move the temp last name into the 2nd

              strcpy(NAMETEMP,First[i]);// same as above but for last name
              strcpy(First[i],First[j]);
              strcpy(First[j],NAMETEMP);


              AGETEMP = age[i];// same as above but for age
              age[i] = age[j];
              age[j] =AGETEMP;
            
           }
      }


  printf("\n\n");
printf("\nAlphabetized List\n");//beginning for the Alphabetized list output
printf("------------------------------------------\n");
  for(i=1;i<=num;i++)
  {
length = strlen(Last[i]) + strlen(First[i]);// Finds length from the combined length of First and Last Name
spaceLen = varlan - length;// Uses a Number and length to create an equal equal spacing for each output
    printf("\t%s,  %s", Last[i], First[i]);//print the last and first names
for(j=0; j < spaceLen; j++){printf(" ");}// outputs a number of spaces
    printf("%d\n", age[i]);//outputs the age
    
  }

  return 0;
}