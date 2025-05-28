#ifndef PARFREQ_HPP
#define PARFREQ_HPP
#include <string>
#include <utility>

using namespace std;

class ParFreq {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una paraula amb la seva freqüència d'aparició en un corpus gran. 
	   
	private:
		pair<string, int> dades;
		//El string es la paraula insertada. Ex: "Apple"
		//El int es la freqüència donada al input juntament amb el string. Ex: "100"
		//INPUT EXEMPLE: Apple 100

	public:	
		//*********************************************************
		// Constructors
	  	//*********************************************************
	  	/*Pre: Cert*/
	  	/*Post: El resultat és un ParFreq sense cap element.*/
	  	ParFreq();

		/* Pre: Cert */
    	/* Post: el paràmetre implícit és una copia profunda de la ParFreq donada com a paràmetre. */	
		ParFreq(const ParFreq &pf);
		
		/* Pre: Cert */
		/* Post: El paràmetre implícit és una ParFreq amb s com a paraula i amb n com freqüència. */
		ParFreq(const string &s, const int &n);
		
		//*********************************************************
		// Destructor
		//*********************************************************
		/*Esborra automàticament els objectes locals en sortir d'un `àmbit de
		visibilitat.*/	   
		~ParFreq();
		
		//*********************************************************
		// Modificadors
		//*********************************************************
		/* Pre: cert*/
		/* Post: es substitueix el paràmetre implícit paraula per s.*/
		void insertParaula(const string &s);
		
		/* Pre: cert*/
		/* Post: es substitueix el paràmetre implícit freq per n.*/
		void insertFreq(const int &n);
		   
		//*********************************************************
		// Consultors
		//*********************************************************
		/* Pre: Cert */
		/* Post: El resultat és el pair del paràmetre implícit */
		pair<string, int> getPair() const;
		/* Pre: Cert */
		/* Post: El resultat és la paraula del paràmetre implícit */
		string getParaula() const;
		
		/* Pre: Cert */
		/* Post: El resultat és la freqüència del paràmetre implícit */
		int getFrequencia() const;
		
		/* Pre:  Cert  */
		/* Post: El resultat indica si la paraula del paràmetre implícit
		és igual a la paraula del parell rebut per paràmetre */ 	   
		bool operator==(const ParFreq& pf) const;

		/* Pre:  Cert  */
		/* Post: El resultat indica si la paraula del paràmetre implícit
		és més petita a la paraula del parell rebut per paràmetre */ 	
		bool operator<(const ParFreq& pf) const;

		/* Pre:  Cert  */
		/* Post: El resultat indica si la paraula del paràmetre implícit
		és més gran a la paraula del parell rebut per paràmetre */
		bool operator>(const ParFreq& other) const;

		/* Pre:  Cert  */
		/* Post: El  p.i. té ara la mateixa paraula i freqüència que el paràmetre `other`;
         retorna una referència al p.i. per paràmetre. */
		ParFreq& operator=(const ParFreq& other);
};
#endif
