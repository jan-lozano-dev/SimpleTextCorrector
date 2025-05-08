#include <iostream>
#include "Corrector.hpp"
using namespace std;

int main(int argc,  char **argv) 
{
	if (argc == 5) {
		string rutaDiccionari(argv[1]);
		string rutaInput(argv[2]);
		string rutaOutput(argv[3]);
		string rutaLog(argv[4]);
		try {
			Corrector corrector(rutaDiccionari);		
			corrector.processaText(rutaInput, rutaOutput, rutaLog);
		} 
		catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	}
	else {
		try {
			Corrector corrector("diccionari_freq1.txt");		
			corrector.processaText("sample1.inp", "sample1.out", "registre1.log");
		} 
		catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	}
}
