CC      := gcc
CFLAGS  := -std=c99 -Wall -Wextra -pedantic -O3 -march=native -fsanitize=address

TARGET  := main
SRC     := main.c stringlist.c

# -------- RULES --------
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean