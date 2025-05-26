#include "Corrector.hpp"
using namespace std;

Corrector::Corrector(const string &rutaDiccionari) { // carrega el diccionari (BST)
	Dicc.llegeixDeFitxer(rutaDiccionari); //s'ompla el vector vd en la classe Diccionari
	Dicc.omplir_BST(); //s'ordena el vector alfabeticament i s'implementa en el BTS
}

pair<bool, string> Corrector::elimina_signes(string s) {
	string signes = ".,!?";
	pair<bool, string> res;
	res.first = false;
	res.second = "";
	unsigned int i = 0;
	if(s.length() != 0){
		unsigned int signes_length = signes.length();
        
	        // Cerca per cada caràcter de s
	        while (i < s.length() && !res.first) {
	            unsigned int j = 0;
	            // Compara amb cada caràcter de signes
	            while (j < signes_length && !res.first) {
	                if (s[i] == signes[j]) {
	                    res.first = true;
	                    res.second = s[i];  // Caràcter eliminat
	                    s.erase(i, 1);     // Elimina el caràcter de s
	                }
	                j++;
	            }
	            i++;
	        }
	}
	return res;
}
		
// Pre: la cua pasada per referència no és buida
// Post: 
string Corrector::prioritzacio(queue <string> &candidates_f) {
    string res;
    int maxim = 0; // Inicialitzem amb un valor petit

    while (!cua.empty()) {
        string element = candidates_f.front(); // Agafem el primer element de la cua
        int freq_e = Dicc.getFrequencia(element);
        if (freq_e > maxim) {
            maxim = freq_e;
            res = element;
        }
        candidates_f.pop(); // Eliminem l'element processat
    }


    return res;
}

//string correcio(const string &s);

//*********************************************************
//Lectura i escriptura
//*********************************************************		
/* Pre: Cert */
/* Post: S'han escrit al fitxer associat a rutaLog totes 
les correccions fetes al text d'entrada sent el format de
cada línia paraula_original -> paraula_corregida */
void Corrector::bolcaRegistre(const string &rutaLog)
{
    ofstream fitxerLog(rutaLog);
	
	// escriure el contingut de l'estructura que emmagatzema
	// els registres a fitxerLog
	
	// fitxerLog << original << " -> " << corregida << endl;
}
//*********************************************************

//MÈTODES PRIVATS
void Corrector::insercio(const string &s, queue<string> &candidates) {
    string s_prova;
    string tot = "abcdefghijklmnopqrstuvwxyz";
    bool trobada = false;
    for (unsigned int i = 0; i < s.size()+1; ++i){
        //INV: Es generen noves paraules en la posició 'i' de 'paraula'.
        for (unsigned int j = 0; j < tot.size(); ++j) {
            //INV: Es genere una nova paraula per cada lletra mínuscula de l'abecedari (per tot[j]) en la posició 'i' de 'paraula'
	    //	   i si es troba en el BST es guarda en la cua 'candidates'.
            s_prova = s; //igualem per evitar modificacions anteiors
            s_prova.insert(i, 1, tot[j]); // '.insert' és una funció implementada amb la llibreria string que insereix a la
		// posició 'i' de 's_prova' 1 vegada el caràcter equivalent a 'tot[j]'
			trobada = Dicc.conte(s_prova);							  
            if (trobada == true) candidates.push(s_prova);
        }
    }
}


void Corrector::esborrat(const string &s, queue<string>&candidates) {
	string s_prova;
	unsigned int n = s.size();
	for (unsigned int i = 0; i < n; ++i) {
		/*INV: s'elimina  caràcter posició 'i' de 'paraula' i si nova creació dins BST, s'insereix en cua 'candidates'*/
        	s_prova = s;
        	s_prova.erase(i, 1); 
        	if (!s_prova.empty() and Dicc.conte(s_prova)) candidates.push(s_prova);
    }
}

void Corrector::substitueix(const string &s, queue<string> &candidates){
	string aux;
	string abecedari = "abcdefghijklmnopqrstuvwxyz";
	unsigned int n = s.length();
	for(unsigned int i = 0; i < n; ++i){
		//Inv:
		unsigned int a_length = abecedari.length();
		for(unsigned int j = 0; i < a_length; ++j){
			aux[i] = abecedari[j];
			if(Dic.conte(aux)) candidates.push(aux);
		}
	}
}

void Corrector::transposa(const string &s, queue<string> &candidates){
	string aux;
	unsigned int n = s.size() - 1;
	for(unsigned int i = 0; i < n; ++i){
		//Inv: 
		aux = paraula;
		swap(aux[i], aux[i + 1]);
		if(dic.conte(aux)) candidates.push(aux);
	}
}

/* Pre: Cert */
/* Post: Si rutaInput està associat a un fitxer, llegeix el
 text del fitxer línia a línia, corregeix cadascuna de les
 paraules de cada línia, les escriu al fitxer associat a
 rutaOutput i escriu al fitxer associat a rutaLog els canvis
 que hagi fet; altrament, mostra un missatge d'error */		
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog) {
    ifstream fitxer(rutaInput);
	if(!fitxer.is_open()){
		throw runtime_error("ERROR. No es pot obrir el fitxer: " + rutaInput);
	} else{
		ofstream output_fitxer(rutaLog);
		if(!output_fitxer.is_open()){
			cerr << "ERROR. No es pot obrir fitxer output." << endl;
		} else{
			ofstream register_fitxer(rutaLog);
			if(!register_fitxer.is_open()){
				cerr << "ERROR. No es pot obrir fitxer registre." << endl;
		} else {	
               		 string s;
               
                	while(getline(fitxer, s)){
					//Inv: ?
				stringstream ss(s);
				string paraula_i;
				bool primera_p = true;
	
				while(ss >> paraula_i) {
					queue <string> candidates_i;
					pair signes =  elimina_signes(paraula_i);
					string paraula = paraula_i; 
					
					if(!Dicc.conte(paraula_i)) {                    
		
						insercio(paraula, candidates_i);
						esborrat(paraula, candidates_i);
						substitueix(paraula, candidates_i);
						transposa(paraula, candidates_i);

                           			paraula = prioritzacio(candidates_i); /* funció que escull la paraula de les candidates amb la freqüència més alta i 
                                                            l'afegeix a candidates_f */
                         			register_fitxer << paraula_i << " -> " << paraula << endl;

                        		}
                        		if(!primera_p){
						output_fitxer << " ";
						output_fitxer << paraula + signes.second;
						primera_p = false;
                        		} 
                        		output_fitxer << paraula + signes.second;
				}

				output_fitxer << endl;

                    
                	}
            }
        }
    }
}
