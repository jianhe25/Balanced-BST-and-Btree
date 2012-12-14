#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

struct Test
{	
	int Time[5][5];
	set<int> standard;

	int op[TEST_SIZE], data[TEST_SIZE], query[TEST_SIZE], erase[TEST_SIZE];
	
	void GenerateCase(int test_size, int op)
	{
		int n = test_size;	
		int RAND_SIZE = 2 * test_size;

		if (op == RANDOM_CASE)
		{
			for (int i=0;i<n;i++) 
			{
				data[i] = myrand() % RAND_SIZE;
				query[i] = myrand() % RAND_SIZE;
				erase[i] = myrand() % RAND_SIZE;
			}
		}else
		{
			for (int i=0;i<n;i++)
			{
				data[i] = (op == ASCENDED_CASE) ? i : n-i;
				query[i] = myrand() % RAND_SIZE;
				erase[i] = myrand() % RAND_SIZE;
			}
		}
		fstream filestr("input.txt", ios::out);
		
		//MessageBox::Show(filestr.good().ToString() + " " + filestr.is_open().ToString());

		filestr << n << " " << n << " " << " " << n << endl;
		for (int i=0;i<n;i++) filestr << data[i] << " ";  filestr << endl;
		for (int i=0;i<n;i++) filestr << query[i] << " "; filestr << endl;
		for (int i=0;i<n;i++) filestr << erase[i] << " "; filestr << endl;
	}
	void FileTest(string FileName, bool test_bst)
	{
		fstream filestr (FileName.c_str(), fstream::in | fstream::out);
		int Insert_Num, Query_Num, Erase_Num; 
		
		filestr >> Insert_Num >> Query_Num >> Erase_Num;	
		for (int i=0;i<Insert_Num;i++) filestr >> data[i];
		for (int i=0;i<Query_Num;i++) filestr >> query[i];
		for (int i=0;i<Erase_Num;i++) filestr >> erase[i];

		for (int p=0;p<4;p++)
		{
			trees[p]->clear();		
			if (p == 0 && !test_bst) 
			{
				Time[0][p] = Time[1][p] = Time[2][p] = 0;
				continue;
			}
			int t0 = clock();
			for (int i=0;i<Insert_Num;i++)
				trees[p]->insert(data[i]);
			int t1 = clock();
			Time[0][p] = t1 - t0;

			for (int i=0;i<Query_Num;i++)
				trees[p]->find(query[i]);
			int t2 = clock();
			Time[1][p] = t2 - t1;

			for (int i=0;i<Erase_Num;i++)
				trees[p]->erase(erase[i]);
			int t3 = clock();
			Time[2][p] = t3 - t2;
			
			trees[p]->clear();
			//MessageBox::Show(p.ToString() + " " + Insert_Time[p].ToString() + " " + Query_Time[p].ToString() + " " + Erase_Time[p].ToString());
		}
	}
};






