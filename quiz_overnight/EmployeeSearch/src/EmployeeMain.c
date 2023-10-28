#include <string.h>
#include <stdlib.h>
#include "../include/Employee.h"

int main(void){
    //defined in employeeone
    PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char* targetName);
    PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char* targetNum);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary);
    
    //defined in employeetable
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    //pointer holding the result of the query
    PtrToEmployee matchPtr;

    //search by number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

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

    //search by phone number
    char* nums[] = {"909-555-2134", "1"};
    for (int i = 0; i < 2; i++) {
        matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, nums[i]);

        if (matchPtr != NULL)
            printf("Phone number %s found in record at position %d\n", nums[i], matchPtr - EmployeeTable);
        else
            printf("Phone number %s not found in the record\n", nums[i]);
    }

    double sals[] = {7.80, 1};
    for (int i = 0; i < 2; i++) {
        matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, sals[i]);

        if (matchPtr != NULL)
            printf("Salary %f found in record at position %d\n", sals[i], matchPtr - EmployeeTable);
        else
            printf("Salary %f not found in the record\n", sals[i]);
    }

    return EXIT_SUCCESS;
}