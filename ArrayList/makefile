
TESTFILE = "testStaticList"
FILE = "staticList"
VALGRINDFLAGS = --leak-check=full --show-leak-kinds=all --log-file=valgrind.txt

all: compile cppcheck run_test linker clean 

compile:
	g++ -Wall -Wextra -lm -g -std=c++17 ./*.cpp -c

cppcheck:
	cppcheck --enable=warning ./*.cpp 

run_test:
	g++ $(FILE).o $(TESTFILE).o /usr/local/lib/libgtest.a -o $(TESTFILE).bin -lpthread
	valgrind $(VALGRINDFLAGS) ./$(TESTFILE).bin
	rm -rf $(TESTFILE).bin $(TESTFILE).o

linker:
	g++ ./*.o -o main.exe

clean:
	rm -rf ./*.o

run:
	valgrind $(VALGRINDFLAGS) ./main.exe

assembly:
	g++ ./*.cpp -S
	