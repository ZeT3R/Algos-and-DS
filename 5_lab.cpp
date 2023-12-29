#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
///////////////////////////////////////////////////////////////////////////////
struct Elem
{
	float i;
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
//////////////////////////////////////////////////////////////////////////////
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
		float first()
		{
			if(head != NULL)
			{
				return head->i;
			}
			else
			{
				cout<< "Our struct is empty ";
				return 0;
			}
		}
		void pop()
		{
			if (head!=NULL)
			{
				Elem* p=head;
				head=head->next;
				delete p;
			}
		}
		void push (float i)
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
//////////////////////////////////////////////////////////////////////////////
class OPZ
{
	private:
		string opz; //строка с польской записью
		string pav; //строка с нормальной записью
		string skobki(string pav);//Добавляет скобки правильному арифметическому выражению
		void operation(const char znak, Stack& st); //для операций над элементами стека
		string toOPZ(const string pav); //Преобразует строку POV в OPZ
	public:
		OPZ(const string str); //обычный конструктор с параметрами
		float OPZ_res (); //Вычисление арифметического выражения, записанного в виде польской записи
		void PAV_print(); //Печать выражения в нормальном виде
		void OPZ_print(); //Печать выражения в постфиксной записи
};
//////////////////////////////////////////////////////////////////////////////
string OPZ::skobki(string pav)
{
	pav.insert(pav.begin(), '(');
	pav.insert(pav.end(), ')');
	return pav;
}
//////////////////////////////////////////////////////////////////////////////
OPZ::OPZ(const string pav)
{
	this->pav=skobki(pav);
	this->opz=toOPZ(this->pav);
}
//////////////////////////////////////////////////////////////////////////////
void OPZ::PAV_print()
{
	cout<<pav<<endl;
}
//////////////////////////////////////////////////////////////////////////////
void OPZ::OPZ_print()
{
	cout<<opz<<endl;
}
//////////////////////////////////////////////////////////////////////////////
void OPZ::operation(const char znak, Stack& st)
{
	if(znak=='+')
	{
		float copy=st.first();
		st.pop();
		st.head->i+=copy;
	}
	if(znak=='-')
	{
		float copy=st.first();
		st.pop();
		st.head->i-=copy;
	}
	if(znak=='*')
	{
		float copy=st.first();
		st.pop();
		st.head->i*=copy;
	}
	if(znak=='/')
	{
		float copy=st.first();
		st.pop();
		st.head->i/=copy;
	}
}
//////////////////////////////////////////////////////////////////////////////
float OPZ::OPZ_res()
{
	string opz=this->opz;
	Stack st;
	string temp="";
	for(int i=0; i<opz.length(); i++)
	{
		if(isalpha(opz[i]))
		{
			string chisl="";
			cout<<"Enter "<<opz[i]<<": ";
			cin>>chisl;
			char bukv=opz[i];
			for(int j=i; opz.find(bukv)!=-1; j++)
					opz.replace(opz.find(bukv),1,chisl);
		}
	}
	for(int i=0; i<opz.length(); i++)
	{
		if(opz[i]=='+'||opz[i]=='-'||opz[i]=='*'||opz[i]=='/')
		{
			if(opz[i]=='-' && isdigit(opz[i+1]))
			{
				temp+=opz[i];
				for(i++; isdigit(opz[i]); i++ )
					temp+=opz[i];
				st.push(atoi(temp.c_str()));
				temp="";	
			}
			operation(opz[i], st);
			continue;
		}
		if(opz[i]!=' ') temp+=opz[i];
		else if(temp!="")
		{
			st.push(atoi(temp.c_str()));
			temp="";
		}
	}
	cout<<"Result: ";
	return(st.first());
}
////////////////////////////////////////////////////////////////////////////
string OPZ::toOPZ(const string pav)
{
	string opz="";
	string zn="";
	for(int i=0; i<pav.length(); i++)
	{
		if(pav[i]=='(')
		{
			int skb=0;
			string temp="";
			for(i++; i<pav.length(); i++)
			{
				if(skb==-1) break;
				if(pav[i]=='(') skb++;
				if(pav[i]==')') skb--;
				temp+=pav[i];
			}
			temp.erase(temp.end()-1);
			opz+=toOPZ(temp);   //Рекурсия
		}
		if(isalpha(pav[i]))
		{
			opz+=pav[i];
			opz+=" ";
		}
		
		if(pav[i]=='+'|| pav[i]=='-'|| pav[i]=='*'|| pav[i]=='/')
		{
			if((zn[0]=='*'|| zn[0]=='/'))
			{
				string d="";
				d+=pav[i]; 
				opz+=zn[0];
				opz+=" ";
				zn.replace(0, 1, d);
			}
			else
			{
				zn.insert(zn.begin(), ' ');
				zn.insert(zn.begin(), pav[i]);
			}
		}
	}
	opz+=zn;
	zn="";	
	return opz;
}
//////////////////////////////////////////////////////////////////////////////
int main()
{
	cout<<"\t\tOPZ\n\n";
	string test2="((a+b*(c-e)/(d+f))/(a*b))/c";// нормально арифметическое выражение (из лекции)
	OPZ tests(test2);// передаем выражение в конструктор
	cout<<"PAV:  ";
	tests.PAV_print(); //печать ПАВ
	cout<<"OPZ:  ";
	tests.OPZ_print(); //печать ОПЗ
	cout<<tests.OPZ_res()<<endl; //Печатаем результат
	//system("pause");
	return 0;
}
