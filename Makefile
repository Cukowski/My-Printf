CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
TARGET = my_printf

all: $(TARGET)

$(TARGET): my_printf.o
	$(CC) $(CFLAGS) -o $(TARGET) my_printf.c

my_printf.o: my_printf.c 
	$(CC) $(CFLAGS) -c my_printf.c

test: $(TARGET)
	./test_my_printf.sh

clean:
	rm -f $(TARGET) *.o