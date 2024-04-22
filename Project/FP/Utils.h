#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;

    class Utils
    {
    private:
        bool m_testMode = false;

    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);

        // Added Functions
        // Safely allocates memory in the destination argument and copies the source into it.
        void alocpy(char*& destination, const char* source);
        // If the prompt is not null. It performs a foolproof entry of an integer. If the user enters an invalid integer it will display an error message 
        // and will not let the user leave the function until a valid integer is entered.
        int getint(const char* prompt) const;
        // Reuses the getint() fucntion to get a valid interger and checks if the interger is within the (min, max) boundaries and displays an error message 
        // based on the value of the errMes parameter
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr) const;
        // Gets a valid double value and checks if the decimal value is within the max and minimum ranges. Displays an error message 
        // based on the value of the errMes paramemter
        double getdouble(const char* prompt = nullptr) const;
        double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr) const;

    };

    extern Utils ut;
}

#endif // !SDDS_UTILS_H
