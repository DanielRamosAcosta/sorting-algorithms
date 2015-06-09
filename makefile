CXX = g++
CXXFLAGS = -std=c++11 -Wall -I $(INCDIR) -o $(BINDIR)/$@ -fdiagnostics-color=always

INCDIR = include
SRCDIR = src
DOCDIR = doc
BINDIR = bin

all: $(INCDIR)/algorithms.hpp $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.cpp

doc:
	doxygen

clean:
	rm -rf bin/*