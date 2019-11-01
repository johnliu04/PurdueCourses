#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>

class Student {
private:
   std::string sName;
public:
   Student (std::string s);
   bool operator==(const Student& std2) const;
   bool operator<(const Student& std2) const;
   bool operator>(const Student& std2) const;
};
#endif /* STUDENT_H_ */
