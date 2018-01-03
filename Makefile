CXX = clang++
CXXFLAGS = -std=c++11 -glldb
LIBS = -lgtest -lpthread
LDFLAGS =
MD = mkdir -p
RM = rm -rf
ifeq ($(OS), Windows_NT)
	CXX = g++
	CXXFLAGS = -std=gnu++0x
	LIBS = -lgtest
	RM = del
	MD = md
	PEEK = dir
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

all: clean testExe shell
	
testExe: $(TEST_MAIN_OBJECTS)
	$(CXX) -o $(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME) $(TEST_MAIN_OBJECTS) $(LDFLAGS) $(LIBS)

shell: $(MAIN_OBJECTS)
	$(CXX) -o $(EXE_FILE_DIR)/$(EXE_FILE_NAME) $(MAIN_OBJECTS) $(LDFLAGS) $(LIBS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

-include ${DEPENDS}

clean:
	$(PEEK)
	$(RM) $(EXE_FILE_NAME)
	$(RM) $(TEST_EXE_FILE_NAME)
	$(RM) $(BUILD_DIR)
	$(MD) $(BUILD_DIR)

test: all
	$(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME)

test.%: all
	$(TEST_EXE_FILE_DIR)/$(TEST_EXE_FILE_NAME) --gtest_filter=$(or $(word 2,$(subst ., ,$@)),$(value 2)).*
