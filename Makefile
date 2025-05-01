CXX = c++
CXXFLAGS = -std=c++11 -Wall -I./data_structures -I./algorithms

SRCS = main.cpp $(wildcard data_structures/*.cpp) $(wildcard algorithms/*.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
