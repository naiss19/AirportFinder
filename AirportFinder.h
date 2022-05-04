#ifndef AIRPORTFINDER_H
#define AIRPORTFINDER_H
#include <string>
#include <iostream>
#include <istream>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;


class AirportFinder 
{

public:
void menu();
AirportFinder();
~AirportFinder();
void getAirport();
void sortBy();
ofstream& operator<< (ofstream& is);
void germanAirports(); //Menu option 1
void twoCriteria(); //Menu option 2
void sumAirports(); //Menu option 3
void groupAirports(); //Menu option 4
void exitQuery(); //Menu option 5
private:
string username;
string password;
void makeMenu();

};


#endif