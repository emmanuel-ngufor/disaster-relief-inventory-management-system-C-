#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"

namespace sdds 
{

    class Graduate : public Student 
    {
        char* m_thesisTitle{};
        char* m_supervisor{};

    public:
        Graduate() = default;
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
        Graduate(const Graduate& other);
        Graduate& operator=(const Graduate& other);
        virtual ~Graduate();
        void display() const;
    };

} // namespace sdds

#endif // SDDS_GRADUATE_H
