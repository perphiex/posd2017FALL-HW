CXX = clang++
CXXFLAGS = -std=c++11 -glldb
LIBS = -lgtest -lpthread
LDFLAGS =

ifeq ($(OS), Windows_NT)
	CXX = g++
	CXXFLAGS = -std=gnu++0x
	LIBS = -lgtest
	PEEK1 = type utException.h
	PEEK2 = type utExpression.h
endif

SOURCE_DIR = src
BUILD_DIR = build
EXE_FILE_DIR = .
TEST_EXE_FILE_DIR = .

EXE_FILE_NAME = shell
TEST_EXE_FILE_NAME = hw8

MAIN_FILES = $(SOURCE_DIR)/main.cpp
TEST_MAIN_FILES = $(SOURCE_DIR)/testMain.cpp

MAIN_OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o, $(MAIN_FILES))
TEST_MAIN_OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o, $(TEST_MAIN_FILES))

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o, $(SOURCES))

MAIN_OBJECTS = $(filter-out $(TEST_MAIN_OBJECT_FILES), $(OBJECTS))
TEST_MAIN_OBJECTS = $(filter-out $(MAIN_OBJECT_FILES), $(OBJECTS))

DEPENDS = ${OBJECTS:.o=.d}

all: testExe shell
	
testExe: $(TEST_MAIN_OBJECTS)
	$(PEEK1)
	$(PEEK2)
	$(CXX) -o $(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME) $(TEST_MAIN_OBJECTS) $(LDFLAGS) $(LIBS)

shell: $(MAIN_OBJECTS)
	$(CXX) -o $(EXE_FILE_DIR)/$(EXE_FILE_NAME) $(MAIN_OBJECTS) $(LDFLAGS) $(LIBS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

-include ${DEPENDS}

clean:
	$(RM) $(EXE_FILE_DIR)/$(EXE_FILE_NAME)
	$(RM) $(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME)
	$(RM) $(BUILD_DIR)/*.o
	$(RM) $(BUILD_DIR)/*.d
	$(RM) $(BUILD_DIR)/*.gcov
	$(RM) $(BUILD_DIR)/*.gcno
	$(RM) $(BUILD_DIR)/*.gcda
	$(RM) -r out
	$(RM) cov.info

test: all
	$(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME)

test.%: all
	$(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME) --gtest_filter=$(or $(word 2,$(subst ., ,$@)),$(value 2)).*
