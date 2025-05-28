#include <iostream>
#include "ParFreq.hpp"
using namespace std;

/*Pre: Cert*/
/*Post: El resultat és un ParFreq sense cap element.*/
ParFreq::ParFreq(){
  dades = make_pair("", 0);
}

/* Pre: Cert */
/* Post: el paràmetre implícit és una copia profunda de la ParFreq donada com a paràmetre. */	
ParFreq::ParFreq(const ParFreq &pf){
  dades = pf.dades;
}
	
/* Pre: Cert */
/* Post: El paràmetre implícit és una ParFreq amb s com a paraula i amb n com freqüència. */
ParFreq::ParFreq(const string &s, const int &n){
  dades = make_pair(s, n);
}

/*Esborra automàticament els objectes locals en sortir d'un `àmbit de visibilitat.*/	   
ParFreq::~ParFreq(){
  //(no s'empra memòria dinàmica, no fem res)
}

/* Pre: cert*/
/* Post: es substitueix el paràmetre implícit paraula per s.*/
void ParFreq::insertParaula(const string &s){
  dades.first = s;
}

/* Pre: cert*/
/* Post: es substitueix el paràmetre implícit freq per n.*/
void ParFreq::insertFreq(const int &n){
  dades.second = n;
}

/* Pre: Cert */
/* Post: El resultat és el pair del paràmetre implícit */
pair<string, int> ParFreq::getPair() const{
  return dades;
}

/* Pre: Cert */
/* Post: El resultat és la paraula del paràmetre implícit */
string ParFreq::getParaula() const{
  return dades.first;
}

/* Pre: Cert */
/* Post: El resultat és la freqüència del paràmetre implícit */
int ParFreq::getFrequencia() const{
  return dades.second;
}

/* Pre:  Cert  */
/* Post: El resultat indica si la paraula del paràmetre implícit
és igual a la paraula del parell rebut per paràmetre */ 	   
bool ParFreq::operator==(const ParFreq& pf) const{
  return dades == pf.dades;
}

/* Pre:  Cert  */
/* Post: El resultat indica si la paraula del paràmetre implícit
és més petita a la paraula del parell rebut per paràmetre */ 	
bool ParFreq::operator<(const ParFreq& pf) const {
  return dades.first < pf.dades.first;
}

/* Pre:  Cert  */
/* Post: El resultat indica si la paraula del paràmetre implícit
és més gran a la paraula del parell rebut per paràmetre */
bool ParFreq::operator>(const ParFreq& pf) const{
    return dades.first > pf.dades.first;
}

/* Pre:  Cert  */
/* Post: El  p.i. té ara la mateixa paraula i freqüència que el paràmetre `other`;
  retorna una referència al p.i. per paràmetre. */
ParFreq& ParFreq::operator=(const ParFreq& pf){
  if(this != &pf){
    dades = pf.dades;
  }
  return *this;
}






