#ifndef PARFREQ_HPP
#define PARFREQ_HPP
#include <string>
using namespace std;

class ParFreq {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una paraula amb la seva freqüència
//						d'aparició en un corpus gran. 

	public:
	
		// ESPECIFICACIÓ DE LA CLASSE ParFreq
		// (especificació Pre/Post de tots els mètodes)
	
	   //*********************************************************
	   // Constructors
	   //*********************************************************
	   
	   //...
	   
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   
	   //...
	 
   	   //*********************************************************
	   // Modificadors
	   //*********************************************************
	   
	   //...
	   
	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la paraula del paràmetre implícit */
	   string getParaula() const;
	   
	   /* Pre: Cert */
	   /* Post: El resultat és la freqüència del paràmetre implícit */
	   int getFrequencia() const;
	   
	   /* Pre:  Cert  */
	   /* Post: El resultat indica si la paraula del paràmetre implícit
		és igual a la paraula del parell rebut per paràmetre */ 	   
	   bool operator==(const ParFreq pf) const;
	   
	   //...
	   
	   
	private:
		// IMPLEMENTACIÓ DE LA CLASSE ParFreq 
		// (definició del nom i tipus de cada atribut)

};
#endif