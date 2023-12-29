#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////
struct Elem;
typedef Elem* pElem;
struct Elem
{
	char c;
	pElem next;
	pElem prev;
};
///////////////////////////////////////////////////////////////
class MyString
{
	private:
		pElem head;
		pElem tail;
	public:
		MyString()
		{
			head = NULL;
			tail = NULL;
		}
//Конструктор принимающий объект класса MyString(конструктор копирования)
	MyString (const MyString& m)
	{
		if (m.head != NULL)
		{
			this->head = new Elem;
			this->head->prev = NULL;
			this->head->next = NULL;
			this->head->c = m.head->c;
			pElem p1 = head;
			pElem p2 = m.head->next;
			while (p2 != NULL)
			{
				pElem adding = new Elem;
				adding->c = p2->c;
				p1->next = adding;
				adding->prev = p1;
				adding->next = NULL;
				p1 = p1->next;
				p2 = p2->next;
			}
			this->tail = p1;
		}
		else
		{
			this->head = NULL;
			this->tail = NULL;
		}
	}
//Конструктор принимающий char*
	MyString (const char* a)
	{
		head = new Elem;
		head->c = a[0];
		head->next = NULL;
		head->prev = NULL;
		pElem previous = head;
		if (a[0] != '\0')
			for (int i = 1; a[i] != '\0'; ++i)
			{
				pElem adding = new Elem;
				adding->c = a[i];
				previous->next = adding;
				adding->prev = previous;
				adding->next = NULL;
				previous = adding;
			}
		tail = previous;
	}
//Функция печати	
	void print()
	{
		pElem p = head;
		while (p != NULL)
		{
			cout << p->c;
			p = p->next;
		}
	}
//Деструктор	
	~MyString()
	{
		pElem deleting = this->head;
		while (head != NULL)
		{
			deleting = head;
			head = head->next;
			delete deleting;
		}
	}
//Конкатенация двух объктов класса строка
	void conc(const MyString& m)
	{
		pElem p1 = this->tail;
		pElem p2 = m.head;
		while (p2 != NULL)
		{
			pElem adding = new Elem;
			adding->c = p2->c;
			p1->next = adding;
			adding->prev = p1;
			adding->next = NULL;
			p1 = p1->next;
			p2 = p2->next;
		}
		this->tail = p1;
	}
//Конкатенация с char*	
	void conc(const char* a) 
	{
		pElem p = this->tail;
		for (int i = 0; a[i]!='\0'; ++i)
		{
			pElem temp=new Elem;
			temp->c=a[i];
			p->next=temp;
			temp->prev=p;
			temp->next=NULL;
			p=p->next;
		}
		tail=p;
	}
//Вычеркивание подстроки	
	void strike(const MyString& ex)
	{
		pElem p_c = this->isin(ex), p_s = ex.head;
		bool rem = false;
		pElem first = NULL;
		if (p_c != NULL)
		{
			if (p_c->prev != NULL)
				first = p_c->prev;
			else
				rem = true;
			while (p_s != NULL)
			{
				pElem deleting = p_c;
				p_c = p_c->next;
				delete deleting;
				p_s = p_s->next;
			}
			if (rem)
			{
				this->head = p_c;
				p_c->prev= NULL;
			}
			else
			{
				first->next = p_c;
				p_c->prev = first;
			}
		}
		if (p_c != NULL)
			while (p_c->next != NULL)
			{
				p_c = p_c->next;
				this->tail = p_c;
			}
		else
			tail = NULL;
	}
//Разделение	
	MyString& divide(pElem p)
	{
		MyString* R = new MyString;
		if (p != NULL)
		{
			R->tail = this->tail;
			this->tail = p->prev;
			this->tail->next = NULL;
			p->prev = NULL;
			R->head = p;
		}
		return *R;
	}
//Подстановка	
	void substitute(pElem p1, const MyString& m)
	{
		if (m.head != NULL)
		{
			if (p1 != NULL)
			{
				pElem following = p1->prev;
				MyString* R = new MyString(m);
				R->tail->next=p1;
				p1->prev=R->tail;
				R->head->prev =following;
				following->next= R->head;
			}
			else 
			{
				MyString* R = new MyString(m);
				R->tail->next = this->head;
				if (this->head != NULL)
					this->head->prev = R->tail;
				this->head = R->head;
			}
		}
	}
//Контекстный поиск	
	pElem isin(const MyString& s)
	{
		pElem r = NULL;
		bool is_curr_right = false;
		pElem p_c = this->head, p_s = s.head;
		while ((p_s != NULL) && (p_c != NULL))
		{
			if (p_c->c == p_s->c)
			{
				if (is_curr_right == false)
					r = p_c;
				is_curr_right = true;
				p_s = p_s->next;
			}
			else
			{
				is_curr_right = false;
				p_s = s.head;
				r = NULL;
			}
			p_c = p_c->next;
		}
		if (is_curr_right)
			return r;
		else return NULL;
	}	
//Контекстная замена	
	void swap(const MyString& context, const MyString& swap)
	{
		pElem found = this->isin(context);
		if (found != NULL)
		{
			found = found->prev;
			this->strike(context);
			this->substitute(found, swap);
		}
	}
};

int main()
{
	MyString s("Cat");
	MyString s2("Dog");
	s.print();
	cout<<"\n";
	s.conc("Fish");
	s.print();
	cout<<"\n";
	s.conc(s2);
	s.print();
	cout<<"\n";
	MyString d("Fish");
	s.strike(d);
	s.print();
	cout<<"\n";
	MyString m=s.divide(s.isin(MyString("D")));
	s.print();
	cout<<"\n";
	m.print();
	cout<<"\n";
	MyString k(m);
	k.substitute(k.isin(MyString("o")), d);
	k.print();
	cout<<"\n";
	k.swap(MyString("DF"), s);
	k.print();
	cout<<"\n";
	system("pause");
	return 0;
}
