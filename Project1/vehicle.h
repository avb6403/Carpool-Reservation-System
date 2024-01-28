#ifndef vehicleH
#define vehicleH	

#include "PassengerNode.h"
#include "seat.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class vehicle {
protected:
	string carType;
	string color;
	vector<seat> seats;
	

public:
	vehicle(string color, string carType);
	string GetType();
	string GetColor();
	void SetSeat(PassengerNode * passenger, int i);
	seat GetSeat(int i);
	vector<seat> GetSeats();
	string ReservationPrint();
	void assignDriver(PassengerNode* passenger);
	virtual void assginPassenger(int seatNum, PassengerNode * passenger) = 0;
	string toString();
};

class truck : public vehicle {
public:
	truck(string color);
	void assginPassenger(int seatNum, PassengerNode * passenger);
	string toString();
};

class compact : public vehicle {
public:
	compact(string color);
	void assginPassenger(int seatNum, PassengerNode * passenger);
	string toString();
};

class sedan : public vehicle {
public:
	sedan(string color);
	void assginPassenger(int seatNum, PassengerNode * passenger);
	string toString();
};
#endif

