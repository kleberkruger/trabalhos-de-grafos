EXE = main

C++ = g++
SRC_DIR = sources
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CFLAGS = -std=c++17 -Wall -O3

.PHONY: all tdd clean

all: $(EXE)
	
$(EXE): $(OBJ)
	$(C++) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(C++) $(CFLAGS) -c $< -o $@

tdd:
	g++ tratamento_tsp/main.cpp $(CFLAGS) -O3 -o tratamento_tsp/tratamento_de_dados

clean:
	rm $(OBJ)
	rm $(EXE)
