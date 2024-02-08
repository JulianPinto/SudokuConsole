CXX=g++
CPPFLAGS=-g -Wall
RM=rm -rf

TARGET=sudoku
SRC=src
BUILD=build
SRCS := $(shell find $(SRC) -name *.cpp)
OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))

all: $(TARGET)

$(TARGET): $(OBJS)
	echo "Building..."
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@

$(BUILD)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) build $(TARGET)
