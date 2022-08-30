/****************************************************************************************************************************************
 **FUNCTION NAME   :    create_queue_func
 **
 **DESCRIPTION     :    This function is used to create a queue to start the sale.
 **
 **
 **RETURNS         :  
 **
 **
 ***************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include "header.h"


//*****************CALLING QUEUES*******************************

//******************* Creating queue for sales**********************
int create_queues_for_sale(){
	int age=0;
//	int res=0;
	while(1)
	{
		printf("enter age:");
		scanf("%d",&age);
		// Validating age

	        if(age<18 || age>35)
		{
			printf("age should be min 15 max 35\n");
			continue;
		}
		else
		{
			break;
		}
	}
	//*********************Calling Queue****************************
	create_queue1();  
	return(EXIT_SUCCESS);

}


//***************CREATES QUEUE1 OF CUSTOMER HAVING AGE BETWEEN15to35..........


int create_queue1(){

	static int counter=0; 
	q  *new;   // creating pointer of q struct type 
	if(counter>4){
		// Queue is full
		printf("\nQUEUE IS FULL!!!");
		return 0;
	}  
	new = (q *) calloc(1,sizeof(q));  

	//*******VALIDATING CUSTOMER NAME..... 

	while(1)
	{
		printf("\nEnter Customer Name:");
		scanf("%s",new->customer_name);
		int length=strlen(new->customer_name);
		if(length<5 || length>30){
			// Invalid customer name
			printf("\nINVALID CUSTOMER NAME!!!");
			continue;
		}
		int flag=0;
		for(int i=0;i<strlen(new->customer_name);i++){
			if(!isalpha(new->customer_name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1){
			// Customer name contain character other than alphabets
			printf("\nCUSTOMER NAME SHOULD CONTAIN ONLY ALPHABETS!!!");
			continue;
		}
		else{
			break;
		}
	}

	//*******VALIDATING PRODUCT CODE.....
	
	while(1)
	{
		printf("\nEnter the Product code(max 3 digit)-");
		scanf("%d",&new->product_code);
		if(new->product_code<1 || new->product_code>999)
		{ 
			//Product_code in invalid contains either less than 1 or more than 999
			printf("\nINVALID PRODUCT CODE!!!\n");
			continue;
		}
		else 
			break;


	}


	//*******VALIDATING UNITS OF PRODUCT.....

	while(1)
	{
		printf("\nEnter units want to buy-");
		scanf("%d",&new->units);
		if(new->units<1 || new->units>50){
			// Products units is invalid ,contains either less than 1 or more than 50
			printf("INVALID UNITS!!!");
		}
		else{
			break;
		}
	}

	//*******ENTERING DATA TO THE QUEUE....
	if(!front1)  
	{  
		front1= new;  
		rear1 = new;   
		front1->next = NULL;  
	}  
	else   
	{  
		rear1->next = new;  
		rear1 = new;  
		rear1->next = NULL;

	}

	counter++;
	return(EXIT_SUCCESS);
}



//**********************************DISPLAYING QUEUE-1****************************************

int display1(){

	//Creating pointer of q struct type
	q *new;  
	new = front1;      
	if(!front1)  
	{  
		// Queue is empty
		printf("\nEmpty queue\n");  
	}  
       	printf("\n             CUSTOMER NAME             UNITS               PRODUCT CODE");
	printf("\n");
	while(new)   
	{  
		// Displaying queue  contents
		printf("\n            %3s                 %5d                  %5d \n",new ->customer_name,new->units,new->product_code);  
		new = new -> next;  
	}  
	system("read a");
        system("clear");
	return(EXIT_SUCCESS);	
}

//*************************************************************************************
