# Ref: Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
.EXPORT_ALL_VARIABLES:
BUILD_DIR = ./build
SRC_DIRS := ./src

CPPFLAGS := -g -Wall -std=c++17
TARGET := "19127631"

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
# OBJS := $(patsubst %,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

# The final build step.
$(TARGET): $(OBJS)
	echo $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source
# NOTE: This is pattern rule. This pattern will match: build/./src/*.cpp,
# so unable to remove './src' from output file was quite a bitter pill 😭.
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET)
	rm -r $(BUILD_DIR)
