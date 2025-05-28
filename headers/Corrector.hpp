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
		Corrector(const std::string &rutaDiccionari);   // carrega el diccionari (BST)

		//*********************************************************
		// Modificadors
		//*********************************************************

		//Mètode auxiliar per funció processaText.
		//*Pre: Cert*/
		/*Post: Si hi ha algun d'aquests signes ". , ! ? ; ” retorna un pair on el primer terme és un bool true i el segon
		element és el signe que s'ha eliminat, altrament el primer element és un false i el segon un string buit */
		std::pair<bool, std::string> elimina_signes(std::string &s);

		// Pre: la cua pasada per referència no és buida
		/* Post: s'ha extret de la cua de candidates el string que té adjunta en el seu ParFreq del Diccionari Dicc la freqüència més alta*/
		std::string prioritzacio(queue<std::string> &candidates_f);

		/* Pre: Cert */
		/* Post: Si rutaInput està associat a un fitxer, llegeix el
		 text del fitxer línia a línia, corregeix cadascuna de les
		 paraules de cada línia, les escriu al fitxer associat a
		 rutaOutput i escriu al fitxer associat a rutaLog els canvis
		 que hagi fet; altrament, mostra un missatge d'error */		
		void processaText(const std::string &rutaInput, const std::string &rutaOutput, const std::string &rutaLog);

	private:
		Diccionari Dicc;	
		
		//MÈTODES PRIVATS
		/*Pre: Cert*/
		/*Post: Es creen paraules inserint lletres a cada posició de 's' pasada per paràmetre i si són dins del BST es guarden 
		dins de la cua 'candidates'*/
		void insercio(const std::string &s, queue<std::string> &candidates);

		/*Pre: Cert*/
		/*Post: Corregeix paraula eliminant lletres a 's' que es creu que "sobren" 
		i si la nova formada és dins del Diccionari s'afegeix a la cua de 'candidates'.*/
		void esborrat(const std::string &s, queue<std::string>&candidates);


		/*Pre: Cert*/
		/*Post: Corregeix paraula substituint lletres a 's' que es creu que "son incorrectes" 
		i si la nova formada és dins del Diccionari s'afegeix a la cua de 'candidates'.*/
		void substitueix(const std::string &s, queue<std::string> &candidates);

		/*Pre: Cert*/
		/*Post: Corregeix paraula transposant lletres a 's' que es creu que "movent-les una posició seràn correctes" 
		i si la nova formada és dins del Diccionari s'afegeix a la cua de 'candidates'.*/
		void transposa(const std::string &s, queue<std::string> &candidates);
};

#endif
