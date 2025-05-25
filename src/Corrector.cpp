#include "Corrector.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Corrector
// (implementació de tots els mètodes especificats en el fitxer Corrector.hpp)


// ...
/* Pre: Cert */
/* Post: Si rutaDiccionari està associat a un fitxer, llegeix
les entrades del fitxer i omple el diccionari del corrector
que crea; altrament, mostra un missatge d'error */
Corrector::Corrector(const string &rutaDiccionari) { // carrega el diccionari (BST)

	Dicc.llegeixDeFitxer(&rutaDiccionari); //s'ompla el vector vd en la classe Diccionari
	Dicc.omplir_BST(); //s'ordena el vector alfabeticament i s'implementa en el BTS

}

/*Pre: Cert*/
/*Post: Es creen paraules inserint lletres a cada posició de 'paraula' pasada per paràmetre i si són dins del BST es guarden 
dins de la cua 'candidates'*/
void Corrector::insercio(const string &paraula, queue<string> &candidates) {
    
	string s_prova;
    string tot = "abcdefghijklmnopqrstuvwxyz";
	bool trobada = false;

    for (unsigned int i = 0; i < paraula.size()+1; ++i){
        //INV: Es generen noves paraules en la posició 'i' de 'paraula'.

        for (unsigned int j = 0; j < tot.size(); ++j) {
            //INV: Es genere una nova paraula per cada lletra mínuscula de l'abecedari (per tot[j]) en la posició 'i' de 'paraula'
			//i si es troba en el BST es guarda en la cua 'candidates'.

            s_prova = paraula; //igualem per evitar modificacions anteiors
            s_prova.insert(i, 1, tot[j]); // '.insert' és una funció implementada amb la llibreria string que insereix a la
										  // posició 'i' de 's_prova' 1 vegada el caràcter equivalent a 'tot[j]'
			
			trobada = Dicc.conte(aux);
										  
            if (trobada == true) candidates.push(s_prova);
        }
    }
}

/*Pre: Cert*/
/*Post: corregeix la paraula eliminant lletres que sobren segons la paraula sugerida per freq*/
void Corrector::esborrat(const string &paraula, queue<string>&candidates) {
    
	string s_prova;

    for (unsigned int i = 0; i < paraula.size(); ++i) {
        /*INV: s'elimina el caràcter en la posició 'i' de 'paraula' i si la nova creació és dins del BST s'insereix en la 
			   cua 'candidates'*/
        s_prova = paraula;

        s_prova.erase(i, 1); // '.erase' és una funció implementada amb la llibreria string que elimina 1 caràcter de la 
							// posició 'i' del string 's_prova'

        if ( s_prova.empty() == false and Dicc.conte(s_prova) ) candidates.push(s_prova);
    }
}


/* Pre: Cert */
/* Post: Si rutaInput està associat a un fitxer, llegeix el
 text del fitxer línia a línia, corregeix cadascuna de les
 paraules de cada línia, les escriu al fitxer associat a
 rutaOutput i escriu al fitxer associat a rutaLog els canvis
 que hagi fet; altrament, mostra un missatge d'error */		
void Corrector::processaText(const string &rutaInput, const string &rutaOutput, const string &rutaLog) {
	
}
		
// ...

//*********************************************************
//Lectura i escriptura
//*********************************************************		

/* Pre: Cert */
/* Post: S'han escrit al fitxer associat a rutaLog totes 
les correccions fetes al text d'entrada sent el format de
cada línia paraula_original -> paraula_corregida */
void Corrector::bolcaRegistre(const string &rutaLog) {
	
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
