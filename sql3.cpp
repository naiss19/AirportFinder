// Copyright (C) 2022 sevkliaz@miamioh.edu

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278",
            "wVQABsJFQhwNdNbr");
    // Create a query
    mysqlpp::Query query = myDB.query();
    query << "SELECT pname, price, category, manufacturer FROM Product ";
    query << "WHERE price <= %0 AND pname LIKE '%%%1';";
    query.parse();  // check to ensure query is correct
    // Run the query and get stored results
    mysqlpp::StoreQueryResult result = query.store(atoi(argv[1]), argv[2]);

    // Results is a 2D vector of mysqlpp::String objects.
    // Print the results.
    std::cout << "pname\tprice\tcategory\tmanufacturer"<<std::endl;
    for (const auto& row : result) {
        for (const auto& col : row) {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
    // All done
    return 0;
}
