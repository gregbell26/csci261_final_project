TARGET = ConsoleBuddy

SRC_FILES = src/Pixel.cpp src/HelperStructures.cpp  src/Console.cpp src/ConsoleBuddy.cpp
TEST_SRC_FILES = test/test.cpp
OBJECTS = $(SRC_FILES:.cpp=.o)
TEST_OBJECTS = $(TEST_SRC_FILES:.cpp=.o)

CXX = g++
CXX_STANDARD = -std=c++14
CFLAGS = -Wall $(CXX_STANDARD) -g

INC_PATH = include/
LIB_PATH = lib/

LIBS = -l$(TARGET)

ifeq ($(OS), Windows_NT)
	CFLAGS := -D WINDOWS $(CFLAGS)
else
	CFLAGS := -D NIX $(CFLAGS)
endif



all: $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $< -I$(INC_PATH) 

$(LIB_PATH):
	mkdir $@

$(TARGET): $(LIB_PATH)lib$(TARGET).a

$(LIB_PATH)lib$(TARGET).a: $(OBJECTS) | $(LIB_PATH)
	ar rvs $@ $^


test: $(TARGET) $(TEST_OBJECTS)
	$(CXX) $(CFLAGS) -o $(TARGET)_$@ $(TEST_OBJECTS) -L$(LIB_PATH) $(LIBS)
	./$(TARGET)_$@


clean:
	rm $(OBJECTS) $(TEST_OBJECTS) $(LIB_PATH)lib$(TARGET).a

