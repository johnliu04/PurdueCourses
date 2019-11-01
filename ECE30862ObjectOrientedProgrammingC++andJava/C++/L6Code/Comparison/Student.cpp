#include "Student.h"
#include <string>

Student::Student (std::string s) : sName(s) { }

bool Student::operator==(const Student& std2) const { 
   return (sName == std2.sName);
}

bool Student::operator<(const Student& std2) const {
   return sName < std2.sName;
}

bool Student::operator>(const Student& std2) const {
   return sName > std2.sName;
}
