/////////////////////////////////////////////////////////////////////////////////////////////////
//File Name: sender.cpp                                                                        //
//File Type: .cpp                                                                              //
//Language: C++                                                                                //
//Size: -                                                                                      //
//Authors: Ahmed Affaan, Ahmed Ahsan Azim                                                      //
//Country: Republic of Maldives                                                                //
//Email: mnlsmmdv13@protonmail.com , ahsanazim34@gmail.com                                     //
//GitHub/GitLab: https://github.com/mnlsmmdv13 , https://gitlab.uwe.ac.uk/aa2-azim             //
//Last Modified:                                                                               //
//Description: BBC Micro:bit Challenge 03 Morse Code Sender                                    //
//Advice: -                                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "MicroBit.h"

MicroBit uBit;

//Buttons
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);

void Send();

/*
 * Function: Send
 * Parameters: N/A
 * Description: Sends 1 and Displays "." when button A is pressed Sends 2 and Displays "-" when Button B is pressed
 */
void Send()
{
    //if statements checks button press, sends data and displays that data on display
    if (uBit.buttonA.isPressed())
    {
        uBit.radio.datagram.send("1");
        uBit.display.print(".");
    }

    else if (uBit.buttonB.isPressed())
    {
        uBit.radio.datagram.send("2");
        uBit.display.print("-");
    }

    uBit.sleep(500);
    uBit.display.clear();
}

int main()
{
    uBit.init();         //initialise microbit at runtime
    uBit.radio.enable(); //enable radio in microbit

    while (1)
    {
        Send(); //call
    }
}
