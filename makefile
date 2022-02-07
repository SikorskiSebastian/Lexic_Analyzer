FLAGS = -Wall -pedantic -Wextra
CCC = cc -c
CCO = cc -o
DEL = rm *.o

analize: main.o alex.o fun_stack.o parser.o store.o fun_main.o
	$(CCO) analize main.o fun_main.o alex.o fun_stack.o parser.o store.o
	$(DEL)

main.o: main.c parser.h
	$(CCC) main.c $(FLAGS)
fun_main.o: fun_main.c fun_main.h
	$(CCC) fun_main.c $(FLAGS)
store.o: store.c store.h
	$(CCC) store.c $(FLAGS)
alex.o: alex.c alex.h
	$(CCC) alex.c $(FLAGS)
parser.o: parser.c parser.h
	$(CCC) parser.c $(FLAGS)

test: fun_stack.o test_main.o tests.o
	$(CCO) test fun_stack.o tests.o test_main.o
	./test
	$(DEL) test

tests.o: tests.c tests.h fun_stack.h
	$(CCC) tests.c $(FLAGS)
test_main.o: test_main.c tests.h
	$(CCC) test_main.c $(FLAGS)
fun_stack.o: fun_stack.c fun_stack.h
	$(CCC) fun_stack.c $(FLAGS)

clean:
	rm analize
