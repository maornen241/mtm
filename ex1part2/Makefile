COMP_FLAG = -std=c99 -Wall -pedantic-errors -Werror -DNDEBUG 


matamikya: matamikya.o matamikya_main.o matamikya_order.o matamikya_print.o matamikya_product.o matamikya_tests.o libas.a libmtm.a
	gcc matamikya.o matamikya_main.o matamikya_order.o matamikya_print.o matamikya_product.o matamikya_tests.o libas.a libmtm.a -lm -o matamikya

matamikya.o: matamikya.c matamikya_print.h matamikya.h amount_set.h set.h matamikya_product.h matamikya_order.h list.h
	gcc -c $(COMP_FLAG) matamikya.c

matamikya_main.o: matamikya_main.c matamikya_tests.h test_utilities.h
	gcc -c $(COMP_FLAG) matamikya_main.c

matamikya_order.o: 	matamikya_order.c matamikya_order.h matamikya_product.h matamikya.h amount_set.h
	gcc -c $(COMP_FLAG) matamikya_order.c

matamikya_print.o: matamikya_print.c matamikya_print.h
	gcc -c $(COMP_FLAG) matamikya_print.c

matamikya_product.o: matamikya_product.c matamikya_product.h matamikya.h amount_set.h
	gcc -c $(COMP_FLAG) matamikya_product.c	

matamikya_tests.o: matamikya_tests.c matamikya_tests.h matamikya.h test_utilities.h
	gcc -c $(COMP_FLAG) matamikya_tests.c	


clean:
	rm -rf 	matamikya.o matamikya_main.o matamikya_order.o matamikya_print.o matamikya_product.o matamikya_tests.o matamikya












