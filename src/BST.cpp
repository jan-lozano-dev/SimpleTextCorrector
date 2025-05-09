//*********************************************************
// Mètodes privats auxiliars
//*********************************************************
template <typename T>
void BST<T>::clear(Item *node) 
{
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}
//*********************************************************
template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) 
{
	
	// PROGRAMA AQUEST MÈTODE
	
}
//*********************************************************
template <typename T>
void BST<T>::ef_find(Item* node, const T& d, Item*& result, bool& found) const {
	if (!found && node != nullptr) {
		//Cas base: Arribem a fulla o en crida recursiva anterior es troba d.
		if (d < node->data) {
            		//FF: mida del subarbre pel que buscar.
			//HI: ???
			ef_find(node->left, d, result, found);
        } else if (d > node->data) {
			//FF: mida del subarbre pel que buscar.
			//HI: ???
            		ef_find(node->right, d, result, found);
        } else {
            		found = true;
            		result = node;
        }
    }
}

template <typename T>
typename BST<T>::Item* BST<T>::find(Item *node, const T& d) const 
{
	Item *result = nullptr;
	bool found;
	//Crida a funció eficient parametritzada recursiva.
	ef_find(node, d, result, bool=;
	return result;	
}

//*********************************************************
// Constructors
//*********************************************************
template <typename T>
BST<T>::BST() {
	root = nullptr;
}

//*********************************************************
// Destructor
//*********************************************************
template <typename T>
BST<T>::~BST() 
{ 
	clear(root); 
}

//*********************************************************
// Modificadors
//*********************************************************
template <typename T>
void BST<T>::insert(const T& d) 
{ 
	root = insert(root, d); 
}

//*********************************************************
// Consultors
//*********************************************************
template <typename T>
pair<bool, T> BST<T>::find(const T& d) const 
{ 
	pair<bool, T> res = make_pair(false, d);
	Item* node = find(root, d);
	if (node != NULL) {
			res.first = true;
			res.second = node->data;
	}
	return res;
}
