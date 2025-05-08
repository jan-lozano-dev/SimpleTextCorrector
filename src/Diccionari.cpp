#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Diccionari
// (implementació de tots els mètodes especificats en el fitxer Diccionari.hpp)

// ...

// ...

//*********************************************************
void Diccionari::llegeixDeFitxer(const string &path)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  // llegeix un parell (paraula, freq) 
											   // per línia
		ParFreq pf(paraula, frequencia);
        insereix(pf);       // suposa que el diccionari té definida l'operació insert
    }
}

	  

