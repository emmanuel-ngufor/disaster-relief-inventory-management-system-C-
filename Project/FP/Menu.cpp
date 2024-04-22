#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string> 
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
    void Menu::setEmpty()
    {
        delete[] m_menuContent;
        m_menuContent = nullptr;
        m_numOfOptions = 0;
    }

    void Menu::set(unsigned int numOpt, const char* text)
    {
        // if the number of options is more than 15 or the CString is null the menu is rendered invalid
        if (numOpt > MAX_OPTIONS || text == nullptr) 
        {
            setEmpty();
        }
        else
        {
            ut.alocpy(m_menuContent, text);
            m_numOfOptions = numOpt;
        }
    }

    Menu::Menu(unsigned int numOpt, const char* text) { set(numOpt, text); }

    Menu::Menu(const Menu& menu) { set(menu.m_numOfOptions, menu.m_menuContent); }

    Menu& Menu::operator=(const Menu& menu)
    {
        // A Menu cannot be copied or assigned to another Menu
        if (this == &menu)
        
           set(menu.m_numOfOptions, menu.m_menuContent);  
    
        return *this;
    }

    Menu::~Menu() { setEmpty(); }

    unsigned int Menu::run() const
    {
        cout << m_menuContent
            << "0- Exit" << endl
            << "> ";
        return ut.getint(0, m_numOfOptions);
    }

}  // namespace sdds