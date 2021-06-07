// author: Mario 
// source of knowledge: https://www.cplusplus.com/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <process.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "gotoxy.h"
#include <locale.h>
#include <time.h>

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

//function for list of items

void product::list_of_item(void)
{
    
    fstream file;
    file.open("PRODUCT.DAT", ios::in);
    file.seekg(0);
    int row = 6, found = 0;
    gotoxy(30, 2);
    cout << "LIST OF ITEMS";
    gotoxy(3, 4);
    cout << "ITEM CODE ITEM NAME ITEM COST ITEM PRICE";
    gotoxy(2, 5);
    cout << "***********************************************************";
    while (file.read((char*)this, sizeof(product)))
    {
        Sleep(2000);
        found = 1;
        gotoxy(5, row);
        cout << itemcode;
        gotoxy(14, row);
        cout << itemname;
        gotoxy(37, row);
        cout << itemcost;
        gotoxy(51, row);
        cout << itemprice;
        if (row == 22)
        {
            row = 5;
            gotoxy(1, 25);
            cout << "Press any key to continue...";
            getche();
            
            gotoxy(30, 2);
            cout << "LIST OF ITEMS";
            gotoxy(3, 4);
            cout << "ITEM CODE ITEM NAME ITEM COST ITEM PRICE";
            gotoxy(2, 5);
            cout << "-------------------------------------------"
                ;
        }
        else
            row++;
    }
    if (!found)
    {
        gotoxy(5, 10);
        cout << "\7Records not found";
    }
    gotoxy(1, 25);
    cout << "Press any key to continue...";
    getche();
    file.close();
}

//function to add items

void product::add_item(void)
{
    int tcode, valid;
    char ch, t_itemcost[10], t_itemprice[10];
    tcode = last_code();
    tcode++;
    do
    {
        
        gotoxy(71, 2);
        cout << "<0>=Exit";
        gotoxy(27, 3);
        cout << "ADDITION OF PRODUCTS";
        gotoxy(26, 4);
        cout << "--------------------";
        gotoxy(5, 6);
        cout << "Item Code : " << tcode;
        gotoxy(5, 8);
        cout << "Item Name : ";
        gotoxy(5, 10);
        cout << "Item Cost : ";
        gotoxy(5, 12);
        cout << "Item Price : ";
        do
        {
            valid = 1;
            gotoxy(1, 8);
            system("cls");
            gotoxy(1, 24);
            system("cls");
            gotoxy(1, 25);
            system("cls");
            gotoxy(3, 25);
            cout << "ENTER ITEM NAME TO ADD IN THE MENU";
            gotoxy(5, 8);
            cout << "Item Name : ";
            fgets(itemname, sizeof(500), stdin);
            strupr(itemname);
            if (itemname[0] == '0')
                return;
            if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
            {
                valid = 0;
                gotoxy(3, 24);
                cout << "\7 Range = 1..20";
                getch();
            }
        }         while (!valid);
        do
        {
            valid = 1;
            gotoxy(1, 10);
            system("cls");
            gotoxy(1, 24);
            system("cls");
            gotoxy(1, 25);
            system("cls");
            gotoxy(3, 25);
            cout << "ENTER ITEM COST TO ADD IN THE MENU";
            gotoxy(5, 10);
            cout << "Item Cost : ";
            fgets(t_itemcost, sizeof(500), stdin);
            itemcost = atof(t_itemcost);
            if (t_itemcost[0] == '0')
                return;
            if (itemcost < 1 || itemcost > 800)
            {
                valid = 0;
                gotoxy(3, 24);
                cout << "\7 Range = 1..800";
                getch();
            }
        }         while (!valid);
        do
        {
            valid = 1;
            gotoxy(1, 12);
            system("cls");
            gotoxy(1, 24);
            system("cls");
            gotoxy(1, 25);
            system("cls");
            gotoxy(3, 25);
            cout << "ENTER ITEM PRICE TO ADD IN THE MENU";
            gotoxy(5, 12);
            cout << "Item Price : ";
            fgets(t_itemprice, sizeof(500), stdin);
            itemprice = atof(t_itemprice);
            if (t_itemprice[0] == '0')
                return;
            if (itemprice < itemcost || itemprice > 1000)
            {
                valid = 0;
                gotoxy(3, 24);
                cout << "\7 Range = " << itemcost << "..1000";
                getch();
            }
        }         while (!valid);
        do
        {
            gotoxy(1, 15);
            system("cls");
            gotoxy(1, 24);
            system("cls");
            gotoxy(1, 25);
            system("cls");
            gotoxy(5, 15);
            cout << "Do you want to save this record (y/n) : ";
            ch = getche();
            ch = toupper(ch);
            if (ch == '0')
                return;
        }         while (ch != 'N' && ch != 'Y');
        if (ch == 'Y')
        {
            itemcode = tcode;
            fstream file;
            file.open("PRODUCT.DAT", ios::out | ios::app);
            file.write((char*)this, sizeof(product));
            file.close();
            tcode++;
        }
        do
        {
            gotoxy(1, 17);
            system("cls");
            gotoxy(1, 24);
            system("cls");
            gotoxy(1, 25);
            system("cls");
            gotoxy(5, 17);
            cout << "Do you want to add more records (y/n) : ";
            ch = getche();
            ch = toupper(ch);
            if (ch == '0')
                return;
        }         while (ch != 'N' && ch != 'Y');
    }     while (ch == 'Y');
}


//function to display record from data file

void product::display_record(int tcode)
{
    fstream file;
    file.open("PRODUCT.DAT", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char*)this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            gotoxy(5, 3);
            cout << "Item Code : " << itemcode;
            gotoxy(5, 4);
            cout << "Item Name : " << itemname;
            gotoxy(5, 5);
            cout << "Item Cost : " << itemcost;
            gotoxy(5, 6);
            cout << "Item Price : " << itemprice;
            break;
        }
    }
    file.close();
}


//returns 1 if item found in data file

int product::item_found(int tcode)
{
    fstream file;
    file.open("PRODUCT.DAT", ios::in);
    file.seekg(0, ios::beg);
    int found = 0;
    while (file.read((char*)this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++;
            break;
        }
    }
    file.close();
    return found;
}


//function returns no if item not found

int product::recordno(int tcode)
{
    fstream file;
    file.open("PRODUCT.DAT", ios::in);
    file.seekg(0, ios::beg);
    int found = 0;
    while (file.read((char*)this, sizeof(product)))
    {
        found++;
        if (itemcode == tcode)
            break;
    }
    file.close();
    return found;
}


//function to delete records

void product::delete_record(int tcode)
{
    fstream file;
    file.open("PRODUCT.DAT", ios::in);
    fstream temp;
    temp.open("temp.dat", ios::out);
    file.seekg(0, ios::beg);
    while (!file.eof())
    {
        file.read((char*)this, sizeof(product));
        if (file.eof())
            break;
        if (itemcode != tcode)
            temp.write((char*)this, sizeof(product));
    }
    file.close();
    temp.close();
    file.open("PRODUCT.DAT", ios::out);
    temp.open("temp.dat", ios::in);
    temp.seekg(0, ios::beg);
    while (!temp.eof())
    {
        temp.read((char*)this, sizeof(product));
        if (temp.eof())
            break;
        file.write((char*)this, sizeof(product));
    }
    file.close();
    temp.close();
}


//function to delete items

void product::delete_item(void)
{
    
    char t_code[5], ch;
    int t, tcode;
    gotoxy(3, 25);
    cout << "Press <ENTER> to see the list";
    gotoxy(5, 3);
    cout << "Enter Item Code of the item to be deleted : ";
    fgets(t_code, sizeof(500), stdin);
    t = atoi(t_code);
    tcode = t;
    if (t_code[0] == '0')
        return;
    if (tcode == 0)
    {
        list_of_item();
        gotoxy(1, 25);
        system("cls");
        gotoxy(3, 25);
        cout << "Press <ENTER> to Exit";
        gotoxy(5, 24);
        cout << "Enter Item Code of the item to be deleted : ";
        fgets(t_code, sizeof(500), stdin);
        t = atoi(t_code);
        tcode = t;
        if (tcode == 0)
            return;
    }
    
    if (!item_found(tcode))
    {
        gotoxy(5, 5);
        cout << "\7Record not found";
        getch();
        return;
    }
    display_record(tcode);
    do
    {
        gotoxy(1, 8);
        system("cls");
        gotoxy(5, 8);
        cout << "Do you want to delete this record (y/n) : ";
        ch = getche();
        ch = toupper(ch);
    }     while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
        return;
    delete_record(tcode);
    gotoxy(5, 15);
    cout << "\7Record Deleted";
    getch();
}


//function modify records

void product::modify_record(int tcode)
{
    int recno;
    recno = recordno(tcode);
    int valid, t_code;
    char ch, t_itemcost[10], t_itemprice[10], t_itemcode[5];
    gotoxy(71, 2);
    cout << "<0>=Exit";
    gotoxy(5, 12);
    cout << "Item Code : ";
    gotoxy(5, 14);
    cout << "Item Name : ";
    gotoxy(5, 16);
    cout << "Item Cost : ";
    gotoxy(5, 18);
    cout << "Item Price : ";
    do
    {
        gotoxy(20, 12);
        
        cout << "Change (y/n) : ";
        ch = getche();
        ch = toupper(ch);
        if (ch == '0')
            return;
    }     while (ch != 'N' && ch != 'Y');
    valid = 0;
    while (ch == 'Y' && !valid)
    {
        valid = 1;
        gotoxy(1, 12);
        system("cls");
        gotoxy(1, 24);
        system("cls");
        gotoxy(1, 25);
        system("cls");
        gotoxy(3, 25);
        cout << "ENTER ITEM CODE TO ADD IN THE MENU";
        gotoxy(5, 12);
        cout << "Item Code : ";
        fgets(t_itemcode, sizeof(500), stdin);
        t_code = atoi(t_itemcode);
        if (t_code == 0)
            return;
        if (item_found(t_code) && t_code != tcode)
        {
            valid = 0;
            gotoxy(3, 24);
            cout << "\7 CODE ALREADY GIVEN";
            getch();
        }
    }
    do
    {
        gotoxy(20, 14);
        system("cls");
        cout << "Change (y/n) : ";
        ch = getche();
        ch = toupper(ch);
        if (ch == '0')
            return;
    }     while (ch != 'N' && ch != 'Y');
    valid = 0;
    while (ch == 'Y' && !valid)
    {
        valid = 1;
        gotoxy(1, 14);
        system("cls");
        gotoxy(1, 24);
        system("cls");
        gotoxy(1, 25);
        system("cls");
        gotoxy(3, 25);
        cout << "ENTER ITEM NAME TO ADD IN THE MENU";
        gotoxy(5, 14);
        cout << "Item Name : ";
        fgets(itemname, sizeof(100), stdin);
        strupr(itemname);
        if (itemname[0] == '0')
            return;
        if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
        {
            valid = 0;
            gotoxy(3, 24);
            cout << "\7 Range = 1..20";
            getch();
        }
    }
    do
    {
        gotoxy(20, 16);
        
        cout << "Change (y/n) : ";
        ch = getche();
        ch = toupper(ch);
        if (ch == '0')
            return;
    }     while (ch != 'N' && ch != 'Y');
    valid = 0;
    while (ch == 'Y' && !valid)
    {
        valid = 1;
        gotoxy(1, 16);
        system("cls");
        gotoxy(1, 24);
        system("cls");
        gotoxy(1, 25);
        system("cls");
        gotoxy(3, 25);
        cout << "ENTER ITEM COST TO ADD IN THE MENU";
        gotoxy(5, 16);
        cout << "Item Cost : ";
        fgets(t_itemcost, sizeof(500), stdin);
        itemcost = atof(t_itemcost);
        if (t_itemcost[0] == '0')
            return;
        if (itemcost < 1 || itemcost > 800)
        {
            valid = 0;
            gotoxy(3, 24);
            cout << "\7 Range = 1..800";
            getch();
        }
    }
    do
    {
        gotoxy(20, 18);
        system("cls");
        cout << "Change (y/n) : ";
        ch = getche();
        ch = toupper(ch);
        if (ch == '0')
            return;
    }     while (ch != 'N' && ch != 'Y');
    valid = 0;
    while (ch == 'Y' && !valid)
    {
        valid = 1;
        gotoxy(1, 18);
        system("cls");
        gotoxy(1, 24);
        system("cls");
        gotoxy(1, 25);
        system("cls");
        gotoxy(3, 25);
        cout << "ENTER ITEM PRICE TO ADD IN THE MENU";
        gotoxy(5, 18);
        cout << "Item Price : ";
        fgets(t_itemprice, sizeof(500), stdin);
        itemprice = atof(t_itemprice);
        if (t_itemprice[0] == '0')
            return;
        if (itemprice < itemcost || itemprice > 1000)
        {
            valid = 0;
            gotoxy(3, 24);
            cout << "\7 Range = " << itemcost << "..1000";
            getch();
        }
    }
    do
    {
        gotoxy(1, 21);
        system("cls");
        gotoxy(1, 24);
        system("cls");
        gotoxy(1, 25);
        system("cls");
        gotoxy(5, 21);
        cout << "Do you want to save this record (y/n) : ";
        ch = getche();
        ch = toupper(ch);
        if (ch == '0')
            return;
    }     while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
        return;
    itemcode = t_code;
    cout << "\n" << itemname;
    cout << itemcost;
    cout << itemprice;
    getch();
    fstream file;
    file.open("PRODUCT.DAT", ios::out | ios::ate);
    int location;
    location = (recno - 1) * sizeof(product);
    file.seekp(location);
    file.write((char*)this, sizeof(product));
    file.close();
    sort();
   
    gotoxy(5, 15);
    cout << "\7Record Modified";
    getch();
}


//modify item, return no if not exists

void product::modify_item(void)
{
    
    char t_code[5], ch;
    int t, tcode;
    gotoxy(3, 25);
    cout << "Press <ENTER> to see the list";
    gotoxy(5, 3);
    cout << "Enter Item Code of the item to be Modify : ";
    fgets(t_code, sizeof(500), stdin);
    t = atoi(t_code);
    tcode = t;
    if (t_code[0] == '0')
        return;
    if (tcode == 0)
    {
        list_of_item();
        gotoxy(1, 25);
        system("cls");
        gotoxy(3, 25);
        cout << "Press <ENTER> to Exit";
        gotoxy(5, 24);
        cout << "Enter Item Code of the item to be modify : ";
        fgets(t_code, sizeof(500), stdin);
        t = atoi(t_code);
        tcode = t;
        if (tcode == 0)
            return;
    }
    
    if (!item_found(tcode))
    {
        gotoxy(5, 5);
        cout << "\7Record not found";
        getch();
        return;
    }
    display_record(tcode);
    do
    {
        gotoxy(5, 8);
        cout << "Do you want to Modify this record (y/n) : ";
        ch = getche();
        ch = toupper(ch);
    }     while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
        return;
    modify_record(tcode);
}


//function to sorting products

void product::sort(void)
{
    int i = 0, j;
    product arr[100];
    product temp;
    fstream file;
    file.open("PRODUCT.DAT", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char*)&arr[i], sizeof(product)))
        i++;
    int size;
    size = i;
    file.close();
    for (i = 1; i < size; i++)
        for (j = 0; j < size - i; j++)
        {
            if (arr[j].itemcode > arr[j + 1].itemcode)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    file.open("PRODUCT.DAT", ios::out);
    for (i = 0; i < size; i++)
        file.write((char*)&arr[i], sizeof(product));
    file.close();
}


//purchase function

void product::purchase(void)
{
    
    account a;
    int t_billno, purchased = 0;
    t_billno = a.last_billno();
    t_billno++;
    char t_code[5], ch;
    float t_quantity;
    int t, tcode, i = 0, valid;
    float qty;
    int t_itemcode;
    float t_qty, t_cost, t_price;
    char t_itemname[30];
   
    do
    {
        
        gotoxy(3, 25);
        cout << "Press <ENTER> to see the list";
        gotoxy(5, 3);
        cout << "Enter Item Code of the item to be Purchase : ";
        fgets(t_code, sizeof(500), stdin);
        t = atoi(t_code);
        tcode = t;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno);
            return;
        }
        if (tcode == 0)
        {
            list_of_item();
            gotoxy(1, 25);
            system("cls");
            gotoxy(3, 25);
            cout << "Press <ENTER> to Exit";
            gotoxy(5, 24);
            cout << "Enter Item Code of the item to be Purchase : ";
            fgets(t_code, sizeof(500), stdin);
            t = atoi(t_code);
            tcode = t;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno);
                return;
            }
        }
        
        if (!item_found(tcode))
        {
            gotoxy(5, 5);
            cout << "\7Item Code not found";
            getch();
            if (purchased)
                a.prepare_bill(t_billno);
            return;
        }
        gotoxy(60, 2);
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        cout << "Date:" << tm.tm_mday << "/" << tm.tm_mon << "/" << tm.tm_year;
        display_record(tcode);
        do
        {
            valid = 1;
            gotoxy(1, 8);
            system("cls");
            gotoxy(1, 24);
            system("cls");
            gotoxy(1, 25);
            system("cls");
            gotoxy(3, 25);
            cout << "ENTER QUANTITY TO BE PURCHASE IN Kg.";
            gotoxy(5, 8);
            cout << "Quantity : ";
            cin >> t_quantity;
            qty = t_quantity;
            if (t_quantity == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno);
                return;
            }
            if (qty < 1 || qty > 800)
            {
                valid = 0;
                gotoxy(3, 24);
                cout << "\7 Range = 1..800";
                getch();
            }
        }         while (!valid);
        do
        {
            gotoxy(5, 10);
            system("cls");
            gotoxy(5, 10);
            cout << "Do you want to cancel this purchase (y/n) : ";
            ch = getche();
            ch = toupper(ch);
        }         while (ch != 'N' && ch != 'Y');
        if (ch == 'N')
        {
            purchased = 1;
            fstream file;
            file.open("PRODUCT.DAT", ios::in);
            file.seekg(0, ios::beg);
            while (file.read((char*)this, sizeof(product)))
            {
                if (itemcode == tcode)
                {
                    t_itemcode = itemcode;
                    strcpy(t_itemname, itemname);
                    t_cost = itemcost;
                    t_price = itemprice;
                    t_qty = qty;
                    a.add_bill(t_billno, t_itemcode, t_itemname, t_qty, t_cost, t_price);
                    i++;
                    break;
                }
            }
            file.close();
        }
        do
        {
            gotoxy(5, 12);
            system("cls");
            gotoxy(5, 12);
            cout << "Do you want to purchase more (y/n) : ";
            ch = getche();
            ch = toupper(ch);
        }         while (ch != 'N' && ch != 'Y');
    }     while (ch == 'Y');
    a.prepare_bill(t_billno);
}


//function for last bill no

int account::last_billno(void)
{
    fstream file;
    file.open("BILL.DAT", ios::in);
    file.seekg(0, ios::beg);
    int t = 0;
    while (file.read((char*)this, sizeof(account)))
        t = billno;
    file.close();
    return t;
}


//add bill function

void account::add_bill(int t_billno, int t_itemcode, char
    t_itemname[30], float t_qty, float t_cost, float t_price)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    code = t_itemcode;
    strcpy(name, t_itemname);
    cost = t_cost;
    price = t_price;
    quantity = t_qty;
    billno = t_billno;
    fstream file;
    file.open("BILL.DAT", ios::out | ios::app);
    file.write((char*)this, sizeof(account));
    file.close();
}


//prepare bill

void account::prepare_bill(int t_billno)
{
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    float total = 0.0, total_bill = 0.0;
    gotoxy(33, 3);
    cout << "CUSTOMER BILL";
    gotoxy(55, 5);
    cout << "Date:" << tm.tm_mday << "/" << tm.tm_mon << "/" << tm.tm_year;
    gotoxy(8, 7);
    cout << "ITEMS PURCHASED";
    gotoxy(8, 8);
    cout << "+++++++++++++++";
    gotoxy(8, 9);
    cout << "Item code Item name Cost Price Qty Total"
        ;
    gotoxy(8, 10);
    cout << "------------------------------------------------------------"
        ;
    int row = 11;
    fstream file;
    file.open("BILL.DAT", ios::in);
    file.seekg(0);
    while (file.read((char*)this, (sizeof(account)) != 0))
    {
        if (billno == t_billno)
        {
            gotoxy(8, 5);
            cout << "BILL NO. # " << billno;
            gotoxy(8, 6);
            cout << "===============";
            gotoxy(10, row);
            cout << code;
            gotoxy(18, row);
            cout << name;
            gotoxy(39, row);
            cout << cost;
            gotoxy(47, row);
            cout << price;
            gotoxy(56, row);
            cout << quantity;
            total = quantity * price;
            gotoxy(63, row);
            cout << total;
            total_bill = total_bill + total;
            row++;
        }
    }
    file.close();
    gotoxy(39, row + 1);
    cout << "TOTAL BILL: Rs." << total_bill << " /=";
    getch();
}


//function list of bills 

void account::bill_list(void)
{
    
    fstream file;
    file.open("BILL.DAT", ios::in);
    file.seekg(0);
    int row = 5, found = 0, pageno = 1, prev_billno = 0, flag = 0;
    float total = 0.0, total_bill = 0.0;
    gotoxy(30, 2);
    cout << "LIST OF BILLS";
    gotoxy(3, 4);
    cout << "Billno. Date Item Code Item name Cost Pri Qty Total";
    gotoxy(3, 5);
    cout
        << "===========================================================================";
    while (file.read((char*)this, sizeof(account)))
    {
        row++;
        Sleep(200);
        found = 1;
        if (prev_billno != billno)
        {
            if (flag)
            {
                gotoxy(52, row);
                cout << "TOTAL BILL: Rs." << total_bill << "/=";
                total_bill = 0.0;
                row++;
            }
            gotoxy(4, row);
            cout << billno;
        }
        flag = 1;
        gotoxy(11, row);
        cout << dd << "/" << mm << "/" << yy;
        gotoxy(24, row);
        cout << code;
        gotoxy(32, row);
        cout << name;
        gotoxy(52, row);
        cout << cost;
        gotoxy(59, row);
        cout << price;
        gotoxy(67, row);
        cout << quantity;
        total = quantity * price;
        gotoxy(73, row);
        cout << total;
        total_bill = total_bill + total;
        if (row >= 23)
        {
            row = 5;
            gotoxy(66, 1);
            cout << "Page no. : " << pageno;
            pageno++;
            gotoxy(1, 25);
            cout << "Press any key to continue...";
            getche();
            
            gotoxy(30, 2);
            cout << "LIST OF BILLS";
            gotoxy(3, 4);
            cout << "Billno. Date Item Code Item name CostPrice Qty Total";
            gotoxy(3, 5);
            cout
                << "===========================================================================";
        }
        prev_billno = billno;
    }
    row++;
    gotoxy(52, row);
    cout << "TOTAL BILL: Rs." << total_bill << "/=";
    if (!found)
    {
        gotoxy(5, 10);
        cout << "\7Records not found";
    }
    gotoxy(66, 1);
    cout << "Page no. : " << pageno;
    gotoxy(1, 25);
    cout << "Press any key to continue...";
    getche();
    file.close();
}


void main(void)
{
    system("cls");
    menu m;
    m.main_menu();
}
