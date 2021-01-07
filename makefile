#Alexander Rollison
#makefile for C++ program
SRC = Code2.cpp
SRC1 = Test.cpp
OBJ = $(SRC:.cpp=.o)
OBJ1 = $(SRC1:.cpp=.o)
EXE = $(SRC:.cpp=.e)

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ) $(OBJ1)
	g++ $(CFLAGS) $(OBJ) $(OBJ1) -o $(EXE)

$(OBJ) : $(SRC)
	g++ -c $(CFLAGS) $(SRC) -o $(OBJ)
	
$(OBJ1) : $(SRC1)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)
