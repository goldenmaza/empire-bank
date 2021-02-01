#ifndef INFO_H_
#define INFO_H_

/* COLOUR värden används för att ge fönstret ett bättre utseende och det gör att man ser bättre helt enkelt... */
#define COLOUR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
#define WHITE   15
#define YELLOW  14
#define GREEN   10
#define	RED     12

using namespace std;

void viewinfo();

/* Informationen satt i sin egen h fil så det blir enklare vid redigering för framtiden... */
void viewinfo()
{
    path = 3;
    /* Meny översikt och översikten över informationen... */
    system("CLS");
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Information Section:"; COLOUR(WHITE);cout << "                                                       º" << endl;
    topedges();
    cout << "  This section contains alot of information on how to use this program:\n\n  "; COLOUR(RED);cout << "---" << endl << endl;COLOUR(WHITE);
    cout << "     1. Main Menu\n\n        1. Register new customer\n\n           1. SSN\n           2. Name\n           3. Initial Deposit\n           4. PIN\n\n        2. View all customers\n\n           1. Choose a customer\n\n              1. Account information\n              2. Deposit money\n              3. Withdrawal money\n\n  ";COLOUR(RED);cout << "=>";COLOUR(WHITE);cout << "    3. ";COLOUR(YELLOW);cout << "Information about program\n\n  ";COLOUR(RED);cout << "---" << endl;COLOUR(WHITE);
    bottomedges();
    bottominterface();

    /* Informationen över första delen av programmet: Registrering... */
    system("CLS");
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Information Section:                       û";COLOUR(WHITE);cout << "VIP is different from our VIP! º" << endl;
    topedges();
    cout << "  Detailed information about:\n\n  "; COLOUR(RED);cout << "---" << endl << endl;COLOUR(WHITE);
    cout << "     1. Main Menu\n\n  ";COLOUR(RED);cout << "=>";COLOUR(WHITE);cout << "    1. ";COLOUR(YELLOW);cout << "Register new customer";COLOUR(WHITE);cout << "\n\n           1. SSN\n           2. Name\n           3. Initial Deposit\n           4. PIN\n\n  ";COLOUR(RED);cout << "---" << endl << endl;COLOUR(WHITE);
    cout << "  We have the main menu which you have already seen and used. The choice\n  of registering and becoming a customer in our bank is just the first step.\n     The Empire Bank is the only bank you'll ever need, we have the best\n  interest rates, the lowest fees and the lowest recorded time for\n  waiting-in-line and that is just the tip of the ice berg." << endl << endl;
    cout << "  When registering a new account you will not only be a part of something\n  important for your community but also you will have to state four important\n  information: "; COLOUR(GREEN);cout << "SSN";COLOUR(WHITE);cout << ", ";COLOUR(GREEN);cout << "Name";COLOUR(WHITE);cout << ", ";COLOUR(GREEN);cout << "Initial Deposit";COLOUR(WHITE);cout << " and the ";COLOUR(GREEN);cout << "PIN.\n     "; COLOUR(WHITE);cout << "The "; COLOUR(GREEN);cout << "SSN";COLOUR(WHITE); cout << " is the social security number which can registered as\n  fallows: 000000-0000 (example: 500513-2332). The ";COLOUR(GREEN);cout << "Name";COLOUR(WHITE); cout << " can be written as\n  fallows: Steve Carter. "; COLOUR(GREEN);cout << "Initial Deposit";COLOUR(WHITE); cout << " is how much you would like to deposit,\n  your first time, into our bank (by stating '0' you will finish the\n  registration, incase you are gonna deposit later). The "; COLOUR(GREEN);cout << "PIN";COLOUR(WHITE); cout << " is the code you\n  would like to use for accessing your account and is needed to register\n  withdrawals (example: 2582 or 698251318)." << endl << endl;
    cout << "  After doing those simple steps you are a customer in our bank. If you are\n  interested in our special offers and becoming an influential customer,\n  contact customer service and your account will be upgraded to "; COLOUR(GREEN);cout << "IP (ImPortant)"; COLOUR(WHITE); cout << "\n  status and have more posibilities of creating a stable economy. As an example\n  you'll need to be an IP customer if you would like to take a bankloan or take\n  part of any of the other IP features as detailed by customer service. "; COLOUR(RED);cout << "VIP\n  (VeryImPortant)";COLOUR(YELLOW);cout << "û";COLOUR(WHITE);cout << " status however give you even more chances and posibilities\n  of having a great economy. Close to no fees, access to secluded areas\n  and so much more..." << endl;
    cout << "     ";COLOUR(GREEN);cout << "Customers";COLOUR(WHITE);cout << ", ";COLOUR(YELLOW);cout << "IP Customers";COLOUR(WHITE);cout << " and "; COLOUR(RED);cout << "VIP Customers";COLOUR(WHITE);cout << " all have different security\n  levels, which means that in this terminal only customers with the lowest\n  security level are shown, contact customer service for an upgrade.\n     ";COLOUR(RED);cout << "VIP Customers";COLOUR(WHITE);cout << " get the opportunity to have their OWN terminal at a location\n  of their choosing, which can be programmed so it will suit the customer's\n  needs and are also fitted with news and other important information about\n  the world's past, present and future history..." << endl;
    bottomedges();
    bottominterface();

    /* Informationen över andra delen av programmet: Visning av alla kunder... */
    system("CLS");
    topinterface();
    cout << "º "; COLOUR(YELLOW);cout << "Information Section:"; COLOUR(WHITE);cout << "                                                       º" << endl;
    topedges();
    cout << "  Detailed information about:\n\n  "; COLOUR(RED);cout << "---" << endl << endl;COLOUR(WHITE);
    cout << "     1. Main Menu\n\n        1. Register new customer\n\n  ";COLOUR(RED);cout << "=>";COLOUR(WHITE);cout << "    2. ";COLOUR(YELLOW);cout << "View all customers";COLOUR(WHITE);cout << "\n\n           1. Choose a customer\n\n              1. Account information\n              2. Deposit money\n              3. Withdrawal money\n\n  ";COLOUR(RED);cout << "---" << endl << endl;COLOUR(WHITE);
    cout << "  You can view all customers of your security level (or as programmed or as\n  desired by customer). You can choose a customer by stating the Customer nr.\n  You can always deposit money on your own account or onto someone elses,\n  though without the PIN you can ONLY take out money with the code. Because of\n  that it's VERY important that you state a ";COLOUR(GREEN);cout << "PIN";COLOUR(WHITE);cout << " number that isn't too easy\n  to figure out.\n     For ";COLOUR(YELLOW);cout << "IP";COLOUR(WHITE);cout << " and ";COLOUR(RED);cout << "VIP";COLOUR(WHITE);cout << " customers you will be given a security code that will be\n  sent to your mobile phone and the terminal will be asking for a fingerprint\n  scan for extra security." << endl << endl;
    cout << "  Account information tells about the customer (obviously not the PIN) and\n  there is a fourth detail that is important. The ";COLOUR(RED);cout << "Locked";COLOUR(WHITE);cout << " feature, it tells you\n  if your account has been locked. Locked: YES! means it's locked and can't be\n  accessed without customer service.\n     Deposit money will let you in add money into our bank that can be taken\n  out on any of our 25 million terminals around the globe.\n     Withdrawal money will let you take out money on any of our terminals\n  around the globe. Here you will have to state a ";COLOUR(GREEN);cout << "PIN";COLOUR(WHITE);cout << " code incase you wanna\n  proceed - as a security measure. Contact customer service incase you want\n  to implement a second PIN code for access (higher security levels ask\n  for more identification)." << endl;
    bottomedges();
    bottominterface();
}

#endif
