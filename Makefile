######################################################################
# Makefile for Endless Dungeon
# Author: lgrumbach
######################################################################

EXEC = endless_dungeon

# TOOLS
CXX = g++
LD = g++

# LIBS
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# TARGET OS
ifeq ($(OS),Windows_NT)
	OS = windows
else
	UNAME := $(shell uname -s)
	ifneq (,$(findstring _NT,$(UNAME)))
		OS = windows
	else ifeq ($(UNAME),Darwin)
		OS = macOS
	else ifeq ($(UNAME),Linux)
		OS = linux
	else
    	$(error OS not supported by this Makefile)
	endif
endif
ARCH := $(shell uname -m)

# DIRECTORIES
SRC_DIR = src
BIN_DIR_ROOT = bin
ASSETS_DIR = res
LIB_DIR = lib
SFML_WIN_DIR = C:\SFML\SFML-3.0.0

# OS-SPECIFIC DIRECTORIES
BIN_DIR := $(BIN_DIR_ROOT)/$(OS)
ifeq ($(OS),windows)
	# Windows 32-bit
	ifeq ($(win32),1)
		BIN_DIR := $(BIN_DIR)32
	# Windows 64-bit
	else
		BIN_DIR := $(BIN_DIR)64
	endif
else ifeq ($(OS),macOS)
	BIN_DIR := $(BIN_DIR)-$(ARCH)
endif


# INCLUDES
INCFLAGS = -I$(LIB_DIR)
INCFLAGS += -I/usr/local/include
INCFLAGS += -Iinclude
ifeq ($(ARCH),arm64)
	INCFLAGS += -I/opt/homebrew/include
else ifeq ($(OS),windows)
	INCFLAGS += -I$(SFML_WIN_DIR)\include
endif

# COMPILER FLAGS
CXXFLAGS  = -std=c++20
CXXFLAGS += -O2
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wpedantic

# LINKER FLAGS
LDFLAGS = -lm -lstdc++

# LINKER LIBRARIES
ifeq ($(OS),macOS)
	LDFLAGS += -framework CoreGraphics -framework Foundation
	ifeq ($(ARCH),arm64)
		LDFLAGS += -L/opt/homebrew/lib
	else ifeq ($(ARCH),x86_64)
		LDFLAGS += -L/usr/local/lib
	endif
else ifeq ($(OS),linux)
	LDFLAGS += -lX11 -lpthread -lpng -lstdc++fs
else ifeq ($(OS),windows)
	LDFLAGS += -static -std=c++20 -static-libgcc -static-libstdc++
	LDFLAGS += -L$(SFML_WIN_DIR)\lib
# mark as GUI application
	LDFLAGS += -mwindows
endif

# GATHER SOURCES
ifeq ($(OS),macOS)
	SRC = $(shell find src -name "*.cpp")
else ifeq ($(OS),linux)
	SRC = $(shell find src -name "*.cpp")
else ifeq ($(OS),windows)
	find_files = $(foreach n,$1,$(shell C:\\\msys64\\\usr\\\bin\\\find.exe -L $2 -name "$n"))
	SRC = $(call find_files,*.cpp,src)
endif

OBJ = $(SRC:%.cpp=$(BIN_DIR)/%.o)
DEP = $(SRC:%.cpp=$(BIN_DIR)/%.d)
-include $(DEP)

# DIRECTORY COPY COMMAND
ifeq ($(OS),windows)
    COPY_DIRS_CMD = cmd /c 'robocopy $(SRC_DIR) $(BIN_DIR)/$(SRC_DIR) /e /xf * /mt /NFL /NDL /NJH /NJS /nc /ns /np & exit 0'
else ifeq ($(OS),macOS)
	COPY_DIRS_CMD = rsync -a --include '*/' --exclude '*' "$(SRC_DIR)" "$(BIN_DIR)"
else ifeq ($(OS),linux)
	COPY_DIRS_CMD = rsync -a --include '*/' --exclude '*' "$(SRC_DIR)" "$(BIN_DIR)"
endif

# ASSETS COPY COMMAND
ifeq ($(OS),windows)
    COPY_ASSETS_CMD = cmd /c 'robocopy $(ASSETS_DIR) $(BIN_DIR)/$(ASSETS_DIR) /s /mt /NFL /NDL /NJH /NJS /nc /ns /np & exit 0'
else ifeq ($(OS),macOS)
	COPY_ASSETS_CMD = rsync -a "$(ASSETS_DIR)" "$(BIN_DIR)"
else ifeq ($(OS),linux)
	COPY_ASSETS_CMD = rsync -a "$(ASSETS_DIR)" "$(BIN_DIR)"
endif

# TARGETS
.DEFAULT_GOAL := endless_dungeon

$(BIN_DIR):
	mkdir -p $@

createdirs: $(BIN_DIR)
	$(COPY_DIRS_CMD)

$(OBJ): $(BIN_DIR)/%.o: %.cpp
	$(CXX) -o $@ -MMD -c $< $(CXXFLAGS) $(INCFLAGS)

endless_dungeon: createdirs $(OBJ)
	$(LD) -o $(BIN_DIR)/$(EXEC) $(filter %.o, $^) $(LDFLAGS) $(LIBS)
	
copyassets:
	$(COPY_ASSETS_CMD)

run:
	./$(BIN_DIR)/$(EXEC)

dev:
	$(MAKE) -s all
	$(MAKE) -s run

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)/$(SRC_DIR)

all:
	@echo "Building for $(OS)"
	@$(MAKE) -s clean
	@$(MAKE) -s endless_dungeon
	@$(MAKE) -s copyassets
	@$(MAKE) -s clean
	@echo "Build finished"