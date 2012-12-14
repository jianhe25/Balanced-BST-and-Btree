template<class T>
class AVL: public Mytree<T>
{
private:
	void updataheight(MEMO *x)
	{
		x->height = max(x->left->height, x->right->height) + 1;
	}
	void rotate_R(MEMO *&x)	
	{
		MEMO *y = x->left;		
		x->left = y->right;				
		y->right = x;
		updataheight(x);
		updataheight(y);
		x = y;
	}
	void rotate_L(MEMO *&x)
	{
		MEMO *y = x->right;		
		x->right = y->left;				
		y->left = x;
		updataheight(x);
		updataheight(y);
		x = y;
	}
	void chk_DFS(MEMO *v, int dep)
	{
		if (v == NIL || dep+1 > 5) return;
		//cout<< v->key << " " << v->left->key << " " << v->right->key << " height= " << v->height << endl;		
		if ((v->left != NIL && v->left->key > v->key) || (v->right != NIL && v->right->key < v->key))
		{
			//printf("error at %d\n",v->key);
			cnt /= 0;
		}
		if (abs(v->left->height - v->right->height) > 1)
		{
			//printf("No Balance at %d\n",v->key); 
			cnt /= 0;
		}
		chk_DFS(v->left, dep+1);
		chk_DFS(v->right, dep+1);
	}
	void balance(MEMO *&x)
	{
		updataheight(x);	
		if (x->left->height > x->right->height+1)	
		{
			MEMO *&y = x->left;
			if (y->right->height > y->left->height)
			{
				rotate_L(y);
			}	
			rotate_R(x);
		} 
		if (x->right->height > x->left->height+1)	
		{
			MEMO *&y = x->right;
			if (y->left->height > y->right->height)			//R-L case
			{
				rotate_R(y);
			}		
			rotate_L(x);
		} 
	}
	void AVL_insert(MEMO *&x,const T &key)
	{
		if (x == NIL)
		{
			x = alloc(key);
			return;
		}
		if (key < x->key)
			AVL_insert(x->left, key);
		else
			AVL_insert(x->right, key);
		balance(x);
	}
	T AVL_delete(MEMO *&x,const T &key)
	{
		T ret;
		if (key == x->key || (key < x->key && x->left == NIL) || (key > x->key && x->right == NIL))
		{
			ret = x->key;
			if (x->left == NIL || x->right == NIL)
			{
				x = (x->left != NIL)? x->left : x->right;
				return ret;
			}else		
				x->key = AVL_delete(x->left, key);	
		}else
		{
			if (key < x->key)
				ret = AVL_delete(x->left, key);		
			else
				ret = AVL_delete(x->right, key);	
		}
		balance(x);
		return ret;
	}
public:	
	bool insert(const T &key)
	{
		if (root == NIL)						//一开始没有节点
		{
			root = alloc(key);
			return true;
		}		
		if (find(key)) return false;
		AVL_insert(root, key);
		return true;
		//chk_DFS(root, 0);
	}
	bool erase(const T &key)
	{	
		if (!find(key))
		{
			return false;
		}else
		{
			AVL_delete(root, key);
			return true;
		}	
		//chk_DFS(root, 0);
	}
};

