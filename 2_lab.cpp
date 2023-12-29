#include <iostream>
using namespace std;

typedef int Inf;
typedef int Key;

struct Elem;
typedef Elem* pElem;
struct Elem
{
	Key key;
	Inf inf;
	pElem next;
	Elem(){
		
	}
	Elem(Key k, Inf i){
		key=k;
		inf=i;
		next=NULL;
	}
};

class Tabl
{
	protected:	
		pElem head;
	public:		
		Tabl(){
			head=NULL;
		}
		void add(Key k, Inf i){
				pElem p = new Elem(k,i);
				p->next=head;
				head=p;
		}
		void del(Key k)
		{
			pElem p = head;
			pElem p1 = head;
			while(p!=NULL) 
			{ 
				if( p->key == k)
				{
					if(p==head)
						head=p->next;
					else
						p1->next = p->next;
					delete p;
					break;
				}
				p1 = p; 
				p = p->next; 
			}	
		}
		
		
		pElem search(Key k, pElem& p1){
			pElem p = head;
			while(p!=NULL && p->key != k){
				p1 = p; 
				p = p->next;
			}
			  
				 
			return p;
		
		
		}
		bool empty()
		{
			return head==NULL;
		}
		void print()
		{
			pElem p=head;
			while(p!=NULL)
			{
				cout<<p->key<<" "<<p->inf<<endl;
				p=p->next;
			}
			cout<<endl;
		}
};

 
class KeyOrdTabl : public Tabl
{
	public:
		void add(Key k, Inf i)
		{
			pElem p = head;
			pElem p1 = head;
			pElem temp = new Elem; temp->key=k; temp->inf=i;
			while(p!=NULL && p->key < k) 
			{ 
				p1 = p; 
				p = p->next; 
			}
			if(p==head) 
			{
				temp->next=head; 
				head=temp;
			}
			else
			{
				p1->next =temp; temp->next=p;
			}
		}
};


class FrOrdTabl : public Tabl
{
	public:
		pElem search(Key k)
		{
			pElem p = head;
			pElem p1 = head;
			p=Tabl::search(k, p1);
//			while(p!=NULL && p->key != k)
//			{	
//				p1=p; p = p->next;
//			} 
			if(p != head && p != NULL)	
			{
				p1->next = p->next; p->next=head; head=p;	
			}
			return p;
		}
};

int main() 
{
setlocale(LC_ALL, "rus");	
	Tabl nt;
	nt.add(10,17);
	nt.print();
	nt.add(5,19);
	nt.print();
	nt.add(7,22);
	nt.print();
	nt.add(12,25);
	nt.print();
	pElem p1;
	nt.search(10, p1);
	nt.print();
	nt.del(7);
	nt.print();
	nt.del(5);
	nt.print();
	nt.del(12);
	nt.print();
	

	KeyOrdTabl* kot = new KeyOrdTabl;
	kot->print();
	kot->add(10,17);
	kot->print();
	kot->add(5,19);
	kot->print();
	kot->add(7,22);
	kot->print();
	kot->add(12,25);
	kot->print();
	
	FrOrdTabl fot;
	fot.print();
	fot.add(10,17);
	fot.print();
	fot.add(5,19);
	fot.print();
	fot.add(7,22);
	fot.print();
	fot.add(12,25);
	fot.print();
	pElem t = fot.search(10);
	fot.print();
	return 0;
}
