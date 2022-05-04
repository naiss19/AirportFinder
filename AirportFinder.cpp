#include "AirportFinder.h"


void AirportFinder::menu() {
    int userInput;
    cout << "Choose an item from the menu" << endl;
    makeMenu();
    cin >> userInput;
    switch(userInput) {
        case 1:
        germanAirports();
        break; 
        case 2:
        twoCriteria();
        break; 
        case 3:
        sumAirports();
        break; 
        case 4:
        groupAirports();
        break; 
        case 5:
        exitQuery();
        break; 
        default:
        cout << "Please choose another number" << endl;
        menu();
        break;
    }
}

void AirportFinder::makeMenu() {
    cout << "Airport Finder Menu:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option 1: Select all airports in the United States by city" << endl;
    cout << "Option 2: 2 selection criteria" << endl;
    cout << "Option 3: Aggregate function" << endl;
    cout << "Option 4: Summarize using grouping" << endl;
    cout << "Option 5: Exit" << endl;
}
//Constructor
AirportFinder::AirportFinder() {

}
//Destructor
AirportFinder::~AirportFinder() {

}
//Helper functions
void AirportFinder::getAirport() {

}
void AirportFinder::sortBy() {

}
//Operator overloading
ofstream& AirportFinder::operator<< (ofstream& is) {

}


void AirportFinder::germanAirports() //Menu option 1 
{

}
void twoCriteria() //Menu option 2
{

}
void sumAirports() //Menu option 3
{

}
void groupAirports() //Menu option 4
{

}
void exitQuery() //Menu option 5
{

}