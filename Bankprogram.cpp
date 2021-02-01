#ifndef BANKPROGRAM_CPP_
#define BANKPROGRAM_CPP_

/* Deklarationer av variabler och v�rdena satta... */
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

/* COLOUR v�rden anv�nds f�r att ge f�nstret ett b�ttre utseende och det g�r att man ser b�ttre helt enkelt... */
#define COLOUR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
#define WHITE   15
#define YELLOW  14
#define GREEN   10
#define	RED     12

using namespace std;

/* Deklarationer av alla funktioner, f�rutom dom i classen, som anv�nds i programmet - vissa
har en viss kontakt med klassen, dessa har ocks� en visuel ordning nedan som �verensst�mmer med hur dom anv�nds... */
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

/* Sj�lva main funktionen som inte har s� mycket kod utan koden som g�r allt vitt, presskeyinterface
f�r b�rjan och slut och sj�lva funktionen som leder till resten... */
int main()
{
    COLOUR(WHITE);
    presskeyinterface();
    beginning();
    presskeyinterface();

    return 0;
}

/* Denna funktion g�r att v�rdena man anger i programmet registreras i klassen... */
void registeraccount( int number, string statedssn, string statedname, int stateddeposit, int statedpin, int status )
{
    information[number].add( number, statedssn, statedname, stateddeposit, statedpin, status );
}

/* Denna funktion tar v�rdena som skickas till sig fr�n funktionen ovan och s�tter v�rdena under varje
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

/* Denna funktion visar inneh�llet med olika f�rger och inget vissas om locked �r lika med noll... */
void Account::view()
{
    if( path == 21 || path == 211 || path == 212 || path == 213 )
    {   /* Denna if g�r att informationen visas endast om kontot �r ol�st och i annat fall visas inget f�rutom 'YES!'... */
        cout << endl;
        cout << "  Nr:   " << (customer+1) << endl << endl;
        cout << "  � SSN�:      ";if( locked == 0 ){ cout << endl; }else{ COLOUR(YELLOW);cout << ssn << endl;COLOUR(WHITE); }
        cout << "  � Name:      ";if( locked == 0 ){ cout << endl; }else{ COLOUR(YELLOW);cout << name << endl;COLOUR(WHITE); }
        cout << "  � Balance:   ";if( locked == 0 ){ cout << endl; }else{ COLOUR(YELLOW);cout << balance << endl;COLOUR(WHITE); }
        cout << "  � Locked:    ";if( locked == 0 ){ COLOUR(RED);cout << "YES!" << endl;COLOUR(WHITE); }else{ COLOUR(GREEN);cout << "NO!" << endl;COLOUR(WHITE); }
    }
    else
    {   /* Detta visas efter att man har angett ett nytt konto... */
        cout << endl;
        cout << "  Nr:   " << (customer+1) << endl << endl;
        cout << "  � SSN�:      "; COLOUR(YELLOW);cout << ssn << endl;COLOUR(WHITE);
        cout << "  � Name:      "; COLOUR(YELLOW);cout << name << endl;COLOUR(WHITE);
        cout << "  � Balance:   "; COLOUR(YELLOW);cout << balance << endl;COLOUR(WHITE);
        cout << "  � PIN:       "; COLOUR(YELLOW);cout << "****" << endl;COLOUR(WHITE);
    }
}

/* Funktionen f�r ett nytt v�rde som skickas till en private medlem via funktionen nedan... */
void update( int value )
{
    information[client-1].update( value );
}

/* Funktionen ger ett nytt v�rde till en private medlem... */
void Account::update( int value )
{
    switch( path )
    {   /* Ifall path har v�rdet 212 vilket motsvarar deposit s� tas v�rdet och adderas... */
        case 212:
            balance += value;
            break;
        case 213:
            balance -= value;
            break;
        /* I annat fall, vid 213, s� subtraheras det... */
    }

    if( value == 0 ) /* Denna ger ett konto som har angett fel pin tre g�nger v�rdet 0 till Locked... */
    {
        locked = 0;
    }
}

/* De fyra funktionerna nedan returnerar v�rdena under customer, balance, pin och locked n�r de beh�vs... */
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
/* Provade med att s�tta ihop dessa och dela dom med ifar men utan lycka s� dom f�r vara en och en... */

/* H�r b�rjar sj�lva programmet med att man anger om man vill registrera, visa alla eller avsluta... */
void beginning()
{
    do
    {
        path = 0;
        topinterface();
        cout << "� "; COLOUR(YELLOW);cout << "Main menu:";COLOUR(WHITE);cout << "                                                                 �" << endl;
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

/* Denna k�rs n�r man anger att man vill skapa en ny kund... V�rdena skapas och sparas i deklarationer
inom denna funktion som sedan skickas till public i klassen... */
void newchoice()
{
    string statedssn, statedname;
    double stateddeposit, statedpin;
    
    path = 1;
    topinterface();
    cout << "� "; COLOUR(YELLOW);cout << "Registration of a new customer:";COLOUR(WHITE);cout << "                    �Social Security Number �" << endl;
    topedges();
    cout << "  "; COLOUR(YELLOW);cout << "STATE:" << endl;COLOUR(WHITE);
    cout << "  "; COLOUR(RED);cout << "------" << endl << endl;COLOUR(WHITE);
    cout << "  � SSN�:      "; COLOUR(GREEN);getline( cin, statedssn );COLOUR(WHITE);
    cout << "  � Name:      "; COLOUR(GREEN);getline( cin, statedname );COLOUR(WHITE);
    cout << "  � Deposit:   "; COLOUR(GREEN);cin >> stateddeposit; cin.ignore();COLOUR(WHITE);
    cout << "  � PIN:       "; COLOUR(GREEN);cin >> statedpin; cin.ignore();COLOUR(WHITE);
    stateddeposit = floor(stateddeposit);
    statedpin = floor(statedpin);
    number++;
    registeraccount( number, statedssn, statedname, stateddeposit, statedpin, status );
    bottomedges();
    bottominterface();

    path = 11;
    topinterface();
    cout << "� "; COLOUR(YELLOW);cout << "Confirmation of the registered customer:";COLOUR(WHITE);cout << "           �Social Security Number �" << endl;
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
    cout << "� "; COLOUR(YELLOW);cout << "List of all current customers:";COLOUR(WHITE);cout << "                     �Social Security Number �" << endl;
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
        /* Denna if kollar om en client st�mmer �verrens med kundnr och kollar sedan om kontot �r l�st,
        �r den det visas lockedinterface... */
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
            cout << "� "; COLOUR(YELLOW);cout << "List of all current customers:";COLOUR(WHITE);cout << "                     �Social Security Number �" << endl;
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

/* Var tvungen att stoppa valm�jligheterna f�r varje kund under en egen funktion f�r att kunna �terkomma
till denna punkt ifall man har gjort en ins�ttning eller uttag... */
void clientoptions()
{
    topinterface();
    cout << "� "; COLOUR(YELLOW);cout << "Customer:";COLOUR(WHITE);cout << "                                                                  �" << endl;
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

/* Funktionen g�r det m�jligt att ange vad man vill s�tta in, +tal ger ett resultat, -tal ger ett
annat och 0 g�r tillbaka... */
void depositchoice()
{
    path = 212;
    topinterface();
    cout << "� "; COLOUR(YELLOW);cout << "Registrating customer Deposit:";COLOUR(WHITE);cout << "                                             �" << endl;
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

/* H�r s� registreras uttag, +tal tar ut, -tal fr�gar om man gick r�tt och 0 g�r tillbaka... */
void withdrawalchoice()
{
    path = 213;
    topinterface();
    cout << "� "; COLOUR(YELLOW);cout << "Registrating customer Withdrawal:";COLOUR(WHITE);cout << "                                          �" << endl;
    topedges();
    if( information[client-1].balancevalue() == 0 )
    {
        impossible();

        listchoice();
    }
    cout << "  PIN: "; COLOUR(GREEN);cin >> value; cin.ignore();COLOUR(WHITE);
    cout << endl;
    
    /* Dock innan man kan ta ut m�ste man ange pin, annars kan vem som helst ta ut pengar... */
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

/* Anger man r�tt h�nder detta, dessutom f�r man olika meddelanden beroende p� +tal, -tal eller 0... */
void correctpin()
{
    topinterface();
    cout << "� "; COLOUR(YELLOW);cout << "Registrating customer Withdrawal:";COLOUR(WHITE);cout << "                                          �" << endl;
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
    if( value > 0 ) /* Vet inte varf�r jag var tvungen att stoppa under tv� ifar, resultatet blev inte bra med ('if' && 'if')... */
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

/* Anger man dock fel pin s� h�nder detta, anger man tre g�nger s� l�ser sig kontot och under visa alla
s� ser man tydligt vilket som har l�sts... */
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
            /* Denna if g�r att ett konto blir l�st... den skickar v�rdet 0 till private medlemmen locked... */
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
