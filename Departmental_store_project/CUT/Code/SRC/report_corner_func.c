/**************************************************************************************************************
 **FUNCTION NAME   :  report_corner_func
 **
 **DESCRIPTION     :  This function is used to display the daily sales report and maximum
 **                   units sold in a day.
 **
 **RETURNS         :  It returns EXIT_SUCCESS on successfull execution and EXIT_FAILURE 
 **                   on insuccessfull execution.
 **
 ***************************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


/**********************************DISPLAYING DAILY SALES REPORT****************************/

int daily_sales_report()
{
	st *ptr;
	if(!start1)
	{
		printf("\nEMPTY LIST!!!");
		return(EXIT_FAILURE);
	}
	printf("\n*************************DAILY SALES REPORT************************************\n");
	printf("\n                PRODUCT CODE         CUSTOMER NAME       UNIT_SOLD         TOTAL PRICE\n");
	double total_day_price=0;
	int total_unit_sold=0;
	for(ptr=start1;(ptr);ptr=ptr->next)
	{
		printf("\n               %5d        %20s       %5d                %7.2lf\n",ptr->product_code,ptr->customer_name,ptr->unit_sold,ptr->total_price);
		total_day_price+=ptr->total_price;
		total_unit_sold+=ptr->unit_sold;
	}
	printf("\nTOTAL DAY PRICE - %lf ",total_day_price);
	printf("\nTOTAL UNIT SOLD - %d ",total_unit_sold);
	return(EXIT_SUCCESS);
}


/****************************DISPLAYING THE HOTCAKE REPORT*****************************************/
int hotcake()
{
	st *ptr;
	if(!start1)
	{
		printf("\nEMPTY LIST!!!");
		return(EXIT_FAILURE);
	}
	int max_unit_sold=start1->unit_sold;
	for(ptr=start1;(ptr);ptr=ptr->next)
	{
		if(ptr->unit_sold>max_unit_sold)
		{
			max_unit_sold=ptr->unit_sold;
		}
	}
	printf("\nTHE MAXIMUM UNIT SOLD IS--- %d\n",max_unit_sold);
	return(EXIT_SUCCESS);
}
/********************************************************************************/
