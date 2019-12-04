#------------------------------------------------------------------------------
# Programming Assignment 2
# Makefile
# Programmer: Tiancheng Fu
# CMPS 101
# Date: April, 22th, 2019
# Cruzid: tfu6
# Student id: 1600058
# This is a Makefile for Lex.java with Macros
#------------------------------------------------------------------------------

Lex : Lex.o List.o
	gcc -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -c -std=c99 -Wall Lex.c

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

ListClient.o : ListClient.c List.h
	gcc -c -std=c99 -Wall ListClient.c

List.o : List.c List.h
	gcc -c -std=c99 -Wall List.c

clean :
	rm -f Lex ListClient Lex.o ListClient.o List.o