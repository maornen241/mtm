COMP_FLAG = -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG 


amount_set_str: amount_set_str_linkedList.o amount_set_str_main.o amount_set_str_tests.o amount_set_str.o
	gcc amount_set_str_linkedList.o amount_set_str_main.o amount_set_str_tests.o amount_set_str.o -o amount_set_str

amount_set_str_.o: amount_set_str.c amount_set_str.h amount_set_str_linkedList.h
	gcc -c $(COMP_FLAG) amount_set_str.c99

amount_set_str_linkedList.o: amount_set_str_linkedList.c amount_set_str_linkedList.h
	gcc -c $(COMP_FLAG) amount_set_str_linkedList.c

amount_set_str_main.o: tests/amount_set_str_main.c amount_set_str_tests.h amount_set_str.h amount_set_str_linkedList.h
	gcc -c $(COMP_FLAG) tests/amount_set_str_main.c

amount_set_str_tests.o: amount_set_str_tests.c amount_set_str_tests.h amount_set_str.h  amount_set_str_linkedList.h
	gcc -c $(COMP_FLAG) amount_set_str_tests.c




matamikya: matamikya.o matamikya_main.o matamikya_order.o matamikya_print.o matamikya_product.o matamikya_tests.o libas.a libmtm.a
	gcc matamikya.o matamikya_main.o matamikya_order.o matamikya_print.o matamikya_product.o matamikya_tests.o libas.a libmtm.a -lm -o matamikya

matamikya.o: matamikya.c matamikya_print.h matamikya.h amount_set.h set.h matamikya_product.h matamikya_order.h list.h
	gcc -c $(COMP_FLAG) matamikya.c

matamikya_main.o: tests/matamikya_main.c matamikya_tests.h test_utilities.h
	gcc -c $(COMP_FLAG) tests/matamikya_main.c

matamikya_order.o: 	matamikya_order.c matamikya_order.h matamikya_product.h matamikya.h amount_set.h
	gcc -c $(COMP_FLAG) matamikya_order.c

matamikya_print.o: matamikya_print.c matamikya_print.h
	gcc -c $(COMP_FLAG) matamikya_print.c

matamikya_product.o: matamikya_product.c matamikya_product.h matamikya.h amount_set.h
	gcc -c $(COMP_FLAG) matamikya_product.c	

matamikya_tests.o: matamikya_tests.c matamikya_tests.h matamikya.h test_utilities.h
	gcc -c $(COMP_FLAG) matamikya_tests.c	





clean:
	rm -rf 	matamikya.o matamikya_main.o matamikya_order.o matamikya_print.o matamikya_product.o matamikya_tests.o matamikya amount_set_str_linkedList.o amount_set_str_main.o amount_set_str_tests.o amount_set_str.o amount_set_str












