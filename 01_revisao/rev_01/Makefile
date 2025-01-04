gcc: main.c
	gcc -o prog main.c -lm

make_test_dir:
	mkdir test -p

make_tests:
	./prog < input/test_1 > test/test_1
	./prog < input/test_2 > test/test_2
	./prog < input/test_3 > test/test_3
	./prog < input/test_4 > test/test_4

diff:
	diff output/test_1 test/test_1
	diff output/test_2 test/test_2
	diff output/test_3 test/test_3
	diff output/test_4 test/test_4