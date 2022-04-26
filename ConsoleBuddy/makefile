TARGET = ConsoleBuddy

SRC_FILES = src/ConsoleBuddy.cpp src/HelperStructures.cpp src/Pixel.cpp src/Console.cpp
TEST_SRC_FILES = test/test.cpp
OBJECTS = $(SRC_FILES:.cpp=.o)
TEST_OBJECTS = $(TEST_SRC_FILES:.cpp=.o)

CXX = g++
CXX_STANDARD = -std=c++14
CFLAGS = -Wall $(CXX_STANDARD) -g

INC_PATH = include/
LIB_PATH = lib/



all: $(TARGET)


$(TARGET): $(OBJECTS)
	ar rcs $(LIB_PATH)lib$@.a $^
# ranlib $(LIB_PATH)lib$@.a


$(OBJECTS): $(SRC_FILES)
	$(CXX) $(CFLAGS) -o $@ -c $<



test: $(TARGET) $(TEST_OBJECTS)
	$(CXX) $(CFLAGS) -o $(TARGET)_$@ $(TEST_OBJECTS) -L$(LIB_PATH) -l$(TARGET)

$(TEST_OBJECTS): $(TEST_SRC_FILES)
	$(CXX) $(CFLAGS) -o $@ -c $< -I$(INC_PATH)


clean:
	rm $(OBJECTS) $(TEST_OBJECTS) $(LIB_PATH)lib$(TARGET).a

