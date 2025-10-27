libconnect4.so: tictactoe.c
	gcc -shared -o $@ $^

run: 
	LD_LIBRARY_PATH=. ./play