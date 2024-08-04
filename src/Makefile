CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11
TEST_FLAGS = -lcheck -lpthread -pthread -lm 
SRC = $(wildcard *.c)

OBJ = $(patsubst %.c, %.o, $(SRC))

TEST_SRC = $(wildcard ./test/*.c)

OBJS_PATHES = $(SRCS:.c=.o)

TEST_OBJ = $(patsubst ./test/%.c, ./test/%.o, $(TEST_SRC))

OS := $(shell uname)
ifeq ($(OS),Linux) # определяем ОС
TEST_LIBS = -lcheck -lm -lsubunit
else
TEST_LIBS = -lcheck
endif

all : clean s21_SmartCalc.a test gcov_report

test.a: $(TEST_OBJ)
	ar r test.a $^	

s21_SmartCalc.a: $(OBJ)
	ar rc s21_SmartCalc.a $^
	ranlib s21_SmartCalc.a
	rm -rf *.o

install:
	mkdir build/
	cd build/ && cmake .. && make
	

uninstall:
	@-rm -rf build/

reinstall: uninstall install


test: s21_SmartCalc.a test.a
	$(CC) test.a s21_SmartCalc.a $(TEST_FLAGS) -o test.out
	./test.out

leaks: test
	leaks -atExit -- ./test.out > leaks.txt

gcov_report: clean test.a
	$(CC) -fprofile-arcs -ftest-coverage test.a $(SRC) -o test.out $(TEST_FLAGS)
	./test.out
	lcov -t "s21_SmartCalc.a" -o s21_SmartCalc.a.info -c -d .
	genhtml -o gcov_report s21_SmartCalc.a.info
	rm -rf *.gcno *.gcda
	open ./gcov_report/index.html

open:
	./build/Calculator.app/Contents/MacOS/Calculator

dvi:
	open Calculator.html

dog: s21_SmartCalc.a
	gcc s21_SmartCalc.a dog.c -o dog.out
	leaks -atExit -- ./dog.out > dog.txt
	
dist: reinstall
	tar cvzf dist_calc_qt.tgz build/

check_linters:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h *.cpp test/*.c test/*.h
	cppcheck *.c *.h *.cpp test/*.c test/*.h
	rm CPPLINT.cfg

cppcheck:
	cppcheck --enable=all  --check-config --suppress=missingIncludeSystem *.c *.h *.cpp test/*.c *.h

clean :
	rm -rf *.o *.a gcov *.gch *.tgz *.gcda *.gcno *.info *.out *.cfg report .clang-format gcov_report
	rm -rf build/
	#rm -f ./test/*.o

rebuild : clean all

style: clean
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -i -n *.c *.h
	rm .clang-format

clang :
	clang-format -i --style=Google *.c *.h *.cpp test/*.c *.h
	clang-format -n --style=Google *.c *.h *.cpp test/*.c *.h