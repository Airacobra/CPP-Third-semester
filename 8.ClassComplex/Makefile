CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=-g
CXXFLAGS+=-Wextra
CXXFLAGS+=-pedantic

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: Complex

Complex: $(OBJ)
	$(CXX) $(CXXLAGS) $? -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $@

.PHONY: clean

clean:
	rm -f Complex $(OBJ)
	
run: Complex
	./Complex
