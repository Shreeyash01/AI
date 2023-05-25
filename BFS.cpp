#include <iostream>
#include <vector>
#include <list>
using namespace std;

class graph{
	int n, s, e, sv, ev;
	vector<list<int>> arr;
	
	public:
	
	graph(){
		cout<<"Enter no. of vertices : ";
		cin>>n;
		arr.resize(n);
	}
	void edge(){
		cout<<"Enter no. of edges : ";
		cin>>e;
		
		for(int i=0; i<e; i++){
			cout<<"Enter sv of "<<i+1<<" edge : ";
			cin>>sv;
			cout<<"Enter ev of "<<i+1<<" edge : ";
			cin>>ev;
			arr[sv].push_back(ev);
		}
	}
	
	void BFS(){
		cout<<"Enter starting vertex : ";
		cin>>s;
		
		vector<bool> visited;
		visited.resize(n,false);
		
		list<int> q;
		
		visited[s]=true;
		q.push_back(s);
		
		while(!q.empty()){
			s=q.front();
			cout<<s<<" ";
			q.pop_front();
			
			for(auto adj:arr[s]){
				if(!visited[adj]){
					visited[adj] = true;
					q.push_back(adj);
				}
			} 		
		}
	}	
};

int main(){
	graph G;
	G.edge();
	G.BFS();
	cout<<"\n\n\n";

	return 0;
}