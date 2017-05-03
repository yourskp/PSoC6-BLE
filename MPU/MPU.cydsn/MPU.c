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

#define CY_REG_CM0P_SCS_MPU_TYPE    (*(uint32 *)0xe000ed90u)
#define CY_REG_CM0P_SCS_MPU_CTRL    (*(uint32 *)0xe000ed94u)
#define CY_REG_CM0P_SCS_MPU_RNR     (*(uint32 *)0xe000ed98u)
#define CY_REG_CM0P_SCS_MPU_RBAR    (*(uint32 *)0xe000ed9Cu)
#define CY_REG_CM0P_SCS_MPU_RASR    (*(uint32 *)0xe000eda0u)

void EnableNullPointerProtection(void)
{
    CY_REG_CM0P_SCS_MPU_RNR =  0x0000000; /* Set the region to 0 */
    CY_REG_CM0P_SCS_MPU_RBAR = 0x00000000; /* Address is zero, which points to ROM */
    CY_REG_CM0P_SCS_MPU_RASR = 0x00000001 |  /* Enable MPU */
                                (0x00000007 << 1) |  /* Size is set to 2^(7+1) = 256B */
                                (0x000000FE << 8) |  /* First sub region is enabled - First 32 bytes of SROM*/
                                (0x00000001 << 18) | /* Sharable = 1 */
                                (0x00000001 << 19) | /* TEX = 001 */
                                (0x00000000 << 24) | /* No access, Cachable (C) & Bufferable (B) are all zero */
                                (0x00000001 << 28);  /* Execute Never (XN) is 1 */;  
    CY_REG_CM0P_SCS_MPU_CTRL = 0x00000004; /* PRIVDEFENA = 1*/
    CY_REG_CM0P_SCS_MPU_CTRL |= 0x00000001; /* ENABLE = 1*/
    //CY_REG_CM0P_SCS_MPU_CTRL |= 0x00000002; /* HFNMIENA = 1*/
}

/* [] END OF FILE */
