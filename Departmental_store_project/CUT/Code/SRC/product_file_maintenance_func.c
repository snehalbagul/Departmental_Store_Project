/****************************************************************************************************************************************
 **FUNCTION NAME   :      product_file_maintenance_func 
 **
 **DESCRIPTION     :      This file enables the employee to add products,edit products and
 **                       delete products from the product master file.
 **
 **RETURNS         :      It returns EXIT_SUCCESS if function is executed successfully 
 **                       or it returns EXIT_FAILURE if function is not executed 
 **                       successfully.
 **
 ***************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


//FUNCION TO ADD PRODUCTS....

int add_product()
{
	//declaring pointer to struct pm type.....
	pm *new,*ptr,*prev;	
	new=(pm *)calloc(1,sizeof(pm));
	if(!new)
	{
		printf("\n------MEMORY NOT ALLOCATED!!!-------\n");
		return(EXIT_FAILURE);
	}

	// VALIDATION FOR PRODUCT CODE.....
	while(1)
	{
		printf("\nEnter the Product code (max 3 digits):");
		scanf("%d",&new->product_code);
		if(new->product_code<1 || new->product_code>999)
		{
			printf("\nINVALID PRODUCT CODE!!!\n");
			continue;
		}

		//loop to find duplicate product code using pointer ptr.....
		for(ptr=start;(ptr) && ptr->product_code!=new->product_code;ptr=ptr->next); 
		//product code already exists....
		if(ptr)               
		{
			printf("\n %d Product code is duplicate\n",new->product_code);
			continue;
		}
		else
		{
			break;
		}
		system("read a");
		system("clear");
	}


	//VALIDATION FOR PRODUCT NAME......

	while(1)
	{
		printf("\nEnter Product name (min 5 and max 30 characters):");
		scanf("%s",new->product_name);
		int length;
		length=strlen(new->product_name);

		//checking number of characters in product name......     
		if(length<5 || length>30)      
		{
			printf("Product name out of range!!\n");
			continue;
		}
		int flag=0;

		//loop to traverse characters in product name
		for(int i=0;new->product_name[i]!='\0';i++)
		{

			//checks character is alphabet or not.....
			if(!isalpha(new->product_name[i])) 
			{
				flag=1;
				break;
			}

		} 
		// Product name contain character other than alphabets
		if(flag==1)
		{
			printf("Product name should only contain alphabets\n");
			continue;
		}
		else
		{
			break;
		}
		system("read a");
		system("clear");

	}

	//*********VALIDATION FOR PRODUCT PRICE.......

	while(1)
	{
		printf("\nEnter Product price-");
		scanf("%lf",&new->product_price);
		//checking productprice is in range or not.....
		if(new->product_price<1 || new->product_price>10000)
		{
			printf("\nINVALID RANGE OF PRICE!!!");
			continue;
		}
		else
		{
			break;
		}
		system("read a");
		system("clear");
	}

	//**********VALIDATION FOR UNITS AVAILABLE......

	while(1)
	{
		printf("\nEnter units available (min 1 and max 50 units):");
		scanf("%d",&new->unit_available);

		//check unit available should be in range one to fifty.....
		if(new->unit_available <1 ||  new->unit_available>50)

		{
			printf("\n INVALID UNITS");
			continue;
		}
		else
		{
			break;
		}
		system("read a");
		system("clear");
	}

	//VALIDATION FOR ZONE CODE

	while(1)
	{
		printf("\nEnter the zone code of the product (X,Y,Z):");
		scanf("%s",&new->zone_code);
		fflush(stdin);
		if(new->zone_code==' ' ||( new->zone_code!='X' && new->zone_code!='Y' && new->zone_code!='Z'))
		{
			// zone code is invalid
			printf("\n INVALID ZONE CODE!!!\n");
			continue;
		}
		else
		{
			break;
		}
		system("read a");
		system("clear");
	}


	// ENTERING DATA...........................

	//condition to insert first element....
	if(!start) 
	{
		start=new;
		new->next=NULL;
	}

	//condition used when list has already one element....
	else if(new->product_code<start->product_code)

	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->product_code<new->product_code;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}
	printf("\n************************Records added successfully*********************\n");
	//free(new);
	return(EXIT_SUCCESS);
}

//FUCNTION TO VIEW PRODUCT DETAILS.....
int view_product()
{
	if(start)
	{
		printf("\n---PRODUCT CODE      PRODUCT NAME    PRODUCT PRICE    UNIT AVAILABLE    ZONE CODE---"); 
		for(pm *ptr=start;(ptr);ptr=ptr->next)
		{

			printf("\n %5d %20s            %7.2lf      %10d       %10c",ptr->product_code,ptr->product_name,ptr->product_price,ptr->unit_available,ptr->zone_code);
		}
	}
}


/***********************FUNCTION TO EDIT PRODUCTS**************************/

int edit_product()
{
	// declaring pointer of pm type
	pm *new,*ptr,*prev;
	if(!start)
		//Product_Master file is empty
	{
		printf("\nEMPTY FILE!!!\n");
		return(EXIT_FAILURE);
	}
	int new_product_code;
	printf("\nEnter product code to edit record:"); // Entering product code to edit
	scanf("%d",&new_product_code);
	for(ptr=start;(ptr)&&ptr->product_code!=new_product_code;ptr=ptr->next);
	if(ptr==NULL)
	{  
		// Product code not found
		printf("\nProduct code %d not found",new_product_code);
		return(EXIT_FAILURE);
	}
	else
	{
		//Product code is found
		// Old product information to that product code
		printf("\nprevious prodcut details are:\n %d %s %d %c",ptr->product_code,ptr->product_name,ptr->unit_available,ptr->zone_code);
		printf("\nEnter product name,units available,zone code:");
		//Editing product information to that product code
		scanf("%s %d %c",ptr->product_name,&ptr->unit_available,&ptr->zone_code);
		printf("\n***********************RECORDS EDITED SUCCESSFULLY********************\n");
	}
	system("read a");
	//to clear screen
	system("clear");
	return(EXIT_SUCCESS);
}



//**********************FUNCTION TO DELETE PRODUCT************************/

int delete_product()
{
	//creating pointer of pm type
	pm *new,*ptr,*prev;
	if(!start)
	{ 
		//Product_Master file is empty
		printf("\nEmpty file\n");
		return(EXIT_FAILURE);
	}
	int new_product_code;
	printf("\nEnter the product code whose record you want to delete:");
	scanf("%d",&new_product_code);
	if(new_product_code==start->product_code)
	{ 
		//When product code to delete matches with first record of list
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{ 
		// Traversing through list to search product_code
		for(ptr=start;(ptr)&&ptr->product_code!=new_product_code;prev=ptr,ptr=ptr->next);
		if(ptr==NULL)
		{
			// product_code not found
			printf("\n%dProduct code not found\n",new_product_code);
			return(EXIT_FAILURE);
		}
		// Deleting product record to that product_code
		prev->next=ptr->next;
		// Releasing memory that is dynamically allocated
		free(ptr);
	}
	printf("\n*******************Record deleted*******************\n");
	system("read a");
	// Clearing the screen
	system("clear");
	return(EXIT_SUCCESS);

}

/*************************DISPLAY PRODUCT RECORDS*****************************/

int display_product()
{
	pm *ptr;
	if(!start)
	{
		printf("\nEMPTY LIST!!!\n");
		return(EXIT_FAILURE);
	}
	printf("\n------------------------------------------------------------\n");
	printf("\nPRODUCT CODE     PRODUCT NAME  PRODUCT PRICE  UNIT AVAILABLE\n");
	printf("\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		printf("\n%4d   %20s    %7.2lf       %5d\n",ptr->product_code,ptr->product_name,ptr->product_price,ptr->unit_available);
	}
	printf("\n------------------------------------------------------------\n");
	return(EXIT_SUCCESS);
}	


/*****************************************************************************/
