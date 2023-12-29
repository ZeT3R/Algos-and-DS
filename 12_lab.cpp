#include <iostream>
using namespace std;
void print(int arr[], int size, int com, int sw)
{
	cout<<"\n====================================================\n";
	cout<<"Compare = "<<com;
	cout<<"\nSwap = "<<sw;
	cout<<"\nArray = ";
	for(int i=0; i<size; i++) cout<<arr[i]<<"  ";
}
/////////////////////////////////////////////////////////////////////////
bool comp(int a, int b, int &cm) //функция подсчета сравнений
{
	cm++;
	if(a>b)return true;
	return false;
}
/////////////////////////////////////////////////////////////////////////	
void Select_sort(int arr[], int size) //сортировка выбором
{
	int compare=0, swap=0;
	for(int i=0; i<size; i++)
	{
		int min_index=i;
		for (int j=i+1; j<size; j++)
		{
			if (comp(arr[min_index],arr[j], compare))
				min_index=j;		
		}
		if(arr[i]!=arr[min_index]) //Чтобы не было перестановки числа с самим собой
		{
			int t=arr[i];
			arr[i]=arr[min_index];
			arr[min_index]=t;
			swap++;
		}
		
	}
	print(arr, size, compare, swap);
}
/////////////////////////////////////////////////////////////////////////	
void Shell_sort(int arr[], int size) //Сортировка Шелла
{
	int compare=0, swap=0, step=size/2;
	while(step>0)
	{
		for(int i=0; i<(size-step); i++)
		{
			int j=i;
			while(j>=0 && comp(arr[j],arr[j+step], compare))
			{
				int t=arr[j];
				arr[j]=arr[j+step];
				arr[j+step]=t;
				swap++;
				j--;	
			}
		}
		step/=2;
	}
	print(arr, size, compare, swap);
}
/////////////////////////////////////////////////////////////////////////
	
int main()
{
	int size;
	//cout<<"Enter size: ";
	//cin>>size;
	int test[8]={8,2,3,1,5,4,6,7};
	int copy[8]={8,2,3,1,5,4,6,7};
/*	int *arr= new int [size];
	for(int i=0; i<size; i++)
	{
		cout<<"Eneter number "<<i+1<<": ";
		cin>>arr[i];
	}*/
	Shell_sort(test, 8);
	for(int i=0; i<8; i++) test[i]=copy[i];
	Select_sort(test, 8);
	return 0;
}



































/*void Shell_sort(int arr[], int size)
{
	int compare=0, swap=0, step=size/2;
	while(step>0)
	{
		for(int i=step; i<size; i++)
		{
			int j=i;
			
			compare++;
			while((j>=step) && arr[j-step]>arr[j])
			{
					int t=arr[j-step];
					arr[j-step]=arr[j];
					arr[j]=t;
					swap++;
				j-=step;
				
				
			}
		}
		step/=2;
	}
	print(arr, size, compare, swap);
}*/





/*void hz_sort(int *arr, int size)
{
	int compare=0; int swap=0;
	for(int i=0; i<size; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			if(arr[j]<arr[i])
			{
				int t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
				compare++;
				swap++;
			}
		}
	}
	print(arr, size, compare, swap);
}*/
