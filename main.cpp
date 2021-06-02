#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>


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

void menu::main_menu(void);
{
    clrscr();
    char ch;
    gotoxy(10, 30);
    cout << "-------------------------------------------";
    gotoxy(10, 23);
    cout << "Sales Management system";
    gotoxy(28, 7);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    gotoxy(30, 9);
    cout << "1: PURCHASE PRODUCTS";
    gotoxy(30, 11);
    cout << "2: LIST OF PRODUCTS";
    gotoxy(30, 13);
    cout << "3: EDIT PRODUCTS FILE";
    gotoxy(30, 15);
    cout << "4: BILLS REPORT";
    gotoxy(30, 17);
    cout << "0: QUIT";
    gotoxy(30, 20);
    cout << "Enter Your Choice : ";
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
    {
        edit_menu();
    }
    else if (ch == '4')
    {
        account a;
        a.bill_list();
    }
    else if (ch == '0')
    {
        break;
    }
        
}


