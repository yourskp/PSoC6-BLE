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

#define CY_REG_CM0P_SCS_MPU_TYPE    (*(uint32 *)0xe000ed90u)
#define CY_REG_CM0P_SCS_MPU_CTRL    (*(uint32 *)0xe000ed94u)
#define CY_REG_CM0P_SCS_MPU_RNR     (*(uint32 *)0xe000ed98u)
#define CY_REG_CM0P_SCS_MPU_RBAR    (*(uint32 *)0xe000ed9Cu)
#define CY_REG_CM0P_SCS_MPU_RASR    (*(uint32 *)0xe000eda0u)

uint32 *pointer;
uint32 value;
uint32 value2;

int main(void)
{
    uint8 index;
    
    __enable_irq(); /* Enable global interrupts. */

    pointer = 0x00000000;
    
    value = *pointer;
    
    EnableNullPointerProtection();
    
    /* Enable CM4.  CY_CORTEX_M4_APPL_ADDR must be updated if CM4 memory layout is changed. */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR);
    
    Cy_SysLib_Delay(1000);

    value2 = *pointer;
    
    for(;;)
    {
        Cy_GPIO_Inv(Green_0);
        Cy_SysLib_Delay(500);
    }
}

/* [] END OF FILE */
