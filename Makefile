CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Corrector.o Diccionari.o ParFreq.o
	$(LINK.cc) -o $@ $^
	
program.o: program.cpp Corrector.hpp Diccionari.hpp ParFreq.hpp BST.hpp

Corrector.o: Corrector.cpp Corrector.hpp Diccionari.hpp ParFreq.hpp BST.hpp

Diccionari.o: Diccionari.cpp Diccionari.hpp ParFreq.hpp BST.hpp

ParFreq.o: ParFreq.cpp ParFreq.hpp

clean:
	rm -vf *.o *.exe *.gch

test1: 
	./program.exe diccionari_freq1.txt sample1.inp sample1.out registre1.log
	
	diff -b sample1.out sample1.cor
	
	diff -b registre1.log registre1.cor

test2: 
	./program.exe diccionari_freq2.txt sample2.inp sample2.out registre2.log
	
	diff -b sample2.out sample2.cor
	
	diff -b registre2.log registre2.cor
	
test3: 
	./program.exe diccionari_freq3.txt sample3.inp sample3.out registre3.log
	
	diff -b sample3.out sample3.cor
	
	diff -b registre3.log registre3.cor
