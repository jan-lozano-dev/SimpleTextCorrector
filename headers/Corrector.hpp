#ifndef CORRECTOR_HPP
#define CORRECTOR_HPP
#include "Diccionari.hpp"
#include "ParFreq.hpp"
#include <algorithm>
#include <vector>
using namespace std;

class Corrector {
// Tipus de mòdul: dades
// Descripció del tipus: Emmagatzema un diccionari de parells (paraula, freqüència)
//						 i proporciona mètodes per llegir un text pla d'un fitxer de
//						 text, corregir-lo ortogràficament i escriure'l corregit en
//						 un fitxer de text. La correcció ortogràfica d'una paraula
//						 s'obté generant paraules candidates a distància d'edició 1,
//						 que es trobin en el diccionari i donant com a resultat la
//						 de major freqüència. 
//						 També emmagatzema i escriu en un fitxer de registre els
//						 canvis fets en el fitxer original.
	
	public:
	
		//*********************************************************
		// Constructors
		//*********************************************************
		
		/* Pre: Cert */
		/* Post: Si rutaDiccionari està associat a un fitxer, llegeix
		 les entrades del fitxer i omple el diccionari del corrector
		 que crea; altrament, mostra un missatge d'error */
		Corrector(const string &rutaDiccionari);   // carrega el diccionari (BST)

		//*********************************************************
		// Modificadors
		//*********************************************************
		
		/* Pre: Cert */
		/* Post: Si rutaInput està associat a un fitxer, llegeix el
		 text del fitxer línia a línia, corregeix cadascuna de les
		 paraules de cada línia, les escriu al fitxer associat a
		 rutaOutput i escriu al fitxer associat a rutaLog els canvis
		 que hagi fet; altrament, mostra un missatge d'error */		
		void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog);
		
		//...
	   
		//...
		
		//*********************************************************
		//Lectura i escriptura
		//*********************************************************		

		/* Pre: Cert */
		/* Post: S'han escrit al fitxer associat a rutaLog totes 
		 les correccions fetes al text d'entrada sent el format de
		 cada línia paraula_original -> paraula_corregida */
		void bolcaRegistre(const string &rutaLog);
		

	private:
		// IMPLEMENTACIÓ DE LA CLASSE Corrector 
		// (definició del nom i tipus de cada atribut)
		// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)
		

};

#endif
