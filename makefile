CXX = g++
CXXFLAGS = -std=c++11 -Wall -I $(INCDIR) -o $(BINDIR)/$@ -fdiagnostics-color=always

INCDIR = include
SRCDIR = src
DOCDIR = doc
BINDIR = bin

HEXT = hpp
SEXT = cpp

insertionSort: $(INCDIR)/insertionSort.$(HEXT) $(SRCDIR)/insertionSort.$(SEXT)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/$@.$(SEXT)