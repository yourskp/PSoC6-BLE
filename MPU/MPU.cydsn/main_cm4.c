/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "MPU.h"

uint32 nullValue;
uint32 *nullPointer;

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    
    EnableNullPointerProtection();
    
    nullPointer = 0x00000000;
    nullValue = *nullPointer;
    
    for(;;)
    {
        Cy_GPIO_Inv(Red_0);
        Cy_SysLib_Delay(500);
    }
}

/* [] END OF FILE */
