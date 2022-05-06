#define MYSQLPP_MYSQL_HEADERS_BURIED
#define LIBSSH_STATIC 1
#ifndef AIRPORTFINDER_H
#define AIRPORTFINDER_H
#include <string>
#include <iostream>
#include <istream>
#include <mysql++/mysql++.h>

using mysqlpp::StoreQueryResult;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

class AirportFinder
{

public:
    void menu();
    void print(StoreQueryResult outcome);
    AirportFinder();
    ~AirportFinder();
    void getAirport();
    void sortBy();
    ofstream &operator<<(ofstream &is);
    void germanAirports(); // Menu option 1
    void twoCriteria();    // Menu option 2
    void sumAirports();    // Menu option 3
    void groupAirports();  // Menu option 4
    void exitQuery();      // Menu option 5

private:
    void makeMenu();
    // Connect to database with: database, server, userID, password
 mysqlpp::Connection myDB; 
};

#endif