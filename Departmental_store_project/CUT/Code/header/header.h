#ifndef HEADER_H
#define HEADER_H
//structure for product file...

typedef struct Product_Master
{
	int product_code;
	char product_name[30];
	int unit_available;
	double product_price;
	char zone_code;
	struct Product_Master *next;
}pm;
pm *start;
//structure of sales transaction file...

typedef struct Sales_Transaction
{
	int product_code;
	char customer_name[30];
	int unit_sold;
	double total_price;
	struct Sales_Transaction *next;
}st;
st *start1;

//Structure for creating queue1

typedef struct queue1
{
	char customer_name[30];
	int units;
	int product_code;
	struct queue1 *next;
}q;
q *front1,*rear1;


int add_product();
int view_product();
int edit_product();
int delete_product();
void *start_sale();
int create_queues_for_sale();
int reports_corner();
int file_to_product_list();
int file_to_sales_transaction_list();
int list_to_product_file();
int list_to_product_file();
int list_to_sales_transaction_file();
int daily_sales_report();
int check_Password();
ssize_t getpasswd(char **,size_t,int,FILE *);
int hotcake();
int create_queue1();
int display_product();
int dequeue1();
int display1();
//pthread_mutex_t accum_mutex=PTHREAD_MUTEX_INITIALIZER;

#endif
