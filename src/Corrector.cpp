#include "Corrector.hpp"
using namespace std;

/* Pre: Cert */
/* Post: Si rutaDiccionari està associat a un fitxer, llegeix
les entrades del fitxer i omple el diccionari del corrector
que crea; altrament, mostra un missatge d'error */
Corrector::Corrector(const string &rutaDiccionari) { // carrega el diccionari (BST)
	ifstream input_dic(rutaDiccionari);
	if(!input_dic.is_open()){
		throw runtime_error("ERROR. No es pot obrir l'archiu: " + rutaDiccionari);
	} else{
		string s;
		vector<ParFreq> v;
		while(getline(input_dic, s)){
			stringstream ss(s);
			ParFreq pf;
			ss >> pf.first() >> pf.second;
			v.push_back(pf)
		}
		dic.omplirBST(v, 0, v.size());
	}
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
