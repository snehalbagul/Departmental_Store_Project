#include <stdio.h>
#include <stddef.h>
#include "header.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"
#include "check_password.c"
#include "product_file_maintenance_func.c"
int init_suite(void)
{
	return 0;

}

int clean_suite(void)
{
	return 0;
}

void test_check_password(void)
{
	CU_ASSERT(check_Password()==0);
	CU_ASSERT(check_Password()==1);
}

void test_add_product(void)
{
	CU_ASSERT(add_product()==0);
	CU_ASSERT(add_product()==1);
}
void test_edit_product(void)
{
	CU_ASSERT(edit_product()==0);
	CU_ASSERT(edit_product()==1);
}
void test_delete_product(void)
{
	CU_ASSERT(delete_product()==0);
	CU_ASSERT(delete_product()==1);
}

int main(void)
{
	CU_pSuite pSuite1 = NULL;

	//Initialize CUnit test registry
	if(CUE_SUCCESS != CU_initialize_registry())
	{
			return CU_get_error();
	}

	//Add suite1 to registry
	pSuite1 = CU_add_suite("Basic_Test_Suite1",init_suite,clean_suite);
	if(pSuite1 == NULL)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Add test1 to suite1
	if((NULL == CU_add_test(pSuite1, "\n\n...... Testing Password.....\n\n",test_check_password)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	//Add test2 to suite1
	if((NULL == CU_add_test(pSuite1, "\n\n....TESTING ADD PRODUCT......\n\n",test_add_product)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	//Add test2 to suite1
	if((NULL == CU_add_test(pSuite1, "\n\n...... Testing EDIT PRODUCT......\n\n",test_edit_product)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	//Add test2 to suite1
	if((NULL == CU_add_test(pSuite1, "\n\n....TESTING DELETE PRODUCT.....\n\n",test_delete_product)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_run_tests(); //OUTPUT to the screen

	CU_cleanup_registry(); //Cleaning the Registry

	return CU_get_error();
}

	
