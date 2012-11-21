CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -g -ggdb
INCLUDE := -I.

# detect os
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBS := -lGL -lGLU -lSDL
endif

ifeq ($(UNAME), Darwin)
LIBS := -framework OpenGL -framework GLUT `sdl-config --cflags --libs`
endif

SOURCE := $(shell find . -type f -name "*.cpp")

default: clean butterfly

butterfly: 
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SOURCE) $(LIBS) -o butterfly

clean:
	$(shell find . -iname "*.[od]" -exec rm '{}' ';')
	$(shell rm -f butterfly)
