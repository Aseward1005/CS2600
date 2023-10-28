#include <string.h>
#include <stdlib.h>
#include "../include/Employee.h"

int main(void){
    //defined in employeeone
    PtrToEmployee searchEmployeeByNymber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char* targetName);
    
    //defined in employeetable
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    //pointer holding the result of the query
    PtrToEmployee matchPtr;

    //search by number
    matchPtr = searchEmployeeByNymber(EmployeeTable, EmployeeTableEntries, 1045);

    //employee 1045 does not exist
    if (matchPtr != NULL)
        printf("Employee 1045 found in record at position %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee 1045 not found in the record\n");

    //search by name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    //tony bobcat does exist
    if (matchPtr != NULL)
        printf("Tony Bobcat found in record at position %d\n", matchPtr - EmployeeTable);
    else
        printf("Tony Bobcat not found in the record\n");

    return EXIT_SUCCESS;
}