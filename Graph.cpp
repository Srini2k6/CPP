#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
	private:
		int V;
		vector<int>* adj;
	public:
	Graph(int v)
	{
		this->V=v;
		adj= new vector<int>[V];
	}
	void addVertex(int u, int v)
	{
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	void bfs(int s)
	{
		bool visited[V];
		for(int i=0;i<V;i++)
			visited[i]=false;
		visited[s]=true;
		queue<int> q;
		q.push(s);

		while(!q.empty())
		{
			int cv=q.front();
			q.pop();
			cout<<cv<<" ";
			for(vector<int>::iterator itr=adj[cv].begin(); itr != adj[cv].end();itr++)
			{
				if(!visited[*itr])
				{
					visited[*itr]=true;
					q.push(*itr);
				}
			}
		}

	}
	
	void dfs(int s)
	{
		bool visited[V];
		for(int i=0;i<V;i++)
			visited[i]=false;
		printDFS(s,visited);
	}
	void printDFS(int s, bool* visited)
	{
		visited[s]=true;
		cout<<s<<" ";
		for(vector<int>::iterator itr=adj[s].begin(); itr != adj[s].end();itr++)
		{
			if(!visited[*itr])
			{
				printDFS(*itr,visited);
			}
		}
	}
};

int main()
{
	Graph g(4);
	g.addVertex(0, 1);
	g.addVertex(0, 2);
	g.addVertex(1, 2);
	g.addVertex(2, 0);
	g.addVertex(2, 3);
	g.addVertex(3, 3);
	cout<<"BFS:";
	g.bfs(2);
	cout<<endl<<"DFS:";
	g.dfs(2);

}
