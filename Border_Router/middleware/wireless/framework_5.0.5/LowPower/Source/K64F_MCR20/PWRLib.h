/*!
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* All rights reserved.
*
* \file PWRLib.h
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* o Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
*
* o Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
*
* o Neither the name of Freescale Semiconductor, Inc. nor the names of its
*   contributors may be used to endorse or promote products derived from this
*   software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#ifndef __PWR_LIB_H__
#define __PWR_LIB_H__

/*****************************************************************************
 *                               INCLUDED HEADERS                            *
 *---------------------------------------------------------------------------*
 * Add to this section all the headers that this module needs to include.    *
 * Note that it is not a good practice to include header files into header   *
 * files, so use this section only if there is no other better solution.     *
 *---------------------------------------------------------------------------*
 *****************************************************************************/

 #include "PWR_Interface.h"
 #include "board.h"
/*****************************************************************************
 *                             PUBLIC MACROS                                *
 *---------------------------------------------------------------------------*
 * Add to this section all the access macros, registers mappings, bit access *
 * macros, masks, flags etc ...
 *---------------------------------------------------------------------------*
 *****************************************************************************/


/*****************************************************************************
 *                             PRIVATE MACROS                                *
 *---------------------------------------------------------------------------*
 * Add to this section all the access macros, registers mappings, bit access *
 * macros, masks, flags etc ...
 *---------------------------------------------------------------------------*
 *****************************************************************************/

/* Definitions for LPTMR timer setup */
/* LPTMR prescaler clocking options */
#define cLPTMR_Source_Int_MCGIRCLK    0
#define cLPTMR_Source_Int_LPO_1KHz    1
#define cLPTMR_Source_Ext_ERCLK32K    2
#define cLPTMR_Source_Ext_OSCERCLK    3


/*****************************************************************************
 *                        PRIVATE TYPE DEFINITIONS                           *
 *---------------------------------------------------------------------------*
 * Add to this section all the data types definitions: stuctures, unions,    *
 * enumerations, typedefs ...                                                *
 *---------------------------------------------------------------------------*
 *****************************************************************************/
/* Constants defined for use with GetLLSWakeUpFlags method */
#define LLWU_EXT_PIN0                  0x1U  /* WakeUp caused by - External pin 0    */            
#define LLWU_EXT_PIN1                  0x2U  /* WakeUp caused by - External pin 1    */         
#define LLWU_EXT_PIN2                  0x4U  /* WakeUp caused by - External pin 2    */      
#define LLWU_EXT_PIN3                  0x8U  /* WakeUp caused by - External pin 3    */      
#define LLWU_EXT_PIN4                  0x10U /* WakeUp caused by - External pin 4    */   
#define LLWU_EXT_PIN5                  0x20U /* WakeUp caused by - External pin 5    */
#define LLWU_EXT_PIN6                  0x40U /* WakeUp caused by - External pin 6    */
#define LLWU_EXT_PIN7                  0x80U /* WakeUp caused by - External pin 7    */
#define LLWU_EXT_PIN8                  0x0100U /* WakeUp caused by - External pin 8  */
#define LLWU_EXT_PIN9                  0x0200U /* WakeUp caused by - External pin 9  */
#define LLWU_EXT_PIN10                 0x0400U /* WakeUp caused by - External pin 10 */
#define LLWU_EXT_PIN14                 0x4000U /* WakeUp caused by - External pin 14 */
#define LLWU_EXT_PIN15                 0x8000U /* WakeUp caused by - External pin 15 */
#define LLWU_INT_MODULE0               0x00010000U /* WakeUp caused by - Internal module 0 (LPTMR0) */
#define LLWU_INT_MODULE1               0x00020000U /* WakeUp caused by - Internal module 1 (CMP0) */
#define LLWU_INT_MODULE2               0x00040000U /* WakeUp caused by - Internal module 2 (BTLL) */
#define LLWU_INT_MODULE3               0x00080000U /* WakeUp caused by - Internal module 3 (DCDC) */
#define LLWU_INT_MODULE4               0x00100000U /* WakeUp caused by - Internal module 4 (TSI0) */
#define LLWU_INT_MODULE5               0x00200000U /* WakeUp caused by - Internal module 5 (RTC) */
#define LLWU_INT_MODULE7               0x00800000U /* WakeUp caused by - Internal module 7 (RTC_Seconds) */
#define LLWU_FILTER1                   0x01000000U /* WakeUp caused by digital filter 1 */
#define LLWU_FILTER2                   0x02000000U /* WakeUp caused by digital filter 2 */

#define  gPWRLib_LLWU_WakeupPin_PTE1_c    LLWU_EXT_PIN0
#define  gPWRLib_LLWU_WakeupPin_PTE2_c    LLWU_EXT_PIN1
#define  gPWRLib_LLWU_WakeupPin_PTE4_c    LLWU_EXT_PIN2
#define  gPWRLib_LLWU_WakeupPin_PTA4_c    LLWU_EXT_PIN3
#define  gPWRLib_LLWU_WakeupPin_PTA13_c   LLWU_EXT_PIN4
#define  gPWRLib_LLWU_WakeupPin_PTB0_c    LLWU_EXT_PIN5
#define  gPWRLib_LLWU_WakeupPin_PTC1_c    LLWU_EXT_PIN6
#define  gPWRLib_LLWU_WakeupPin_PTC3_c    LLWU_EXT_PIN7
#define  gPWRLib_LLWU_WakeupPin_PTC4_c    LLWU_EXT_PIN8
#define  gPWRLib_LLWU_WakeupPin_PTC5_c    LLWU_EXT_PIN9
#define  gPWRLib_LLWU_WakeupPin_PTC6_c    LLWU_EXT_PIN10
#define  gPWRLib_LLWU_WakeupPin_PTC11_c   LLWU_EXT_PIN11
#define  gPWRLib_LLWU_WakeupPin_PTD0_c    LLWU_EXT_PIN12
#define  gPWRLib_LLWU_WakeupPin_PTD2_c    LLWU_EXT_PIN13
#define  gPWRLib_LLWU_WakeupPin_PTD4_c    LLWU_EXT_PIN14
#define  gPWRLib_LLWU_WakeupPin_PTD6_c    LLWU_EXT_PIN15

#define    gPWRLib_LLWU_WakeupModuleFlag_LPTMR_c      LLWU_INT_MODULE0
#define    gPWRLib_LLWU_WakeupModuleFlag_CMP0_c       LLWU_INT_MODULE1
#define    gPWRLib_LLWU_WakeupModuleFlag_RTC_Alarm_c  LLWU_INT_MODULE5
     
#define  gPWRLib_LLWU_WakeupModuleEnable_LPTMR_c      (1<<0)
#define  gPWRLib_LLWU_WakeupModuleEnable_CMP0_c       (1<<1)
#define  gPWRLib_LLWU_WakeupModuleEnable_RTC_Alarm_c  (1<<4)   


/*****************************************************************************
 *                               PUBLIC VARIABLES(External)                  *
 *---------------------------------------------------------------------------*
 * Add to this section all the variables and constants that have global      *
 * (project) scope.                                                          *
 * These variables / constants can be accessed outside this module.          *
 * These variables / constants shall be preceded by the 'extern' keyword in  *
 * the interface header.                                                     *
 *---------------------------------------------------------------------------*
 *****************************************************************************/

/* Zigbee stack status */
extern PWRLib_StackPS_t PWRLib_StackPS;

/* For LVD function */

#if (cPWR_LVD_Enable == 2)
extern PWRLib_LVD_VoltageLevel_t PWRLib_LVD_SavedLevel;
#endif



/*****************************************************************************
 *                            PUBLIC FUNCTIONS                               *
 *---------------------------------------------------------------------------*
 * Add to this section all the global functions prototype preceded (as a     *
 * good practice) by the keyword 'extern'                                    *
 *---------------------------------------------------------------------------*
 *****************************************************************************/


/*---------------------------------------------------------------------------
 * Name: PWRLib_Radio_Enter_Doze
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_Radio_Enter_Doze
(
  void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_Radio_Enter_AutoDoze
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_Radio_Enter_AutoDoze
(
  void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_Radio_Enter_Idle
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_Radio_Enter_Idle
(
  void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_Radio_Enter_Hibernate
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_Radio_Enter_Hibernate
(
  void
);

void PWRLib_MCU_Enter_Sleep
(
  void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_MCUEnter_VLLS0
 * Description: Puts the processor into VLLS0 (Very Low Leakage Stop1).

                Mode of operation details:
                 - ARM core enters SleepDeep Mode
                 - ARM core is clock gated (HCLK = OFF)
                 - NVIC is disable (FCLK = OFF)
                 - LLWU should configure by user to enable the desire wake up source
                 - Platform and peripheral clock are stopped
                 - All SRAM powered off
                 - VLLS0 mode is exited into RUN mode using LLWU module or RESET.
                   All wakeup goes through Reset sequence.

                The AVLLS must be set to 0b1 in SMC_PMPROT register in order to allow VLLS mode.

 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_MCU_Enter_VLLS0
(
void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_MCUEnter_VLLS1
 * Description: Puts the processor into VLLS1 (Very Low Leakage Stop1).

                Mode of operation details:
                 - ARM core enters SleepDeep Mode
                 - ARM core is clock gated (HCLK = OFF)
                 - NVIC is disable (FCLK = OFF)
                 - LLWU should configure by user to enable the desire wake up source
                 - Platform and peripheral clock are stopped
                 - All SRAM powered off
                 - VLLS1 mode is exited into RUN mode using LLWU module or RESET.
                All wakeup goes through Reset sequence.

                The AVLLS must be set to 0b1 in MC_PMPROT register in order to allow VLLS mode.

 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_MCU_Enter_VLLS1
(
void
);
/*---------------------------------------------------------------------------
 * Name: PWRLib_MCUEnter_VLLS2
 * Description: Puts the processor into VLLS1 (Very Low Leakage Stop1).

                Mode of operation details:
                 - ARM core enters SleepDeep Mode
                 - ARM core is clock gated (HCLK = OFF)
                 - NVIC is disable (FCLK = OFF)
                 - LLWU should configure by user to enable the desire wake up source
                 - Platform and peripheral clock are stopped
                 - All SRAM powered off
                 - VLLS1 mode is exited into RUN mode using LLWU module or RESET.
                All wakeup goes through Reset sequence.

                The AVLLS must be set to 0b1 in MC_PMPROT register in order to allow VLLS mode.

 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_MCU_Enter_VLLS2
(
void
);
/*---------------------------------------------------------------------------
 * Name: PWRLib_MCUEnter_LLS3
 * Description: Puts the processor into LLS3 (Low Leakage Stop1).

                Mode of operation details:
                 - ARM core enters SleepDeep Mode
                 - ARM core is clock gated (HCLK = OFF)
                 - NVIC is disable (FCLK = OFF)
                 - LLWU should configure by user to enable the desire wake up source
                 - Platform and peripheral clock are stopped
                 - Full SRAM retention.               

                The ALLS must be set to 0b1 in SMC_PMPROT register in order to allow LLS mode.

 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_MCU_Enter_LLS3
(
void
);
/*---------------------------------------------------------------------------
 * Name: PWRLib_MCUEnter_Stop
 * Description: Puts the processor into Stop 

                Mode of operation details:
                 - ARM core enters SleepDeep Mode
                 - ARM core is clock gated (HCLK = OFF)
                 - NVIC is disable (FCLK = OFF)
                 - Platform and peripheral clock are stopped
                 - Full SRAM retention.               
                The ALLS must be set to 0b1 in SMC_PMPROT register in order to allow LLS mode.

 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_MCU_Enter_Stop
(
void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_MCUEnter_VLPS
 * Description: Puts the processor into Verry-Low_Power-Stop 

                Mode of operation details:
                 - ARM core enters SleepDeep Mode
                 - ARM core is clock gated (HCLK = OFF)
                 - NVIC is disable (FCLK = OFF)
                 - Platform and peripheral clock are stopped
                 - Full SRAM retention.               
                The ALLS must be set to 0b1 in SMC_PMPROT register in order to allow LLS mode.

 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_MCU_Enter_VLPS
(
void
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_LLWU_UpdateWakeupReason
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_LLWU_UpdateWakeupReason(void);

/*---------------------------------------------------------------------------
 * Name: PWRLib_LLWU_DisableAllWakeupSources
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_LLWU_DisableAllWakeupSources();

/*---------------------------------------------------------------------------
 * Name: PWRLib_LPTMR_Init
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_LPTMR_Init(void);

/*---------------------------------------------------------------------------
 * Name: PWRLib_LPTMR_GetTimeSettings
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_LPTMR_GetTimeSettings(uint32_t timeInMs, uint8_t* pClkMode,uint32_t* pTicks, uint32_t* pFreq);

/*---------------------------------------------------------------------------
 * Name: PWRLib_LPTMR_ClockStart
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_LPTMR_ClockStart
(
  uint8_t  ClkMode,
  uint32_t Ticks
);

/*---------------------------------------------------------------------------
 * Name: PWRLib_LPTMR_ClockCheck
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
uint32_t PWRLib_LPTMR_ClockCheck
(
  void
);


/*---------------------------------------------------------------------------
 * Name: PWRLib_LPTMR_ClockStop
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
void PWRLib_LPTMR_ClockStop
(
  void
);


/*---------------------------------------------------------------------------
 * Name: PWRLib_LVD_CollectLevel
 * Description: -
 * Parameters: -
 * Return: -
 *---------------------------------------------------------------------------*/
PWRLib_LVD_VoltageLevel_t PWRLib_LVD_CollectLevel
(
  void
);

#endif /* __PWR_LIB_H__ */
