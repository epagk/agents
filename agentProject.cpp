// Name: agentProject
// Author: Emmanouil Pagkalos

#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <bits/stdc++.h>
#include "agent.h" // header in local directory
#include "graph.h" // header in local directory

using namespace std;

void Agent::displayAgent()
{
    string gndr = (gender == true) ? "Male" : "Female";
    cout << "Agent: " << id << "\n\tGender: " << gndr << "\n\tSociability: " << sociable << "\n\tPoliteness: " << polite << "\n\tPrim: " << prim << endl;
}

// Calculate coalition's value if valid
float coalition_value(vector<pair<Agent,float> > adj[], vector<int> coalition)
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
            int n = (it->first).getID();

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
			int f = (it->first).getID();

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
void coalition_rate(vector<Agent> agents, vector <pair<Agent, float> > adj[], vector<int> coalition)
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
				if ( product > 0.5 ) { addEdge(adj, getAgent(agents, v),  getAgent(agents, u), product);  }
			}

		}

		coalition.erase(coalition.begin());
	}
}

int main() 
{
	srand ( time(NULL) );

	int V = 48;

	vector<pair<Agent, float> > adj[V];
	vector<Agent> agents = create_graph(adj, V);
	// printGraph(adj, V);

	vector<int> coal{25, 28, 30, 35};	// Just the IDs of agents 
	cout << "\nValue of coalition: " << coalition_value(adj, coal) << endl;

	coalition_rate(agents, adj, coal);
	printGraph(adj, V);

	return 0;
}