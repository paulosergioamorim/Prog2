gcc:
	gcc -o prog main.c -lm

run: main.c
	./prog < input/test_1 > test/test_1
	./prog < input/test_2 > test/test_2
	./prog < input/test_3 > test/test_3
	./prog < input/test_4 > test/test_4
	./prog < input/test_5 > test/test_5
	./prog < input/test_6 > test/test_6
	./prog < input/test_7 > test/test_7
	./prog < input/test_8 > test/test_8
	./prog < input/test_9 > test/test_9
	./prog < input/test_10 > test/test_10
	
	diff output/test_1 test/test_1 -Z
	diff output/test_2 test/test_2 -Z
	diff output/test_3 test/test_3 -Z
	diff output/test_4 test/test_4 -Z
	diff output/test_5 test/test_5 -Z
	diff output/test_6 test/test_6 -Z
	diff output/test_7 test/test_7 -Z
	diff output/test_8 test/test_8 -Z
	diff output/test_9 test/test_9 -Z
	diff output/test_10 test/test_10 -Z

setup:
	mkdir -p test

clean:
	rm test/*