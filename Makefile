INC_DIR = include
EXE_NAME = hw1

all: $(EXE_NAME)

$(EXE_NAME): main.o Shapes.o Media.o Sort.o
ifeq ($(OS), Windows_NT)
	$(CXX) -o $(EXE_NAME) main.o Shapes.o Media.o Sort.o -lgtest
else
	$(CXX) -o $(EXE_NAME) main.o Shapes.o Media.o Sort.o -lgtest -lpthread
endif
	
	
main.o: main.cpp utSort.h
	$(CXX) -std=gnu++0x -c main.cpp

Shapes.o: $(INC_DIR)/Shapes.h Shapes.cpp
	$(CXX) -std=gnu++0x -c Shapes.cpp

Media.o: $(INC_DIR)/Media.h Media.cpp
	$(CXX) -std=gnu++0x -c Media.cpp

Sort.o: $(INC_DIR)/Sort.h Sort.cpp
	$(CXX) -std=gnu++0x -c Sort.cpp

clean:	
ifeq ($(OS), Windows_NT)
	del *.o *.exe
else
	rm -f *.o $(EXE_NAME)
endif