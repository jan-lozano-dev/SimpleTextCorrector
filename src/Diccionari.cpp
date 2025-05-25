#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE Diccionari
// (implementació de tots els mètodes especificats en el fitxer Diccionari.hpp)



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

/* Pre: Cert */
/* Post: Si les paraules dels parells que es troben en el vector rebut per paràmetre no
apareixien ja al diccionari, s'han afegit al diccionari els parells rebuts en el vector per
paràmetre; altrament, el diccionari no s'ha modificat */
void Diccionari::ef_omplir_BST(vector<ParFreq> &v, int pos_i, int pos_f){
    
    int meitat = pos_i + (pos_f - pos_i)/2; //posició situada a la meitat del vector
    ParFreq pf_ins = v[meitat];
    arbre_ord.insert(pf_ins); //la funció insert comprovarà que no hi ha cap altre ParFreq igual a pf_ins dins del BST

    if (pos_f - pos_i > 1){
        ef_omplir_BST(v_aux, pos_i, meitat);
        /* HI: Si les paraules dels parells que es troben en el vector des de l'inici fins la meitat
        apareixien ja al diccionari, s'han afegit al diccionari els parells rebuts en el vector 
        per paràmetre; altrament, el diccionari no s'ha modificat. */
        /* Fita: la mida del vector que comprèn del ini fins al mig. */

        ef_omplir_BST(v_aux, meitat, pos_f);
        /* HI: Si les paraules dels parells que es troben en el vector des de la meitat fins al final
        apareixien ja al diccionari, s'han afegit al diccionari els parells rebuts en el vector 
        per paràmetre; altrament, el diccionari no s'ha modificat. */
        /* Fita: la mida del vector que comprèn del mig fins al fin. */
    }
}



//*********************************************************
// Modificadors
//*********************************************************
/* Pre: Cert */
/* Post: Si la paraula del parell rebut per  paràmetre no 
apareixia ja al diccionari, s'ha afegit al diccionari el
parell rebut per paràmetre; altrament, el diccionari no 
s'ha modificat */
void Diccionari::omplir_BST() { // inserció en el BST 
    sort(v_aux.begin(), v_aux.end(), a.getParaula() < b.getParaula()); // Ordenar el vector vd alfabèticament
    //bool ordenarVector(const ParFreq& a, const ParFreq& b) {
    //return a.getParaula() < b.getParaula();}
    // traslladem el vector ordenat a el BTS arbre_ord
    int posi_f = v.size()-1; //posició final del vector
    int posi_i = 0;          //posició inicial del vector

    ef_omplir_BST(v_aux, posi_i, posi_f);
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
bool Diccionari::conte(const string &paraula) const{  // cerca en el BST
    //DUBTE: EN LA FUNCIÓ FIND DEL BTS, ES POT PASSAR UN STRING PERQ HO BUSQUI TOT I QUE SON PARFREQ'S? ÉS A DIR, BUSCARAN 
    //       LA PARAULA DE CADA PARFREQ?
    ParFreq pfcerca(paraula, 0); // La Freqüència no ens importa, posem 0
    return arbre_ord.find(pfcerca).first;
    
} 


/* Pre: La paraula rebuda per paràmetre està en el
diccionari */
/* Post: El resultat és la freqüència que apareix al
diccionari de la paraula rebuda per paràmetre */	 
int Diccionari::getFrequencia(const string &paraula) const {
    ParFreq pfcerca(paraula, 0);
    pair res = arbre_ord.find(pfcerca); 


    return res.second.getFrequencia() // Ens han dit que la paraula ja és en el diccionari, no fa falta comprobar si ho està
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

	  

