#ifndef BANKPROGRAM_CPP_
#define BANKPROGRAM_CPP_

/* Deklarationer av variabler och värdena satta... */
int path = 0, client = 0, status = 1, number = -1;
double value = 0;
char choice = 0;

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <windows.h>
#include "class.h"
#include "beauty.h"
#include "info.h"

/* COLOUR värden används för att ge fönstret ett bättre utseende och det gör att man ser bättre helt enkelt... */
#define COLOUR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
#define WHITE   15
#define YELLOW  14
#define GREEN   10
#define	RED     12

using namespace std;

/* Deklarationer av alla funktioner, förutom dom i classen, som används i programmet - vissa
har en viss kontakt med klassen, dessa har också en visuel ordning nedan som överensstämmer med hur dom används... */
void registeraccount( int number, string statedssn, string statedname, int stateddeposit, int statedpin, int status );
 void update( int value );
void beginning();
 void newchoice();
 void listchoice();
  void clientoptions();
   void depositchoice();
   void withdrawalchoice();
    void correctpin();
    void incorrectpin();
 void informationchoice();

/* Själva main funktionen som inte har så mycket kod utan koden som gör allt vitt, presskeyinterface
för början och slut och själva funktionen som leder till resten... */
int main()
{
    COLOUR(WHITE);
    presskeyinterface();
    beginning();
    presskeyinterface();

    return 0;
}

/* Denna funktion gör att värdena man anger i programmet registreras i klassen... */
void registeraccount( int number, string statedssn, string statedname, int stateddeposit, int statedpin, int status )
{
    information[number].add( number, statedssn, statedname, stateddeposit, statedpin, status );
}

/* Denna funktion tar värdena som skickas till sig från funktionen ovan och sätter värdena under varje
private medlem... */
void Account::add( int addcustomer, string addssn, string addname, int addbalance, int addpin, int addlocked )
{
    customer = addcustomer;
    ssn = addssn;
    name = addname;
    balance = addbalance;
    pin = addpin;
    locked = addlocked;
}

/* Denna funktion visar innehållet med olika färger och inget vissas om locked är lika med noll... */
void Account::view()
{
    if( path == 21 || path == 211 || path == 212 || path == 213 )
    {   /* Denna if gör att informationen visas endast om kontot är olåst och i annat fall visas inget förutom 'YES!'... */
        cout << endl;
        cout << "  Nr:   " << (customer+1) << endl << endl;
        cout << "  þ SSNû:      ";if( locked == 0 ){ cout << endl; }else{ COLOUR(YELLOW);cout << ssn << endl;COLOUR(WHITE); }
        cout << "  þ Name:      ";if( locked == 0 ){ cout << endl; }else{ COLOUR(YELLOW);cout << name << endl;COLOUR(WHITE); }
        cout << "  þ Balance:   ";if( locked == 0 ){ cout << endl; }else{ COLOUR(YELLOW);cout << balance << endl;COLOUR(WHITE); }
        cout << "  þ Locked:    ";if( locked == 0 ){ COLOUR(RED);cout << "YES!" << endl;COLOUR(WHITE); }else{ COLOUR(GREEN);cout << "NO!" << endl;COLOUR(WHITE); }
    }
    else
    {   /* Detta visas efter att man har angett ett nytt konto... */
        cout << endl;
        cout << "  Nr:   " << (customer+1) << endl << endl;
        cout << "  þ SSNû:      "; COLOUR(YELLOW);cout << ssn << endl;COLOUR(WHITE);
        cout << "  þ Name:      "; COLOUR(YELLOW);cout << name << endl;COLOUR(WHITE);
        cout << "  þ Balance:   "; COLOUR(YELLOW);cout << balance << endl;COLOUR(WHITE);
        cout << "  þ PIN:       "; COLOUR(YELLOW);cout << "****" << endl;COLOUR(WHITE);
    }
}

/* Funktionen får ett nytt värde som skickas till en private medlem via funktionen nedan... */
void update( int value )
{
    information[client-1].update( value );
}

/* Funktionen ger ett nytt värde till en private medlem... */
void Account::update( int value )
{
    switch( path )
    {   /* Ifall path har värdet 212 vilket motsvarar deposit så tas värdet och adderas... */
        case 212:
            balance += value;
            break;
        case 213:
            balance -= value;
            break;
        /* I annat fall, vid 213, så subtraheras det... */
    }

    if( value == 0 ) /* Denna ger ett konto som har angett fel pin tre gånger värdet 0 till Locked... */
    {
        locked = 0;
    }
}

/* De fyra funktionerna nedan returnerar värdena under customer, balance, pin och locked när de behövs... */
int Account::customervalue()
{
    return customer;
}
int Account::balancevalue()
{
    return balance;
}
int Account::pinvalue()
{
    return pin;
}
int Account::lockedvalue()
{
    return locked;
}
/* Provade med att sätta ihop dessa och dela dom med ifar men utan lycka så dom får vara en och en... */

/* Här börjar själva programmet med att man anger om man vill registrera, visa alla eller avsluta... */
void beginning()
{
    do
    {
        path = 0;
        topinterface();
        cout << "º "; COLOUR(YELLOW);cout << "Main menu:";COLOUR(WHITE);cout << "                                                                 º" << endl;
        topedges();
        cout << "  "; COLOUR(YELLOW);cout << "CHOOSE:" << endl;COLOUR(WHITE);
        cout << "  "; COLOUR(RED);cout << "-------" << endl << endl;COLOUR(WHITE);
        cout << "  1. Register a new customer" << endl;
        cout << "  2. View all current customers" << endl;
        cout << "  3. Information about program" << endl;
        cout << "  4. Exit program" << endl;
        bottomedges();
        choicebottominterface();
        switch( choice )
        {
            case '1':
                newchoice();
                break;
            case '2':
                listchoice();
                break;
            case '3':
                informationchoice();
                break;
            case '4':
                break;
            default:
                path = 4;
                impossible();
                break;
        }
    }
    while( choice != 4 );
}

/* Denna körs när man anger att man vill skapa en ny kund... Värdena skapas och sparas i deklarationer
inom denna funktion som sedan skickas till public i klassen... */
void newchoice()
{
    string statedssn, statedname;
    double stateddeposit, statedpin;
    
    path = 1;
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Registration of a new customer:";COLOUR(WHITE);cout << "                    ûSocial Security Number º" << endl;
    topedges();
    cout << "  "; COLOUR(YELLOW);cout << "STATE:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "------" << endl << endl;COLOUR(WHITE);
    cout << "  þ SSNû:      "; COLOUR(GREEN);getline( cin, statedssn );COLOUR(WHITE);
    cout << "  þ Name:      "; COLOUR(GREEN);getline( cin, statedname );COLOUR(WHITE);
    cout << "  þ Deposit:   "; COLOUR(GREEN);cin >> stateddeposit; cin.ignore();COLOUR(WHITE);
    cout << "  þ PIN:       "; COLOUR(GREEN);cin >> statedpin; cin.ignore();COLOUR(WHITE);
    stateddeposit = floor(stateddeposit);
    statedpin = floor(statedpin);
    number++;
    registeraccount( number, statedssn, statedname, stateddeposit, statedpin, status );
    bottomedges();
    bottominterface();

    path = 11;
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Confirmation of the registered customer:";COLOUR(WHITE);cout << "           ûSocial Security Number º" << endl;
    topedges();
    cout << "  "; COLOUR(YELLOW);cout << "STATED:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "-------" << endl;COLOUR(WHITE);
    information[number].view();
    bottomedges();
    bottominterface();
}

/* Denna visar alla kunder som finns, finns ingen registerar visas ett meddelande om det... */
void listchoice()
{
    path = 2;
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "List of all current customers:";COLOUR(WHITE);cout << "                     ûSocial Security Number º" << endl;
    topedges();
    if( number < 0 )
    {
        path = 20;
        cout << "  \aThere are no current customers!" << endl;
        bottomedges();
        bottominterface();
    }
    else
    if( number >= 0 )
    {
        path = 21;
        cout << "  "; COLOUR(YELLOW);cout << "CUSTOMERS:" << endl;COLOUR(WHITE);
        cout << "  "; COLOUR(RED);cout << "----------" << endl;COLOUR(WHITE);
        for( int loop = 0; loop <= number; loop++ )
        {
            information[loop].view();
            cout << endl;
            COLOUR(RED);cout << "  ---" << endl;COLOUR(WHITE);
        }
        bottomedges();
        clientbottominterface();
        /* Denna if kollar om en client stämmer överrens med kundnr och kollar sedan om kontot är låst,
        är den det visas lockedinterface... */
        if( information[client-1].customervalue() == (client-1) && information[client-1].lockedvalue() == 0 )
        {
            lockedinterface();    
            
            listchoice();
        }
        else
        if( client == 0 )
        {
            presskeyinterface();

            beginning();
        }
        else
        if( client < 0 || client > number+1)
        {
            path = 20;
            topinterface();
            cout << "º "; COLOUR(YELLOW);cout << "List of all current customers:";COLOUR(WHITE);cout << "                     ûSocial Security Number º" << endl;
            topedges();
            cout << "  \aThere is no customer with that number!" << endl;
            bottomedges();
            bottominterface();

            listchoice();
        }
        else
        if( client >= 0 || client <= number )
        {
            clientoptions();
        }
    }
}

/* Var tvungen att stoppa valmöjligheterna för varje kund under en egen funktion för att kunna återkomma
till denna punkt ifall man har gjort en insättning eller uttag... */
void clientoptions()
{
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Customer:";COLOUR(WHITE);cout << "                                                                  º" << endl;
    topedges();
    cout << "  "; COLOUR(YELLOW);cout << "CURRENT:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "--------" << endl;COLOUR(WHITE);
    information[client-1].view();
    cout << endl << endl;
    cout << "  "; COLOUR(YELLOW);cout << "CHOOSE:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "-------" << endl << endl;COLOUR(WHITE);
    cout << "  1. Make a deposit" << endl;
    cout << "  2. Make a withdrawal" << endl;
    cout << "  3. Return to main menu" << endl;
    bottomedges();
    choicebottominterface();
    
    switch( choice )
    {
        case '1':
            depositchoice();
            break;
        case '2':
            withdrawalchoice();
            break;
        case '3':
            beginning();
            break;
        default:
            path = 4;
            impossible();
            break;
    }
}

/* Funktionen gör det möjligt att ange vad man vill sätta in, +tal ger ett resultat, -tal ger ett
annat och 0 går tillbaka... */
void depositchoice()
{
    path = 212;
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Registrating customer Deposit:";COLOUR(WHITE);cout << "                                             º" << endl;
    topedges();
    cout << "  "; COLOUR(YELLOW);cout << "BEFORE:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "-------" << endl;COLOUR(WHITE);
    information[client-1].view();
    cout << endl;
    cout << "  State your deposit: "; COLOUR(GREEN);cin >> value; cin.ignore();COLOUR(WHITE);
    if( value > 0 )
    {
        update( value );
    }
    cout << endl;
    cout << "  "; COLOUR(YELLOW);cout << "AFTER:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "------" << endl;COLOUR(WHITE);
    information[client-1].view();
    cout << endl << endl;
    
    if( value < 0 )
    {
        cout << "  Ehm, you chose the wrong selection, in the menu, if you are\n  trying to make a withdrawal!" << endl;
    }
    else
    if( value == 0 )
    {
        cout << "  Returning..." << endl;
    }
    else
    if( value > 0 )
    {
        cout << "  Thank you for depositing money into our bank! Have a very nice day!" << endl;
    }
    bottomedges();
    bottominterface();
    value = 0;
    
    clientoptions();
}

/* Här så registreras uttag, +tal tar ut, -tal frågar om man gick rätt och 0 går tillbaka... */
void withdrawalchoice()
{
    path = 213;
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Registrating customer Withdrawal:";COLOUR(WHITE);cout << "                                          º" << endl;
    topedges();
    if( information[client-1].balancevalue() == 0 )
    {
        impossible();

        listchoice();
    }
    cout << "  PIN: "; COLOUR(GREEN);cin >> value; cin.ignore();COLOUR(WHITE);
    cout << endl;
    
    /* Dock innan man kan ta ut måste man ange pin, annars kan vem som helst ta ut pengar... */
    if( information[client-1].pinvalue() == value )
    {
        correctpin();
    }
    else
    if( information[client-1].pinvalue() != value )
    {
        incorrectpin();
    }
    bottomedges();
    bottominterface();
    value = 0;

    clientoptions();
}

/* Anger man rätt händer detta, dessutom får man olika meddelanden beroende på +tal, -tal eller 0... */
void correctpin()
{
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Registrating customer Withdrawal:";COLOUR(WHITE);cout << "                                          º" << endl;
    topedges();
    cout << "  You've stated the correct PIN number!" << endl << endl << endl;
    cout << "  "; COLOUR(YELLOW);cout << "BEFORE:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "-------" << endl;COLOUR(WHITE);
    information[client-1].view();
    cout << endl;
    cout << "  State your withdrawal: "; COLOUR(GREEN);cin >> value; cin.ignore();COLOUR(WHITE);
    if( value > information[client-1].balancevalue() )
    {
        cout << endl << endl;
        cout << "  \aThe withdrawal couldn't be registered, not enough money on the account!" << endl;
        bottomedges();
        bottominterface();

        clientoptions();
    }
    else
    if( value > 0 ) /* Vet inte varför jag var tvungen att stoppa under två ifar, resultatet blev inte bra med ('if' && 'if')... */
    {
        if( value <= information[client-1].balancevalue() )
        {
            update( value );
        }
    }
    cout << endl;
    cout << "  "; COLOUR(YELLOW);cout << "AFTER:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "------" << endl;COLOUR(WHITE);
    information[client-1].view();
    cout << endl << endl;

    if( value < 0 )
    {
        cout << "  Ehm, you chose the wrong selection, in the menu, if you are\n  trying to make a deposit!" << endl;
    }
    else
    if( value == 0 )
    {
        cout << "  Returning..." << endl;
    }
    else
    if( value > 0 )
    {
        cout << "  Thank you for choosing our bank! Have a good day!" << endl;
    }
}

/* Anger man dock fel pin så händer detta, anger man tre gånger så låser sig kontot och under visa alla
så ser man tydligt vilket som har låsts... */
void incorrectpin()
{
    COLOUR(RED);cout << "  \aWARNING MESSAGE!";COLOUR(WHITE);cout << " You have stated the incorrect PIN number!";COLOUR(RED);cout << " WARNING MESSAGE!" << endl << endl;
    COLOUR(WHITE);cout << "  ---" << endl << endl;
    COLOUR(WHITE);cout << "  Two more chances of stating the"; COLOUR(GREEN);cout << " CORRECT";COLOUR(WHITE);cout << " PIN number: "; COLOUR(GREEN);cin >> value; cin.ignore();COLOUR(WHITE);

    if( information[client-1].pinvalue() != value )
    {
        cout << endl;
        cout << "  \aYou're still stating the";COLOUR(RED);cout << " INCORRECT";COLOUR(WHITE);cout << " PIN number! One more chance and\n  the police won't get involved!" << endl << endl;
        COLOUR(GREEN);cout << "  CORRECT";COLOUR(WHITE);cout << " PIN: "; COLOUR(GREEN);cin >> value; cin.ignore();COLOUR(WHITE);
        cout << endl;
        cout << "  ---" << endl << endl;

        if( information[client-1].pinvalue() != value )
        {
            cout << "  This account is now";COLOUR(RED);cout << " LOCKED";COLOUR(WHITE);cout << ", the registered customer will be notified and\n  the police will be up your ass in a few moments!" << endl << endl;
            cout << "  Smile, a picture has now been taken of your sorry ass!\n\n  ";COLOUR(GREEN);cout << "Have a good day!";COLOUR(WHITE);cout << " " << endl;
            status = 0;
            update( status );
            status = 1;
            /* Denna if gör att ett konto blir låst... den skickar värdet 0 till private medlemmen locked... */
        }
        else
            clientoptions();
    }
    else
        clientoptions();
}

void informationchoice()
{
    viewinfo();
}

#endif
