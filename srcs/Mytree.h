template<class T>
struct Mytree
{
	virtual struct MEMO
	{
		T key;
		int height, id, _key2, size;
		MEMO *left,*right,*fa;
	};
	MEMO *root, *NIL;
	MEMO memo[MEMO_SIZE];
	int cnt;

	virtual MEMO *alloc(const T &_key)
	{
		MEMO *addr = &memo[cnt++];
		memset(addr,0,sizeof(*addr));		//初始化，指针全指向NIL。
		addr->_key2 = rand() % 1000;		//随机一个treap的_key2值
		addr->key = _key;					//初始化key
		addr->height = 1;
		addr->left = NIL;
		addr->right = NIL;
		addr->fa = NIL;
		return addr;
	}	
	virtual MEMO *find(MEMO *it,const T &_key)
	{
		if (it == NIL)	// _key not found
		{
			return NIL;
		}
		if (_key == it->key)	//_key found 
		{
			return it;
		}
		if (_key < it->key)
			return find(it->left, _key);
		else
			return find(it->right, _key);
	}
	virtual bool find(const T &_key)
	{
		return find(root, _key) != NIL;
	}	
	virtual bool erase(const T &_key){return false;}
	virtual bool insert(const T &_key){return false;}
	virtual void clear()
	{
		cnt = 0;
		NIL = &memo[cnt++];
		memset(NIL, 0, sizeof(MEMO));
		root = NIL;
	}
	virtual void calc_ID(MEMO *v)
	{
		if (v == NIL) return;
		v->id = tot_ID++;
		circle[v->id].key = v->key;
		circle[v->id].key2 = v->_key2;
		v->size = 1;
		if (v->left != NIL)
		{
			calc_ID(v->left);
			v->size += v->left->size;
			edge.push_back(make_pair(v->id, v->left->id));
		}
		if (v->right != NIL)
		{
			calc_ID(v->right);	
			v->size += v->right->size;
			edge.push_back(make_pair(v->id, v->right->id));
		}
	}
	virtual void dfs(MEMO *v,int Lbound)
	{
		if (v == NIL) return;
		int mid = Lbound;
		if (v->left != NIL)
		{
			circle[v->left->id].y = circle[v->id].y + UNIT_LENGTH_Y;		
			dfs(v->left, Lbound);
			mid = v->left->size + Lbound;
		}
		if (v->right != NIL)
		{
			circle[v->right->id].y = circle[v->id].y + UNIT_LENGTH_Y;			
			dfs(v->right, mid + 1);	
		}
		circle[v->id].x = mid;
	}
	Mytree()
	{
		clear();
	}
	virtual void tranverse()
	{
		tot_ID = 0;
		edge.clear();
		circle[0].y = CENTRE_Y;
		calc_ID(root);
		dfs(root, 5);	
		for (int i=0;i<tot_ID;i++)
		{
			circle[i].x *= UNIT_GAP;
		}
		if (circle[0].x < 470)
		{
			int delta = 470 - circle[0].x;		
			for (int i=0;i<tot_ID;i++)
				circle[i].x += delta;
		}
	}
};
