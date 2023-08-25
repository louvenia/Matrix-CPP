CC = gcc
CFLAGS = -Wall -Werror -Wextra -lstdc++
TEST_OUT = test

all: clean s21_matrix_oop.a test

s21_matrix_oop.a:
	@$(CC) $(CFLAGS) -c s21_matrix_oop.сс
	@ar rc s21_matrix_oop.a s21_matrix_oop.o
	@ranlib s21_matrix_oop.a
	@rm s21_matrix_oop.o

test:
	@$(CC) $(CFLAGS) test.сс s21_matrix_oop.сс -lgtest -pthread -o $(TEST_OUT)
	@./$(TEST_OUT)

clean:
	@rm -rf report *.o *.a *.gcda *.gcno *.info *.out *.txt *.dSYM $(TEST_OUT)

rebuild: clean all

gcov_report:
	@$(CC) $(CFLAGS) test.сс s21_matrix_oop.сс -lgtest --coverage -o report.out
	@./report.out
	@lcov -t "report" -o report.info --no-external -c -d .
	@genhtml -o ./report report.info
	@rm -rf *.gcda *.gcno *.info *.out
	@open ./report/src/index.html

check_leaks: clean test
	@leaks -atExit -- ./test

check_style:
	@clang-format -style=Google -n *.сс test.сс *.h 

correct_style:
	@clang-format -style=Google -i *.сс test.сс *.h 

all_check: check_leaks check_style