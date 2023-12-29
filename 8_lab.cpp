#include<iostream>
using namespace std;

struct Node;
typedef Node* pNode;
struct Node
{
	int root;
	pNode left;
	pNode right;
	Node(int a)
	{
		left=right=NULL;
		root=a;
	}
};

class Tree
{
	pNode head;
/////////////////////////////////////////////////////////////////////////		
	public:
/////////////////////////////////////////////////////////////////////////		
	Tree()
	{
		head=NULL; 	
	}
/////////////////////////////////////////////////////////////////////////		
	pNode& getHead()
	{
		return head;
	}
/////////////////////////////////////////////////////////////////////////	
	void add(pNode &temp, int a)
	{
		if(head==NULL)
		{	
			head=new Node(a);
			return;
		}
		else
		{
			if(a<temp->root)
			{
				if(temp->left==NULL)
				{
					temp->left=new Node(a);
					return;
				}
				else  add(temp->left, a);				
			}
		
			else if (a>temp->root)
			{
				if(temp->right==NULL)
				{
					temp->right=new Node(a);
					return;
				}	
				else add(temp->right, a);	
			}
		}
	}
/////////////////////////////////////////////////////////////////////////	
	bool find(pNode &temp, int a) //поиск
	{
		if(temp==NULL)
		{
			cout<<"Not found!\n";
			return false;
		}
		else if(temp->root==a)
		{
			cout<<"found!\n";
			return true;
		} 
		else if(temp->root>a) find(temp->left, a);
		else find(temp->right, a);
	}
/////////////////////////////////////////////////////////////////////////		
	void print(pNode &temp) //Печать в прямом порядке
	{
		if(temp==NULL)
		{
			cout<<"Tree is empty\n";
			return;
		} 
		cout<<temp->root<<"  ";
		if(temp->left!=NULL) print(temp->left);
		if(temp->right!=NULL) print(temp->right);
	}
/////////////////////////////////////////////////////////////////////////		
	void print_sort(pNode &temp) //Печать в отсортированном порядке
	{
		if(temp==NULL)
		{
			cout<<"Tree is empty\n";
			return;
		} 
		if(temp->left!=NULL) print_sort(temp->left);
		cout<<temp->root<<"  ";
		if(temp->right!=NULL) print_sort(temp->right);
	}
/////////////////////////////////////////////////////////////////////////		
	void print_reverse(pNode &temp) //Печать в обратном порядке
	{
		if(temp==NULL)
		{
			cout<<"Tree is empty\n";
			return;
		} 
		if(temp->left!=NULL) print_reverse(temp->left);
		if(temp->right!=NULL) print_reverse(temp->right);
		cout<<temp->root<<"  ";
	}
/////////////////////////////////////////////////////////////////////////		
	void print_reverse_sort(pNode &temp) //Печать в обратном отсорированном порядке
	{
		if(temp==NULL)
		{
			cout<<"Tree is empty\n";
			return;
		} 
		if(temp->right!=NULL) print_reverse_sort(temp->right);
		cout<<temp->root<<"  ";
		if(temp->left!=NULL) print_reverse_sort(temp->left);
	}
/////////////////////////////////////////////////////////////////////////		
};

int main()
{
	//int arr2[8]={4,2,1,3,5,7,6,8};
	int arr[12]={22,10,3,5,13,26,18,19,17,2,4,12};
	Tree a;
	for(int i=0; i<12; i++) a.add(a.getHead(), arr[i]);
	cout<<"\t\tObhodi\n\n";
	a.print(a.getHead());
	cout<<"\n\n";
	a.print_sort(a.getHead());
	cout<<"\n\n";
	a.print_reverse(a.getHead());
	cout<<"\n\n";
	a.print_reverse_sort(a.getHead());
	cout<<"\n\n";
	a.find(a.getHead(), 100);
	a.find(a.getHead(), 17);
	return 0;
}
