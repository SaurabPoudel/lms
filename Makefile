ifeq ($(OS),Windows_NT)
    RM = del /Q /S
    MKDIR = mkdir
    EXECUTABLE = $(BIN_DIR)\library.exe
    DATA_DIR_SEP = \\
else
    RM = rm -rf
    MKDIR = mkdir -p
    EXECUTABLE = $(BIN_DIR)/library
    DATA_DIR_SEP = /
endif

CXX = g++
CXXFLAGS = -Wall -Werror
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DATA_DIR = data

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) | $(BIN_DIR) $(DATA_DIR)
    $(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
    $(CXX) $(CXXFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR):
    $(MKDIR) $(OBJ_DIR)

$(BIN_DIR):
    $(MKDIR) $(BIN_DIR)

$(DATA_DIR):
    $(MKDIR) $(DATA_DIR)

# Common clean target for all platforms
clean:
    $(RM) $(OBJ_DIR) $(BIN_DIR)

# Additional target for Windows
ifeq ($(OS),Windows_NT)
    clean-data-folder:
        $(RM) $(DATA_DIR)
    change-permission-win:
        echo F | xcopy /Y >NUL $(DATA_DIR)
        icacls $(DATA_DIR) /grant Everyone:F /t
endif

# Additional target for macOS
ifeq ($(shell uname -s),Darwin)
    change-permission:
        chmod -R 777 $(DATA_DIR)
endif

