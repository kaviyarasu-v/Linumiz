/*
------  Program details ------

 Author Name        : V.Kaviyarasu
 
 Date               : 13-oct-2021

 Program Task       : Provided input file and a line number, delete that line without using temporary file

-----------*********---------------
*/


//---------START-------------

//Header
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// main function
int main()
{   
    //defining a variable for accessing the array index
    int index;
    int index_1=0;
    
    //the count variable is used for increasing the line
    int line_count=1;

    FILE *f,*f1,*f2,*f3; //defining file pointer to access the input file
    
    //to store given input file name
    char file_name[100];

    //to take a character variable for accessing each character from the file
    char c;

    //integer variable for provided line delete number to store
    int delete_line;
    
    //user prompt for file name
    printf("\nEnter the file name :");
    scanf("%s",&file_name);
    

    //User prompt for enter delete line number

    printf("\nEnter the delete line number :");
    scanf("%d",&delete_line);
    
    //opening the input file with first file pointer in read mode
    f=fopen(file_name,"r");
    

    //to identify the file bytes to allocate array size
    fseek(f,0,SEEK_END);
    index=ftell(f);

    //closing the file
    fclose(f);
	
        //intialize array variable and allocate the size to store the whole content into the vaariable
	char file_data[index]; 

        //again to opening a file using another pointer variable with read and write mode
	f1=fopen(file_name,"r+");
	
        //  this loop to delete the matches line number
        while(!feof(f1))
	 {

          // getting the single character everytime until the loop gets fail
	  c=getc(f1);
	 
          //counting the line when it reach the '\n'
	  if(c=='\n')
	  {
	  	line_count++;
	  }
	  

          //if the line count matches the given delete line number it will not allow to store that particular data to array variable
	  if(delete_line != line_count)
	  {
	  file_data[index_1]=c;

          // incrementing this variable for array then it will store the data to the next index of the array
	  index_1++;	
          }
      
	 }
		

        // closing the file after the loop process finished
	fclose(f1);
	
        //opening the file with another file pointer for erase the entire data from the file
	f2=fopen(file_name,"w");
        fprintf(f2,"%s",'\0');
        rewind(f2);
 
        //it will generate the input file into fresh file
	fclose(fopen(file_name,"w"));
    
        // again the final time to open the file with another pointer variable with append mode for write the stored data in file from array variable 
        f3=fopen(file_name,"a+");

        //the data will be written to the file 
        fprintf(f3,"%s",file_data);
    
        //finaly closing the file as per the file handling method
        fclose(f3);
	
         return 0;
   

  
    /*--------------------------------------END-------------------------------------------------------------------------*/	
}
