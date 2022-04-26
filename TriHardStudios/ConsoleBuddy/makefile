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
	CFLAGS := -D WINDOWS
else
	CFLAGS := -D NIX
endif



all: $(TARGET)


$(TARGET): $(OBJECTS)
	ar rvs $(LIB_PATH)lib$@.a $^


%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

test: $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CFLAGS) -o $(TARGET)_$@ $(TEST_OBJECTS) -L$(LIB_PATH) $(LIBS)
#   $(CXX) $(CFLAGS) -o $(TARGET)_$@ $^
	./$(TARGET)_$@

$(TEST_OBJECTS):$(TEST_SRC_FILES)
	$(CXX) $(CFLAGS) -o $@ -c $< -I$(INC_PATH) 


clean:
	rm $(OBJECTS) $(TEST_OBJECTS) $(LIB_PATH)lib$(TARGET).a

