#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds 
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // TODO: Declare overloaded read function prototypes
   
   // Reads the name of the employee | Receives as a parameter an pointer to an array of characters
   bool read(char *&name);
   // Reads an employee number | Accepts as a  parameter a reference to an interger
   bool read(int& empNo);
   // Reads the employee salary | Acceptes as a parameter a reference to an floating point number in double precision
   bool read(double& salary); 


}

#endif // !SDDS_FILE_H_