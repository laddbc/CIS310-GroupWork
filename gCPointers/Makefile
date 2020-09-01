# Simplified Modular Makefile
# Build whatever source files are in src/ folder
# *.o and named executable in build folder
# clean gets rid of whole build folder
# Compiling x86 code on x86 Linux (or similar)
#   CC - the C++ compiler to use
#   ASM - the assembler to use
CC := g++
ASM := nasm

# Directory for compiled object files.
BUILD = build

# Base source directory
SOURCE = src

# Name of ekecutable file to build
EXEC_NAME = PointerProgram
EXECUTABLE := $(BUILD)/$(EXEC_NAME)

# CFLAGS - flags for the C compiler
#   -std=c++17 use the C++ 2017 standard
#   -O<n>      set optimization level applied; 0 means no optimization
#   -Wall      report all possible warnings
#   -Werror    treat any warning as an error and stop the compile
#   -g         include debug information in the .o and executable files
CFLAGS = -std=c++17 -O0 -Wall -Werror -g

# LDFLAGS - flags for the linker
#   -static    link all libraries statically rather than dynamically
LDFLAGS := -static

SRC :=  $(wildcard $(SOURCE)/*.cpp)

OBJ := $(patsubst $(SOURCE)/%.cpp,$(BUILD)/%.o,$(SRC))

all: $(BUILD) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJ)
	@echo $(SRC)
	@echo $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD)/%.o: $(SOURCE)/%.cpp
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@


# So: the build directory might not exist (see clean); it, and all
# subordinate directories, must be made. Base dir depends on any subdirs
# and is build after them. $(BUILD) is made because $(BUILDDIRS) might
# be empty.
$(BUILD): $(BUILDDIRS)
	@mkdir -p $@

# mkdir -p permits making a deeper than 1 tree AND remaking an existing
# directory. So the previous rule runs fine even if this one runs first
$(BUILDDIRS):
	@mkdir -p $@

# Rule to clean files.
.PHONY:	clean
clean :
	-rm -rf $(BUILD)
