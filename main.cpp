
#include <iostream>
#include <fstream>
#include <process.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include "gotoxy.h"

using namespace std;

//class menu: controls over all functions

class menu
{
public: void main_menu(void);
private: void edit_menu(void);
};

//class: product

class product
{
public:
    void add_item(void);
    void delete_item(void);
    void modify_item(void);
    void list_of_item(void);
    void purchase(void);
private:
    int last_code(void);
    void delete_record(int);
    void modify_record(int);
    void display_record(int);
    int item_found(int);
    int recordno(int);
    void sort(void);

    int itemcode;
    char itemname[30];
    float itemcost, itemprice;
};

//class : account 

class account
{
public:
    void bill_list(void);
    void prepare_bill(int);
    int last_billno(void);
    void add_bill(int, int t_itemcode, char* t_itemname, float t_qty,
        float t_cost, float t_price);
private:
    int code, billno, length;
    int dd, mm, yy;
    float cost, price, quantity;
    char name[30];
};

//function menu: creates a main menu

void menu::main_menu(void)
{
    
    char ch;
    while (1)
        {
        
        gotoxy(10, 30);
        std::cout << "-------------------------------------------";
        gotoxy(10, 23);
        std::cout << "Sales Management system";
        gotoxy(28, 7);
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        gotoxy(30, 9);
        std::cout << "1: PURCHASE PRODUCTS";
        gotoxy(30, 11);
        std::cout << "2: LIST OF PRODUCTS";
        gotoxy(30, 13);
        std::cout << "3: EDIT PRODUCTS FILE";
        gotoxy(30, 15);
        std::cout << "4: BILLS REPORT";
        gotoxy(30, 17);
        std::cout << "0: QUIT";
        gotoxy(30, 20);
        std::cout << "Enter Your Choice : ";
        ch = getche();
        if (ch == '1')
        {
            product p;
            p.purchase();
        }
        else if (ch == '2')
        {
            product p;
            p.list_of_item();
        }
        else if (ch == '3')
            edit_menu();
        else if (ch == '4')
        {
            account a;
            a.bill_list();
        }
        else if (ch == '0')
            break;
    }
        
}

//function edit menu create edit menu and call function
void menu::edit_menu(void)
{
    char ch;
    while (1)
    {
        
        gotoxy(10, 3);
        std::cout
            << "--------------------------------------------";
        gotoxy(10, 23);
        std::cout
            << "---------------------------------------------";
        gotoxy(32, 6);
        std::cout << "E D I T M E N U";
        gotoxy(32, 7);
        std::cout << "~~~~~~~~~~~~~~~~";
        gotoxy(32, 10);
        std::cout << "1: ADD PRODUCTS";
        gotoxy(32, 12);
        std::cout << "2: MODIFY PRODUCTS";
        gotoxy(32, 14);
        std::cout << "3: DELETE PRODUCTS";
        gotoxy(32, 16);
        std::cout << "0: EXIT";
        gotoxy(32, 19);
        std::cout << "Enter Choice : ";
        ch = getche();
        if (ch == '1')
        {
            product p;
            p.add_item();
            break;
        }
        else if (ch == '2')
        {
            product p;
            p.modify_item();
            break;
        }
        else if (ch == '3')
        {
            product p;
            p.delete_item();
            break;
        }
        else if (ch == '0')
            break;
    }
}

//function to returns last record



int product::last_code(void)
{
    fstream file;
    file.open("Product.dat", ios::in);
    file.seekg(0, ios::beg);
    int t = 0;
    while (file.read((char*) this, sizeof(product)))
        t = itemcode;
    file.close();
    return t;
}


void main(void)
{
    
    menu m;
    m.main_menu();
}
