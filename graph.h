#include <iostream>
#include <bits/stdc++.h> 
#include "agent.h" // header in local directory

using namespace std;

extern vector<pair<Agent, float> > adj[48];

Agent getAgent(vector<Agent> agents, int ID)
{
	for (auto it = agents.begin(); it!=agents.end(); it++)
	{
		if ((*it).getID() == ID)
			return (*it);
	}
}

// Check if two agents are connected
bool agentsConnection(vector <pair<Agent, float> > adj[], int u, int v)
{
	for (auto it = adj[u-1].begin(); it!=adj[u-1].end(); it++)
	{
		int n = (it->first).getID();
		if (n == v) return true;
	}

	return false;
}

// To add an edge
void addEdge(vector <pair<Agent, float> > adj[], Agent agent1, Agent agent2, float wt)
{
	int ID1 = agent1.getID()-1;
	int ID2 = agent2.getID()-1;

    adj[ID1].push_back(make_pair(agent2, wt));
    adj[ID2].push_back(make_pair(agent1, wt));
}

// Remove edge
void removeEdge(vector <pair<Agent, float> > adj[], int u, int v)
{
	int n,c;
	cout << "remove edge (" << u << ", " << v << ")" << endl;

	if ( agentsConnection(adj, u, v) )
	{
		c = 0;
		for (auto it = adj[u-1].begin(); it!=adj[u-1].end(); it++)
		{
			n = (it->first).getID();
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
			n = (it->first).getID();
			if (n == u) 
			{
				adj[v-1].erase(it); 
				break;
			}

			++c;
		}
	}
}

// Create a Graph
vector<Agent> create_graph(vector<pair<Agent,float> > adj[], int V)
{
	vector<Agent> agents;

	// Init the agents
	for (int i = 1; i < V+1; ++i)
	{
		bool g = (rand() % 2 == 1) ? true : false;
		int s = rand()  % 10 + 1;
		int p = rand()  % 10 + 1;
		int pr = rand() % 10 + 1;
		Agent ag(i, g, s, p, pr);
		agents.push_back(ag);
	}

	// Insert edges on Graph
	addEdge(adj, getAgent(agents, 1),  getAgent(agents, 2), 0.3);    addEdge(adj, getAgent(agents,2),   getAgent(agents, 3), 0.8); 	
	addEdge(adj, getAgent(agents, 2),  getAgent(agents, 4), 0.4); 	 addEdge(adj, getAgent(agents, 4),  getAgent(agents, 7), 0.57);
    addEdge(adj, getAgent(agents, 4),  getAgent(agents, 6), 0.01); 	 addEdge(adj, getAgent(agents, 6),  getAgent(agents, 7), 0.64); 	
    addEdge(adj, getAgent(agents, 5),  getAgent(agents, 6), 0.73); 	 addEdge(adj, getAgent(agents, 5),  getAgent(agents, 8), 0.6);
    addEdge(adj, getAgent(agents, 5),  getAgent(agents, 9), 0.32); 	 addEdge(adj, getAgent(agents, 9),  getAgent(agents, 10), 0.44); 	
    addEdge(adj, getAgent(agents, 8),  getAgent(agents, 10), 0.7); 	 addEdge(adj, getAgent(agents, 8),  getAgent(agents, 11), 0.82);
    addEdge(adj, getAgent(agents, 11), getAgent(agents, 12), 0.92);  addEdge(adj, getAgent(agents, 11), getAgent(agents, 13), 0.41); 
    addEdge(adj, getAgent(agents, 13), getAgent(agents, 14), 0.7); 	 addEdge(adj, getAgent(agents, 13), getAgent(agents, 15), 0.8);
    addEdge(adj, getAgent(agents, 14), getAgent(agents, 15), 0.3); 	 addEdge(adj, getAgent(agents, 15), getAgent(agents, 16), 0.75); 
    addEdge(adj, getAgent(agents, 16), getAgent(agents, 17), 0.2); 	 addEdge(adj, getAgent(agents, 16), getAgent(agents, 18), 0.62);
    addEdge(adj, getAgent(agents, 18), getAgent(agents, 23), 0.55);  addEdge(adj, getAgent(agents, 12), getAgent(agents, 20), 0.75); 
    addEdge(adj, getAgent(agents, 19), getAgent(agents, 20), 0.6); 	 addEdge(adj, getAgent(agents, 20), getAgent(agents, 21), 0.9);
    addEdge(adj, getAgent(agents, 20), getAgent(agents, 22), 0.45);  addEdge(adj, getAgent(agents, 22), getAgent(agents, 26), 0.5); 	
    addEdge(adj, getAgent(agents, 26), getAgent(agents, 31), 0.6);	 addEdge(adj, getAgent(agents, 19), getAgent(agents, 21), 0.4);
    addEdge(adj, getAgent(agents, 19), getAgent(agents, 24), 0.5); 	 addEdge(adj, getAgent(agents, 21), getAgent(agents, 27), 0.1); 	
    addEdge(adj, getAgent(agents, 27), getAgent(agents, 32), 0.8); 	 addEdge(adj, getAgent(agents, 19), getAgent(agents, 25), 0.2);
    addEdge(adj, getAgent(agents, 22), getAgent(agents, 27), 0.7); 	 addEdge(adj, getAgent(agents, 23), getAgent(agents, 28), 0.7); 	
    addEdge(adj, getAgent(agents, 23), getAgent(agents, 29), 0.1); 	 addEdge(adj, getAgent(agents, 25), getAgent(agents, 30), 0.6);
    addEdge(adj, getAgent(agents, 30), getAgent(agents, 35), 0.7); 	 addEdge(adj, getAgent(agents, 28), getAgent(agents, 35), 0.6); 	
    addEdge(adj, getAgent(agents, 29), getAgent(agents, 37), 0.8); 	 addEdge(adj, getAgent(agents, 36), getAgent(agents, 37), 0.75);
    addEdge(adj, getAgent(agents, 36), getAgent(agents, 38), 0.9); 	 addEdge(adj, getAgent(agents, 38), getAgent(agents, 39), 0.4); 	
    addEdge(adj, getAgent(agents, 35), getAgent(agents, 36), 0.5); 	 addEdge(adj, getAgent(agents, 35), getAgent(agents, 40), 0.4);
    addEdge(adj, getAgent(agents, 34), getAgent(agents, 40), 0.8);   addEdge(adj, getAgent(agents, 45), getAgent(agents, 46), 0.5);	
    addEdge(adj, getAgent(agents, 32), getAgent(agents, 33), 0.7); 	 addEdge(adj, getAgent(agents, 33), getAgent(agents, 41), 0.5);
    addEdge(adj, getAgent(agents, 31), getAgent(agents, 34), 0.6); 	 addEdge(adj, getAgent(agents, 31), getAgent(agents, 33), 0.6); 	
    addEdge(adj, getAgent(agents, 42), getAgent(agents, 44), 0.7); 	 addEdge(adj, getAgent(agents, 43), getAgent(agents, 44), 0.8);
    addEdge(adj, getAgent(agents, 41), getAgent(agents, 42), 0.6); 	 addEdge(adj, getAgent(agents, 42), getAgent(agents, 43), 0.3); 	
    addEdge(adj, getAgent(agents, 44), getAgent(agents, 45), 0.4); 	 addEdge(adj, getAgent(agents, 40), getAgent(agents, 47), 0.6);
    addEdge(adj, getAgent(agents, 47), getAgent(agents, 48), 0.7);

    return agents;
}

// Print adjacency list representation of graph
void printGraph(vector<pair<Agent,float> > adj[], int V)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(3);

    int id, s, p, pr;
    float w;

    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u+1 << " is connected to: \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            id = it->first.getID(); s = it->first.getSociability(); p = it->first.getPoliteness(); pr = it->first.getPrim();
            w = it->second;
            cout << "\tNode " << id << " (sociability: " << s << ", politeness: " << p << ", prim: " << pr << ")" << " with edge weight = "
                 << w << "\n";
        }
        cout << "\n";
    }
}
