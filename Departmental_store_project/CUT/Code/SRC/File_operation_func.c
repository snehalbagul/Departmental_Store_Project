/**********************************************************************************************************************************
 **FUNCTION NAME    :   File_operation_func
 **
 **DESCRIPTION      :	This file is used to get records from PRODUCT MASTER and SALES
                        TRANSACTION File and put the records from list to file.
 **
 **
 **
 **RETURNS	   :    It returns a SUCCESS OR FAILURE status.
 *
 **
 ***********************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

/**********************GETTING RECORDS FROM PRODUCT MASTER FILE IN LIST*****************/

int file_to_product_list()
{
	pm *new,*last;
	FILE *fp;
	if((fp=fopen("Product_Master","rb"))==NULL)
	{
		printf("Product master cannot be opened");
		return(EXIT_FAILURE);
	}
	new=(pm *)calloc(1,sizeof(pm));
	fread(new,sizeof(pm),1,fp);

	while(!feof(fp))
	{
		if(!start)
		{
			start=last=new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		new=(pm *)calloc(1,sizeof(pm));
		fread(new,sizeof(pm),1,fp);
	}
	free(new);
	return(EXIT_FAILURE);
}



/***************************GETTING RECORDS FROM TRANSACTION FILE TO LIST****************/


int file_to_sales_transaction_list()
{
	st *new,*last1;
	FILE *fp;
	if((fp=fopen("Sales_Transaction","rb"))==NULL)
	{
		printf("sales transaction cannot be opened");
		return(EXIT_FAILURE);
	}
	new=(st *)calloc(1,sizeof(st));
	fread(new,sizeof(st),1,fp);

	while(!feof(fp))
	{
		if(!start1)
		{
			start1=last1=new;
			new->next=NULL;
		}
		else
		{
			last1->next=new;
			last1=new;
			new->next=NULL;
		}
		new=(st *)calloc(1,sizeof(st));
		fread(new,sizeof(st),1,fp);
	}
	free(new);
	return(EXIT_FAILURE);
}


/***************************GETTING RECORDS FROM LIST AND ADDING IT TO FILE**************/

int list_to_product_file()
{
	pm *ptr;
	FILE *fp;
	fp=fopen("Product_Master","wb");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		fwrite(ptr,sizeof(pm),1,fp);
	}
	fclose(fp);
	return(EXIT_FAILURE);
}


/***************************GETTING DATA FROM LIST AND ADDING THEM TO TRANSACTION FILE********/

int list_to_sales_transaction_file()
{
	st *ptr;
	FILE *fp;
	fp=fopen("Sales_Transaction","wb");
	for(ptr=start1;(ptr);ptr=ptr->next)
	{
		fwrite(ptr,sizeof(st),1,fp);
	}
	fclose(fp);
	return(EXIT_FAILURE);
}

/********************************************************************************************/

