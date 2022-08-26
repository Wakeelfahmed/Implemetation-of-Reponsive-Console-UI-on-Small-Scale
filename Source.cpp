#include<iostream>
#include <windows.h>
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
        // Message_legth_Correction = (Message.size() / 2) - 2;     //monitor Center lign
        Message_legth_Correction = (Message.size() / 2) -1;     // Center Align
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
}


