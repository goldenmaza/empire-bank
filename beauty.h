#ifndef BEAUTY_H_
#define BEAUTY_H_

/* COLOUR vไrden anvไnds f๖r att ge f๖nstret ett bไttre utseende och det g๖r att man ser bไttre helt enkelt... */
#define COLOUR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
#define WHITE   15
#define YELLOW  14
#define GREEN   10
#define	RED     12

using namespace std;

/* Deklarationer av funktioner f๖r utseendet... */
void topinterface();
void topedges();
void bottomedges();
void bottominterface();
void choicebottominterface();
void clientbottominterface();
void presskeyinterface();
void lockedinterface();
void impossible();
void paths();

/* Dessa tio funktioner ger utseendet till programmet, utan dessa skulle det endast bli trๅkig text,
dessutom anvไnder jag dessa ไn att skriva samma sak flera gๅnger... */
void topinterface()
{
    system("CLS");
    cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป" << endl;
    paths();
    cout << "บ The Empire Terminal ธ ID#: 13256982                                        บ" << endl;
    cout << "บ                                                                            บ" << endl;
}

void topedges()
{
    cout << "บ----------------------------------------------------------------------------บ" << endl;
    cout << "ศ\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/ผ" << endl << endl;
}

void bottomedges()
{
    cout << endl;
    cout << "ษ/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ป" << endl;
    cout << "บ----------------------------------------------------------------------------บ" << endl;
}

void bottominterface()
{
    cout << "บ                                                                            บ" << endl;
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
    cout << "  ";
    system("PAUSE");
}

void choicebottominterface()
{
    cout << "บ                                                                            บ" << endl;
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
    cout << "  I choose: "; COLOUR(GREEN);cin >> choice; cin.ignore();COLOUR(WHITE);
    choice = floor(choice);
    cout << endl;
    cout << "  ";
}

void clientbottominterface()
{
    cout << "บ                                                                            บ" << endl;
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
    cout << "  I choose customer ( 0 returns to main menu ): "; COLOUR(GREEN);cin >> client; cin.ignore();COLOUR(WHITE);
    cout << endl;
    cout << "  ";
}

void presskeyinterface()
{
    system("CLS");
    cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<< endl;
    cout << "บ                                                                            บ" << endl;
    cout << "บ Anubis Empire - Empire Bank Terminal ธ                                     บ" << endl;
    cout << "บ                                                                            บ" << endl;
    cout << "บ "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 บ" << endl;
    cout << "บ----------------------------------------------------------------------------บ" << endl;
    cout << "บ\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/บ" << endl;
    cout << "บ----------------------------------------------------------------------------บ" << endl;
    cout << "บ                                                                            บ" << endl;
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
    cout << "  ";
    system("PAUSE");          
}

void lockedinterface()
{
    path = 4;
    system("CLS");
    cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<< endl;
    paths();
    cout << "บ The Empire Terminal ID#: 13256982                                          บ" << endl;
    cout << "บ                                                                            บ" << endl;
    cout << "บ "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 บ" << endl;
    cout << "บ----------------------------------------------------------------------------บ" << endl;
    cout << "บ\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/บ" << endl;
    cout << "บ ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ บ" << endl;
    cout << "บ ณณ  ณณ                                                              ณณ  ณณ บ" << endl;
    cout << "บ ณณ      I'm sorry, this account has been"; COLOUR(RED);cout << " LOCKED"; COLOUR(WHITE);cout << "...  If you are the      ณณ บ" << endl;
    cout << "บ ณณ         owner, you will be"; COLOUR(GREEN);cout << " contacted"; COLOUR(WHITE);cout << " shortley, if you aren't         ณณ บ" << endl;
    cout << "บ ณณ  ณณ                you will be"; COLOUR(RED);cout << " arrested"; COLOUR(WHITE);cout << " shortley!                ณณ  ณณ บ" << endl;
    cout << "บ ณณ  ณณ  ณณ  ณณ  ณณ                                      ณณ  ณณ  ณณ  ณณ  ณณ บ" << endl;
    cout << "บ ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ  ณณ บ" << endl;
    cout << "บ/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\บ" << endl;
    cout << "บ----------------------------------------------------------------------------บ" << endl;
    cout << "บ                                                                            บ" << endl;
    cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
    cout << "  ";
    system("PAUSE");
}

void impossible()
{
    if( path == 213 )
    {
        path == 4;
        system("CLS");
        cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<< endl;
        paths();
        cout << "บ The Empire Terminal ID#: 13256982                                          บ" << endl;
        cout << "บ                                                                            บ" << endl;
        cout << "บ "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 บ" << endl;
        cout << "บ----------------------------------------------------------------------------บ" << endl;
        cout << "บ\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ                                                      ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ       The withdrawal wouldn't be possible, since your        ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ                account has the balance of";COLOUR(GREEN);cout << " 0";COLOUR(WHITE);cout << "..                ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ                                                      ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\บ" << endl;
        cout << "บ----------------------------------------------------------------------------บ" << endl;
        cout << "บ                                                                            บ" << endl;
        cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
        cout << "  ";
        system("PAUSE");
    }
    else
    if( path == 4 )
    {
        system("CLS");
        cout << "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<< endl;
        paths();
        cout << "บ The Empire Terminal ID#: 13256982                                          บ" << endl;
        cout << "บ                                                                            บ" << endl;
        cout << "บ "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 บ" << endl;
        cout << "บ----------------------------------------------------------------------------บ" << endl;
        cout << "บ\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ                                                      ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ     You've stated an alternative that is not possible...     ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ       Only the available possibilities are 1, 2 and 3.       ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ                                                      ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ  ฒฒ บ" << endl;
        cout << "บ/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\บ" << endl;
        cout << "บ----------------------------------------------------------------------------บ" << endl;
        cout << "บ                                                                            บ" << endl;
        cout << "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ" << endl << endl;
        cout << "  ";
        system("PAUSE");
    }
}

/* Denna funktion visar i programmet VART man ไr vid det speciella tillfไllet... */
void paths()
{
    if( path == 0 )
    {
        cout << "บ                                                                       "; COLOUR(YELLOW);cout << "Main"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 1 )
    {
        cout << "บ                                                                "; COLOUR(YELLOW);cout << "Main -> New"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 11 )
    {
        cout << "บ                                                "; COLOUR(YELLOW);cout << "Main -> New -> Confirmation"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 2 )
    {
        cout << "บ                                                               "; COLOUR(YELLOW);cout << "Main -> List"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 20 )
    {
        cout << "บ                                                      "; COLOUR(YELLOW);cout << "Main -> List -> Empty"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 21 )
    {
        cout << "บ                                                    "; COLOUR(YELLOW);cout << "Main -> List -> Current"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 211 )
    {
        cout << "บ                                          "; COLOUR(YELLOW);cout << "Main -> List -> Current -> Locked"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 212 )
    {
        cout << "บ                                         "; COLOUR(YELLOW);cout << "Main -> List -> Current -> Deposit"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 213 )
    {
        cout << "บ                                      "; COLOUR(YELLOW);cout << "Main -> List -> Current -> Withdrawal"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 3 )
    {
        cout << "บ                                                     "; COLOUR(YELLOW);cout << "Program -> Information"; COLOUR(WHITE);cout << " บ" << endl;
    }
    else
    if( path == 4 )
    {
        cout << "บ                                               "; COLOUR(YELLOW);cout << "Program -> Impossible action"; COLOUR(WHITE);cout << " บ" << endl;
    }
}

#endif
