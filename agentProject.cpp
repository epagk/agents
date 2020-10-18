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

int main() 
{
	srand ( time(NULL) );

	int V = 48;
	vector<Agent> agents;
	vector<pair<Agent, float> > adj[V];

	create_graph(agents, adj, V);
	printGraph(adj, V);


	return 0;
}