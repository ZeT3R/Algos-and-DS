#include <iostream>
using namespace std;
class Graf
{
	int size;
	int **Graf_weight;
	int **Matrix;
	bool *visited;
	public:
////////////////////////////////////////////////////////////////////////			
		Graf(int size, int *matrix)
		{
			this->size=size;
			Graf_weight= new int *[size];
			Matrix=new int *[size];
			visited=new bool[size];
			for(int i=0; i<size; i++) visited[i]=0;
			for(int i=0; i<size; i++)
			{
				Matrix[i]=new int[size];
				Graf_weight[i]=new int[size];
				for(int j=0; j<size; j++)
				{
					Matrix[i][j]=matrix[i*size+j];
					Graf_weight[i][j]=0;
				}		
			}
		}
////////////////////////////////////////////////////////////////////////				
		~Graf()
		{
			for(int i=0; i<size; i++)
			{
				delete[] Matrix[i];
				delete[]Graf_weight[i];
			}
			delete[]Graf_weight;	
			delete[] Matrix;
			delete[]visited;	
		}
////////////////////////////////////////////////////////////////////////		
		void Graf_way_print()
		{
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<size; j++)
					cout<<Matrix[i][j]<<"  ";
				cout<<"\n";	
			}		
		}
////////////////////////////////////////////////////////////////////////		
		void Graf_weight_print()
		{
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<size; j++)
					cout<<Graf_weight[i][j]<<"  ";
				cout<<"\n";	
			}		
		}
////////////////////////////////////////////////////////////////////////		
		void DFS(int st) //поиск в глубину
		{
			int pos;
			cout<<st+1<<" ";
			visited[st]=1;
			for(pos=0; pos<size; pos++)
				if(Matrix[st][pos]!=0 && !visited[pos])
			DFS(pos);	
		}
////////////////////////////////////////////////////////////////////////
		void Floyd_Algorithm(int begin, int end)
		{	
		int **Floyd=new int *[size];			
			for(int i=0; i<size; i++)
			{
				Floyd[i]=new int[size];
				for(int j=0; j<size; j++)
					Floyd[i][j]=Graf_weight[i][j];
			}
				for(int k=0; k<size; k++)
					for(int i=0; i<size; i++)
						for(int j=0; j<size; j++)
							if(Floyd[i][k] && Floyd[k][j] && i!=j)
							if(Floyd[i][k]+Floyd[k][j]<Floyd[i][j] || Floyd[i][j]==0) 
								Floyd[i][j]=Floyd[i][k]+Floyd[k][j];
								
			cout<<Floyd[begin-1][end-1]<<"\n\n";
			/*for(int i=0; i<size; i++)
			{
				for(int j=0; j<size; j++)
					cout<<Floyd[i][j]<<"  ";
				cout<<"\n";	
			}		*/
			for(int i=0; i<size; i++)
				delete[] Floyd[i];
			delete[] Floyd;				
		}
////////////////////////////////////////////////////////////////////////		
		void add_weight()
		{
			for(int i=0; i<size; i++)
				for(int j=0; j<size; j++)
					Graf_weight[i][j]=Matrix[i][j];
			for(int i=0; i<size; i++)
			{
				for(int j=i; j<size; j++)
				{
					if(Graf_weight[i][j]==1)
					{
						cout<<"\nEnter weight "<<i+1<<"-->"<<j+1<<": ";
						int weight;
						cin>>weight;
						Graf_weight[i][j]=weight;
						Graf_weight[j][i]=weight;
					}
				}
			}
		}		
};
////////////////////////////////////////////////////////////////////////
int main()
{
	const int size=5;
	int Matrix[size][size]=
	{
		{0,1,0,0,1},
		{1,0,1,1,0},
		{0,1,0,0,1},
		{0,1,0,0,1},
		{1,0,1,1,0}
	};
	Graf test(size, *Matrix);
	test.Graf_way_print();
	cout<<"\n\npoisk v glubinu\n";
	test.DFS(3);
	cout<<"\n\n";
	cout<<"for example enter 2,7,4,2,3,2";
	test.add_weight();
	test.Graf_weight_print();
	cout<<"\n\nFloyd_Algorithm(1,5): ";
	test.Floyd_Algorithm(1,5);

	return 0;
}
