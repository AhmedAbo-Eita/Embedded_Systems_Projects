//#############################################################################
//
// FILE:   empty_bitfield_driverlib_main.c
//
// TITLE:  Empty Example
//
// Empty Bit-Field & Driverlib Example
//
// This example is an empty project setup for Bit-Field and Driverlib 
// development.
//
//#############################################################################
//
// 
// $Copyright:
// Copyright (C) 2013-2024 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//

#include "F28x_Project.h"

//MACROS
#define OUTPUT      1
#define INPUT       0
#define SetPin      1
#define ClearPin    1

//
// Main
//
void main(void)
{
    //Initialization the system 
    InitSysCtrl();

    //Initialization GPIO pins 
    EALLOW;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 =       0;      // Set the pin as GPIO31 pin
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 =       0;      // Set the pin as GPIO31 pin
    GpioCtrlRegs.GPBGMUX1.bit.GPIO34 =      0;      // Set the pin as GPIO31 pin

    // set direction
    GpioCtrlRegs.GPADIR.bit.GPIO31 =        OUTPUT; // Set the GPIO31 pin as output pin
    GpioCtrlRegs.GPADIR.bit.GPIO16 =        INPUT; // Set the GPIO16 pin as input pin
    GpioCtrlRegs.GPBDIR.bit.GPIO34 =        OUTPUT; // Set the GPIO34 pin as output pin
    EDIS;
    
    //Manage the state of GPIO pins 
    //set GPIO31 and GPIO34
    GpioDataRegs.GPBCLEAR.bit.GPIO34 =       ClearPin;

    while(1)
    {
        // in case of the button is pushed the led will light up
        if(GpioDataRegs.GPADAT.bit.GPIO16 == 1)
        {
            GpioDataRegs.GPACLEAR.bit.GPIO31 = ClearPin; // turn the led on
        }
        else
        {
            GpioDataRegs.GPASET.bit.GPIO31 = SetPin; // turn the led off
        }
    }
}

//
// End of File
//
