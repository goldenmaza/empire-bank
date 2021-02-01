#ifndef CLASS_H_
#define CLASS_H_

using namespace std;

/* Storleken p� classen, dvs antalet kunder - i detta fall - som kan sparas... */
const int size = 13;

/* Sj�lva klassen, Account, vilket inneh�ller kundnr, personnummer, namn, saldo, pinkod och om kontot �r l�st under private...*/
/* Under public har vi add (vilket l�gger till en ny kund), update (vilket �ndrar ett v�rde), view som visar v�rdena och fyra return funktioner... */
class Account
{
    private:
        int customer;
        string ssn;
        string name;
        int balance;
        int pin;
        int locked;
    public:
        void add( int addcustomer, string addssn, string addname, int addbalance, int addpin, int addlocked );
        void update( int value );
        void view();
        int customervalue();
        int balancevalue();
        int pinvalue();
        int lockedvalue();
};
Account information[size];

#endif
