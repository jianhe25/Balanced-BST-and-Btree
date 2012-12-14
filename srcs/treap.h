using namespace std;
using namespace System::Windows::Forms;

template<class T>
class Treap: public Mytree<T>
{
private:
	void rotate_L(MEMO *x,MEMO *y)
	{
		MEMO **upper;					//������¼�����Ǹı�x������ӻ����Ҷ���,����left��MEMO*,
										//���Ըı�����ҪMEMO **
		if (x->fa == NIL)				//xΪ���ڵ�ʱ����fa==NIL��ǣ���ʱ��ı�rootΪy��
		{
			root = y;
			y->fa = NIL;
		}else
		{
			if (x->fa->left == x)			//x�ĸ�������y�ϡ�
				upper = &x->fa->left;
			else
				upper = &x->fa->right;
			*upper = y;
			y->fa = x->fa;
		}
		x->left = y->right;				//x������� ��Ϊ y���Ҷ���
		y->right->fa = x;
		
		y->right = x;					//y���Ҷ��� ��Ϊ x
		x->fa = y;
	}
	void rotate_R(MEMO *y,MEMO *x)
	{
		MEMO **upper;
		if (y->fa == NIL)
		{
			root = x;
			x->fa = NIL;
		}else
		{
			if (y->fa->left == y)
				upper = &y->fa->left;
			else
				upper = &y->fa->right;
			*upper = x;
			x->fa = y->fa;
		}
		
		y->right = x->left;
		x->left->fa = y;

		x->left = y;
		y->fa = x;
	}
	void shift_up(MEMO *cur)
	{
		while (cur != root && cur->_key2 < cur->fa->_key2)
		{
			if (cur->fa->left == cur)
			{
				rotate_L(cur->fa, cur);
			}else
			{
				rotate_R(cur->fa, cur);
			}
		}
	}
public:	
	bool insert(const T &key)
	{
		if (find(key)) return false;					//_key exists, not add	
		MEMO *cur = alloc(key);	
		if (root == NIL)						//һ��ʼû�нڵ�
		{
			root = cur;
			cur->fa = NIL;
			return true;
		}
		MEMO *old = root;
		while (1)								//��λ�ýڵ㣬�Ȳ嵽��������Ӧλ��
		{
			if (cur->key < old->key)
			{
				if (old->left == NIL)			   //���old�������Ϊ��,�����һ��ʼ�ͷ������
				{
					cur->fa = old;	
					old->left = cur;
					shift_up(old->left);
					break;
				}else
				old = old->left;
			}
			else
			{	
				if (old->right == NIL)
				{
					cur->fa = old;
					old->right = cur;
					shift_up(old->right);
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
		}
		else
		{
			while (it->left != NIL || it->right != NIL)
			{
				if (it->left != NIL && it->right != NIL)
				{
					int best = min(it->left->_key2, it->right->_key2);
					if (it->left->_key2 == best)
					{
						rotate_L(it, it->left); 
					}else
					{
						rotate_R(it, it->right);
					}	
				}else
				if (it->left != NIL)
				{
					rotate_L(it, it->left);
				}else
				if (it->right != NIL)
				{
					rotate_R(it, it->right);
				}
			}
			if (it->fa->left == it)
				it->fa->left = NIL;
			else
				it->fa->right = NIL;
			
			return true;
		}
	}
};
