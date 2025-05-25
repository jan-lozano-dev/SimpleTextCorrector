#include "Corrector.hpp"
using namespace std;

/* Pre: Cert */
/* Post: Si rutaDiccionari està associat a un fitxer, llegeix
les entrades del fitxer i omple el diccionari del corrector
que crea; altrament, mostra un missatge d'error */
Corrector::Corrector(const string &rutaDiccionari) { // carrega el diccionari (BST)
	Diccionari Dicc;
	Dicc.llegeixDeFitxer(&rutaDiccionari); //s'ompla el vector vd en la classe Diccionari
	Dicc.omplir_BST(); //s'ordena el vector alfabeticament i s'implementa en el BTS

}


/* Pre: Cert */
/* Post: Si rutaInput està associat a un fitxer, llegeix el
 text del fitxer línia a línia, corregeix cadascuna de les
 paraules de cada línia, les escriu al fitxer associat a
 rutaOutput i escriu al fitxer associat a rutaLog els canvis
 que hagi fet; altrament, mostra un missatge d'error */		
void processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog) {
	
}
		
// ...

//*********************************************************
//Lectura i escriptura
//*********************************************************		

/* Pre: Cert */
/* Post: S'han escrit al fitxer associat a rutaLog totes 
les correccions fetes al text d'entrada sent el format de
cada línia paraula_original -> paraula_corregida */
void bolcaRegistre(const string &rutaLog) {
	
}

//*********************************************************
void Corrector::bolcaRegistre(const string &rutaLog)
{
    ofstream fitxerLog(rutaLog);
	
	// escriure el contingut de l'estructura que emmagatzema
	// els registres a fitxerLog
	
	// fitxerLog << original << " -> " << corregida << endl;
}
//*********************************************************
