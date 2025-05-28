#include <iostream>
#include "Diccionari.hpp"
#include <stdexcept>
using namespace std;

// Pre: cert.
// Post: retorna vector ordenat.
bool ordenarVector(const ParFreq& a, const ParFreq& b) {
    return a.getParaula() < b.getParaula();
}

/* Pre: Cert */
/* Post: El resultat és un Diccionari sense cap ParFeq */	
Diccionari::Diccionari() {
}

/* Esborra automàticament els objectes locals
en sortir d'un àmbit de visibilitat */
Diccionari::~Diccionari() {
}

/* Pre: lo >= 0; hi >= 0 */
/* Post: Si les paraules dels parells que es troben en el vector rebut per paràmetre no
apareixien ja al diccionari, s'han afegit al diccionari els parells rebuts en el vector per
paràmetre; altrament, el diccionari no s'ha modificat */
void Diccionari::ef_omplir_BST(int lo , int hi){
    if (lo > hi) return;
    int mid = lo + (hi - lo) / 2;
    arbre_ord.insert(v_aux[mid]);
    /* HI: Seguim insertant elements al BST, ara els elements de la meitat esquerre del vector*/
    /* FF: llargada vector que comprèn del lo a mid - 1. */
    ef_omplir_BST(lo,   mid - 1);
    /* HI: Seguim insertant elements al BST, ara els elements de la meitat dreta del vector*/
    /* FF: llargada vector que comprèn de mid + 1 a hi.*/
    ef_omplir_BST(mid + 1, hi);
}

/* Pre: Cert */
/* Post: Si la paraula del parell rebut per  paràmetre no apareixia ja al diccionari, s'ha afegit
al diccionari el parell rebut per paràmetre; altrament, el diccionari no  s'ha modificat */
void Diccionari::omplir_BST() { // inserció en el BST 
    sort(v_aux.begin(), v_aux.end(), ordenarVector); // Ordenar el vector vd alfabèticament
    ef_omplir_BST(0, int(v_aux.size()) - 1);
}

// Pre: Cert
// Post: retorna el vector 'vd' de ParFreq's del Diccionari 
vector<ParFreq> Diccionari::getVector() const{
    return v_aux;
}

/* Pre:  Cert  */
/* Post: El resultat és true si el diccionari conté la paraula rebuda per paràmetre. Altrament false. */	   
bool Diccionari::conte(const string &paraula) const{  // cerca en el BST
    ParFreq pfcerca(paraula, 0); // La Freqüència no ens importa, posem 0
    return arbre_ord.find(pfcerca).first;  
} 

/* Pre: La paraula rebuda per paràmetre està en el diccionari */
/* Post: El resultat és la freqüència que apareix al diccionari de la paraula rebuda per paràmetre */	 
int Diccionari::getFrequencia(const string &paraula) const {
    ParFreq pfcerca(paraula, 0);
    pair<bool, ParFreq> res = arbre_ord.find(pfcerca);
    return res.second.getFrequencia(); // Ens han dit que la paraula ja és en el diccionari, no fa falta comprobar si ho està
}

/* Pre: Cert */
/* Post: Si el path rebut per paràmetre està associat a un fitxer, llegeix el fitxer de parells 
(paraula, freqüència) i omple el diccionari; altrament, mostra un missatge  d'error.*/
void Diccionari::llegeixDeFitxer(const string &path)
{
    ifstream fitxer(path);
    if (not fitxer.is_open()) {
        throw runtime_error("Error en obrir el fitxer-diccionari: " + path);
    }
    string paraula;
	int frequencia;
    while (fitxer >> paraula >> frequencia) {  // llegeix un parell (paraula, freq) 
		//Inv: bucle de recorregut. Encara queden parells per llegir i tractar.
        ParFreq pf(paraula, frequencia);
        v_aux.push_back(pf);
    }
}

	  

