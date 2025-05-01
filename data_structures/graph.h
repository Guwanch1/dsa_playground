#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

using namespace std;

class Graph {
	
	private: 
		vector<set<int>> adjList; 
		bool isDirected;
		void dfsRec(vector<bool>& visited, int node);

	public:
		Graph(int vertices, bool isDirected = false);
		bool addEdge(int src, int dest);
		bool removeEdge(int src, int dest);
		void addVertex();
		bool removeVertex(int id);
		void printGraph();
		bool dfs(int node);
		bool bfs(int node);
};

#endif
