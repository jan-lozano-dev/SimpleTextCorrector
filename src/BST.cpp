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
typename BST<T>::Item* BST<T>::find(Item *node, const T& d) const 
{
	
	// PROGRAMA AQUEST MÈTODE
	
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
