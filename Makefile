# Simple Makefile for SDL2 project

CXX = g++
CXXFLAGS = -Wall -std=c++17 $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

SRC = main.cpp Framebuffer.cpp
OUT = main

all:
	$(CXX) $(SRC) -o $(OUT) $(CXXFLAGS) $(LDFLAGS)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
