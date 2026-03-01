CC = gcc
CFLAGS = -Wall -g

# Now, just typing 'make' will trigger 'run', which triggers 'all'
run: all
	.\addressbook.exe

all:
	$(CC) $(CFLAGS) *.c -o addressbook.exe