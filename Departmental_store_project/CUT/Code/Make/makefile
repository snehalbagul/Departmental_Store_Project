OBJ=main.o #File_operation_func.o check_password.o create_queue_func.o start_sale.o product_file_maintenance_func.o report_corner_func.o
HEAD=header.h
CL=*.o
CC=gcc -c
CO=gcc -o
FO=File_operation_func.c
CP=check_password.c
CQ=create_queue_func.c
SS=start_sale.c
PFM=product_file_maintenance_func.c
RC=report_corner_func.c

menu: $(OBJ)
	$(CO)  menu $(OBJ) -lpthread
main.o: main.c $(HEAD)
	$(CC)  main.c

File_operation_func.o: $(FP) $(HEAD)
	$(CC)  $(FP)

check_password.o: $(CP) $(HEAD)
	$(CC)  $(CP)

create_queue_func.o: $(CQ) $(HEAD)
	$(CC)  $(CQ)

start_sale.o: $(SS) $(HEAD)
	$(CC)  $(SS) -lpthread 

product_file_maintenance_func.o: $(PFM) $(HEAD)
	$(CC) $(PFM)

report_corner_func.o: $(RC) $(HEAD)
	$(CC) $(RC)
clean:
	rm $(CL)
