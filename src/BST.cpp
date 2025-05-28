#include <iostream>
#include "BST.hpp"

using namespace std;
/* Pre: Cert */
/* Post: No fa res si 'node' és NULL, sinó allibera espai de la jerarquia de nodes apuntada per 'node' */
template <typename T>
void BST<T>::clear(Item *node) 
{
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

/* Pre: Cert */
/* Post: El paràmetre "result" apunta a l'arbre resultat d'inserir "d" al subarbre original amb arrel "node", 
		 mantenint les propietats del BST. El booleà "inserted" val true si s'ha realitzat la inserció (no hi ha duplicat). */
template <typename T>
typename BST<T>::Item* BST<T>::ef_insert(Item *node, const T& d, Item* &result, bool &inserted) 
{
	if(!inserted){
		if(node == nullptr){
			//En BST, s'inserta en fulles. Insertem.
			node = new Item{d, nullptr, nullptr};
			result = node;
			inserted = true;
			
		} else if(d < node->data){ //Element a inserir més petit que el node actual. Anem a l'esquerra.
			Item* tmp = node->left;
			//FF: mida subarbre amb arrel "tmp" on s'inserirà "d".
			//HI: Suposem que la posició on em d'inserir "d" es troba dins del subarbre esquerre 
			//    que prèn per root "tmp".
			ef_insert(tmp, d, tmp, inserted);
			node->left = tmp;
			result = node;

		} else if(d > node->data){ //Element a inserir més gran que el node actual. Anem a la dreta.
			Item* tmp = node->right;
			//FF: mida subarbre amb arrel "tmp" on s'inserirà "d".
			//HI: Suposem que posició on inserir "d" es troba dins subarbre dret que prèn per root "tmp".
			ef_insert(tmp, d, tmp, inserted);
			node->right = tmp;
			result = node;

		} else{ //No podem insertar un duplicat.
			result = node;
			inserted = true;
		}		
	}
	return result;
}


/* Pre: Cert */
/* Post: Afegeix un node nou amb el valor rebut per paràmetre a la jerarquia de nodes
		 apuntada per 'node', mantenint les propietats de BST */
template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) 
{
	Item *result = node;
	bool inserted = false;
	//Crida a funció eficient parametritzada recursiva.
	ef_insert(node, d, result, inserted);
	return result;	
}

/* Pre: Cert */
/* Post: Si existeix node amb root == d en subarbre que "node" apunta, booleà "found" 
  		 serà true i "result" apuntarà a aquest node. Cas contrari, "found" false i result == nullptr. */
template <typename T>
void BST<T>::ef_find(Item* node, const T& d, Item*& result, bool& found) const {
	if (!found && node != nullptr) {
		//Cas base: Arribem a fulla o en crida recursiva anterior es troba d.
		if (d < node->data) {
            //FF: mida del subarbre pel que buscar.
			//HI: Si "d" es troba en el subarbre amb arrel "node->left", llavors "result"
			//    apuntarà a aquest node i "found" serà cert.
			ef_find(node->left, d, result, found);
        } else if (d > node->data) {
			//FF: mida del subarbre pel que buscar.
			//HI: Si "d" es troba en el subarbre amb arrel "node->right", llavors "result"
			//    apuntarà a aquest node i "found" serà cert.
			ef_find(node->right, d, result, found);
        } else {
            		found = true;
            		result = node;
        }
    }
}

/* Pre: Cert */
/* Post: El resultat és el node de la jerarquia de nodes apuntada per 'node', amb el mateix
		 valor que el valor rebut per paràmetre */
template <typename T>
typename BST<T>::Item* BST<T>::find(Item *node, const T& d) const 
{
	Item *result = nullptr;
	bool found = false;
	//Crida a funció eficient parametritzada recursiva.
	ef_find(node, d, result, found);
	return result;	
}

/* Pre: Cert */
/* Post: El resultat és un bst sense cap element */	
template <typename T>
BST<T>::BST() {
	root = nullptr;
}

/* Esborra automàticament els objectes locals en sortir d'un àmbit de visibilitat */
template <typename T>
BST<T>::~BST() 
{ 
	clear(root); //Crida a mètode privat. 
}

/* Pre: Cert */
/* Post: Afegeix un element, amb el valor rebut per paràmetre, al bst paràmetre implícit */
template <typename T>
void BST<T>::insert(const T& d) 
{ 
	root = insert(root, d); //Crida a mètode privat.
}

/* Pre: Cert */
/* Post: El primer component del resultat indica si el bst paràmetre implícit conté un element
		 amb el valor rebut per paràmetre; en cas afirmatiu, el segon component conté l'element 
		 del paràmetre implícit amb aquest valor, altrament conté un element buit */
template <typename T>
pair<bool, T> BST<T>::find(const T& d) const 
{ 
	pair<bool, T> res = make_pair(false, d);
	Item* node = find(root, d); //Crida a mètode privat.
	if (node != NULL) {
			res.first = true;
			res.second = node->data;
	}
	return res;
}

#include "ParFreq.hpp"
template class BST<ParFreq>;
