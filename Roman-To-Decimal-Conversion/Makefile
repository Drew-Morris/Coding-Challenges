TESTS:=Tests
FLAGS:=-Wall -Werror
COMPILER:=g++ -std=c++20
CODE:=*.cpp
EXECUTABLE:=converter

compile:
	$(COMPILER) $(FLAGS) -g $(CODE) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) *.o *.out

test-all: test-1 test-2 test-3 test-4

test-1:
	./$(EXECUTABLE) $(TESTS)/in-1.txt > temp.txt
	diff -w temp.txt $(TESTS)/out-1.txt && echo "\nTEST 1 - PASSED\n"
	rm -f temp.txt


test-2:
	./$(EXECUTABLE) $(TESTS)/in-2.txt > temp.txt
	diff temp.txt $(TESTS)/out-2.txt && echo "\nTEST 2 - PASSED\n"
	rm -f temp.txt

test-3:
	./$(EXECUTABLE) $(TESTS)/in-3.txt > temp.txt
	diff temp.txt $(TESTS)/out-3.txt && echo "\nTEST 3 - PASSED\n"
	rm -f temp.txt

test-4:
	./$(EXECUTABLE) $(TESTS)/in-4.txt > temp.txt
	diff temp.txt $(TESTS)/out-4.txt && echo "\nTEST 4 - PASSED\n"
	rm -f temp.txt
