#include "seat.h"

seat::seat(int nCredits) {
	credits = nCredits;
	passenger = nullptr;
}

int seat::GetCredits(){
	return credits;
}
void seat::TakeCredits() {
	credits = 0;
}

void seat::SetPassenger(PassengerNode *passenger){
	this->passenger = passenger;
}

PassengerNode * seat::GetPassenger(){
	return this->passenger;
}

string seat::toString() {
	if (this->passenger == NULL) {
		return "Empty";
	}
	else {
		return this->passenger->toString();
	}
}
