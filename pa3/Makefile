#------------------------------------------------------------------------------
# Assignment: Programming Assignment 3 (pa3)
# Makefile
# Programmer: Tiancheng Fu
# CMPS 101
# Date: May, 13th, 2019
# Cruzid: tfu6
# Student id: 1600058
# This is a Makefile for Sparse.java with Macros
#------------------------------------------------------------------------------

JAVAC      = javac
MAINCLASS  = Sparse
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) Makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS)

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest

%.class: %.java
	$(JAVAC) $<

clean:
	rm *.class $(JARFILE)

check:
	
	ls  /afs/cats.ucsc.edu/class/cmps101-pt.s19/pa3/tfu6