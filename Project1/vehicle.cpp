#include "vehicle.h"
#include "PassengerNode.h"
#include "seat.h"
#include <iostream>

vehicle::vehicle(string color, string carType) {
	this->color = color;
	this->carType = carType;
	this->seats = {};
	
}

void vehicle::assignDriver(PassengerNode* passenger) {
	SetSeat(passenger, 0);
}
string vehicle::GetType(){
	return this->carType;
}

string vehicle::GetColor(){
	return this->color;
}


void vehicle::SetSeat(PassengerNode * passenger, int i){
	seats[i].SetPassenger(passenger);
}

seat vehicle::GetSeat(int seatNum){
	return this->seats[seatNum];
}

vector<seat> vehicle::GetSeats() {
	return this->seats;
}

string vehicle::toString(){
	string s = "";
	string res = this->GetType()+" "+this->color + "\n" + "(-) ";
	for (int i = 1; i < seats.size(); i++) {
		s += "(";
		if (this->GetSeat(i).GetPassenger() == nullptr) {
			s += to_string(this->GetSeat(i).GetCredits());
		} 
		else {
			s += "x";
		}
		s += ") ";
	}
	return res + s + "\n";
}

string vehicle::ReservationPrint() {
	string s = "";
	string res = this->GetType() + " " + this->color + "\n" + "(-) ";
	for (int i = 1; i < seats.size(); i++) {
		s += "(";
		if (this->GetSeat(i).GetPassenger() == nullptr) {
			s += "Unassigned";
		}
		else {
			s += seats.at(i).GetPassenger()->GetName();
		}
		s += ") ";
	}
	return res + s + "\n";
}

truck::truck(string color) : vehicle(color, "Truck") {
	this->seats = {};
	this->seats.push_back(seat(0));
	this->seats.push_back(seat(5));
	
}

void truck::assginPassenger(int seatNum, PassengerNode * passenger) {
	if (GetSeat(seatNum).GetCredits() == 5) {
		//seat is free
		cout << "Truck: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		GetSeat(seatNum).TakeCredits();
	}
}

string truck::toString()
{
	return string();
}


compact::compact(string color): vehicle(color, "Compact"){
	this->seats = {};
	this->seats.push_back(seat(0));
	this->seats.push_back(seat(5));
	this->seats.push_back(seat(3));
	this->seats.push_back(seat(3));
}

void compact::assginPassenger(int seatNum, PassengerNode * passenger) {
	if (GetSeat(seatNum).GetCredits() == 5) {
		//seat is free
		cout << "Compact: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}
	else if (GetSeat(seatNum).GetCredits() == 3) {
		//seat is free
		cout << "Compact: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}

	else if (GetSeat(seatNum).GetCredits() == 3) {
		//seat is free
		cout << "Compact: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}
}

string compact::toString()
{
	return string();
}

sedan::sedan(string color): vehicle(color, "Sedan"){
	this->seats = {};
	this->seats.push_back(seat(0));
	this->seats.push_back(seat(5));
	this->seats.push_back(seat(2));
	this->seats.push_back(seat(1));
	this->seats.push_back(seat(2));
}

void sedan::assginPassenger(int seatNum, PassengerNode * passenger) {
	if (GetSeat(seatNum).GetCredits() == 5) {
		//seat is free
		cout << "Sedan: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}
	else if (GetSeat(seatNum).GetCredits() == 2) {
		//seat is free
		cout << "Sedan: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}
	else if (GetSeat(seatNum).GetCredits() == 1) {
		//seat is free
		cout << "Sedan: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}
	else if (GetSeat(seatNum).GetCredits() == 2) {
		//seat is free
		cout << "Sedan: " << "Seat " << seatNum << "  reserved" << endl;
		SetSeat(passenger, seatNum);
		// erase the credits of the seat
		GetSeat(seatNum).TakeCredits();
	}
}

string sedan::toString(){
	return string();
}

