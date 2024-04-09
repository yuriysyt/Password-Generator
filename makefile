CXX = g++
CXXFLAGS = -std=c++14

SRCS = main.cpp src/PasswordGenerator.cpp
TARGET = main

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

.PHONY: clean

clean:
	rm -f $(TARGET)
