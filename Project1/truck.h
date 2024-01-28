#ifndef truckH
#define truckH	

#include "PassengerNode.h"
#include "vehicle.h"
#include <iostream>
#include <string>
#include <iomanip>

class truck : public vehicle {
private:
	string carType = "Truck";
	string Seat[2] = { NULL, NULL };
public:
	truck();
	void SetTruck(string type, int seat);
};

#endif