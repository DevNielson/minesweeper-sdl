CXX := g++
VERSION := -std=c++23
WARNINGS := -Wall -Wextra -g
OPTIMIZATION := -O2
CXX_FLAGS := $(VERSION) $(WARNINGS) $(OPTIMIZATION)
CXX_LINKERS := -lstdc++exp

BIN_DIR := ../bin
BUILD_DIR := ../build
INCLUDE_DIR := -I ../include
SRC_DIR := ../src
SOURCE := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.cpp.o,$(SOURCE))
TARGET := $(BIN_DIR)/Minesweeper.exe

SDL_INCLUDE := -I ../SDL*/x86_64-w64-mingw32/include
SDL_LIB := -L ../SDL*/x86_64-w64-mingw32/lib
SDL_LINKERS := -lSDL3

INCLUDES :=  $(INCLUDE_DIR) $(SDL_INCLUDE)
LIBS := $(SDL_LIB)
LINKERS := $(CXX_LINKERS) $(SDL_LINKERS)

.PHONY: all
all: $(TARGET)

.PHONY: run
run: $(TARGET)
	@$^

$(TARGET): $(OBJECTS)
	@$(CXX) $(CXX_FLAGS) -o $@ $^ $(INCLUDES) $(LIBS) $(LINKERS)

$(BUILD_DIR)/%.cpp.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXX_FLAGS) -c -o $@ $< $(INCLUDES) $(LIBS)

.PHONY: clean
clean:
	@rm $(BUILD_DIR)/*.o $(TARGET)
