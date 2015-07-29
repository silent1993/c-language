#include <iostream>
#include <string>
#include <fstream>


using namespace std;
typedef struct tree{
	string nodename;
	string condition;
	tree* lchild;
	tree* rchild;
}* BTREE;


BTREE treehead;
int index=0;
string Sin;

BTREE CreateTree()
{
	BTREE addtree=new tree;
	for (; index < Sin.length(); index++)
	{
		string temp;
		while (Sin[index] != ' ')
		{
			temp = temp + Sin[index];
			index++;

		}
		index++;
		if (temp == "SELECT")
		{
			addtree->nodename = temp;
			temp.erase();
			index += 2;
			while (Sin[index] != ']')
			{
				temp += Sin[index];
				index++;
			}
			addtree->condition = temp;
			addtree->rchild = NULL;
			addtree->lchild = CreateTree();
		}
		else if (temp == "PROJECTION")
		{
			addtree->nodename = temp;
			temp.erase();
			index += 2;
			while (Sin[index] != ']')
			{
				temp += Sin[index];
				index++;
			}
			addtree->condition = temp;
			addtree->rchild = NULL;
			addtree->lchild = CreateTree();
		}
		
		else if (temp == "JOIN")
		{
			addtree->nodename = temp;
			temp.erase();
			int j = index;
			while (Sin[j] != '(')
			{
				j--;
			}
			j+=2;
			while (Sin[j] != ' ')
			{
				temp += Sin[j];
				j++;
			}
			BTREE btemp=new tree;
			btemp->nodename = temp;
			btemp->lchild = NULL;
			btemp->rchild = NULL;
			temp.erase();
			addtree->lchild = btemp;
			while (Sin[index] != ' ')
			{
				temp = temp + Sin[index];
				index++;

			}
			index++;
			BTREE ctemp = new tree;
			ctemp->nodename = temp;
			ctemp->lchild = NULL;
			ctemp->rchild = NULL;
			addtree->rchild = ctemp;

		}
		else 
		{
			
			addtree = CreateTree();
		}
		temp.erase();
		return addtree;
	}
	return addtree;
}



bool isEmpty(BTREE bt)
{
	if (bt == NULL)
		return true;
	else
		return false;
}
int flag = 0;
BTREE FindFather(string name,BTREE BT)
{
	BTREE temp;
	temp = new tree;
	if (!isEmpty(BT))
	{
		if (BT->lchild->nodename == name)
		{
			return BT;
		}
		else
		{
			temp=FindFather(name, BT->lchild);
			
			
		}
	}
	return temp;
}
void Preorder(BTREE BT)
{
	if (!isEmpty(BT))
	{
		cout << BT->nodename << endl;
		if (BT->nodename == "PROJECTION" || BT->nodename == "SELECT")
			cout << BT->condition << endl;
		Preorder(BT->lchild);
		Preorder(BT->rchild);
	}
	return;
}

void optimize(BTREE BT)
{
	
	string condition1;
	string condition2;
	string temp;
	if (!isEmpty(BT))
	{
		if (BT->nodename == "SELECT" )
		{
			for (int i = 0; i < BT->condition.length(); i++)
			{
				if (BT->condition[i] == '&')
				{

					for (int j = 0; j < i; j++)
					{
						temp += BT->condition[j];
					}
					condition1 = temp;
					temp.erase();
					i++;
					for (; i < BT->condition.length(); i++)
					{
						temp += BT->condition[i];

					}
					condition2 = temp;
				}
				else
				{
					if ((i + 1) == BT->condition.length())
					{
						condition1 = BT->condition;
					}
					
				}
			}
			BTREE father;
			BTREE temp;
			temp = new tree;
			father = FindFather(BT->nodename, treehead);
			father->lchild = BT->lchild;
			if (BT->lchild->nodename == "JOIN")
			{
				temp = BT->lchild;
				BTREE temp1,temp2;
				temp1 = new tree;
				temp2 = new tree;
				temp1->nodename = "SELECT";
				temp2->nodename = "SELECT";
				temp1->condition = condition1;
				temp2->condition = condition2;
				temp1->lchild = temp->lchild;
				temp1->rchild = NULL;
				temp->lchild = temp1;
				temp2->lchild = temp->rchild;
				temp2->rchild = NULL;
				temp->rchild = temp2;
			}
			else
			{
				if (BT->lchild->lchild->nodename == "JOIN")
				{
					temp = BT->lchild->lchild;
					BTREE temp1;
					temp1 = new tree;
					temp1->nodename = "SELECT";
					temp1->condition = condition1;
					temp1->lchild = temp->lchild;
					temp1->rchild = NULL;
					temp->lchild = temp1;
				}
			}
			flag = 1;
			return;
		}
		if (!flag)
		{
			optimize(BT->lchild);
			optimize(BT->rchild);
		}
	}
	
}
int main()
{
	//cout << "Please input the string!"<<endl;
	ifstream fin;
	fin.open("E://test.txt");
	getline(fin, Sin);
	
	treehead = new tree;
	cout << Sin << endl;
	treehead->lchild= CreateTree();
	treehead->rchild = NULL;
	Preorder(treehead);
	cout << "after optimize!" << endl;
	optimize(treehead);
	Preorder(treehead);
	return 0;
}