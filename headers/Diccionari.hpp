#ifndef DICCIONARI_HPP
#define DICCIONARI_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "BST.hpp"
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
	   
	   //...
	   
	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   
	   //...
	 
   	   //*********************************************************
	   // Modificadors
	   //*********************************************************
	   
	   /* Pre: Cert */
	   /* Post: Si la paraula del parell rebut per  paràmetre no 
		apareixia ja al diccionari, s'ha afegit al diccionari el
		parell rebut per paràmetre; altrament, el diccionari no 
		s'ha modificat */
	   void insereix(const ParFreq &pf);  // inserció en el BST
	   
	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
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
	
		// IMPLEMENTACIÓ DE LA CLASSE Diccionari 
		// (definició del nom i tipus de cada atribut)
		// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)
};
#endif
