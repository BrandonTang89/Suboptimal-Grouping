#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
#include <map>
#include <cstring>
using namespace std;

int pax_per_group;
int n, e, u, v, rating,total_rating;
double weight;
double adjmat[500][500];

vector<pair<int,int>> friends;
vector<pair<double, pair<int,int>>> edgelist; //weight, (u, v)

//Custom comparator
bool comp(pair<double, pair<int,int>> a, pair<double, pair<int,int>>b){
	if (a.first > b.first)return true;
	return false;
}
//UFDS
int parent[500];
int root(int x){
	if (parent[x] == -1)return x;
	return parent[x] = root(parent[x]);
}
bool same_set(int a, int b){
	return (root(a) == root(b));
}
void connect(int a, int b){
	int roota = root(a);
	int rootb = root(b);
	if (roota == rootb)return;
	parent[roota] = rootb;
}
int group_pax[500];
int main(){
	memset(parent, -1, sizeof(parent));
	ifstream in("input.in");
	
	//Parsing Input
	in >> n >> pax_per_group;
	for (int i=0;i<n;i++){
		friends.clear();
		total_rating = 0;
		in >> u >> e;
		
		for (int j=0;j<e;j++){
			in >> v >> rating;
			friends.push_back(make_pair(v,rating));
			total_rating += rating;
		}
		
		//Initialising Adjmat
		weight = 1.0/double(total_rating);
		for (auto f: friends){
			adjmat[u][f.first] = weight*f.second;
		}
		
	}
	
	//Initialist Edge List
	for (int i=0; i<n;i++){
		group_pax[i] = 1;
		for (int j=i+1;j<n;j++){//to not repeat pairs, start from i+1 (also avoids i == j)
			weight = adjmat[i][j] + adjmat[j][i];
			edgelist.push_back(make_pair(weight, make_pair(i, j)));
		}
	}
	
	sort(edgelist.begin(), edgelist.end(), comp);
	
	for (auto e: edgelist){
		u = e.second.first;
		v = e.second.second;
		int ngp = group_pax[root(u)] + group_pax[root(v)];//new group pax
		if (same_set(u, v) ||ngp > pax_per_group)continue;
		connect(u, v);
		group_pax[root(u)] = ngp;
	}
	
	//Output (console)
	cout << "Calculations Finished --- "<<endl;
	cout << "person:";
	for (int i=0;i<n;i++){
		cout << i << " ";
	}
	cout << endl;
	
	map<int, int>m;
	int counter =1;
	cout << "group :";
	for (int i=0;i<n;i++){
		if (m.find(root(i)) == m.end())m[root(i)] = counter++;
		cout << m[root(i)] << " ";
	}
	cout << endl;
	
	
	//Output (file)
	ofstream out("output.out");
	for (int i =1; i<counter; i++){
		out << "-" << i << endl;
		for (int j=0;j<n;j++){
			if (m[root(j)] == i)out << j << endl;
		}
	}
	
}


/*Input Format

n
u e {v rating}*e //n lines

e.g.
6
0 0
1 0
2 1 1 1
3 1 0 1
4 2 1 2 2 1
5 1 1 1
*/
	
	
	
	
	
	
	
