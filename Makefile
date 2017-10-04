INC_DIR = include
SRC_DIR = src
TEST_DIR = test
EXE_NAME = hw2
CXX = g++
CPPFLAGS = -std=c++11

all: $(EXE_NAME)

$(EXE_NAME): main.o term.o atom.o number.o variable.o
ifeq ($(OS), Windows_NT)
	$(CXX) -o $(EXE_NAME) main.o term.o atom.o number.o variable.o -lgtest
else
	$(CXX) -o $(EXE_NAME) main.o term.o atom.o number.o variable.o -lgtest -lpthread
endif
	
	
main.o: $(SRC_DIR)/main.cpp $(TEST_DIR)/utTerm.h
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/main.cpp

term.o: $(INC_DIR)/term.h $(SRC_DIR)/term.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/term.cpp

atom.o: $(INC_DIR)/atom.h $(SRC_DIR)/atom.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/atom.cpp

number.o: $(INC_DIR)/number.h $(SRC_DIR)/number.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/number.cpp

variable.o: $(INC_DIR)/variable.h $(SRC_DIR)/variable.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/variable.cpp

clean:	
ifeq ($(OS), Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(EXE_NAME)
endif