
CXX = g++
CXXFLAGS = -Iinclude -std=c++17 -Wall
LDFLAGS = -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC = main.cpp
TARGET = main

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
