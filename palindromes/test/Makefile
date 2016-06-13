# Specify source some directories and some names
SOURCEDIR = $(shell pwd)
BUILDDIR = ../../palindromes_build/test
BUILDSRCDIR = ../../palindromes_build/src
INCLUDES = -I $(SOURCEDIR)/../src -I ../../googletest-release-1.7.0/include
LIBS  = -lpalindromes -lgtest -lpthread
LIBSFOLDERS = -L$(BUILDSRCDIR) -L../../googletest-release-1.7.0_build

# Specify compilers and flags
CXX = g++
CXXFLAGS= --std=c++11 -Wall -g  

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%,$(SOURCES))

.PHONY: build
build: $(OBJECTS)

$(OBJECTS): $(BUILDDIR)/% : $(SOURCEDIR)/%.cpp 
	if [ ! -d "$(BUILDDIR)" ]; then mkdir "$(BUILDDIR)"; fi
	if [ ! -d "$(BUILDDIR)"/data ]; then cp -r "$(SOURCEDIR)"/data "$(BUILDDIR)"/data; fi
	$(CXX) $(CXXFLAGS) $< $(INCLUDES) $(LIBSFOLDERS) $(LIBS) -o $@ 

.PHONY: clean 
clean:
	rm -rf $(BUILDDIR)/*;

.PHONY: test
test:
	for testExe in $(BUILDDIR)/*; do if [ -f $$testExe ]; then $$testExe; fi done
	

