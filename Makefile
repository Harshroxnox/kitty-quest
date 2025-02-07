# Debug build (with assertions & logs)
# make debug

# Release build 
# make clean
# make release

# NOTES:
# When writing recipies use space indentation
# INCLUDE -> include folder containing all the header files
# SRC -> src folder containing all cpp files
# OBJ -> obj folder will contain all the object files(.o)
# LIB -> lib contain the precompiled libraries
# The final TARGET or exe program name is main
# Layout of Recipie
# OUTPUT_FILE: DEPENDENCIES
# (TAB) Command/Action
CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDE = include
LIB = lib
LIBRARIES = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = main
# Debug and Release configurations
DEBUGFLAGS = -g -DDEBUG
RELEASEFLAGS = -O2 -DNDEBUG
# Build Debug
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: $(TARGET)
# Build Release 
release: CXXFLAGS += $(RELEASEFLAGS)
release: $(TARGET)
# All the src files with .cpp extension inside cpp folder
SRC_FILES = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
# Since initially obj folder will be empty. Make sure obj folder exists 
OBJ_FILES = $(patsubst src/%.cpp, obj/%.o, $(SRC_FILES))

# LINKING
# We get our single executable from all object files
# but wait we don't have any obj files
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

# COMPILATION
# For each file in src create the respective object file in obj/
# For compilation we don't need any libraries only header files that 
# is given with -Iinclude
obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

# Cleaning for removing all object files and main (exe)
clean:
	rm -rf $(TARGET) obj/*
