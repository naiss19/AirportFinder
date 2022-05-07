#define MYSQLPP_MYSQL_HEADERS_BURIED
#include "AirportFinder.h"
#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <mysql++/mysql++.h>

using namespace mysqlpp;
using std::cin;
using std::cout;
using std::endl;

// think you need this 

// print the DB
void AirportFinder::print(StoreQueryResult outcome)
{
    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    for (const auto &row : outcome)
    {
        for (const auto &col : row)
        {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}


// Constructor
AirportFinder::AirportFinder()
{
    // this->AirportFinder = AirportFinder;
    //  this-> myDB = mysqlpp::Connection("cse278", "localhost", "cse278",
    //         "wVQABsJFQhwNdNbr");
    menu();
}



    // Accessing the miamioh server
    // ----------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------
    // from th SQL1.cpp


    //==========================================================================
// Helper functions
// void AirportFinder::getAirport()
// {
//     mysqlpp::Connection myDB("cse278", "localhost", "cse278",
//             "wVQABsJFQhwNdNbr");
//     Query query = myDB.query();
//     mysqlpp::StoreQueryResult outcome = query.store();
// }
// void AirportFinder::sortBy()
// {
//     mysqlpp::Connection myDB("cse278", "localhost", "cse278",
//             "wVQABsJFQhwNdNbr");
//     Query query = myDB.query();
// }
// // Operator overloading
// ofstream &AirportFinder::operator<<(ofstream &is){

// }

// Find airports in Germany by city
void AirportFinder::germanAirports() // Menu option 1  ONE COLUMN
{
mysqlpp::Connection myDB("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");
  mysqlpp::Query query = myDB.query();


    string place;                                                 // city
    cout << "Find airports in Germany by city\n";                 //  print statement
    cin >> place;                                                 //  city
    query << "SELECT Name FROM Airports WHERE City = " << quote_only << place << ";"; //  SQL CODE second part
    query.parse();                                             // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult outcome = query.store();

    print(outcome);

    /// need to make method to only print one column NOW
}
void AirportFinder::twoCriteria() // Menu option 2  TWO COLUMNS
{
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");
    // show a column here and then ask them to chose from that  suggestion
   mysqlpp:: Query query = myDB.query();
    string country;
    string timezone;
    cout << "Please enter a country below" << endl;
    cout << "Example:\n America\n Canada\n Germany\n" << endl;
    cin >> country; //use getline to get full input 
    cout << "Please enter a time zone below" << endl;
    cout << "Example: America/Pacific \n Atlantic/Reykjavik" << endl; //  print statement

 
    cin >> timezone;  //  taking in specific airport
    query << "SELECT Name, City, Latitude, Longitude FROM Airports WHERE Country = " << quote_only << country << " AND Tz = " << quote_only << timezone << ";";
    // "WHERE Name = %0;";                                           //  SQL CODE second part
    query.parse();                                                         // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult outcome = query.store();
    print(outcome);
    /// need to make method to only print 2 column NOW
}
void AirportFinder::sumAirports() //  Menu option 3
{
mysqlpp::Connection myDB("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");
    Query query = myDB.query();
    query << "SELECT City , COUNT(*) FROM AirportFinder;"; // SQL CODE
    query << "WHERE COUNTRY = 'GERMANY'";                  // SQL CODE second party
    query << "GROUP BY City";
    query.parse(); // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult outcome = query.store();
}
//===================================================================================
//                  I stopped here
//==================================================================================
void AirportFinder::groupAirports() //  Menu option 4
{
mysqlpp::Connection myDB("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");
    Query query = myDB.query();
    // did not finish will work on it TOMORROW
    query << "SELECT name , COUNT(*) FROM AirportFinder;"; // SQL CODE
    query << "WHERE COUNTRY = 'GERMANY'";                  // SQL CODE second party
    query << "GROUP BY City";
    query.parse(); // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult outcome = query.store();
}
void AirportFinder::exitQuery() //  Menu option 5
{
    return;
}

void AirportFinder::makeMenu()
{
    cout << "Airport Finder Menu:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Option 1: Select all airports in the United States by city" << endl;
    cout << "Option 2: 2 selection criteria" << endl;
    cout << "Option 3: Aggregate function" << endl;
    cout << "Option 4: Summarize using grouping" << endl;
    cout << "Option 5: Exit" << endl;
}
void AirportFinder::menu()
{
    int userInput;
    cout << "Choose an item from the menu" << endl;
    makeMenu();
    cin >> userInput;
    switch (userInput)
    {
    case 1:
    
     AirportFinder::germanAirports();
        break;
    case 2:
       AirportFinder::twoCriteria();
        break;
    case 3:
      AirportFinder::sumAirports();
        break;
    case 4:
       AirportFinder::groupAirports();
        break;
    case 5:
        AirportFinder::exitQuery();
        break;
    default:
        cout << "Please choose another number" << endl;
       AirportFinder::menu();
        break;
    }
}
