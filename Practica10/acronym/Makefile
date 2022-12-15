
EXE_NAME=acronym
CXX=g++
CXXFLAGS=-std=c++17 -Wall
SRCDIR=.
INCLUDEDIR=.
OUTDIR=bin
CPPFLAGS=-I./$(INCLUDEDIR)
DEPS=$(wildcard $(SRCDIR)/*.cc)
DIRPATH=$(shell realpath .)
DIRNAME=$(shell basename $(DIRPATH))

default_target: all

all: clean build

build: $(DEPS)
	mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $(OUTDIR)/$(EXE_NAME) $^

clean: 
	rm -rf $(OUTDIR)

tar:
	cd ..; tar cvfz $(DIRNAME)/PortilloGarciaJoseAngel-$(NAME).tar.gz --exclude-from=./$(DIRNAME)/.gitignore $(DIRNAME)

.PHONY: all build clean