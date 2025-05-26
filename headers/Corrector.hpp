#ifndef CORRECTOR_HPP
#define CORRECTOR_HPP
#include "Diccionari.hpp"
#include "ParFreq.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

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

		//Mètode auxiliar per funció processaText.
		//*Pre: Cert*/
		/*Post: Si hi ha algun d'aquests signes ". , ! ? ; ” retorna un pair on el primer terme és un bool true i el segon
		  element és el signe que s'ha eliminat, altrament el primer element és un false i el segon un string buit */
		pair<bool, string> elimina_signes(string s);

		/* Pre: Cert */
		/* Post: Si rutaInput està associat a un fitxer, llegeix el
		 text del fitxer línia a línia, corregeix cadascuna de les
		 paraules de cada línia, les escriu al fitxer associat a
		 rutaOutput i escriu al fitxer associat a rutaLog els canvis
		 que hagi fet; altrament, mostra un missatge d'error */		
		void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog);
				
		// Pre: la cua pasada per referència no és buida
		/*Post: RELLENAR*/
		string prioritzacio(queue<string> &candidates_f);
		
		//*********************************************************
		//Lectura i escriptura
		//*********************************************************		w

		/* Pre: Cert */
		/* Post: S'han escrit al fitxer associat a rutaLog totes 
		 les correccions fetes al text d'entrada sent el format de
		 cada línia paraula_original -> paraula_corregida */
		void bolcaRegistre(const string &rutaLog);

	private:
		Diccionari Dicc;	
		
		//MÈTODES PRIVATS

		/*Pre: Cert*/
		/*Post1: Es creen paraules inserint lletres a cada posició de 'paraula' pasada per paràmetre i si són dins del BST es guarden 
		dins de la cua 'candidates'*/
		/*Pos2t: Corregeix paraula insertant lletres a 's' que es creu que "falten" 
		donada paraula del diccionari que per freqüència sembla ser la més correcta.*/
		void insercio(const string &paraula, queue<string> &candidates);

		/*Pre: Cert*/
		/*Post: Corregeix paraula eliminant lletres a 's' que es creu que "sobren" 
		donada paraula del diccionari que per freqüència sembla ser la més correcta.*/
		void esborrat(const string &paraula, queue<string>&candidates);


		/*Pre: Cert*/
		/*Post: Corregeix paraula substituint lletres a 's' que es creu que "son incorrectes" 
				donada paraula del diccionari que per freqüència sembla ser la més correcta.*/
		void substitueix(const string &s, queue<string> &candidates);

		/*Pre: Cert*/
		/*Post: Corregeix paraula transposant lletres a 's' que es creu que "movent-les una posició seràn correctes" 
				donada paraula del diccionari que per freqüència sembla ser la més correcta.*/
		void transposa(const string &s, queue<string> &candidates);

};

#endif
