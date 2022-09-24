#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class Graph{
	unordered_map<T,list<T> >mp;
public:

	void addEdge(T u, T v, bool bidir = false){
		mp[u].push_back(v);
		if(bidir){
			mp[v].push_back(v);
		}
	}

	void Print(){
		for(auto node:mp){
			cout<<node.first<<":";

			for(auto neighbour : node.second){
				cout<<neighbour<<" ";
			}
			cout<<endl;
		}
	}
};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Graph<string>g;

	g.addEdge("Putin","Trump");
	g.addEdge("Putin","Modi");
	g.addEdge("Putin","Pope");
	g.addEdge("Modi","Trump",true);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Yogi","Prabhu");
	g.addEdge("Prabhu","Modi");

	g.print();
	return 0;

}