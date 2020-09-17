/***************************************************************/
/* Author   : Hossam Sultan                                    */
/* DATE     : 17 SEP 2020                                      */
/* Version  : V01                                              */
/***************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


             /*Register Definition*/
#define RCC_CR          *((u32*)0x4002 1000)
#define RCC_CFGR        *((u32*)0x4002 1004)
#define RCC_CIR         *((u32*)0x4002 1008)
#define RCC_APB2RSTR    *((u32*)0x4002 100C)
#define RCC_APB1RSTR    *((u32*)0x4002 1010)
#define RCC_AHBENR      *((u32*)0x4002 1014)
#define RCC_APB2ENR     *((u32*)0x4002 1018)
#define RCC_APB1ENR     *((u32*)0x4002 101C)
#define RCC_BDCR        *((u32*)0x4002 1020)
#define RCC_CSR         *((u32*)0x4002 1024)

#endif