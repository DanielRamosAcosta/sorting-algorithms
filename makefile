CXX = g++
CXXFLAGS = -std=c++11 -Wall -I $(INCDIR) -o $(BINDIR)/$@ -fdiagnostics-color=always

INCDIR = include
SRCDIR = src
DOCDIR = doc
BINDIR = bin

HEXT = hpp
SEXT = cpp

insertionSort: $(INCDIR)/insertionSort.$(HEXT) $(SRCDIR)/main.$(SEXT)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.$(SEXT)

selectionSort: $(INCDIR)/selectionSort.$(HEXT) $(SRCDIR)/main.$(SEXT)
	$(CXX) $(CXXFLAGS) $(SRCDIR)/main.$(SEXT)

doc:
	doxygen

clean:
	rm -rf bin/*