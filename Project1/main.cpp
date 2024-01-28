
#include <iostream>
#include <fstream>
#include <string>
#include "PassengerNode.h"
#include "vehicle.h"

using namespace std;

bool check_reservation(vector<vehicle*> CarList, PassengerNode* passenger) {
    for (auto v : CarList) {
        for (auto s : v->GetSeats()) {
            if (s.GetPassenger() == NULL) {
                continue;
            }
            else {
                if (passenger->GetName() == s.GetPassenger()->GetName()) {
                    return true;
                }
            }
        }
    }
    return false;
}

void delete_reservation(vector<vehicle*>* CarList, PassengerNode* passenger) {
    for (auto v : *CarList) {
        for (int i = 1; i < v->GetSeats().size(); i++) {
            if (v->GetSeat(i).GetPassenger() == NULL) {
                continue;
            }
            else {
                if (passenger->GetName() == v->GetSeat(i).GetPassenger()->GetName()) {
                    v->SetSeat(nullptr, i);
                }
            }
        }
    }
}


//display the vehicles and reserved seats. 
void display(vector<vehicle*> CarList) {
    for (vehicle* v : CarList) {
        cout << v->toString() << endl;
    }
}

//search the passenger LinkedList for prompted user name
PassengerNode* searchLinkedList(PassengerNode* headNode, string fname, string lname) {
    string name = fname + " " + lname;
    PassengerNode* tmp;
    tmp = headNode->GetNext();
    //run through the list to find the name
    while (tmp) {
        // if found name. return tmp 
        if (tmp->GetName() == name) {
            return(tmp);
        }
        tmp = tmp->GetNext();
    }
    // if not. return nullptr
    return(nullptr);
}

// read the .dat file
PassengerNode* file_read() {
    PassengerNode* headNode = new PassengerNode();
    PassengerNode* lastNode = headNode;

    ifstream file; //ifstream is for input from plain text files
    file.open("quidditch.dat"); //open input.txt

    string mFirstName, mLastName;
    int mCredit;

    if (!file.is_open()) {
        cout << "Could not open file quidditch.dat" << endl;
        return(nullptr);
    }

    for (uint16_t i = 0; i < 8; i++) {
        file >> mFirstName >> mLastName;
        string name = mFirstName + " " + mLastName;
        PassengerNode* mNode = new PassengerNode(name, 0); // create current node
        lastNode->InsertAfter(mNode); // insert variable in node. 
        lastNode = mNode;
        // headNode -> mNode -> mNode2
    }
    for (uint16_t i = 8; i < 31; i++) {
        file >> mFirstName >> mLastName >> mCredit;
        string name = mFirstName + " " + mLastName;
        PassengerNode* mNode = new PassengerNode(name, mCredit);
        lastNode->InsertAfter(mNode);
        lastNode = mNode;
    }
    file.close(); //close the file stream
    return(headNode);
}

bool checkDriver(PassengerNode* headNode, PassengerNode* studentDetails) {
    PassengerNode *driverNode = headNode->GetNext();
    for (int i = 0; i < 8; i++) {
        if (driverNode->GetName() == studentDetails->GetName()) {
            return true;
        }
        driverNode = driverNode->GetNext();
    }
    return false;
}
int main() {
    int num;
    string color;
    int seatNum;         //the seatNum in the vehicle
    int updatedCredits;  //user's credits after they made reservation   
    int select;

    string name;
    string firstName;
    string lastName;
    name = firstName + " " + lastName;
    int PASS = 1234;
    ofstream printout;


    PassengerNode* headNode = file_read();
    PassengerNode* studentDetails;
    //create 8 obj for 8 vehicle 
    truck* obj1 = new truck("Purple        [1]");
    compact* obj2 = new compact("Red         [2]");
    sedan* obj3 = new sedan("Blue          [3]");
    truck* obj4 = new truck("Green         [4]");
    compact* obj5 = new compact("Blue        [5]");
    sedan* obj6 = new sedan("Black         [6]");
    compact* obj7 = new compact("Yellow      [7]");
    sedan* obj8 = new sedan("Green         [8]");

    //created a vector vehicle that included 8 obj 
    vector<vehicle*> CarList = {};
    CarList.push_back(obj1);
    CarList.push_back(obj2);
    CarList.push_back(obj3);
    CarList.push_back(obj4);
    CarList.push_back(obj5);
    CarList.push_back(obj6);
    CarList.push_back(obj7);
    CarList.push_back(obj8);

    
    bool check_res;
    cout << "Quidditch Team Carpool Reservation System " << "\n" << endl;
    while ( true) {
        cout << "You have Entered the main Menu!" << endl;
        cout << "Please chose on of the following options: " << endl;
        cout << "1. Create a reservation." << endl;
        cout << "2. Delete reservation." << endl;
        cout << "3. Modify Reservation." << endl;
        cout << "4. Display all vehicle." << endl;
        cout << "5. Print all vehicles." << endl;
        cout << "6. Print a vehicle." << endl;
        cout << "7. Exit" << "\n" << endl;
        cin >> select;
        cout << "\n";

        switch (select) {
        case 1:
            cout << "Enter Name: " << endl; // user promt their name 
            cin >> firstName;
            cin >> lastName;
            studentDetails = searchLinkedList(headNode, firstName, lastName);
            if (studentDetails != nullptr) {
                
                if (checkDriver(headNode, studentDetails)) {
                    cout << "\nYou are a driver. You can't make reservation\n" << endl;
                    break;
                }
                
                check_res = check_reservation(CarList, studentDetails);
                if (check_res == false) {
                    cout << "\n" << "User info: " << "\n" << studentDetails->GetName() << " " << studentDetails->GetCredits() << "\n" << endl;
                    // check if the student alr made their reservation 
                    display(CarList);
                    cout << "What Car would you like?" << endl;
                    cin >> num;
                    cout << "\n" << endl;
                    cout << "What seat would you like to reserve? " << endl;
                    cin >> seatNum;
                    cout << "\n" << endl;
                    vehicle* v = CarList.at(num - 1);
                    //check if the seat is empty then assign the passenger into the vehicle. If not print occupied 
                    if (v->GetSeat(seatNum).GetPassenger() == nullptr) {
                        //check if the passenger credits is enought the reserve the seat that they want. If not then print and return to seat selection
                        if (studentDetails->GetCredits() >= v->GetSeat(seatNum).GetCredits()) {
                            v->assginPassenger(seatNum, studentDetails); // assign passenger info into the seat that they chose.
                            updatedCredits = studentDetails->setCredits(v->GetSeat(seatNum).GetCredits()); // update the credit after reservation made.
                            cout << v->GetSeat(seatNum).toString() << " | Credits remaining: " << updatedCredits << "\n" << endl; // print passenger in the seat and their remaining credits. 
                        }
                        else {
                            cout << "Student don't have enough credits to reserve the seat" << endl;
                        }
                    }
                    else {
                        cout << "Seat is occupied" << endl;
                        cout << "\n" << endl;
                    }

                }
                else {
                    cout << "\nUser already reserved seat\n" << endl;
                }
            }
            else {
                cout << "Name does not exist. Please Try again!" << endl;
                cout << "\n" << endl;
            }
            break;

        case 2:
            cout << "Enter Name: " << endl; // user promt their name 
            cin >> firstName;
            cin >> lastName;
            studentDetails = searchLinkedList(headNode, firstName, lastName);
            if (studentDetails != nullptr) {
                if (checkDriver(headNode, studentDetails)) {
                    cout << "\nYou are a driver. You can't delete reservation\n" << endl;
                    break;
                }
                check_res = check_reservation(CarList, studentDetails);
                if (check_res) {
                    delete_reservation(&CarList, studentDetails);
                    display(CarList);
                }
            }
            else {
                cout << "Name does not exist. Please Try again!" << endl;
                cout << "\n" << endl;
            }
            break;

        case 3:
            cout << "Enter Name: " << endl; // user promt their name 
            cin >> firstName;
            cin >> lastName;
            studentDetails = searchLinkedList(headNode, firstName, lastName);
            if (studentDetails != nullptr) {
                if (checkDriver(headNode, studentDetails)) {
                    cout << "\nYou are a driver. You can't Modify reservation\n" << endl;
                    break;
                }
                check_res = check_reservation(CarList, studentDetails);
                if (check_res == true) {
                    delete_reservation(&CarList, studentDetails);
                    cout << "What Car would you like?" << endl;
                    cin >> num;
                    cout << "\n" << endl;
                    cout << "What seat would you like to reserve? " << endl;
                    cin >> seatNum;
                    cout << "\n" << endl;
                    vehicle* v = CarList.at(num - 1);
                    //check if the seat is empty then assign the passenger into the vehicle. If not print occupied 
                    if (v->GetSeat(seatNum).GetPassenger() == nullptr) {
                        //check if the passenger credits is enought the reserve the seat that they want. If not then print and return to seat selection
                        if (studentDetails->GetCredits() >= v->GetSeat(seatNum).GetCredits()) {
                            v->assginPassenger(seatNum, studentDetails); // assign passenger info into the seat that they chose.
                            updatedCredits = studentDetails->setCredits(v->GetSeat(seatNum).GetCredits()); // update the credit after reservation made.
                            cout << v->GetSeat(seatNum).toString() << " | Credits remaining: " << updatedCredits << "\n" << endl; // print passenger in the seat and their remaining credits. 
                            display(CarList); // display all vehicles with all the occupied seats
                        }
                        else {
                            cout << "Student don't have enough credits to reserve the seat" << endl;
                        }
                    }
                    else {
                        cout << "Seat is occupied" << endl;
                        cout << "\n" << endl;
                        display(CarList);
                    }
                }
                else {
                    cout << "Name does not exist. Please Try again!" << endl;
                    cout << "\n" << endl;
                }
            }
                break;

        case 4:
            display(CarList);
            break;
        
        case 5:
            cout << "If you are an administrator, enter the password: " << endl;
            int password;
            cin >> password;
            
            printout.open("all_reservation.txt");
            if (password == PASS) {
                for (int i = 0; i < CarList.size(); i++) {
                    printout << CarList.at(i)->ReservationPrint()<< "\n";
                }
                printout.close();
            }
            else
            {
                cout << "Sorry, you are not an administrator!" << endl;
            }
            break;
        
        case 6:
            cout << "Select the vehicle" << endl;
            int num;
            cin >> num;
            switch (num) {
            case 1:
                printout.open("Purple_truck.txt");
                printout << CarList.at(0)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 2:
                printout.open("Red_compact.txt");
                printout << CarList.at(1)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 3:
                printout.open("Blue_sedan.txt");
                printout << CarList.at(2)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 4:
                printout.open("Green_truck.txt");
                printout << CarList.at(3)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 5:
                printout.open("Blue_compact.txt");
                printout << CarList.at(4)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 6:
                printout.open("Black_sedan.txt");
                printout << CarList.at(5)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 7:
                printout.open("Yellow_compact.txt");
                printout << CarList.at(6)->ReservationPrint() << "\n";
                printout.close();
                break;
            case 8:
                printout.open("Green_sedan.txt");
                printout << CarList.at(7)->ReservationPrint() << "\n";
                printout.close();
                break;
            }
        break;

        case 7:
            return 0;  

        default:
            cout << "Unknown command!" << endl;
            break;
        }
    }
    return 0;
}