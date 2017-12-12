CXX = clang++
CXXFLAGS = -std=c++11 -glldb
LIBS = -lgtest -lpthread

ifeq ($(OS), Windows_NT)
	CXX = g++
	CXXFLAGS = -std=gnu++0x
	LIBS = -lgtest
endif

SOURCE_DIR = src
BUILD_DIR = build
EXE_FILE_DIR = .

EXE_FILE_NAME = hw7

SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o, $(SOURCES))

DEPENDS = ${OBJECTS:.o=.d}

all: $(OBJECTS)
	$(CXX) -o $(EXE_FILE_DIR)/$(EXE_FILE_NAME) $(OBJECTS) $(LIBS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

-include ${DEPENDS}

clean:
	$(RM) $(EXE_FILE_DIR)/$(EXE_FILE_NAME)
	$(RM) $(BUILD_DIR)/*.o
	$(RM) $(BUILD_DIR)/*.d

test: all
		$(EXE_FILE_DIR)/$(EXE_FILE_NAME)

test.%: all
		$(EXE_FILE_DIR)/$(EXE_FILE_NAME) --gtest_filter=$(or $(word 2,$(subst ., ,$@)),$(value 2)).*