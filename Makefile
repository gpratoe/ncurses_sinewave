CC = gcc
LIBS = -lm -lncurses

sine: sine.c
	$(CC) -o sine sine.c $(LIBS)

run: sine
	./sine
	@make clean

.PHONY: clean
clean:
	rm -f sine