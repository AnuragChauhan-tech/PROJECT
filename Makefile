CC = gcc
CFLAGS = -Wall -Wextra -g

SRCDIR = src
OBJ = $(SRCDIR)/main.c $(SRCDIR)/students.c

all:
	$(CC) $(CFLAGS) $(OBJ) -o result_mgmt

clean:
	rm -f result_mgmt