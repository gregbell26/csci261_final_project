TARGET = sandbox
SRC_FILES = sandbox.cpp
OBJECTS = $(SRC_FILES:.cpp=.o)

CXX = g++
CXX_STANDARD = -std=c++14
CFLAGS = -Wall $(CXX_STANDARD) -g

INC_PATH = TriHardStudios/ConsoleBuddy/include/
LIB_PATH = TriHardStudios/ConsoleBuddy/lib/

LIBS = -lConsoleBuddy

ifeq ($(OS), Windows_NT)
	CFLAGS := -D WINDOWS $(CFLAGS)
else
	CFLAGS := -D NIX $(CFLAGS)
endif

all: $(TARGET)

ConsoleBuddy:
	$(MAKE) -C TriHardStudios/ConsoleBuddy

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $< -I$(INC_PATH) 


$(TARGET): $(OBJECTS) ConsoleBuddy
	$(CXX) $(CFLAGS) -o $@ $(OBJECTS) -L$(LIB_PATH) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET) $(OBJECTS)
	$(MAKE) -C TriHardStudios/ConsoleBuddy clean