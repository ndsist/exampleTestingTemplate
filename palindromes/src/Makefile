# Specify source some directories and some names
SOURCEDIR = $(shell pwd)
OUTPUTFILE  = libpalindromes.a
INSTALLDIR  = ../../palindromes_install
BUILDDIR = ../../palindromes_build/src
EXECUTABLE = main

# Specify compilers and flags
CXX = g++
CXXFLAGS= --std=c++11 -Wall -g -c 

# Specify extensions of files to delete when cleaning
CLEANEXTS = o a

HEADERS = $(wildcard $(SOURCEDIR)/*.hpp)
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Default target
.PHONY: install
install: build
	if [ ! -d "$(INSTALLDIR)"/include ]; then mkdir "$(INSTALLDIR)"/include; fi 
	cp "$(HEADERS)" "$(INSTALLDIR)"/include/;
	if [ ! -d "$(INSTALLDIR)"/lib ]; then mkdir "$(INSTALLDIR)"/lib; fi
	cp "$(BUILDDIR)"/"$(OUTPUTFILE)" "$(INSTALLDIR)"/lib/

.PHONY: uninstall
uninstall: 
	if [ -d "$(INSTALLDIR)"/include ]; then rm -f "$(INSTALLDIR)"/include/*; fi
	if [ -d "$(INSTALLDIR)"/lib ]; then rm -f "$(INSTALLDIR)"/lib/*; fi

.PHONY: build
build: $(OUTPUTFILE)

# http://stackoverflow.com/a/37701195
# Build libpalindromes.a from palindromesFinder.o
$(OUTPUTFILE): $(OBJECTS)
	ar rcs $(BUILDDIR)/$@ $^

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp  $(SOURCEDIR)/%.hpp   #it gets inefficient with multiple files, in that case see http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/ instead 
	if [ ! -d "$(BUILDDIR)" ]; then mkdir "$(BUILDDIR)"; fi
	$(CXX) $(CXXFLAGS) -I $(SOURCEDIR) $< -o $@

.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -f $(BUILDDIR)/*.$$file; done

