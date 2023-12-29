#include <iostream>
using namespace std;
struct Elem
{
	int i;
	Elem* next;
	Elem()
	{
		next=NULL;
	}
	Elem (int i)
	{
		this->i=i;
		next=NULL;
	}
};
	class Stack
	{
	public:
		Elem* head;
		Stack()
		{
			head=NULL;
		}
		bool empty()
		{
			return head==NULL;
		}
		int first()
		{
			if(head != NULL)
			{
				return head -> i;
			}
			else
			{
				cout<< "Our struct is empty ";
				return 0;
			}
		}
		void pop (int& i)
		{
			if (head!=NULL)
			{
				i=head->i;
				Elem* p=head;
				head=head->next;
				delete p;
			}
		}
		void push (int i)
		{
			Elem* el=new Elem(i);
			el->next=head;
			head=el;
		}
		void print()
		{
			Elem* temp=head;
			while (temp!=NULL)
			{
				cout<<temp->i<<' ';
				temp=temp->next;
			}
			cout<<endl;
		}
	};
	class Queue : public Stack
	{
	public:
		void push(int i)
		{
			Elem* el=new Elem(i);
			if (head==NULL)
			{
				head=el;
				return;
			}
			Elem* temp=head;
			while(temp->next !=NULL)
				temp=temp->next;
			temp->next=el;
		}
	};
	class Dack : public Queue
	{
	public:
		void pop_end(int& i)
		{
			if (head==NULL)
				return;
			if (head->next==NULL)
			{
				i=head->i;
				delete head;
				head=NULL;
				return;
			}
			Elem* temp=head;
			while (temp->next->next !=NULL)
				temp=temp->next;
			i=temp->next->i;
			delete temp->next;
			temp->next=NULL;
		}
	};
int main()
{
	Stack st;
	for (int i=0; i<10; i++)
		st.push(i);
	st.print();
	int i;
	st.pop(i);
	cout<<i<<endl;
	st.print();
	Queue q;
	for (int i=0; i<10; i++)
		q.push(i);
	q.print();
	q.pop(i);
	cout<<i<<endl;
	q.print();
	Dack d;
	for (int i=0; i<10; i++)
	{
		if (i%2 == 0)
			d.push(i);
		else
			d.Stack::push(i);
	}
	d.print();
	d.pop_end(i);
	cout<<i<<endl;
	d.print();
	d.pop(i);
	cout<<i<<endl;
	d.print();
	system("pause");
	return 0;
}
