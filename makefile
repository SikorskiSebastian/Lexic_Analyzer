FLAGS = -Wall -pedantic -Wextra
CCC = cc -c
CCO = cc -o
MV = mv *.o bin/

analize: main.o alex.o fun_stack.o parser.o store.o fun_main.o
	$(CCO) $@ $^
	$(MV)

main.o: src/main.c src/parser.h
	$(CCC) $< $(FLAGS)
	-mkdir bin
fun_main.o: src/fun_main.c src/fun_main.h
	$(CCC) $< $(FLAGS)
store.o: src/store.c src/store.h
	$(CCC) $< $(FLAGS)
alex.o: src/alex.c src/alex.h
	$(CCC) $< $(FLAGS)
parser.o: src/parser.c src/parser.h
	$(CCC) $< $(FLAGS)

test: fun_stack.o test_main.o tests.o
	$(CCO) $@ $^
	$(MV)
	./test

tests.o: src/tests.c src/tests.h src/fun_stack.h
	$(CCC) $< $(FLAGS)
test_main.o: src/test_main.c src/tests.h
	$(CCC) $< $(FLAGS)
fun_stack.o: src/fun_stack.c src/fun_stack.h
	$(CCC) $< $(FLAGS)

.PHONY: clean

clean:
	rm bin/*.o analize test
