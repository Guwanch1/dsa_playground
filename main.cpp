#include "data_structures/linked_list.h"
#include "data_structures/graph.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "algorithms/binary_search.h"
#include "algorithms/bubble_sort.h"
#include "algorithms/quick_sort.h"
#include <iostream>
using namespace std;

void inputMultiple(vector<int>& v) {
    string s;
    cout << "Enter numbers (type 'q' to stop):\n";
    while (true) {
        cout << "> ";
        cin >> s;
        if (s == "q" || s == "Q") break;
        try {
            int num = stoi(s);
            v.push_back(num);
        } catch (...) {
            cout << "Invalid input. Try again.\n";
        }
    }
}



void dsalinkedlist(){

	LinkedList list;

	int option, value, position;

	cout << "\n===== Linked List Menu =====\n";
	cout << "1. Insert at beginning\n";
	cout << "2. Insert at end\n";
	cout << "3. Insert at position\n";
	cout << "4. Delete from beginning\n";
	cout << "5. Delete from end\n";
	cout << "6. Delete from position\n";	
	cout << "7. Display list\n";
	cout << "0. Exit\n";

	while(true) {
		cout << "Choose option: ";
		cin >> option;	


		switch(option) {
			case 0:
				return;
			case 1: 
				cout << "Value: ";
				cin >> value;
				list.insertAtBeginning(value);
				break;
			case 2: 
				cout << "Value: ";
				cin >> value;
				list.insertAtEnd(value);
				break;
			case 3:
				cout << "Value: ";
				cin >> value;
				cout << "Position: ";
				cin >> position;
				if(!list.insertAtPosition(value, position)) {
					cout << "Invalid position\n";
				}
				break;
			case 4: 
				if(!list.deleteFromBeginning()) cout << "List is empty\n";
				break;
			case 5:
				if(!list.deleteFromEnd()) cout << "List is empty\n";
				break;
			case 6:
				cout << "Position: ";
				cin >> position;
				if(!list.deleteFromPosition(position)) cout << "Invalid position\n";
				break;
			case 7:
				list.display();
				break;
			default: cout << "Invalid choice.\n";
		}
	}

}

void dsagraph(){

	int src, dest, vertices, option;
	bool directed;

	cout << "Number of vertices: ";
	cin >> vertices;

	cout << "Is directed? (0: false, 1: true)\n Input:";
	cin >> directed;


	Graph myg(vertices, directed);

	cout << "\n===== Graph Menu =====\n";
	cout << "1. Add edge\n";
	cout << "2. Remove edge\n";
	cout << "3. Add vertex\n";
	cout << "4. Remove vertex\n";
	cout << "5. Depth-First search\n";
	cout << "6. Breadth-First search\n";
	cout << "7. Print\n";
	cout << "0. Exit\n";
	while(true) {
		cout << "Option: ";
		cin >> option;

		switch(option) {
			case 1:
				cout << "Source: ";
				cin >> src;
				cout << "Destination: ";
				cin >> dest;
				if(!myg.addEdge(src, dest)) {
					cout << "Invalid\n";
				}
				break;
			case 2:
				cout << "Source: ";
				cin >> src;
				cout << "Destination: ";
				cin >> dest;
				if(!myg.removeEdge(src, dest)) {
					cout << "Invalid\n";
				}
				break;
			case 3:
				myg.addVertex();
				break;
			case 4:
				cout << "Vertex id:";
				cin >> src;
				if(!myg.removeVertex(src)) cout << "Invalid\n";
				break;
			case 5:
				cout << "Start node: "; cin >> src;
				if(!myg.dfs(src)) cout << "Invalid node\n";
				break;
			case 6:
				cout << "Start node: "; cin >> src;
				if(!myg.bfs(src)) cout << "Invalid node\n";
				break;
			case 7:
				myg.printGraph();
				break;
			case 0:
				return;
			default: 
				cout << "Invalid option\n";
				break;
		}

	}

}

void dsastack(){
	int x, option, result;
	Stack stack;

	cout << "\n===== Stack Menu =====\n";
	cout << "1. Push\n";
	cout << "2. Pop\n";
	cout << "3. Peek\n";
	cout << "4. isEmpty?\n";
	cout << "5. Print\n";
	cout << "0. Exit\n";

	while(true) {
		cout << "Option: ";
		cin >> option;

		switch(option) {
			case 1:
				cout << "Value: ";
				cin >> x;
				if(!stack.push(x)) cout << "Stack overflow\n";
				break;
			case 2:
				if(!stack.pop()) cout << "Stack underflow\n";
				break;
			case 3:
				if(!stack.peek(result)) cout << "Stack is empty\n";
				else cout << result << "\n";
				break;
			case 4:
				cout << stack.isEmpty() << "\n";
				break;
			case 5:
				stack.printStack();
				break;
			case 0:
				return;
			default:
				cout << "Invalid option\n";
				break;

		}

	}

}

void dsaqueue() {
	int option, value;
	cout << "\n===== Queue Menu =====\n";
	cout << "1. Is empty?\n";
	cout << "2. Enqueue\n";
	cout << "3. Dequeue\n";
	cout << "4. Get Front\n";
	cout << "5. Print\n";
	cout << "0. Exit\n";
	
	Queue que;

	while(true) {
		cout << "Option: ";
		cin >> option;

		switch(option) {
			case 1:
				cout << que.isEmpty() << "\n";
				break;
			case 2:
				cout << "Value: ";
				cin >> value;
				que.enqueue(value);
				break;
			case 3:
				if(!que.dequeue()) cout << "Queue is empty\n";
				break;
			case 4:
				if(!que.getFront(value)) cout << "Queue is empty\n";
				else cout << value << "\n";
				break;
			case 5:
				que.display();
				break;
			case 0:
				return;
			default:
				cout << "Invalid option\n";
				break;
		}
	}
}

void dataStructuresMenu() {
	int option;

	while(true) {

		cout << "\n===== Data Structures Menu =====\n";
		cout << "1. Singly Linked List\n";
		cout << "2. Graph\n";
		cout << "3. Stack\n";
		cout << "4. Queue\n";
		cout << "0. Exit\n";
		cout << "Choose option: ";	
		cin >> option;	


		switch(option) {
			case 1: dsalinkedlist(); break;
			case 2: dsagraph(); break;
			case 3: dsastack(); break;
			case 4: dsaqueue(); break;
			case 0: return;
			default: cout << "Invalid choice.\n";
		}
	}

}

void algobubble_sort() {
	cout << "\n===== Bubble sort =====\n";
	cout << "1. Add element to the array\n";
	cout << "2. Add many elements\n";
	cout << "3. Print the array\n";
	cout << "4. Bubble sort\n";
	cout << "0. Exit\n";
	int option, val;
	vector<int> v;
	string s="";
	while(true) {
		cout << "Option: "; cin >> option;
		switch(option) {
			case 1:
				cout << "Value: "; cin >> val; 
				v.push_back(val);
				break;
			case 3:
				for(int i : v) cout << i << " ";
				cout << "\n";
				break;
			case 2: 
				inputMultiple(v);
				break;
			case 4:
				bubble_sort(v);
				break;
			case 0:
				return;
			default:
				cout << "Invalid option\n";
				break;
		}
	}

}

void algoquick_sort() {
	cout << "\n===== Quick sort =====\n";
	cout << "1. Add element to the array\n";
	cout << "2. Add many elements\n";
	cout << "3. Print the array\n";
	cout << "4. Quick sort\n";
	cout << "0. Exit\n";
	int option, val;
	vector<int> v;
	string s="";
	while(true) {
		cout << "Option: "; cin >> option;
		switch(option) {
			case 1:
				cout << "Value: "; cin >> val; 
				v.push_back(val);
				break;
			case 3:
				for(int i : v) cout << i << " ";
				cout << "\n";
				break;
			case 2: 
				inputMultiple(v);
			    break;
			case 4:
				quick_sort(v, 0, v.size()-1);
				break;
			case 0:
				return;
			default:
				cout << "Invalid option\n";
				break;
		}
	}
}

void algobinary_search() {
	cout << "\n===== Binary search =====\n";
	cout << "1. Add element to the array\n";
	cout << "2. Find an element\n";
	cout << "3. Print the array\n";
	cout << "4. Add many elements\n";
	cout << "0. Exit\n";
	int option, val;
	vector<int> v;
	string s="";
	while(true) {
		cout << "Option: "; cin >> option;
		switch(option) {
			case 1:
				cout << "Value: "; cin >> val; 
				v.push_back(val);
				sort(v.begin(), v.end());
				break;
			case 2:
				cout << "Element you want to find: "; cin >> val;
				binary_search(v, val);
				break;
			case 3:
				for(int i : v) cout << i << " ";
				cout << "\n";
				break;
			case 4: 
				inputMultiple(v);
			    break;
			case 0:
				return;
			default:
				cout << "Invalid option\n";
				break;
		}
	}

}

void algorithmsMenu(){

	int option;

	while(true) {

		cout << "\n===== Algorithms Menu =====\n";
		cout << "1. Bubble sort\n";
		cout << "2. Quick sort\n";
		cout << "3. Binary search\n";
		cout << "0. Exit\n";
		cout << "Option: ";
		cin >> option;	

		switch(option) {
			case 1: algobubble_sort(); break;
			case 2: algoquick_sort(); break;
			case 3: algobinary_search(); break;
			case 0: return;
			default: cout << "Invalid option\n"; break;
		}

	}

}

int main() {
	cout << "Note: Indexing starts from 0.\n";
	int option;

	while(true) {
		
		cout << "\n===== DSA PLAYGROUND =====\n";
		cout << "1. Data Structures\n";
		cout << "2. Algorithms\n";
		cout << "0. Exit\n";
		cout << "Choose option: ";
		cin >> option; 

		switch(option) {
			case 1: dataStructuresMenu(); break;
			case 2: algorithmsMenu(); break;
			case 0: 
				cout << "Exiting program. Goodbye!\n";
				return 0;
			default: cout << "Invalid choice.\n";
		}
	

	}

	return 0;
}