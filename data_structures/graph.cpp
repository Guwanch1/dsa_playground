#include "graph.h"
#include <iostream>
#include <queue>

Graph::Graph(int vertices, bool directed) {
    adjList.resize(vertices);
    isDirected = directed;  
}

bool Graph::addEdge(int src, int dest) {
	if(src < 0 || dest < 0) return false;
	if(src >= adjList.size() || dest >= adjList.size()) return false;
    adjList[src].insert(dest); 
    if (!isDirected) {
        adjList[dest].insert(src);  
    }
    return true;
}

bool Graph::removeEdge(int src, int dest) {
	if(src < 0 || dest < 0) return false;
	if(src >= adjList.size() || dest >= adjList.size()) return false;

	adjList[src].erase(dest);

    if (!isDirected) {
        adjList[dest].erase(src);
    }

    return true;

}

void Graph::addVertex() {
    adjList.push_back(set<int>());
}

bool Graph::removeVertex(int id) {
	if(id < 0 || id >= adjList.size()) return false;
	for(int i=0; i<adjList.size(); i++) {
		if(i != id) {
			removeEdge(i, id);
		}
	}
	adjList.erase(adjList.begin() + id);
	return true;
}

void Graph::printGraph() {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i  << ": "; 
        if (adjList[i].empty()) {
            cout << "NULL\n";
        } else {
            for (const auto& neighbor : adjList[i]) {
                cout << neighbor  << " --> ";
            }
            cout << "NULL\n";
        }
    }
}

void Graph::dfsRec(vector<bool>& visited, int node) {
    visited[node] = true;
    cout << "Visited node: " << node  << endl;

    for (auto i : adjList[node]) {
        if (!visited[i]) {
            cout << " -> Moving to node " << i << " from node " << node  << endl;
            dfsRec(visited, i);
        } else {
            cout << " -> Node " << i << " already visited, skipping\n";
        }
    }
}

bool Graph::dfs(int node) {
    if(node < 0 || node >= adjList.size()) return false;
    vector<bool> visited(adjList.size(), false);
    dfsRec(visited, node);
    return true;
}

bool Graph::bfs(int node) {
    if(node < 0 || node >= adjList.size()) return false;
    int size = adjList.size(), curr;
    queue<int> q;
    vector<bool> visited(size, false);
    visited[node] = true;
    q.push(node);
    cout << "Start from node: " << node  << "\n";
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        cout << "Visited node: " << curr  << "\n";
        for (int i : adjList[curr]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                cout << " -> Enqueued node " << i  << " from node " << curr  << "\n";
            } else {
                cout << " -> Node " << i  << " already visited, skipping\n";
            }
        }
        cout << "Queue: [ ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front()  << " ";
            temp.pop();
        }
        cout << "]\n";
    }
    return true;
}
