#ifndef seatH
#define seatH	

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "PassengerNode.h"

using namespace std;

class seat {
private:
	PassengerNode *passenger;
	int credits;

public:
	seat(int nCredits);
	int GetCredits();
	void TakeCredits();
	void SetPassenger(PassengerNode *passenger);
	PassengerNode *GetPassenger();
	string toString();
};

#endif