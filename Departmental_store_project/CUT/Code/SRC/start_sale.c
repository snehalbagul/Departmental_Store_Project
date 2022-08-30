/**********************************************************************************************************************
 **FUNCTION NAME	:  start_sale
 **
 **DESCRIPTION		:  This function is used to lock a queue so that at a time two	
 **                        person in a queue can buy a product.
 **
 **********************************************************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include "header.h"

pthread_mutex_t accum_mutex=PTHREAD_MUTEX_INITIALIZER; 

/**********OPTION2*****START SALE FOR CUSTOMER***********************************/

void *start_sale()
{
	// mutex is locked
	pthread_mutex_lock(&accum_mutex);
	//dequeuing the customer from queue for sale
	dequeue1();

	dequeue1();
	printf("\n------------SALES STARTED--------------\n");
	// mutex is unlocked
	pthread_mutex_unlock(&accum_mutex);
	system("read a");
	system("clear");
	return(EXIT_SUCCESS);

}

/**************REMOVING CUSTOMER AND ADDING IN QUEUE*****************************/

int dequeue1()
{

	if(!front1)  
	{  
		// queue is empty
		printf("\nUNDERFLOW\n");  
		return 0;  
	} 


	//ADDING DATA TO QUEUE3.....

	st *new,*prev,*ptr1;  //creating pointers of struct st type
	q *temp;              //creating pointers of struct q type    

	new=(st *)calloc(1,sizeof(st)); 
	if(!new)  
	{  
		// memory not allocated for new pointer
		printf("\nMemory Not Allocated!!!\n");  
		return 0;  
	}

	new->product_code=front1->product_code;
	new->unit_sold=front1->units;
	pm *ptr2;             // creating pointers of struct pm type
	for(ptr2=start;(ptr2)&& ptr2->product_code!=new->product_code;ptr2=ptr2->next);
	if(!ptr2)
	{
		//product_code not found
		printf("\nProduct not found...");
		front1=front1->next;
		return 0;
	}
	new->total_price=ptr2->product_price*new->unit_sold;
	ptr2->unit_available=ptr2->unit_available-new->unit_sold;

	strcpy(new->customer_name,front1->customer_name);
	//adding customer details to Sales_Transaction list
	if(!start1)  
	{   
		start1= new; 
		new-> next = NULL;  

	}  
	else if(new->product_code<start1->product_code)
	{
		new->next=start1;
		start1=new;
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->product_code<new->product_code;prev=ptr1,ptr1=ptr1->next);  

		prev->next=new; 
		new->next=ptr1;
	}

	temp = front1;  
	front1 = front1-> next;  
	free(temp);
        return(EXIT_SUCCESS);	
}
/***************************************************************************************************/
