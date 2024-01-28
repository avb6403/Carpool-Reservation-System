#include "PassengerNode.h"


string PassengerNode::GetName() {
	return(name);
}

int PassengerNode::GetCredits() {
	return(credit);
}

int PassengerNode::setCredits(int credit)
{
	return this->credit = this->GetCredits() - credit;
}

// Print DOB info for single DOBNode (definition)
void PassengerNode::PrintPassengerInfo() {
	cout << name << " " << credit << endl;
}

// Insert node-x after node-1
// Before Call: node-1 -> node-2
// After Call: node-1 -> node-x -> next-2
void PassengerNode::InsertAfter(PassengerNode* newNodePtr) {
	PassengerNode* tmpNextPtr;
	tmpNextPtr = nextNodePtr;
	nextNodePtr = newNodePtr;
	newNodePtr->nextNodePtr = tmpNextPtr;
};

string PassengerNode::toString() {
	return name;
}

