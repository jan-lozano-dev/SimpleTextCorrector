#ifndef BST_HPP
#define BST_HPP
#include <iostream>
using namespace std;

/* Representació d'un arbre binari cerca o BST (binary search tree).
 * Un arbre binari de cerca és un arbre binari en què el subarbre esquerre de qualsevol node
 * (si no està buit) conté valors menors que el que conté aquest node, i el subarbre dret(si no està buit) conté valors més grans. */ 
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
		/* Post: No fa res si 'node' és NULL, sinó allibera espai de la jerarquia de nodes apuntada per 'node' */
		void clear(Item *node);

		/* Pre: Cert */
		/* Post: El paràmetre "result" apunta a l'arbre resultat d'inserir "d" al subarbre 
  		  original amb arrel "node", mantenint les propietats del BST. 
      		  El booleà "inserted" val true si s'ha realitzat la inserció (no hi ha duplicat). */
		Item* ef_insert(Item *node, const T& d, Item* &result, bool &inserted);
		
		/* Pre: Cert */
		/* Post: Afegeix un node nou amb el valor rebut per paràmetre a la jerarquia de nodes
				 apuntada per 'node', mantenint les propietats de BST */
		Item* insert(Item *node, const T& d);

		/* Pre: Cert */
		/* Post: Si existeix node amb root == d en subarbre que "node" apunta, booleà "found" 
  			 	 serà true i "result" apuntarà a aquest node. Cas contrari, "found" false i result == nullptr. */
		void ef_find(Item* node, const T& d, Item*& result, bool& found) const;

		/* Pre: Cert */
		/* Post: El resultat és el node de la jerarquia de nodes apuntada per 'node', amb el mateix
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
		/* Pre: Cert */
		/* Post: El primer component del resultat indica
		   si el bst paràmetre implícit conté un element
		   amb el valor rebut per paràmetre; en cas afirmatiu,
		   el segon component conté l'element del paràmetre
		   implícit amb aquest valor, altrament conté un
		   element buit */
		pair<bool, T> find(const T& d) const;
};
#endif
