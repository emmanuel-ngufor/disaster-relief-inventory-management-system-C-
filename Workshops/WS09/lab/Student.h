#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds
{
    class Student 
    {
        char* m_name{};
        int m_age{};

    public:
        Student() = default;
        Student(const char* name, int age);
        Student(const Student& other);
        Student& operator=(const Student& other);
        virtual ~Student();
        const char* getName() const;
        int getAge() const;
        void display() const;
    };

} // namespace sdds

#endif // SDDS_STUDENT_H