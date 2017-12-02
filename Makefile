CXX = clang++
CXXFLAGS = -std=c++11 -g
LDFLAGS =
LIBS = -lgtest -lpthread

ifeq ($(OS), Windows_NT)
	CXX = g++
	CXXFLAGS = -std=gnu++0x
	LIBS = -lgtest
	PEEK = type utIterator.h
endif

SRC_DIR = .
INCLUDE_DIR = .
TEST_DIR = .
BUILD_DIR = .
TEST_TARGET = main
EXECUTE_FILE_NAME = hw7
 
H_FILES = $(wildcard $(INCLUDE_DIR)/*.h)
HEADERS = $(filter-out ./utIterator.h,$(H_FILES))


OBJECTS=$(patsubst $(INCLUDE_DIR)/%.h, $(BUILD_DIR)/%.o, $(HEADERS))
TEST_HEADERS = $(wildcard $(TEST_DIR)/ut*.h)


all: $(BUILD_DIR)/$(TEST_TARGET).o $(OBJECTS)
	$(CXX) -o $(EXECUTE_FILE_NAME) $(BUILD_DIR)/$(TEST_TARGET).o $(OBJECTS) $(LDFLAGS) $(LIBS)
	$(PEEK)
	
$(BUILD_DIR)/$(TEST_TARGET).o: $(SRC_DIR)/$(TEST_TARGET).cpp $(TEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$(TEST_TARGET).cpp -o $(BUILD_DIR)/$(TEST_TARGET).o
 
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean:
	$(RM) $(EXECUTE_FILE_NAME)
	$(RM) $(BUILD_DIR)/*.o
 
test: clean all
	@./$(EXECUTE_FILE_NAME)
 
test.%: clean all
	@./$(EXECUTE_FILE_NAME) --gtest_filter=$(or $(word 2,$(subst ., ,$@)),$(value 2)).*
