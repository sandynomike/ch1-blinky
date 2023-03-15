//  Challenge 1, Blinky
//  Mike Shegedin, 03/2023
//
//  Hardware Setup:
//  ===============
//  Only uses LED on GPIO Port C Pin 13, which is built into the Blue Pill.

//  Software Setup:
//  ===============
//  Steps to Set Up GPIO Port C, Pin 13:
//  1. Enable GPIO Port C in the RCC APB2ENR register.
//  2. Set the configuration and mode of the GPIO pin by setting the CNF[1:0] and MODE[1:0]
//     bits for Pin C13 to function as output, push-pull, 2 MHz.
//     Since this is pin 13, the relevant register is the GPIOC CRH register (Configuration
//     Register High). The bit settings are as follows:
//         CNF13[1:0] = 0b00 for general purpose output, push-pull
//        MODE13[1:0] = 0b10 for output mode, max speed of 2 MHz

#include "stm32f103xb.h"

int
main( void )
{
    // Enable GPIO Port C
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // CNF13[1:0] = 0b00 (General purpose output, push-pull)
    // Clear CNF13[1:0]
    // Note that the default state of CNFxx[1:0] = 0b01, so the 0-bit must be cleared.
    GPIOC->CRH &= ~GPIO_CRH_CNF13_Msk;  // This clears both bits of CNF13

    // Set MODE13[1:0] to 0b10 (Output mode, 2 MHz)
    GPIOC->CRH |= GPIO_CRH_MODE13_1;          // This sets bit 1 of MODE13

    while( 1 )                                // Endless loop to flash LED
    {
        GPIOC->ODR ^= GPIO_ODR_ODR13;         // Flip pin C13
        for( uint32_t x = 0; x<3.3e5; x++ )   // Wait approx. a half second.
        {                                     // Empty for-loop is probably
        }                                     // 12 cycles per iteration of the loop.
    }
} // End main.c
