#include <string.h>
#include "../include/Employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                        int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for (; ptr < endPtr; ptr++)
    {
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    }

    return NULL;                                        
}

//comparison helpers
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr){
    return * (long*) targetPtr != tableValuePtr->number; //typecast as long pointer and dereference
}
static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char*) targetPtr, tableValuePtr->name); //typecast as a char pointer and compare
}
static int compareEmployeePhoneNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return strcmp((char*) targetPtr, tableValuePtr->phone); //typecast as a char pointer and compare
}
static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr) {
    return * (double*) targetPtr != tableValuePtr->salary; //typecast as long pointer and dereference
}

//wrappers
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long number){
    return searchEmployeeTable(ptr, tableSize, &number, compareEmployeeNumber);
}
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char* name){
    return searchEmployeeTable(ptr, tableSize, name, compareEmployeeName);
}

//for quiz 2
PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char* phoneNum){
    return searchEmployeeTable(ptr, tableSize, phoneNum, compareEmployeePhoneNumber);
}
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double salary){
    return searchEmployeeTable(ptr, tableSize, &salary, compareEmployeeSalary);
}