CXX = clang++
CXXFLAGS = -std=c++11 -glldb
LDFLAGS =
LIBS = -lgtest -lpthread

ifeq ($(OS), Windows_NT)
	CXX = g++
	CXXFLAGS = -std=gnu++0x
	LIBS = -lgtest
	#PEEK = type utIterator.h
endif

SRC_DIR = .
INCLUDE_DIR = .
TEST_DIR = .
BUILD_DIR = .
TEST_TARGET = main
EXECUTE_FILE_NAME = hw7
EXECUTE_FILE_PATH = .
 
H_FILES = $(wildcard $(INCLUDE_DIR)/*.h)
TEST_HEADERS = $(wildcard $(TEST_DIR)/ut*.h)
HEADERS = $(filter-out $(TEST_HEADERS),$(H_FILES))
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
TEMP = $(patsubst $(SRC_DIR)/%.cpp, $(INCLUDE_DIR)/%.h, $(SOURCES))
HEADER_ONLY = $(filter-out $(TEMP),$(HEADERS))
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(BUILD_DIR)/$(TEST_TARGET).o $(OBJECTS) $(HEADER_ONLY)
	@$(CXX) -o $(EXECUTE_FILE_PATH)/$(EXECUTE_FILE_NAME) $(OBJECTS) $(LDFLAGS) $(LIBS)
	
$(BUILD_DIR)/$(TEST_TARGET).o: $(SRC_DIR)/$(TEST_TARGET).cpp $(TEST_HEADERS)
	@$(PEEK)
	@$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$(TEST_TARGET).cpp -o $(BUILD_DIR)/$(TEST_TARGET).o
 
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.h
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(EXECUTE_FILE_PATH)/$(EXECUTE_FILE_NAME)
	@$(RM) $(BUILD_DIR)/*.o
 
test: clean all
	@$(EXECUTE_FILE_PATH)/$(EXECUTE_FILE_NAME)
 
test.%: clean all
	@$(EXECUTE_FILE_PATH)/$(EXECUTE_FILE_NAME) --gtest_filter=$(or $(word 2,$(subst ., ,$@)),$(value 2)).*
