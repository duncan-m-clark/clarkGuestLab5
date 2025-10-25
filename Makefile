libconnect4.so: tictactoe.c
	gcc -shared -o $@ $^
