CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -g -ggdb
LIBS := -l GL -lGLU -lSDL
INCLUDE := -I.

SOURCE := $(shell find . -type f -name "*.cpp" -printf "%P\n")

default: butterfly

butterfly: 
	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SOURCE) $(LIBS) -o butterfly

clean:
	$(shell find . -iname "*.[od]" -exec rm '{}' ';')
	$(shell rm -f butterfly)
