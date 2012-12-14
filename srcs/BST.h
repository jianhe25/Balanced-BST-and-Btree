
template<class T>
class BST: public Mytree<T>
{
private:
	T BST_delete(MEMO *&x,T &_key)
	{
		if (_key == x->key || (_key < x->key && x->left == NIL) || (_key > x->key && x->right == NIL))
		{
			T tmp = x->key;
			if (x->left == NIL || x->right == NIL)
				x = (x->left != NIL)? x->left : x->right;
			else		
				x->key = BST_delete(x->left, _key);	
			return tmp;
		}else
		{
			if (_key < x->key)
				return BST_delete(x->left, _key);		
			else
				return BST_delete(x->right, _key);
		}
	}
public:
	bool insert(const T &_key)
	{			
		if (find(_key)) return false;					//_key exists, not add	
		MEMO *cur = alloc(_key);	
		if (root == NIL)						//一开始没有节点
		{
			root = cur;
			return true;
		}
		MEMO *old = root;
		while (1)								//定位该节点，先插到二叉树对应位置
		{
			if (cur->key < old->key)
			{
				if (old->left == NIL)			   //如果old的左儿子为空,左儿子一开始就分配好了，size为0说明是空
				{
					old->left = cur; 			   //则old的左儿子设为cur，cur的fa设为old,其实是复制。
					break;
				}else
				old = old->left;
			}
			else
			{
				if (old->right == NIL)
				{
					old->right = cur;
					break;
				}else
				old = old->right;
			}
		}
		return true;
	}
	bool erase(const T &_key)
	{
		MEMO *it = find(root, _key);
		if (it == NIL)
		{
			return false;
		}else
		{
			BST_delete(root, it->key);	
			return true;
		}
	}
};
