#include<iostream>
#include <windows.h>
//_CRT_SECURE_NO_WARNINGS
using namespace std;
COORD UI_NEW, UI_OLD, UI_temp;
HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
void get_console_sz()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    UI_OLD = UI_NEW;
    UI_NEW.X = csbi.srWindow.Bottom - csbi.srWindow.Top; //x  hori
    UI_NEW.Y = csbi.srWindow.Right - csbi.srWindow.Left;   //y vertical

    if (UI_NEW.Y !=  UI_OLD.Y || UI_NEW.X != UI_OLD.X) {
       
        system("CLS");
        SetConsoleCursorPosition(Console, { 0,1 });
            cout << UI_NEW.Y;
      //  for (int i = 0; i < 9000000; i++){ }
    }
    if (UI_NEW.Y % 2 == 1)
    {
      //  UI_NEW.Y += 1;
    }
}
void Print_Center_Aligned(string Message) {
    int Message_Newlegth = Message.size();
    int Message_legth_Correction = Message.size();
    if (Message.size() % 2 == 1) {
        Message_legth_Correction = (Message.size() / 2);
        // cout << short(Message_Newlegth/2);
    }
    else{
        // Message_legth_Correction = (Message.size() / 2) - 2;     //TOSHIBA Center Align
        Message_legth_Correction = (Message.size() / 2) -1;     //TOSHIBA Center Align
    }
        //Message_legth_Correction = Message_Newlegth/2;
   // Message_legth_Correction;
        SetConsoleCursorPosition(Console, { short(UI_NEW.Y / 2 - Message_legth_Correction) , 0 });
        cout << Message;
}
int main() {
    string Message = "BUY CAR";
    cout << "Lenght of String is : " << Message.size() << endl;   //  5 / 2 = 2.5
    cout << Message.size() / 2;
    for (size_t i = 0; i < 900000; i++) {}
    while (1) {
        get_console_sz();
        Print_Center_Aligned(Message);
    }
/*
    while (1)
    {
        // SetConsoleCursorPosition(Console, { 0,0 });
        get_console_sz(&myvar);
   //     cout << myvar.cols;

        char s[] = "hello world";
        printf("%*s\n", strlen(s) + ((myvar.cols+2) - strlen(s)) / 2, s);

    }/*_dupenv_s  */
    //int columns = strtol(getenv("COLUMNS"), NULL, 10);
   // int fwidth = strlen(s) + (columns - strlen(s)) / 2;
    //printf("%*s\n", fwidth, s);
    /*char* mytext = "hello, world!";
    int x, y;
    getmaxyx(stdscr, y, x);
    mvaddstr(stdscr, y / 2, (x / 2) - (strlen(mytext) / 2)), mytext);*/
}


