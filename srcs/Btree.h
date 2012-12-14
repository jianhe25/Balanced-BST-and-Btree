template<class T>
class Btree: public Mytree<T>
{
	const static int t = 3;	// branch factor
	const static int MEMO_SIZE_Btree = 200000;
	struct MEMO
	{
		int size, id;
		bool leaf;
		T key[2*t]; 
		MEMO* son[2*t+1];		
		int pos(const T &_key)
		{
			for (int i=1;i<=size;i++)
			if (key[i] == _key)
				return i;
			return 0;
		}
		void remove(int pos)			//remove x's pos key and pos child
		{
			for (int i=pos;i<size;i++)
			{	
				key[i] = key[i+1];
				son[i] = son[i+1];
			}
			son[size] = son[size+1];
			size--;
		}
	}memo[MEMO_SIZE_Btree];	
	MEMO *root;
	int cnt, size;
	
	MEMO *find(MEMO *x,const T &_key,int &th)
	{
		int i = 1;
		while (i <= x->size && _key > x->key[i]) 
			i++;
		if (i <= x->size && x->key[i] == _key) 
		{
			th = i;
			return x;
		}
		if (x->leaf) 
		{
			th = -1;
			return NULL;
		}else
			return find(x->son[i], _key, th);
	}
	MEMO *alloc()
	{
		memo[cnt].id = cnt;
		return &memo[cnt++];
	}
	void split(MEMO *x,int i,MEMO *y)
	{
		MEMO *z = alloc();
		z->leaf = y->leaf;
		
		z->size = t - 1;
		for (int j=1;j<=t-1;j++)
			z->key[j] = y->key[j+t];
			
		if (!y->leaf)
		{
			for (int j=1;j<=t;j++)
				z->son[j] = y->son[j+t];
		}
		y->size = t - 1;
		
		for (int j=x->size+1;j>=i+1;j--)
			x->son[j+1] = x->son[j];
		x->son[i+1] = z; 		
				
		for (int j=x->size;j>=i;j--)
			x->key[j+1] = x->key[j];
		
		x->key[i] = y->key[t];	
		x->size++;
	}
	void insert_nonfull(MEMO *x,const T &_key)
	{
		int i = x->size;
		if (x->leaf)
		{
			while (i >= 1 && _key < x->key[i])
			{
				x->key[i+1] = x->key[i];
				i--;
			}
			x->key[i+1] = _key;
			x->size++;
		}else
		{
			while (i >= 1 && _key < x->key[i])
				i--;
			i = i + 1;
			if (x->son[i]->size == 2*t-1)	// full node
			{
				split(x, i, x->son[i]);
				if (_key > x->key[i])
					i++;
			}
			insert_nonfull(x->son[i], _key);
		}
	}
	void chk_DFS(MEMO *x, int dep)
	{
		if (x == NULL)
		{	
			return;
		}
		printf("dep=%d x is size = %d 		",dep, x->size);
		for (int i=1;i<=x->size;i++) printf("%d ",x->key[i]); printf("\n");
		
		for (int i=1;i<=x->size+1;i++)
			chk_DFS(x->son[i], dep+1);	
	}
	T find_predecessor(MEMO *x,const T &key)
	{		
		for (int i=x->size;i>=1;i--)
		if (x->key[i] < key)
		{
			if (x->leaf)
				return x->key[i];
			else
				return find_predecessor(x->son[i+1], key);
		}
	}
	T find_successor(MEMO *x,const T &key)
	{		
		for (int i=1;i<=x->size;i++)
		if (x->key[i] > key)
		{
			if (x->leaf)
				return x->key[i];
			else
				return find_successor(x->son[i], key);
		}
	}
	void merge(MEMO *x,int k)	// merge x's k and k+1 son to k.
 	{
		MEMO *y = x->son[k];
		MEMO *z = x->son[k+1];
		y->key[t] = x->key[k];
		for (int i=1;i<=t-1;i++)
		{
			y->key[t+i] = z->key[i];
			y->son[t+i] = z->son[i];
		} 
		y->son[2*t] = z->son[t];
		y->size = 2*t-1;
		
		x->son[k] = y;
		for (int i=k;i<x->size;i++)
		{	
			x->key[i] = x->key[i+1];
			x->son[i+1] = x->son[i+2];
		}
		x->size--;	
		if (x == root && x->size == 0)
			root = y;
	}
	void B_delete(MEMO *x,const T &key)
	{
		if (x->leaf)				//key must in the leaf, because we have find(key) before 
		{	
			x->remove( x->pos(key) );
			return;
		}else						//x is an internal node
		{
			T k1;
			int pos = x->pos(key);			//key in x
			if (pos)
			{
				MEMO *y = x->son[pos];
				if (y->size >= t)			//y has at least t keys
				{
					k1 = find_predecessor(y, key); 
					x->key[pos] = k1;
					B_delete(y, k1);
				}else						//y has t-1 keys
				{
					MEMO *z = x->son[pos+1];
					if (z->size >= t)		//z has at least t keys
					{
						k1 = find_successor(z, key); 
						x->key[pos] = k1;
						B_delete(z, k1);
					}else					//both y and z have t-1 keys
					{
						merge(x, pos);
						B_delete(y, key);
					}
				}
			}else					//key is not in internal node x
			{
				int k = x->size+1;	//reserve c as the last child of x
				for (int i=1;i<=x->size;i++)
				if (key < x->key[i])
				{
					k = i;
					break;
				}
				MEMO *c = x->son[k];
				MEMO *z;
				if (c->size == t-1)
				{
					if (k > 1 && x->son[k-1]->size >= t)	//put k1 to c, and put son[k-1]'s last key to k1. 
					{
						k1 = x->key[k-1];
						z = x->son[k-1];
						c->son[ c->size+2 ] = c->son[ c->size+1 ];	//insert k1 to c's first key.
						for (int i=c->size;i>=1;i--)
						{
							c->key[i+1] = c->key[i];							
							c->son[i+1] = c->son[i];
						}
						c->key[1] = k1;
						c->son[1] = z->son[ z->size+1 ];
						c->size++;
						x->key[k-1] = z->key[ z->size ];	
						z->size--;					//remove z's last key and last+1's son
					}else
					if (k <= x->size && x->son[k+1]->size >= t)
					{
						k1 = x->key[k];
						z = x->son[k+1];
						
						c->key[c->size+1] = k1;			//insert k1 to c's last key
						c->son[c->size+2] = z->son[1];
						c->size++;
						
						x->key[k] = z->key[1];
						z->remove(1);					//remove z's first key
					}else
					{
						if (k > 1)
						{	
							merge(x, k-1);
							c = x->son[k-1];
							//B_delete(x->son[k-1], key);
						}else
						{
							merge(x, k);
							//B_delete(x->son[k], key);
						}	
					}	
				}	
				B_delete(c, key);
			}	
		}	
	}
	void calc_ID(MEMO *v)
	{
		v->id = tot_ID++;
		if (v->leaf) return;
		for (int i=1;i<=v->size+1;i++)
			calc_ID(v->son[i]);
	}
	int dfs(MEMO *v)
	{
		int id = v->id;
		for (int i=1;i<=v->size;i++)
			btreeRect[id].key[i] = v->key[i];
		btreeRect[id].size = v->size;
		btreeRect[id].leaf = v->leaf;

		int tmp = btreeRect[id].x;	
		if (!v->leaf)
		{
			for (int i=1;i<=v->size+1;i++)
			{
				int son_id = v->son[i]->id;
				btreeRect[id].son[i] = son_id;
				btreeRect[son_id].x = (i>1)? tmp + RECT_GAP : tmp;	
				btreeRect[son_id].y = btreeRect[id].y + UNIT_LENGTH_Y;				
				tmp = dfs(v->son[i]);
			}
		}
		return tmp + v->size*RECT_LENGTH_X;
	}
	void dfs1(MEMO *v)
	{
		if (v->leaf) return;
		for (int i=1;i<=v->size+1;i++)
		{
			dfs1(v->son[i]);
		}
		btreeRect[v->id].x = (btreeRect[v->son[1]->id].x + btreeRect[v->son[v->size+1]->id].x) / 2;			
	}
public:	
	void clear()
	{
		size = cnt = 0;
		MEMO *x = alloc();
		x->leaf = true;
		x->size = 0;
		root = x;
	}
	Btree()
	{	
		clear();
	}
	bool insert(const T &_key)
	{
		if (find(_key)) return false;
		MEMO *r = root;
		if (r->size == 2*t-1)
		{
			MEMO *s = alloc();
			root = s;
			s->leaf = false;
			s->size = 0;
			s->son[1] = r;
			split(s, 1, r);
			insert_nonfull(s, _key);
		}else
		{
			insert_nonfull(r, _key);
		}
		return true;
	}
	bool find(const T &_key)
	{
		int th;
		return find(root, _key, th) != NULL;	
	}
	bool erase(const T &_key)
	{		
		if (!find(_key)) return false;
		B_delete(root, _key);
		return true;
	}
	void tranverse()
	{
		tot_ID = 0;
		calc_ID(root);
		btreeRect[root->id].x = 0;
		btreeRect[root->id].y = 30;
		int width = dfs(root);
		dfs1(root);

		int Lmost = INFI;
		for (int i=0;i<tot_ID;i++)
			Lmost = min(Lmost, btreeRect[i].x);
				
		for (int i=0;i<tot_ID;i++)				//保持不出左边界
		{
			btreeRect[i].x += MARGIN_LEFT - Lmost; 
		}
		if (btreeRect[0].x < 470)				//根移到中间
		{
			int delta = 470 - btreeRect[0].x;
			for (int i=0;i<tot_ID;i++)
				btreeRect[i].x += delta;
		}
	}	
};
