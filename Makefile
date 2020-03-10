CFLGS = -g -Wall -Werror
OBJS = main.o Implementation.o
EXEC = main
CC = gcc

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)
clean:
	rm -f $(EXEC) $(OBJS)