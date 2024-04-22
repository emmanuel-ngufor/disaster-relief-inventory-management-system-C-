#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


namespace sdds 
{

   class Portfolio 
   {
   private: 

      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:

       // Constructors
       Portfolio();

       // 3 Parameter Constructor
       Portfolio(double value, const char* stock, char type);

       // emptyPortfolio
       void emptyPortfolio();

       // Display A Portfolio
       void dispPortfolio() const; 

       // Display All
       std::ostream& display() const; 

       // Operators and Conversion Overloads
       
       // Portfolio can be casted to a double(double type).The result would be the value of the Portfolio m_value.This operator can not modify the Portfolio object.
       operator double() const;

       // Portfolio can be casted to C - string(const char* type).The result would be the name of the stock m_stock.This operator can not modify the Portfolio object.
       operator const char* () const; 

       // Portfolio can be casted to a char (char type). The result would be the type of investment m_type. This operator can not modify the Portfolio object.
       operator char() const;

       // Portfolio can be casted to a bool (boolean type). This will return TRUE if the type of the investment m_type is Growth 'G' or Value 'V or Investment 'I'. 
       // For any other types, it will return FALSE.
       operator bool() const;

       // A double can be added to the value of the Portfolio m_value using += operator; if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted. 
       // Reference of the Portfolio is returned after the operation.
       Portfolio& operator+= (double value);

       // A double can be subtracted from the value of the Portfolio m_value using -= operator; if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted. 
       // Reference of the Portfolio is returned after the operation.
       Portfolio& operator-= (double value); 

       // The bool operator ~() will return true if m_value is negative. This operator can not modify the Portfolio object.
       bool operator~ () const;

       // Overload the << operator* (left shift operator) to move $dollar investment value m_value from Portfolio in the right to the left. 
       // After this operation, the total investment value of the Portfolio on the left will be the sum of both Portfolios. The Portfolio on the right is set to empty.
       Portfolio& operator<<(Portfolio& right);

       // Overload the >> operator* (right shift operator) to move $dollar investment value m_value from Portfolio in the left to the right. 
       // After this operation, the total investment value of the Portfolio in the right will be the sum of both Portfolios. The Portfolio on the left is set to empty. 
       // It is not allowed to invest values from a Portfolio back to itself.If any of the two portfolios don't evaluate to TRUE, no action should be taken.
       Portfolio& operator>>(Portfolio& right);

   };  // End of class Porfolio


   // Binary Helper Operators
   
   // Binary stand alone helper + operator that accepts a constant Portfolio reference at left and another constant Portfolio reference at right and returns a double value. 
   // The double value should be the sum of the m_values of the two Flights. If any of the two Portfolios don't evaluate to TRUE, then zero is returned.
   double operator+ (const Portfolio& other1, const Portfolio& other2);  

   // Binary stand alone helper += operator that accepts a double reference at left and a constant Portfolio reference at right and returns a double value. 
   // The $dollar investment value of the right operand(Portfolio reference) should be added to the left operand(double reference) Then the value of the double reference is returned.
   double operator+= (double& value, const Portfolio& other);
   

} // namespace sdds

#endif // SDDS_Portfolio_H_