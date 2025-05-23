#ifndef DICCIONARI_HPP
#define DICCIONARI_HPP
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "BST.hpp"
#include <algorithm>
#include <vector>
#include "ParFreq.hpp"
using namespace std;

class Diccionari {
// Tipus de mòdul: dades
// Descripció del tipus: Representa el conjunt d'entrades (paraules i freqüència)
//						d'un diccionari.
	
	public:
  	
	   //*********************************************************
	   // Constructors
	   //*********************************************************
	   /* Pre: Cert */
	   /* Post: El resultat és un Diccionari sense cap ParFeq */	
	   Diccionari();

	   //...
	   
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   /* Esborra automàticament els objectes locals
       en sortir d'un àmbit de visibilitat */
		~Diccionari();

	   //...
	 
   	   //*********************************************************
	   // Modificadors
	   //*********************************************************
	   /* Pre: Cert */
	   /* Post: Si la paraula del parell rebut per  paràmetre no 
		apareixia ja al diccionari, s'ha afegit al diccionari el
		parell rebut per paràmetre; altrament, el diccionari no 
		s'ha modificat */
		void crear_BTS(const vector<ParFreq> &v); // inserció en el BST 

	   /* Pre: Cert */
	   /* Post: Si la paraula del parell rebut per  paràmetre no 
		apareixia ja al diccionari, s'ha afegit al diccionari el
		parell rebut per paràmetre; altrament, el diccionari no 
		s'ha modificat */
	   //void insereix(const ParFreq &pf);  // inserció en el BST
	   

	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
	   // Pre: Cert
	   // Post: retorna el vector 'vd' de ParFreq's del Diccionari 
	   vector<ParFreq> getVector();

	   /* Pre:  Cert  */
	   /* Post: El resultat indica si el diccionari conté la
	   paraula rebuda per paràmetre */	   
	   bool conte(const string &paraula) const; // cerca en el BST
	   
	   /* Pre: La paraula rebuda per paràmetre està en el
		diccionari */
	   /* Post: El resultat és la freqüència que apareix al
		diccionari de la paraula rebuda per paràmetre */	 
	   int getFrequencia(const string &paraula) const;
	   
	   //...
	   
	   //...
	   
	   //*********************************************************
	   //Lectura i escriptura
	   //*********************************************************
	   
	   /* Pre: Cert */
	   /* Post: Si el path rebut per paràmetre està associat a un
		fitxer, llegeix el fitxer de parells (paraula, freqüència)
		i omple el diccionari; altrament, mostra un missatge 
		d'error.*/
	   void llegeixDeFitxer(const string &path);
	  
	private:
	vector <ParFreq> vd;
	BST <ParFreq> arbreOrd;
		// IMPLEMENTACIÓ DE LA CLASSE Diccionari 
		// (definició del nom i tipus de cada atribut)
		// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)
};
#endif
