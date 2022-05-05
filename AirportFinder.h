#define LIBSSH_STATIC 1
#ifndef AIRPORTFINDER_H
#define AIRPORTFINDER_H
#include <string>
#include <iostream>
#include <istream>

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
    AirportFinder(char *username, char *password);
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
    char *username = "hallbd4";
    char *password = "PGF*zMbvY.u2p.DT";
    char *serverName = "hallbd4@ceclnx01.cec.miamioh.edu";
    void makeMenu();
    mysqlpp::Connection myDB = new Connection("cse278", "localhost", username,
                             password);
};

#endif