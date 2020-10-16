//============================================================================
// Name        : firstProject.cpp
// Author      : epagkalos
// Version     : 1
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


// To add an edge
void addEdge(vector <pair<int, float> > adj[], int u, int v, float wt)
{
    adj[u-1].push_back(make_pair(v, wt));
    adj[v-1].push_back(make_pair(u, wt));
}

// Check if two agents are connected
bool agentsConnection(vector <pair<int, float> > adj[], int u, int v)
{
	for (auto it = adj[u-1].begin(); it!=adj[u-1].end(); it++)
	{
		int n = it->first;
		if (n == v) return true;
	}

	return false;
}

// Remove edge
void removeEdge(vector <pair<int, float> > adj[], int u, int v)
{
	int n,c;

	if ( agentsConnection(adj, u, v) )
	{
		c = 0;
		for (auto it = adj[u-1].begin(); it!=adj[u-1].end(); it++)
		{
			n = it->first;
			if (n == v) 
			{
				adj[u-1].erase(it); 
				break;
			}

			++c;
		}

		c = 0;
		for (auto it = adj[v-1].begin(); it!=adj[v-1].end(); it++)
		{
			n = it->first;
			if (n == u) 
			{
				adj[v-1].erase(it); 
				break;
			}

			++c;
		}
	}
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int,float> > adj[], int V)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(3);

    int v;
    float w;

    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u+1 << " is connected to: \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight = "
                 << w << "\n";
        }
        cout << "\n";
    }
}

// Normalize the weights
void norm_weights(vector<pair<int,float> > adj[], int V)
{
	cout << "Weight Normalization \n\n";

	float max = numeric_limits<float>::min();
	float min = numeric_limits<float>::max();
	float w;


	for (int u = 0; u < V; u++)
	{
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
		{
			w = it->second;
			if (w > max){ max = w; }
			if (w < min){ min = w; }
		}
	}

	for (int u = 0; u < V; u++)
	{
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
		{
			it->second = (it->second - min) / (max - min);
		}
	}
}

// Create a Graph
void create_graph(vector<pair<int,float> > adj[])
{
    addEdge(adj, 1, 2, 0.3); 	addEdge(adj, 2, 3, 0.8); 	addEdge(adj, 2, 4, 0.4); 	addEdge(adj, 4, 7, 0.57);
    addEdge(adj, 4, 6, 0.01); 	addEdge(adj, 6, 7, 0.64); 	addEdge(adj, 5, 6, 0.73); 	addEdge(adj, 5, 8, 0.6);
    addEdge(adj, 5, 9, 0.32); 	addEdge(adj, 9, 10, 0.44); 	addEdge(adj, 8, 10, 0.7); 	addEdge(adj, 8, 11, 0.82);
    addEdge(adj, 11, 12, 0.92); addEdge(adj, 11, 13, 0.41); addEdge(adj, 13, 14, 0.7); 	addEdge(adj, 13, 15, 0.8);
    addEdge(adj, 14, 15, 0.3); 	addEdge(adj, 15, 16, 0.75); addEdge(adj, 16, 17, 0.2); 	addEdge(adj, 16, 18, 0.62);
    addEdge(adj, 18, 23, 0.55); addEdge(adj, 12, 20, 0.75); addEdge(adj, 19, 20, 0.6); 	addEdge(adj, 20, 21, 0.9);
    addEdge(adj, 20, 22, 0.45); addEdge(adj, 22, 26, 0.5); 	addEdge(adj, 26, 31, 0.6);	addEdge(adj, 19, 21, 0.4);
    addEdge(adj, 19, 24, 0.5); 	addEdge(adj, 21, 27, 0.1); 	addEdge(adj, 27, 32, 0.8); 	addEdge(adj, 19, 25, 0.2);
    addEdge(adj, 22, 27, 0.7); 	addEdge(adj, 23, 28, 0.7); 	addEdge(adj, 23, 29, 0.1); 	addEdge(adj, 25, 30, 0.6);
    addEdge(adj, 30, 35, 0.7); 	addEdge(adj, 28, 35, 0.6); 	addEdge(adj, 29, 37, 0.8); 	addEdge(adj, 36, 37, 0.75);
    addEdge(adj, 36, 38, 0.9); 	addEdge(adj, 38, 39, 0.4); 	addEdge(adj, 35, 36, 0.5); 	addEdge(adj, 35, 40, 0.4);
    addEdge(adj, 34, 40, 0.8);  addEdge(adj, 45, 46, 0.5);	addEdge(adj, 32, 33, 0.7); 	addEdge(adj, 33, 41, 0.5);
    addEdge(adj, 31, 34, 0.6); 	addEdge(adj, 31, 33, 0.6); 	addEdge(adj, 42, 44, 0.7); 	addEdge(adj, 43, 44, 0.8);
    addEdge(adj, 41, 42, 0.6); 	addEdge(adj, 42, 43, 0.3); 	addEdge(adj, 44, 45, 0.4); 	addEdge(adj, 40, 47, 0.6);
    addEdge(adj, 47, 48, 0.7);
}

// Calculate coalition's value if valid
float coalition_value(vector<pair<int,float> > adj[], vector<int> coalition)
{
	int v;
	float value = 0; 
	bool valid = true;

	vector<int> neighbors;

	int len = coalition.size();

	// Check if coalition is valid
	for (int i = 0; i < len; ++i)
	{
		
		v = coalition[i] - 1;
		for (auto it = adj[v].begin(); it!=adj[v].end(); it++)
        {
            int n = it->first;

            std::vector<int>::iterator in = std::find(neighbors.begin(), neighbors.end(), n);	// If element not already in neighbors set
            if (in == neighbors.end())
    			neighbors.push_back(n);
        }
	}

	for (int i = 0; i < len; ++i)
	{
		v = coalition[i];

		std::vector<int>::iterator in = std::find(neighbors.begin(), neighbors.end(), v);
		if (in == neighbors.end())
    		valid = false;

	}

	if(!valid) { return -1; }	// NOT valid coalition

	// Coalition is Valid. Calculate Value
	vector<int> visited;

	for (int i = 0; i < len; ++i)
	{
		v = coalition[i];
		visited.push_back(v);

		for (auto it = adj[v-1].begin(); it!=adj[v-1].end(); it++)
		{
			int f = it->first;

			 std::vector<int>::iterator in = std::find(visited.begin(), visited.end(), f);	// check if f in coalition
			 std::vector<int>::iterator ic = std::find(coalition.begin(), coalition.end(), f);	// check if f in visited
			 if (in == visited.end() && ic != coalition.end())	// f has to be member of coalition but NOT visited yet
			 {
			 	value += it->second;
			 }
		}
	}

	return value;
}

// Coalition members rate each other
void coalition_rate(vector <pair<int, float> > adj[], vector<int> coalition)
{
	int rate1, rate2;
	int v,u;

	srand ( time(NULL) );

	while( !coalition.empty() )
	{
		v = coalition[0];	// First agent

		for (int j = 1; j < coalition.size(); ++j)
		{
			u = coalition[j];	// Second agent

			rate1 = rand() % 11;	// Rate from agent v to agent u
			rate2 = rand() % 11;	// Rate from agent u to agent v

			cout << "Agent " << v << " rates agent " << u << " as " << rate1 << "/10" << endl;
			cout << "Agent " << u << " rates agent " << v << " as " << rate2 << "/10" << endl; 
			float product = (float) (rate1*rate2) / 100;
			cout << "Relationship between " << v << " and " << u << " is rated as " << product << " \n" << endl;

			if ( agentsConnection(adj, v, u) )
			{
				if ( product < 0.1 ) { removeEdge(adj, v, u); }
			}
			else
			{
				if ( product > 0.5 ) { addEdge(adj, v, u, product); }
			}

		}

		coalition.erase(coalition.begin());
	}
}

// Create a Coalition Structure
void create_CS(vector <pair<int, float> > adj[], int V)
{
	srand ( time(NULL) );

	int f = rand() % (V-1) + 1;
	cout << "random peak: " << f << endl; 
}


int main() 
{
	int V = 48;
	vector<pair<int, float> > adj[V];

	create_graph(adj);
	printGraph(adj, V);

	// vector<int> coal{25, 28, 30, 35};
	// float val = coalition_value(adj, coal);

	// if (val != -1){
	// 	cout << "Value of coalition: " << val << endl;
	// }
	// else{
	// 	cout << "This coalition is not valid!" << endl;
	// }

	// coalition_rate(adj, coal);
	// printGraph(adj, V);

	create_CS(adj, V);

	return 0;
}

