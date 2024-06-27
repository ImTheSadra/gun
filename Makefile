CC = g++
 
FLAGS = -lSDL2 -lmingw32 -mconsole

INCLUDE = -I./include

LIBS = -L./lib

OUTPUT = build/app
INPUT = source/main.cpp

all: compile run

compile:
	@$(CC) $(INPUT) -o $(OUTPUT) $(FLAGS) $(INCLUDE) $(LIBS)

run:
	@cd build/ && app.exe