#ifndef BST_HPP
#define BST_HPP
#include <iostream>
using namespace std;

/*  
 * Representació d'un arbre binari cerca o
 * BST (binary search tree).
 * Un arbre binari de cerca és un arbre binari
 * en què el subarbre esquerre de qualsevol node
 * (si no està buit) conté valors menors que el
 * que conté aquest node, i el subarbre dret
 * (si no està buit) conté valors més grans.
 */ 

template <typename T>
class BST  {
	
	private:
		struct Item {
			T data;
			Item *left;
			Item *right;
			Item(const T& d, Item *l, Item *r) {
				data = d;
				left = l;
				right = r;
			}
		};

		Item *root;
	
	
		//*********************************************************
		// Mètodes privats auxiliars
		//*********************************************************
		
		/* Pre: Cert */
		/* Post: No fa res si 'node' és NULL, sinó 
		   allibera espai de la jerarquia de nodes
		   apuntada per 'node' */
		void clear(Item *node);

		/* Pre: Cert */
		/* Post: Afegeix un node nou amb el valor
		   rebut per paràmetre a la jerarquia de
		   nodes apuntada per 'node', mantenint
		   les propietats de BST */
		Item* insert(Item *node, const T& d);
		
		/* Pre: Cert */
		/* Post: El resultat és el node de la jerarquia
		   de nodes apuntada per 'node', amb el mateix
		   valor que el valor rebut per paràmetre */
		Item* find(Item *node, const T& d) const;
	
	
	public:

		//*********************************************************
		// Constructors
		//*********************************************************
	
		/* Pre: Cert */
		/* Post: El resultat és un bst sense cap element */	
		BST();


		//*********************************************************
		// Destructor
		//*********************************************************
	
		/* Esborra automàticament els objectes locals
		   en sortir d'un àmbit de visibilitat */
		~BST();

		//*********************************************************
		// Modificadors
		//*********************************************************

		/* Pre: Cert */
		/* Post: Afegeix un element, amb el valor rebut
		   per paràmetre, al bst paràmetre implícit */
		void insert(const T& d);
	

		//*********************************************************
		// Consultors
		//*********************************************************	
		// Pre: t és un BST.
		// Post: Modifica result cert si i només si x apareix a t.
		void ef_searchInBST(BinaryTree<int> &t, int x, bool &result){
		    if(!result){
		        if(!t.isEmpty()){
		            int root = t.getRoot();
		            if(x < root){
		                //Search in left tree.
		                //FF: nº de nodes per tractar.
		                //HI: result indica que fins ara no hi ha l'element a trobar.
		                ef_searchInBST(t.getLeft(),x, result);
		            } else if(x > root){
		                //Search in right tree.
		                //FF: nº de nodes per tractar.
		                //HI: result indica que fins ara no hi ha l'element a trobar.
		                ef_searchInBST(t.getRight(),x, result);
		            } else{
		                //x == root
		                result = true;
		            }
		        }
		    }
		}

		/* Pre: Cert */
		/* Post: El primer component del resultat indica
		   si el bst paràmetre implícit conté un element
		   amb el valor rebut per paràmetre; en cas afirmatiu,
		   el segon component conté l'element del paràmetre
		   implícit amb aquest valor, altrament conté un
		   element buit */
		pair<bool, T> find(const T& d) const;
		// Pre: t és un BST.
		// Post: Retorna cert si i només si x apareix a t.
		bool searchInBST(BinaryTree<int> &t, int x){
		    bool result = false;
		
		    ef_searchInBST(t, x, result);
		    return result;
		}
	
};

#include "BST.cpp"

#endif
