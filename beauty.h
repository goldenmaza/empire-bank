#ifndef BEAUTY_H_
#define BEAUTY_H_

/* COLOUR v�rden anv�nds f�r att ge f�nstret ett b�ttre utseende och det g�r att man ser b�ttre helt enkelt... */
#define COLOUR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
#define WHITE   15
#define YELLOW  14
#define GREEN   10
#define	RED     12

using namespace std;

/* Deklarationer av funktioner f�r utseendet... */
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

/* Dessa tio funktioner ger utseendet till programmet, utan dessa skulle det endast bli tr�kig text,
dessutom anv�nder jag dessa �n att skriva samma sak flera g�nger... */
void topinterface()
{
    system("CLS");
    cout << "����������������������������������������������������������������������������ͻ" << endl;
    paths();
    cout << "� The Empire Terminal � ID#: 13256982                                        �" << endl;
    cout << "�                                                                            �" << endl;
}

void topedges()
{
    cout << "�----------------------------------------------------------------------------�" << endl;
    cout << "�\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/�" << endl << endl;
}

void bottomedges()
{
    cout << endl;
    cout << "�/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\�" << endl;
    cout << "�----------------------------------------------------------------------------�" << endl;
}

void bottominterface()
{
    cout << "�                                                                            �" << endl;
    cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
    cout << "  ";
    system("PAUSE");
}

void choicebottominterface()
{
    cout << "�                                                                            �" << endl;
    cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
    cout << "  I choose: "; COLOUR(GREEN);cin >> choice; cin.ignore();COLOUR(WHITE);
    choice = floor(choice);
    cout << endl;
    cout << "  ";
}

void clientbottominterface()
{
    cout << "�                                                                            �" << endl;
    cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
    cout << "  I choose customer ( 0 returns to main menu ): "; COLOUR(GREEN);cin >> client; cin.ignore();COLOUR(WHITE);
    cout << endl;
    cout << "  ";
}

void presskeyinterface()
{
    system("CLS");
    cout << "����������������������������������������������������������������������������ͻ"<< endl;
    cout << "�                                                                            �" << endl;
    cout << "� Anubis Empire - Empire Bank Terminal �                                     �" << endl;
    cout << "�                                                                            �" << endl;
    cout << "� "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 �" << endl;
    cout << "�----------------------------------------------------------------------------�" << endl;
    cout << "�\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/�" << endl;
    cout << "�----------------------------------------------------------------------------�" << endl;
    cout << "�                                                                            �" << endl;
    cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
    cout << "  ";
    system("PAUSE");          
}

void lockedinterface()
{
    path = 4;
    system("CLS");
    cout << "����������������������������������������������������������������������������ͻ"<< endl;
    paths();
    cout << "� The Empire Terminal ID#: 13256982                                          �" << endl;
    cout << "�                                                                            �" << endl;
    cout << "� "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 �" << endl;
    cout << "�----------------------------------------------------------------------------�" << endl;
    cout << "�\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/�" << endl;
    cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
    cout << "� ��  ��                                                              ��  �� �" << endl;
    cout << "� ��      I'm sorry, this account has been"; COLOUR(RED);cout << " LOCKED"; COLOUR(WHITE);cout << "...  If you are the      �� �" << endl;
    cout << "� ��         owner, you will be"; COLOUR(GREEN);cout << " contacted"; COLOUR(WHITE);cout << " shortley, if you aren't         �� �" << endl;
    cout << "� ��  ��                you will be"; COLOUR(RED);cout << " arrested"; COLOUR(WHITE);cout << " shortley!                ��  �� �" << endl;
    cout << "� ��  ��  ��  ��  ��                                      ��  ��  ��  ��  �� �" << endl;
    cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
    cout << "�/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\�" << endl;
    cout << "�----------------------------------------------------------------------------�" << endl;
    cout << "�                                                                            �" << endl;
    cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
    cout << "  ";
    system("PAUSE");
}

void impossible()
{
    if( path == 213 )
    {
        path == 4;
        system("CLS");
        cout << "����������������������������������������������������������������������������ͻ"<< endl;
        paths();
        cout << "� The Empire Terminal ID#: 13256982                                          �" << endl;
        cout << "�                                                                            �" << endl;
        cout << "� "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 �" << endl;
        cout << "�----------------------------------------------------------------------------�" << endl;
        cout << "�\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/�" << endl;
        cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
        cout << "� ��  ��  ��                                                      ��  ��  �� �" << endl;
        cout << "� ��  ��       The withdrawal wouldn't be possible, since your        ��  �� �" << endl;
        cout << "� ��  ��                account has the balance of";COLOUR(GREEN);cout << " 0";COLOUR(WHITE);cout << "..                ��  �� �" << endl;
        cout << "� ��  ��  ��                                                      ��  ��  �� �" << endl;
        cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
        cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
        cout << "�/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\�" << endl;
        cout << "�----------------------------------------------------------------------------�" << endl;
        cout << "�                                                                            �" << endl;
        cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
        cout << "  ";
        system("PAUSE");
    }
    else
    if( path == 4 )
    {
        system("CLS");
        cout << "����������������������������������������������������������������������������ͻ"<< endl;
        paths();
        cout << "� The Empire Terminal ID#: 13256982                                          �" << endl;
        cout << "�                                                                            �" << endl;
        cout << "� "; COLOUR(YELLOW);cout << "Press a key to continue..."; COLOUR(WHITE);cout << "                                                 �" << endl;
        cout << "�----------------------------------------------------------------------------�" << endl;
        cout << "�\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/�" << endl;
        cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
        cout << "� ��  ��  ��                                                      ��  ��  �� �" << endl;
        cout << "� ��  ��     You've stated an alternative that is not possible...     ��  �� �" << endl;
        cout << "� ��  ��       Only the available possibilities are 1, 2 and 3.       ��  �� �" << endl;
        cout << "� ��  ��  ��                                                      ��  ��  �� �" << endl;
        cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
        cout << "� ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  �� �" << endl;
        cout << "�/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\�" << endl;
        cout << "�----------------------------------------------------------------------------�" << endl;
        cout << "�                                                                            �" << endl;
        cout << "����������������������������������������������������������������������������ͼ" << endl << endl;
        cout << "  ";
        system("PAUSE");
    }
}

/* Denna funktion visar i programmet VART man �r vid det speciella tillf�llet... */
void paths()
{
    if( path == 0 )
    {
        cout << "�                                                                       "; COLOUR(YELLOW);cout << "Main"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 1 )
    {
        cout << "�                                                                "; COLOUR(YELLOW);cout << "Main -> New"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 11 )
    {
        cout << "�                                                "; COLOUR(YELLOW);cout << "Main -> New -> Confirmation"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 2 )
    {
        cout << "�                                                               "; COLOUR(YELLOW);cout << "Main -> List"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 20 )
    {
        cout << "�                                                      "; COLOUR(YELLOW);cout << "Main -> List -> Empty"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 21 )
    {
        cout << "�                                                    "; COLOUR(YELLOW);cout << "Main -> List -> Current"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 211 )
    {
        cout << "�                                          "; COLOUR(YELLOW);cout << "Main -> List -> Current -> Locked"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 212 )
    {
        cout << "�                                         "; COLOUR(YELLOW);cout << "Main -> List -> Current -> Deposit"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 213 )
    {
        cout << "�                                      "; COLOUR(YELLOW);cout << "Main -> List -> Current -> Withdrawal"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 3 )
    {
        cout << "�                                                     "; COLOUR(YELLOW);cout << "Program -> Information"; COLOUR(WHITE);cout << " �" << endl;
    }
    else
    if( path == 4 )
    {
        cout << "�                                               "; COLOUR(YELLOW);cout << "Program -> Impossible action"; COLOUR(WHITE);cout << " �" << endl;
    }
}

#endif
