//
// Implementation
//
template <typename E>					// constructor
  AVLTree<E>::AVLTree() : ST() { }
  
template <typename E>                                   // deconstructor
  AVLTree<E>::~AVLTree() { }

template <typename E>					// node height utility
  int AVLTree<E>::height(const TPos& v) const
    { return (v.isExternal() ? 0 : (*v).height()); }

template <typename E>					// set height utility
  void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.left());
    int hr = height(v.right());
    (*v).setHeight(1 + std::max(hl, hr));			// max of left & right
  }

template <typename E>					// is v balanced?
  bool AVLTree<E>::isBalanced(const TPos& v) const {	
    int bal = height(v.left()) - height(v.right());
    return ((-1 <= bal) && (bal <= 1));
  }

template <typename E>					// get tallest grandchild
  typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    TPos zl = z.left();
    TPos zr = z.right();
    if (height(zl) >= height(zr))			// left child taller
      if (height(zl.left()) >= height(zl.right()))
        return zl.left();
      else
        return zl.right();
    else 						// right child taller
      if (height(zr.right()) >= height(zr.left()))
        return zr.right();
      else
        return zr.left();
  }


//
// ToDo
//

template <typename E>					// remove key k entry
  void AVLTree<E>::erase(const K& k) {
    // ToDo
    TPos v = this->finder(k, ST::root());	
	if (! v.isExternal()) {
		TPos w = this->eraser(v);
		rebalance(w); 	
  }
}

template <typename E>					// insert (k,x)
  typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    
    // ToDo
    TPos v = this->inserter(k, x); 
    setHeight(v);
    rebalance(v);
    return Iterator(v);
  }
  
template <typename E>					// rebalancing utility
  void AVLTree<E>::rebalance(const TPos& v) {
    
    // ToDo
    TPos z = v;
	while (!(z== ST::root()))
	{
		z = z.parent();
		setHeight(z);
		if (!isBalanced(z))
		{
			TPos x = tallGrandchild(z); 
			z = restructure(x); //trinode restructure
			setHeight(z.left()); //update height
			setHeight(z.right());
			setHeight(z);
		}
	}
  }

template <typename E>				// Binary Search Tree Rotation
  typename AVLTree<E>::TPos AVLTree<E>::restructure(const TPos& v) {

	// ToDo
	//p:parent g:grand gp:grandparent 
	AVLTree<E>::TPos c = v;
	AVLTree<E>::TPos b = c.parent();
	AVLTree<E>::TPos a = b.parent();
	
	
	AVLTree<E>::TPos gp = a;
	AVLTree<E>::TPos ggp = a.parent();
	
	K a_k = a.v->elt.key();
	K b_k = b.v->elt.key();
	K c_k = c.v->elt.key();
	
	if(a_k > b_k)
	{
		if(b_k > c_k)//LL
		{
			AVLTree<E>::TPos bright; //right child of b
			b.v->par = a.v->par;
			a.v->left = bright.v = b.v->right;
			b.v->right = a.v;
			a.v->par = b.v;
			c.v->par = b.v;
			bright.v->par=a.v;
			if(ggp.v->left == gp.v)
				ggp.v->left = b.v;
			else if(ggp.v->right == gp.v)
				ggp.v->right = b.v;
			else{
				cout << "Error in restructure";
			}
		return b;
		}
	 else//LR
	 {
		AVLTree<E>::TPos cright, cleft; //left right child of c;
		c.v->par = a.v->par;
		a.v->left = cright.v = c.v->right;
		b.v->right = cleft.v = c.v ->left;
		c.v->right = a.v;
		c.v->left = b.v;
		b.v->par = c.v;
		a.v->par = c.v;
		cright.v->par = a.v;
		cleft.v->par = b.v;
		if(ggp.v->left == gp.v)
			ggp.v->left = c.v;
		else if(ggp.v->right == gp.v)
			ggp.v->right = c.v;
		else{
			cout << "Error in restructure";
		}
		return c;
	 }
	}
	else
	{
		if(b_k < c_k){//RR
			AVLTree<E>::TPos bleft; //left chid of b
			b.v->par = a.v->par;
			a.v->right = bleft.v = b.v->left;
			b.v->left = a.v;
			a.v -> par = b.v;
			c.v -> par = b.v;
			bleft.v->par = a.v;
			if(ggp.v->left == gp.v)
				ggp.v->left = b.v;
		    else if(ggp.v->right == gp.v)
				ggp.v->right = b.v;
			else{
				cout << "Error in restructure";
			}
			return b;
		}
		else{//RL
			AVLTree<E>::TPos cright, cleft; //right and left of c;
			c.v->par = a.v->par;
			a.v->right = cleft.v = c.v->left;
			b.v->left = cright.v = c.v->right;
			c.v->left = a.v;
			c.v->right = b.v;
			a.v->par = c.v;
			b.v->par = c.v;
			cleft.v->par = a.v;
			cright.v->par = b.v;
			if(ggp.v->left == gp.v)
				ggp.v->left = c.v;
		    else if(ggp.v->right == gp.v)
				ggp.v->right = c.v;
			else{
				cout << "Error in restructure";
			}
			return c;
		}
	}
  }

