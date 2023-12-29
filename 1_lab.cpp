#include <iostream>
#include <bitset>
#include <string>
#include <Windows.h>
#define dflt SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)
#define blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY)
#define yell SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define red  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED)
using namespace std;
int arr[10]={5, 34, 56, -23, -12, 0, 39, 15, 45, 100};
class Set{
public:
    int shk[10];
    // ���������� �����������
    Set()
	{
        for(int i = 0; i < 10; i++)
            shk[i] = 0;
    }
    // ������� ����������
    void add(int s)
	{
		for(int i=0; i<10; i++)
		if(arr[i]==s){
			shk[i] = 1;
			break;
		} 
    }
    // ������� ��������������
	void belong(int s)
	{
		for(int i=0; i<10; i++)
		{
		if ((arr[i]==s) && (shk[i]==1))
		{
		cout<<"�����������\n";
		goto a;
	    }
	    }
		cout<<"�� �����������\n";
		a:;
	}
    // ������� ��������
	void remove(int s)
	{
		for(int i=0; i<10; i++)
		if(arr[i]==s){
			shk[i] = 0;
			goto a;
		} 
        a:;
		
	}	
	//������� �����������
    void show()
	{
        cout << "{ ";
        for(int i = 0; i < 10; i++)
		
            if(shk[i] == 1)
                cout << arr[i] << ' ';
		cout << '}' << endl;
}
// �������-�����?
void emptiness()
	{
		for(int i=0; i<10; i++)
		{
			if (shk[i]== 1)
			{
				cout<<"�� �����\n";
				return;
			} 
		}
		cout<<"�����\n";
	}
// ������� �����������
Set &unite(Set s2)
{
	Set *s3=new Set;
    for(int i = 0; i < 10; i++)
	{
        if(shk[i] == 1 || s2.shk[i] == 1) s3->shk[i] = 1;
    }
    return *s3;
}

// ������� �����������
Set &peresech(Set s2)
{
	Set *s3=new Set;
    for(int i = 0; i < 10; i++)
	{
        if(shk[i] == 1 && s2.shk[i] == 1) s3->shk[i] = 1;  
    }
    return *s3;
}
// ������� ��������
Set &difference(Set s2)
{
Set *s3=new Set;
	for(int i = 0; i < 10; i++)
	{
      if(shk[i] == 1 && s2.shk[i] == 0) s3->shk[i] = 1;   
    }
    return *s3;
}
	//������� ����������
Set &dop()
{
	Set *s3=new Set;
	for(int i = 0; i < 10; i++)
	{
       if(shk[i] == 0) s3->shk[i] = 1;    
    }
    return *s3;
}
};
int main(){
setlocale(LC_ALL, "Rus");
string line="================================================================================\n";
blue;
cout<<line; yell;
cout<<"\t\t\t\t������������ ������ �1\n\n"; blue;
cout<<line<<endl; yell;

for(int i=0; i<10; i++)
{
	cout<<arr[i]<<"\t";
}
cout<<endl; blue;
cout<<line; yell;

    Set set1;
    set1.show();
    set1.add(34);
    set1.add(0);
    set1.add(39);
    set1.show();
    set1.belong(39);
    set1.remove(39);
    set1.belong(39);
    set1.add(39);
    Set set2;
    set2.add(56);
    set2.add(5);
    set2.add(39);
    set2.show();
    Set set3;
	set3=set1.unite(set2);
    set3.show();
    set3=set1.difference(set2);
	set3.show();
    set3=set1.peresech(set2);
    set3.show();
    set3=set1.dop();
    set3.show();
    Set set4;
    set4.emptiness();
	system("pause");

    return 0;
}

