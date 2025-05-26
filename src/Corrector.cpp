#include "Corrector.hpp"
using namespace std;

Corrector::Corrector(const string &rutaDiccionari) { // carrega el diccionari (BST)
	Dicc.llegeixDeFitxer(&rutaDiccionari); //s'ompla el vector vd en la classe Diccionari
	Dicc.omplir_BST(); //s'ordena el vector alfabeticament i s'implementa en el BTS
}

bool Corrector::elimina_signes(string &word, string &signe){
	string signes = ".,!?";
	bool trobat = false;
	unsigned int i = 0;
	unsigned int n = word.length();
	if(n != 0){
		unsigned int signes_length = signes.length();
		while(!trobat and i < signes_length){
			if(word[n - 1] == signes[i]){
				signe = word[n - 1];
				word.erase(n - 1, 1);
				trobat = true;
			} else {
				++i:
			}
		}
	}
	return trobat
}

	
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog) {
	ifstream input_file(rutaInput);
	if(!input_file.is_open()){
		throw runtime_error("ERROR. No es pot obrir el fitxer: " + rutaInput);
	} else{
		ofstream output_file(rutaLog);
		if(!output_file.is_open()){
			cerr << "ERROR. No es pot obrir fitxer output." << endl;
		} else{
			ofstream register_file(rutaLog);
			if(!register_file.is_open()){
				cerr << "ERROR. No es pot obrir fitxer registre." << endl;
			} else {	
				string s;
				while(getline(input_file, s)){
					//Inv: ?
					stringstream ss(s);
					string word, pf;
					bool first = true;
					while(ss >> word){
						string signe;
						string word_correct = elimina_signes(word, signe); //Posa nom funcio correcte
						if(!dic.conte(word_correct)){
							final_word = correccio(word_correcte);
							register_file << word_correct << " -> " << final_word << endl;
						}
						if(!first) output_file << " ";
						output_file << final_word << signe:
						first = false;
					}
					output_file << endl;
			}
		}
	}
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
void Corrector::insercio(const string &paraula, queue<string> &candidates) {
    string s_prova;
    string tot = "abcdefghijklmnopqrstuvwxyz";
    bool trobada = false;
    for (unsigned int i = 0; i < paraula.size()+1; ++i){
        //INV: Es generen noves paraules en la posició 'i' de 'paraula'.
        for (unsigned int j = 0; j < tot.size(); ++j) {
            //INV: Es genere una nova paraula per cada lletra mínuscula de l'abecedari (per tot[j]) en la posició 'i' de 'paraula'
	    //	   i si es troba en el BST es guarda en la cua 'candidates'.
            s_prova = paraula; //igualem per evitar modificacions anteiors
            s_prova.insert(i, 1, tot[j]); // '.insert' és una funció implementada amb la llibreria string que insereix a la
		// posició 'i' de 's_prova' 1 vegada el caràcter equivalent a 'tot[j]'
			trobada = Dicc.conte(aux);							  
            if (trobada == true) candidates.push(s_prova);
        }
    }
}


void Corrector::esborrat(const string &paraula, queue<string>&candidates) {
	string s_prova;
	unsigned int n = paraula.size();
	for (unsigned int i = 0; i < n; ++i) {
		/*INV: s'elimina  caràcter posició 'i' de 'paraula' i si nova creació dins BST, s'insereix en cua 'candidates'*/
        	s_prova = paraula;
        	s_prova.erase(i, 1); 
        	if (!s_prova.empty() and Dicc.conte(s_prova)) candidates.push(s_prova);
    }
}

void Corrector::substitueix(const string &word, queue<string> &pos){
	string aux;
	string abecedari = "abcdefghijklmnopqrstuvwxyz";
	unsigned int n = word.length();
	for(unsigned int i = 0; i < n; ++i){
		//Inv:
		aux[i] = abecedari[j];
		if(Dic.conte(aux)) pos.push(aux);
	}
}

void Corrector::transposa(const string &word, queue<string> &pos){
	string aux;
	unsigned int n = word.size() - 1;
	for(unsigned int i = 0; i < n; ++i){
		//Inv: 
		aux = paraula;
		swap(aux[i], aux[i + 1]);
		if(dic.conte(aux)) pos.push(aux);
	}
}
