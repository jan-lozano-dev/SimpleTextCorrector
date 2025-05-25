#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Diccionari
// (implementació de tots els mètodes especificats en el fitxer Diccionari.hpp)

bool ordenarVector(const ParFreq& a, const ParFreq& b) {
    return a.getParaula() < b.getParaula(); 
}

//*********************************************************
// Constructors
//*********************************************************
/* Pre: Cert */
/* Post: El resultat és un Diccionari sense cap ParFeq */	
Diccionari() {
}

 
//*********************************************************
// Destructor
//*********************************************************
/* Esborra automàticament els objectes locals
en sortir d'un àmbit de visibilitat */
~Diccionari() {
}

// ...


//*********************************************************
// Modificadors
//*********************************************************
/* Pre: Cert */
/* Post: Si la paraula del parell rebut per  paràmetre no 
apareixia ja al diccionari, s'ha afegit al diccionari el
parell rebut per paràmetre; altrament, el diccionari no 
s'ha modificat */
void omplir_BTS() { // inserció en el BST 
    sort(v_aux.begin(), v_aux.end(), ordenarVector);// Ordenar el vector vd alfabèticament
    // traslladem el vector ordenat a el BTS arbre_ord
    unsigned int i = (v_aux.size()/2);
    arbre_ord.insert(vd[i]);
    //ara hauriem de crear dos vectors, un de l'esquerra i un de la dreta
    
    while (i > 1) {

        //fer bucle fins que hi hagi només una paraula
    }
}    

// ...

//*********************************************************
// Consultors
//*********************************************************

// Pre: Cert
// Post: retorna el vector 'vd' de ParFreq's del Diccionari 
vector<ParFreq> Diccionari::getVector() const{
    return v_aux;
}

/* Pre:  Cert  */
/* Post: El resultat indica si el diccionari conté la
paraula rebuda per paràmetre */	   
bool conte(const string &paraula) const{  // cerca en el BST
    //DUBTE: EN LA FUNCIÓ FIND DEL BTS, ES POT PASSAR UN STRING PERQ HO BUSQUI TOT I QUE SON PARFREQ'S? ÉS A DIR, BUSCARAN 
    //       LA PARAULA DE CADA PARFREQ?
    ParFreq pfcerca(paraula, 0); // La Freqüència no ens importa, posem 0
    return arbre_ord.find(pfcerca).first;
    
} 


/* Pre: La paraula rebuda per paràmetre està en el
diccionari */
/* Post: El resultat és la freqüència que apareix al
diccionari de la paraula rebuda per paràmetre */	 
int getFrequencia(const string &paraula) const {
    ParFreq pfcerca(paraula, 0);
    pair res = arbre_ord.find(pfcerca); 


    return res.second // Ens han dit que la paraula ja és en el diccionari, no fa falta comprobar si ho està
}


//*********************************************************
//Lectura i escriptura
//*********************************************************

/* Pre: Cert */
/* Post: Si el path rebut per paràmetre està associat a un
fitxer, llegeix el fitxer de parells (paraula, freqüència)
i omple el diccionari; altrament, mostra un missatge 
d'error.*/
void Diccionari::llegeixDeFitxer(const string &path)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }

    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  // llegeix un parell (paraula, freq) 
											   // per línia
		ParFreq pf(paraula, frequencia);
        v_aux.push_back(pf);       // suposa que el diccionari té definida l'operació insert
    }
}

	  

