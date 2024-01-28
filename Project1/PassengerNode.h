#ifndef PassengerNODEH
#define PassengerNODEH	

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PassengerNode {
private: 
	string name;                  // Node data - person's name
	int credit;                   // Node data - person's credit
	PassengerNode *nextNodePtr;
	
public: 
	// Default Constructor
	PassengerNode() {
		name = "none"; 
		credit = 0; 
		nextNodePtr = nullptr;
	};
	// 2nd Constructor w/default nextNodePtr
	PassengerNode(string nName, int nCredit) {
		name = nName; 
		credit = nCredit; 
		nextNodePtr = nullptr;
	};
	// 3nd Constructor w/entered nextNodePtr
	PassengerNode(string nName, int nCredit, PassengerNode* nextPtr) {
		name = nName; 
		credit = nCredit; 
		nextNodePtr = nextPtr;
	};
	// Get location pointed by nextNodePtr
	PassengerNode* GetNext() {
		return (nextNodePtr);
	};
	// Get location pointed by nextNodePtr
	void SetNext(PassengerNode* nextPtr) {
		nextNodePtr = nextPtr;
	};

	void PrintPassengerInfo();

	string GetName();
	int GetCredits();
	int setCredits(int credit);
	void InsertAfter(PassengerNode* newNodePtr);

	string toString();
};
#endif