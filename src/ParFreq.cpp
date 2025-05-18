#include "ParFreq.hpp"
using namespace std;

//Constructor buït
ParFreq::ParFreq(){
  dades = make_pair("", 0);
}

//Constructor per còpia
ParFreq::ParFreq(const ParFreq &pf){
  dades = pf.dades;
}
	
//Constructor amb inputs
ParFreq::ParFreq(const string &s, const int &n){
  dades = make_pair(s, n);
}

//Destructor
ParFreq::~ParFreq(){
  //(no s'empra memòria dinàmica, no fem res)
}
//Modificador inserta nova paraula
void ParFreq::insertParaula(const string &s){
  dades.first = s;
}

//Modificador inserta nova freqüència
void ParFreq::insertFreq(const int &n){
  dades.second = n;
}

//Consultor: retorna pair
pair<string, int> ParFreq::getPair() const{
  return dades;
}

//Consultor: retorna paraula del pair
string ParFreq::getParaula() const{
  return dades.first;
}
//Consultor: retorna freqüència del pair
int ParFreq::getFrequencia() const{
  return dades.second;
}

//Operador comparador. Comprova si paràmetre implícit y pair pf són iguals.
bool ParFreq::operator==(const ParFreq& pf) const{
  return dades == pf.dades;
}
