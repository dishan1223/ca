# Makefile for your program

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Target executable
TARGET = ca

# Source files
SRCS = ca.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin

uninstall:
	rm -f /usr/local/bin/$(TARGET)

