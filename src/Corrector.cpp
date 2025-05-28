#include <iostream>
#include "Corrector.hpp"
using namespace std;

/* Pre: Cert */
/* Post: Si rutaDiccionari està associat a un fitxer, llegeix les entrades del fitxer i omple el diccionari del corrector
que crea; altrament, mostra un missatge d'error */
Corrector::Corrector(const string &rutaDiccionari) { // carrega el diccionari (BST)
	Dicc.llegeixDeFitxer(rutaDiccionari); //s'ompla el vector vd en la classe Diccionari
	Dicc.omplir_BST(); //s'ordena el vector alfabeticament i s'implementa en el BTS
}

//*Pre: Cert*/
/*Post: Si hi ha algun d'aquests signes ". , ! ? ; ” retorna un pair on el primer terme és un bool true i el segon
element és el signe que s'ha eliminat, altrament el primer element és un false i el segon un string buit */
pair<bool, string> Corrector::elimina_signes(string &s) {
	string signes = ".,!?";
	pair<bool, string> res;
	res.first = false;
	unsigned int i = 0;
	if(s.length() != 0){
		unsigned int signes_length = signes.length();
	        while (i < s.length() && !res.first) {
				// Inv: el bucle ha comparat  cada caràcter de 's' amb cada caràcter de 'signes' i para si trobar alguna igualtat
	            unsigned int j = 0;
	            while (j < signes_length && !res.first) {
					// Inv: Compara amb cada caràcter de string amb el caràcter s[i]
	                if (s[i] == signes[j]) {
	                    res.first = true;
	                    res.second = s[i];  
	                    s.erase(i, 1);     
	                }
	                j++;
	            }
	            i++;
	        }
	}
	return res;
}
		
// Pre: la cua pasada per referència no és buida
// Post: s'ha extret de la cua de candidates el string que té adjunta en el seu ParFreq del Diccionari Dicc la freqüència més alta*/
string Corrector::prioritzacio(queue <string> &candidates_f) {
    string res;
    int maxim = 0; // Inicialitzem amb un valor petit

    while (!candidates_f.empty()) {
		//Inv: s'ha extret de la cua de candidates el string que té adjunta en el seu ParFreq del Diccionari Dicc la freqüència més alta*/
		//Fita: candidates_f.size()
        string element = candidates_f.front(); 
        int freq_e = Dicc.getFrequencia(element);
        if (freq_e > maxim) {
            maxim = freq_e;
            res = element;
        }
        candidates_f.pop(); 
    }


    return res;
}


//MÈTODES PRIVATS
/*Pre: Cert*/
/*Post1: Es creen paraules inserint lletres a cada posició de 's' pasada per paràmetre i si són dins del BST es guarden 
dins de la cua 'candidates'*/
void Corrector::insercio(const string &s, queue<string> &candidates) {
    string s_prova;
    string tot = "abcdefghijklmnopqrstuvwxyz";
    bool trobada = false;
    for (unsigned int i = 0; i < s.size()+1; ++i){
        //INV: Es generen noves paraules en la posició 'i' de 's_prova' afegint tots els caràcters posibles de 'tot'.
		//Fita: s.size()+1 - i
        for (unsigned int j = 0; j < tot.size(); ++j) {
            //INV: Es genere una nova paraula  per cada lletra mínuscula de l'abecedari
	    	//	   i si es troba en el BST es guarda en la cua 'candidates'.
			//Fita: tot.size() - j

            s_prova = s; 
            s_prova.insert(i, 1, tot[j]); 
											
			trobada = Dicc.conte(s_prova);							  
            if (trobada == true) candidates.push(s_prova);
        }
    }
}

/*Pre: Cert*/
/*Post: Corregeix paraula eliminant lletres a 's' que es creu que "sobren" 
i si la nova formada és dins del Diccionari s'afegeix a la cua de 'candidates'.*/
void Corrector::esborrat(const string &s, queue<string>&candidates) {
	string s_prova;
	unsigned int n = s.size();
	for (unsigned int i = 0; i < n; ++i) {
		/*INV: s'elimina  caràcter posició 'i' de 'paraula' i si nova creació dins BST, s'insereix en cua 'candidates'*/
		//Fita: n-i
        	s_prova = s;
        	s_prova.erase(i, 1); 
        	if (!s_prova.empty() and Dicc.conte(s_prova)) candidates.push(s_prova);
    }
}

/*Pre: Cert*/
/*Post: Corregeix paraula substituint lletres a 's' que es creu que "son incorrectes" 
i si la nova formada és dins del Diccionari s'afegeix a la cua de 'candidates'.*/
void Corrector::substitueix(const string &s, queue<string> &candidates){
	string aux;
	string abecedari = "abcdefghijklmnopqrstuvwxyz";
	unsigned int n = s.length();
	for(unsigned int i = 0; i < n; ++i){
		//Inv: el bucle ha substituit  cada caràcter de 'aux' amb cada caràcter de 'abecedari' i
		// si la nova paraula formada és dins del Diccionari s'afegeix a la cua de 'candidates'
		//Fita: n-i
        aux = s;
		unsigned int a_length = abecedari.length();
		for(unsigned int j = 0; j < a_length; ++j){
			//Inv: el bucle ha substuit cada caràcter de 'abecedari' amb el caràcter aux[i] i
			// si la nova paraula formada és dins del Diccionari s'afegeix a la cua de 'candidates'
			//Fita: abecedari.length()-j
            if (aux[i] != abecedari[j]) {
			    aux[i] = abecedari[j];
			    if(Dicc.conte(aux)) candidates.push(aux);
            }
		}
	}
}

/*Pre: Cert*/
/*Post: Corregeix paraula transposant lletres a 's' que es creu que movent-les una posició "seràn correctes" 
i si la nova formada és dins del Diccionari s'afegeix a la cua de 'candidates'.*/
void Corrector::transposa(const string &s, queue<string> &candidates){
	string aux;
	unsigned int n = s.size() - 1;
	for(unsigned int i = 0; i < n; ++i){
		//Inv: el bucle ha intercanviat cada caràcter de 's' amb el caràcter aux[i] i
		// si la nova paraula formada és dins del Diccionari s'afegeix a la cua de 'candidates'
		//Fita: n-i
		aux = s;
		swap(aux[i], aux[i + 1]);
		if(Dicc.conte(aux)) candidates.push(aux);
	}
}

/* Pre: Cert */
/* Post: Si rutaInput està associat a un fitxer, llegeix el text del fitxer línia a línia, corregeix cadascuna de les
 paraules de cada línia, les escriu al fitxer associat a rutaOutput i escriu al fitxer associat a rutaLog els canvis
 que hagi fet; altrament, mostra un missatge d'error */		
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog) {
    ifstream fitxer(rutaInput);
	if(!fitxer.is_open()){
		throw runtime_error("ERROR. No es pot obrir el fitxer: " + rutaInput);
	} else{
		ofstream output_fitxer(rutaOutput);
		if(!output_fitxer.is_open()){
			cerr << "ERROR. No es pot obrir fitxer output." << endl;
		} else{
			ofstream register_fitxer(rutaLog);
			if(!register_fitxer.is_open()){
				cerr << "ERROR. No es pot obrir fitxer registre." << endl;
		} else {	
               	string s;
				while(getline(fitxer, s)){
					//Inv: Llegeix les línies del fitxer han estat llegides i processa les paraules del fitxer d'acord amb la Post de la funció 'processaText'
					//Fita: nombre de línies del fitxer d'entrada per rutaInput
					bool primera_p = true;
					stringstream ss(s);
					string paraula_i;

					while(ss >> paraula_i) {
						//Inv: S’han processat totes les paraules de la línia 'ss' i tractades d'acord amb la Post de la funció 'processaText'
						//Fita: nombre de strings separats per espais de cada línea
						queue <string> candidates_i;
						pair<bool, string> signes =  elimina_signes(paraula_i);
						string paraula = paraula_i; 
						
						if(!Dicc.conte(paraula_i)) {                    
							insercio(paraula, candidates_i);
							esborrat(paraula, candidates_i);
							substitueix(paraula, candidates_i);
							transposa(paraula, candidates_i);
							if(!candidates_i.empty()){
								paraula = prioritzacio(candidates_i); /* funció escull paraula de candidates amb freqüència més alta i afegeix a candidates_f */
								register_fitxer << paraula_i << " -> " << paraula << endl;
							}
						}
						if(!primera_p){
							output_fitxer << " ";
						}
						else { primera_p = false;} 
					output_fitxer << paraula + signes.second;
					}
					output_fitxer << endl;
				}
            }
        }
    }
}
