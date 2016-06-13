# Specify source some directories and some names
SOURCEDIR = $(shell pwd)
LIB  = palindromes
INSTALLDIR  = ../../palindromes_install
BUILDDIR = ../../palindromes_build/bin
BUILDSRCDIR = ../../palindromes_build/src

# Specify compilers and flags
CXX = g++
CXXFLAGS= --std=c++11 -Wall -g  

HEADERSDIR = $(SOURCEDIR)/../src
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%,$(SOURCES))

# Default target
.PHONY: install
install: build
	if [ ! -d "$(INSTALLDIR)"/bin ]; then mkdir "$(INSTALLDIR)"/bin; fi 
	cp "$(BUILDDIR)"/* "$(INSTALLDIR)"/bin/

.PHONY: uninstall
uninstall: 
	if [ -d "$(INSTALLDIR)"/bin ]; then rm -f "$(INSTALLDIR)"/bin/*; fi

.PHONY: build
build: $(OBJECTS)

$(OBJECTS): $(BUILDDIR)/% : $(SOURCEDIR)/%.cpp 
	if [ ! -d "$(BUILDDIR)" ]; then mkdir "$(BUILDDIR)"; fi
	$(CXX) $(CXXFLAGS) $< -I $(HEADERSDIR) -L$(BUILDSRCDIR) -l$(LIB) -o $@ 

.PHONY: clean 
clean:
	rm -f $(BUILDDIR)/*;

