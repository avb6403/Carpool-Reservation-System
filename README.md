# Carpool reservation system for RIT’s Quidditch Team

## Idea
This project involves designing, implementing, and testing a carpool reservation system for RIT's Quidditch Team. The system addresses the transportation needs of 31 team members, where 8 members with cars provide transportation for the remaining 23. The goal is to efficiently manage seat reservations using a week-to-week, first-come-first-serve basis.

## Seat Allocation
Two 1-passenger Pickup Trucks (2 seats)  
Three 3-passenger Compact Cars (9 seats)  
Three 4-passenger Sedan Cars (12 seats)  

## Seat Credits
Each of the 23 passengers is allocated 20 "seat credits" at the start of the season.  

Seat values vary based on seat type:
 * Front seats: 5 points each
 * Back seats in compact cars: 3 points each
 * Side-back seats in sedans: 2 points each
 * Middle-back seats in sedans: 1 point each

## Design Specifications
Team member data is stored in the "quidditch.dat" file.  
The program reads and saves data to update the internal database.  
Menu-driven interface with options to create, modify, delete reservations, display vehicles, and print reports.  
The reservation process includes seat selection, credit validation, and assignment of a unique reservation number.  

## Code Requirements
Hierarchical implementation with user-defined libraries.  
The class named "reservation" encapsulates reservation information and related functions.  
Utilization of linked list to store-created reservations.  

# Features
1) Create a Reservation:  
 * Enter the passenger's name; validate against the database.  
 * Display available seats with a creative and understandable diagram.  
 * Select seats by category or specific vehicle/seat.  
 * Validate availability and credits before confirming the reservation.  
 * Assign a unique two-digit reservation number.  
   
3) Modify Reservation:    
 * Enter reservation number to reselect a different vehicle and seat.  
  * Update all appropriate databases.  

4) Delete Reservation:  
  * Enter the reservation number to delete and update databases.  

5) Display Vehicles:  
  * Display seat assignment diagram.  

6) Print Vehicle Assignments:  
  * Display and print the passenger list for a specific vehicle.  

7) Print Reservations:  
  * Print a complete passenger list (manifest) for all vehicles.  
  * Password-protected and accessible only to the system administrator.  
