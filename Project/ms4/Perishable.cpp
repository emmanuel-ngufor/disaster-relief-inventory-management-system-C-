#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include "Perishable.h"
#include "Utils.h"

namespace sdds
{
    void Perishable::setEmpty()
    {
        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;
    }

    void Perishable::set(Date expiry, const char* handling)
    {
        m_expiry = expiry;

        if (handling != nullptr)
            ut.alocpy(m_handlingInstructions, handling);
        else
            setEmpty();
    }

    Perishable::Perishable() : Item() { set(); }

    Perishable::Perishable(const Perishable& perishable) : Item(perishable) { set(perishable.m_expiry, perishable.m_handlingInstructions); }

    Perishable& Perishable::operator=(const Perishable& perishable)
    {
        if (this != &perishable)
        {
            (Item&)*this = perishable;
            set(perishable.m_expiry, perishable.m_handlingInstructions);
        }
        return *this;
    }

    Perishable::~Perishable() { setEmpty(); }

    const Date& Perishable::expiry() const { return m_expiry; }

    int Perishable::readSku(std::istream& istr) { return m_sku = ut.getint(10000, 39999, "SKU: "); }

    std::ofstream& Perishable::save(std::ofstream& ofstr) const
    {
        if (m_state) // if the state of the Item is good
        {
            Item::save(ofstr); // call the save of the Base class
            ofstr << "\t";
            if (m_handlingInstructions != nullptr && m_handlingInstructions[0] != '\0') // if handling instructions exist and the attribute is not empty
                ofstr << m_handlingInstructions;
            ofstr << "\t";
            Date tempDate = m_expiry; // for printing formatted date only
            tempDate.formatted(false);
            tempDate.write(ofstr);
        }
        return ofstr;
    }

    std::ifstream& Perishable::load(std::ifstream& ifstr) 
    {
        std::string handling; 

        Item::load(ifstr); // call the load of the Base class
        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;

        if (ifstr.peek() != '\t') // if the very first character is not a Tab
        {
            getline(ifstr, handling, '\t');
            ut.alocpy(m_handlingInstructions, handling.c_str());
        }
        if (ifstr.peek() == '\t')
            ifstr.ignore();
        ifstr >> m_expiry;
        if (ifstr.peek() == '\n') // ignores the newline
            ifstr.ignore();

        if (ifstr.fail()) // if the ifstream object has failed
            m_state = "Input file stream read (perishable) failed!";

        return ifstr;
    }

    std::ostream& Perishable::display(std::ostream& ostr) const
    {
        if (!m_state) // if the state is bad
            ostr << m_state;
        else
        {
            if (linear())
            {
                Item::display(ostr); // display of the base class is called

                if (m_handlingInstructions != nullptr && m_handlingInstructions[0] != '\0') // if handling instructions are not null and not empty
                    ostr << "*";
                else
                    ostr << " ";
                ostr << m_expiry;
            }
            else
            {
                ostr << "Perishable ";
                Item::display(ostr); // display the base class
                ostr << "Expiry date: ";
                ostr << m_expiry;
                ostr << std::endl;
                if (m_handlingInstructions != nullptr && m_handlingInstructions[0] != '\0')
                    ostr << "Handling Instructions: " << m_handlingInstructions << std::endl; 
            }
        }
        return ostr;
    }

    std::istream& Perishable::read(std::istream& istr)
    {
        Item::read(istr); // read of the base class is called

        std::string handling; 
        delete[] m_handlingInstructions;
        m_handlingInstructions = nullptr;

        std::cout << "Expiry date (YYMMDD): ";
        istr >> m_expiry;
        std::cout << "Handling Instructions, ENTER to skip: ";
        istr.ignore(1000, '\n');
        if (istr.peek() != '\n') // if the very first character is not '\n'
        {
            getline(istr, handling, '\n');
            ut.alocpy(m_handlingInstructions, handling.c_str());
        }

        if (istr.fail()) // if istream object is in a fail state
            m_state = "Perishable console date entry failed!";

        return istr;
    }


} // namespace sdds