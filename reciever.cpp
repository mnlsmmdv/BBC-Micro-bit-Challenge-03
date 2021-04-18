/////////////////////////////////////////////////////////////////////////////////////////////////
//File Name: reciever.cpp                                                                      //
//File Type: .cpp                                                                              //
//Language: C++                                                                                //
//Size: -                                                                                      //
//Authors: Ahmed Affaan, Ahmed Ahsan Azim                                                      //
//Country: Republic of Maldives                                                                //
//Email: mnlsmmdv13@protonmail.com , ahsanazim34@gmail.com                                     //
//GitHub/GitLab: https://github.com/mnlsmmdv13 , https://gitlab.uwe.ac.uk/aa2-azim             //
//Last Modified:                                                                               //
//Description: BBC Micro:bit Challenge 03 Morse Code Reciever                                  //
//Advice: -                                                                                    //
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "MicroBit.h"

MicroBit uBit;
void Data();

/*
 * Function: Data
 * Parameters: N/A
 * Description: Code to handle the received data from Sender and the display it on Reciever
 */
void Data(MicroBitEvent e)
{
    //Takes data sent from Sender and stores it in a variable
    ManagedString dataFromSender = uBit.radio.datagram.recv();

    //If-statement issued to display correct corossponding values
    if (dataFromSender == "1")
    {
        uBit.display.print(".");
    }
    else if (dataFromSender == "2")
    {
        uBit.display.print("-");
    }

    //Delay duration given for the Micro:bit to go to sleep
    uBit.sleep(500);
    //Clears the screen after delay is done
    uBit.display.clear();
}

//BBC Micro:bit Main function
int main()
{
    //BBC Micro:bit runtime initialised
    uBit.init();
    //Micro:bit will listen to any of the physical functions on it are used
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, Data);
    uBit.radio.enable(); //Enables the radio function in Micro:bit

    //While-loop issued to keep the Micro:bit running
    while (1)
    {
        uBit.sleep(1000);
    }
}
