#include <iostream>
using namespace std;
#define max 10

class DFS{
	int v[10] = {0};
	int Mat[max][max] = {0};
	int n;
	
	public:
	DFS(){
		cout<<"Enter no of vertices : ";
		cin>>n;
	}
	void AdjMat(){
		cout<<"Enter Adjacency Matrix : \n";
		for(int i=0; i<n; i++){
			cout<<"Enter row "<<i+1<<" : ";
			for(int j=0; j<n; j++){
				cin>>Mat[i][j];
			}
		}
	}
	void Display(int a){
		int b;
		
		cout<< " " <<a;
		v[a]=1;
		for(b=0; b<n; b++){
			if(v[b]!=1 && Mat[a][b]==1){
				Display(b);
			}
		}	
	}	
};

int main(){
	DFS D;
	D.AdjMat();
	cout<<"DFS spanning tree : \n";
	D.Display(0);
	
	return 0;
}