TARGET = ConsoleBuddy

SRC_FILES = src/ConsoleBuddy.cpp
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
	ar rvs $(LIB_PATH)/$@.a $^


$(OBJECTS): $(SRC_FILES)
	$(CXX) $(CFLAGS) -o $@ -c $<



test: $(TARGET) $(TEST_OBJECTS)
	$(CXX) $(CFLAGS) -o $(TARGET)_$@ $(LIB_PATH)$(TARGET).a $(TEST_OBJECTS) -L$(LIB_PATH) 

$(TEST_OBJECTS): $(TEST_SRC_FILES)
	$(CXX) $(CFLAGS) -o $@ -c $< -I$(INC_PATH)


