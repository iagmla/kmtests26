CC=gcc
CFLAGS=-O3 -std=c99 -w -lm
TARGET=kmtests26
all: $(TARGET)

$(TARGET): kmtests26.c
	$(CC) kmtests26.c $(CFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
