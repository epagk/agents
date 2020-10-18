#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <string>

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

      void displayAgent();
};

#endif