
# Compiladores
CC=g++
LEX=flex++

# Dependências
all: lexAnalyzer

lexAnalyzer: lexAnalyzer.o parser.o lex.yy.o
	$(CC) lexAnalyzer.o parser.o lex.yy.o -o lexAnalyzer

lexAnalyzer.o: lexAnalyzer.cpp parser.h
	$(CC) -c -std=c++17 lexAnalyzer.cpp

parser.o: parser.cpp parser.h tokens.h
	$(CC) -c -std=c++17 parser.cpp

lex.yy.o: lex.yy.cc tokens.h
	$(CC) -c -std=c++17 lex.yy.cc

lex.yy.cc: lexer.l tokens.h
	$(LEX) lexer.l

clean:
	rm lexAnalyzer lex.yy.cc lex.yy.o parser.o lexAnalyzer.o
