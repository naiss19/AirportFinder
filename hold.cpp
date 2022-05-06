#define MYSQLPP_MYSQL_HEADERS_BURIED
#include "AirportFinder.h"
#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <mysql++/mysql++.h>
//think you need this 

//print the DB
void print(mysqlpp::StoreQueryResult outcome) {
 // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    for (const auto& row : outcome) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }


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
this-> myDB = mysqlpp::Connection("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");


}
//Destructor
AirportFinder::~AirportFinder() {
    delete this->myDB;
  //  delete this->AirportFinder;


}
//Helper functions
void AirportFinder::getAirport() {
    
    

}
void AirportFinder::sortBy() {

}
//Operator overloading
ofstream& AirportFinder::operator<< (ofstream& is) {

}

//Find airports in Germany by city
void AirportFinder::germanAirports() //Menu option 1  ONE COLUMN
{

string place; // city
cout<< "Find airports in Germany by city\n";  //  print statement
cin >> place;  //  city
mysqlpp::Query query = myDB.query()
  query << "SELECT Name FROM Airports;"; //SQL CODE
   query << "WHERE City = %0q;";                                                //  SQL CODE second part
    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult outcome = query.store(place);

    print(outcome);


    ///need to make method to only print one column NOW 


}
void twoCriteria() //Menu option 2  TWO COLUMNS
{
// show a column here and then ask them to chose from that  suggestion 


//     string ariport;  //  airport name 
// cout<< "Enter a name of a airport in the city\n";  //  print statement 
// cin>> ariport; //  taking in specific airport  

// mysqlpp::Query query = myDB.query()
//   query << "SELECT Name, City, Latitude, Longitude FROM Airports;"; //  SQL CODE
//    query << "WHERE Name = %0q;";                                          //  SQL CODE second part 
//     query.parse();  // check to ensure query is correct
//     // Run the query and get stored results
//     mysqlpp::StoreQueryResult outcome = query.store();


    ///need to make method to only print 2 column NOW 


}
void sumAirports()  //  Menu option 3
{

// mysqlpp::Query query = myDB.query()
//   query << "SELECT City , COUNT(*) FROM Airports;"; //SQL CODE
//    query << "WHERE COUNTRY = 'GERMANY'";                                                //SQL CODE second party 
//    query << "GROUP BY City";
//     query.parse();  // check to ensure query is correct
//     // Run the query and get stored results
//     mysqlpp::StoreQueryResult outcome = query.store();

}
//===================================================================================
//                  I stopped here
//==================================================================================
void groupAirports()  //  Menu option 4
{
//did not finish will work on it TOMORROW 
//     mysqlpp::Query query = myDB.query()
//   query << "SELECT name , COUNT(*) FROM AirportFinder;"; //SQL CODE
//    query << "WHERE COUNTRY = 'GERMANY'";                                                //SQL CODE second party 
//    query << "GROUP BY City";
//     query.parse();  // check to ensure query is correct
//     // Run the query and get stored results
//     mysqlpp::StoreQueryResult outcome = query.store();

}
void exitQuery()  //  Menu option 5
{

}

}
// Connect to database with: database, server, userID, password
 mysqlpp::Connection myDB; 