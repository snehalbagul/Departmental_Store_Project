/*****************************************************************************************************************************************
 ** FILENAME  :  main.c
 **
 ** DESCRIPTION : This File defines the function which send external message for Refer.
 ** 
 ** Revision History :
 ** DATE                         NAME                                         REASON
 ** ---------------------------------------------------------------------------------------
 ** 25 August 2022               Muskan Yadhav                                To make main.c file
 ** 25 August 2022               Snehal Bagul                                 To make changes in file header
 ****************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stddef.h>
#include <ctype.h>
#include "header.h"
#include "File_operation_func.c"
#include "product_file_maintenance_func.c"
#include "start_sale.c"
#include "report_corner_func.c"
#include "create_queue_func.c"
#include "check_password.c"

int main()
{
	start=NULL;
	start1=NULL;                   	//initializing struct pointer st as NULL.......
	front1=rear1=NULL;
	file_to_product_list();          //taking all records from product file to product list...
	system("read a");
	file_to_sales_transaction_list(); //taking all records from sales transaction file to sales transaction list....
	int choice1,choice2,choice3;
	int res_Status=0;
	choice1=0;
	pthread_t thread1;

	//Loop for outer menu.....
	while(choice1!=6)
	{
		system("clear");
		printf("\n1.Product File Maintenance.\n2.Start Sales\n3.Create Queues for sales\n4.Reports Corner\n5.Display queue\n6.Exit.\n");
		printf("Enter your choice-");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1:
				res_Status=check_Password();  //function call to check employee password...
				if(res_Status==1)
				{
					printf("\nINVALID PASSWORD!!!\n");
					return(EXIT_FAILURE);

				}
				//Loop for submenu.....
				else{
					choice2=0;
					printf("\n*************************PRODUCT FILE MAINTENANCE*************************\n");
					while(choice2!=5)
					{
						printf("\n1.Add Product\n2.Edit Product\n3.Delete Product\n4.View Products\n5.Go Back\n");
						printf("Enter your choice-");
						scanf("%d",&choice2);
						switch(choice2)
						{
							case 1:add_product();//function call to add a product..
							       break;
							case 2:edit_product();//function call to edit or update a record...
							       break;
							case 3:delete_product();//function call to delete a product record...
							       break;
							case 4:display_product();
							       break;
							case 5:break;
							default:printf("\nINVALID CHOICE!!!");
								break;
						}
					}
				}

				break;

			case 2://USE OF THREAD...
				pthread_create(&thread1,NULL,start_sale,NULL);
				pthread_join(thread1,NULL);
				printf("thread run successfully..");
				break;


			case 3:create_queues_for_sale();   //function call to create two queues based on the age of a customer...
			       break;


			case 4:
			       //loop for another sub menu...
			       choice3=0;
			       printf("\n*************************REPORT CORNER***********************\n");
			       while(choice3!=3)
			       {
				       printf("\n1.Sales Day Report\n2.The Hotcake\n3.Go Back\n");
				       printf("Enter your choice-");
				       scanf("%d",&choice3);
				       switch(choice3)
				       {
					       case 1:daily_sales_report(); //function call to display daily sales report...
						      break;
					       case 2:hotcake(); //function call to display the most sale product in a day...
						      break;
					       case 3:break;

					       default:printf("\nINVALID CHOICE!!!");
						       break;
				       }
			       }
			       break;

			case 5:printf("\n----------DISPLAYING QUEUE-------------\n");
			       display1();
			       break;

			case 6:break;
			default:printf("\nINVALID CHOICE!!!");
				break;
		}
	}
	if(start)
		list_to_product_file();      // updating product file...
	if(start1)
		list_to_sales_transaction_file();   //updating sales transaction file...
}




