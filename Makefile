CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp \
      src/array.cpp \
      src/linked_list.cpp \
      src/doubly_linked_list.cpp \
      src/stack.cpp \
      src/queue.cpp

OUT = app

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

