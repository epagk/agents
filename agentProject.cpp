// Name: agentProject
// Author: Emmanouil Pagkalos

#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Agent
{
	private:
		int id;			// Identifier of agent
		bool gender;	// Male = True or Female = False
		int sociable;	// grade of sociability /10
		int polite;		// grade of politeness /10
		int prim;		// grade of image /10
	
	public:
		Agent(int ID, bool g, int s, int p, int pr) { // Constructor with parameters
		  id = ID;
	      gender = g;
	      sociable = s;
	      polite = p;
	      prim = pr;
	    }

	    Agent(){

	    }

    public:
    	// Setter
    	void setID(int ID) {
      		id = ID;
    	}

    	// Getter
    	int getID() {
      		return id;
    	}

    	// Setter
    	void setGender(bool g) {
      		gender = g;
    	}

    	// Getter
    	bool getGender() {
      		return gender;
    	}

    	// Setter
    	void setSociability(int s) {
      		sociable = s;
    	}

    	// Getter
    	int getSociability() {
      		return sociable;
    	}

    	// Setter
    	void setPoliteness(int p) {
      		polite = p;
    	}

    	// Getter
    	int getPoliteness() {
      		return polite;
    	}

    	// Setter
    	void setPrim(int pr) {
      		prim = pr;
    	}

    	// Getter
    	int getPrim() {
      		return prim;
    	}

    	void displayAgent(){
    		string gndr = (gender == true) ? "Male" : "Female";
    		cout << "Agent: " << id << "\n\tGender: " << gndr << "\n\tSociability: " << sociable << "\n\tPoliteness: " << polite << "\n\tPrim: " << prim << endl;
    	}
};

Agent getAgent(vector<Agent> agents, int ID)
{
	for (auto it = agents.begin(); it!=agents.end(); it++)
	{
		if ((*it).getID() == ID)
			return (*it);
	}
}

// To add an edge
void addEdge(vector <pair<Agent, float> > adj[], Agent agent1, Agent agent2, float wt)
{
	int ID1 = agent1.getID();
	int ID2 = agent2.getID();

    adj[ID1].push_back(make_pair(agent2, wt));
    adj[ID2].push_back(make_pair(agent1, wt));
}

// Create a Graph
void create_graph(vector<pair<Agent,float> > adj[], int V)
{
	for (int i = 1; i < V+1; ++i)
	{
		bool g = (rand() % 2 == 1) ? true : false;
		int s = rand()  % 10 + 1;
		int p = rand()  % 10 + 1;
		int pr = rand() % 10 + 1;
		Agent ag(i, g, s, p, pr);
		agents.push_back(ag);
	}

	
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
        cout << "Node " << u << " is connected to: \n";
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

int main() 
{
	srand ( time(NULL) );

	int V = 48;
	vector<pair<Agent, float> > adj[V];

	create_graph(adj);
	printGraph(adj, V);


	return 0;
}