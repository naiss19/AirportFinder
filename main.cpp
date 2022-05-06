#define MYSQLPP_MYSQL_HEADERS_BURIED
#include "AirportFinder.h"
#include <mysql++/mysql++.h>

int main(int argc, char const *argv[])
{
    AirportFinder a;
    a.menu();
    return 0;
}
