//*****************************************************************************
//
// timer.h - Prototypes for the timer module
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
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
//
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __TIMER_H__
#define __TIMER_H__

#include "inc/hw_types.h"

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// Values that can be passed to TimerConfigure as the ulConfig parameter.
//
//*****************************************************************************
#define TIMER_CFG_ONE_SHOT       0x00000021  // Full-width one-shot timer
#define TIMER_CFG_ONE_SHOT_UP    0x00000031  // Full-width one-shot up-count
                                            // timer
#define TIMER_CFG_PERIODIC       0x00000022  // Full-width periodic timer
#define TIMER_CFG_PERIODIC_UP    0x00000032  // Full-width periodic up-count
                                            // timer
#define TIMER_CFG_RTC            0x01000000  // Full-width RTC timer
#define TIMER_CFG_SPLIT_PAIR     0x04000000  // Two half-width timers
#define TIMER_CFG_A_ONE_SHOT     0x00000021  // Timer A one-shot timer
#define TIMER_CFG_A_ONE_SHOT_UP  0x00000031  // Timer A one-shot up-count timer
#define TIMER_CFG_A_PERIODIC     0x00000022  // Timer A periodic timer
#define TIMER_CFG_A_PERIODIC_UP  0x00000032  // Timer A periodic up-count timer
#define TIMER_CFG_A_CAP_COUNT    0x00000003  // Timer A event counter
#define TIMER_CFG_A_CAP_COUNT_UP 0x00000013  // Timer A event up-counter
#define TIMER_CFG_A_CAP_TIME     0x00000007  // Timer A event timer
#define TIMER_CFG_A_CAP_TIME_UP  0x00000017  // Timer A event up-count timer
#define TIMER_CFG_A_PWM          0x0000000A  // Timer A PWM output
#define TIMER_CFG_B_ONE_SHOT     0x00002100  // Timer B one-shot timer
#define TIMER_CFG_B_ONE_SHOT_UP  0x00003100  // Timer B one-shot up-count timer
#define TIMER_CFG_B_PERIODIC     0x00002200  // Timer B periodic timer
#define TIMER_CFG_B_PERIODIC_UP  0x00003200  // Timer B periodic up-count timer
#define TIMER_CFG_B_CAP_COUNT    0x00000300  // Timer B event counter
#define TIMER_CFG_B_CAP_COUNT_UP 0x00001300  // Timer B event up-counter
#define TIMER_CFG_B_CAP_TIME     0x00000700  // Timer B event timer
#define TIMER_CFG_B_CAP_TIME_UP  0x00001700  // Timer B event up-count timer
#define TIMER_CFG_B_PWM          0x00000A00  // Timer B PWM output

//*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ulIntFlags parameter, and returned from TimerIntStatus.
//
//*****************************************************************************
#define TIMER_TIMB_MATCH        0x00000800  // TimerB match interrupt
#define TIMER_CAPB_EVENT        0x00000400  // CaptureB event interrupt
#define TIMER_CAPB_MATCH        0x00000200  // CaptureB match interrupt
#define TIMER_TIMB_TIMEOUT      0x00000100  // TimerB time out interrupt
#define TIMER_TIMA_MATCH        0x00000010  // TimerA match interrupt
#define TIMER_RTC_MATCH         0x00000008  // RTC interrupt mask
#define TIMER_CAPA_EVENT        0x00000004  // CaptureA event interrupt
#define TIMER_CAPA_MATCH        0x00000002  // CaptureA match interrupt
#define TIMER_TIMA_TIMEOUT      0x00000001  // TimerA time out interrupt

//*****************************************************************************
//
// Values that can be passed to TimerControlEvent as the ulEvent parameter.
//
//*****************************************************************************
#define TIMER_EVENT_POS_EDGE    0x00000000  // Count positive edges
#define TIMER_EVENT_NEG_EDGE    0x00000404  // Count negative edges
#define TIMER_EVENT_BOTH_EDGES  0x00000C0C  // Count both edges

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ulTimer
// parameter.
//
//*****************************************************************************
#define TIMER_A                 0x000000ff  // Timer A
#define TIMER_B                 0x0000ff00  // Timer B
#define TIMER_BOTH              0x0000ffff  // Timer Both

//*****************************************************************************
//
// Values that can be passed to TimerSynchronize as the ulTimers parameter.
//
//*****************************************************************************
#define TIMER_0A_SYNC           0x00000001  // Synchronize Timer 0A
#define TIMER_0B_SYNC           0x00000002  // Synchronize Timer 0B
#define TIMER_1A_SYNC           0x00000004  // Synchronize Timer 1A
#define TIMER_1B_SYNC           0x00000008  // Synchronize Timer 1B
#define TIMER_2A_SYNC           0x00000010  // Synchronize Timer 2A
#define TIMER_2B_SYNC           0x00000020  // Synchronize Timer 2B
#define TIMER_3A_SYNC           0x00000040  // Synchronize Timer 3A
#define TIMER_3B_SYNC           0x00000080  // Synchronize Timer 3B
#define TIMER_4A_SYNC           0x00000100  // Synchronize Timer 4A
#define TIMER_4B_SYNC           0x00000200  // Synchronize Timer 4B
#define TIMER_5A_SYNC           0x00000400  // Synchronize Timer 5A
#define TIMER_5B_SYNC           0x00000800  // Synchronize Timer 5B
#define WTIMER_0A_SYNC          0x00001000  // Synchronize Wide Timer 0A
#define WTIMER_0B_SYNC          0x00002000  // Synchronize Wide Timer 0B
#define WTIMER_1A_SYNC          0x00004000  // Synchronize Wide Timer 1A
#define WTIMER_1B_SYNC          0x00008000  // Synchronize Wide Timer 1B
#define WTIMER_2A_SYNC          0x00010000  // Synchronize Wide Timer 2A
#define WTIMER_2B_SYNC          0x00020000  // Synchronize Wide Timer 2B
#define WTIMER_3A_SYNC          0x00040000  // Synchronize Wide Timer 3A
#define WTIMER_3B_SYNC          0x00080000  // Synchronize Wide Timer 3B
#define WTIMER_4A_SYNC          0x00100000  // Synchronize Wide Timer 4A
#define WTIMER_4B_SYNC          0x00200000  // Synchronize Wide Timer 4B
#define WTIMER_5A_SYNC          0x00400000  // Synchronize Wide Timer 5A
#define WTIMER_5B_SYNC          0x00800000  // Synchronize Wide Timer 5B

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void TimerEnable(unsigned long ulBase, unsigned long ulTimer);
extern void TimerDisable(unsigned long ulBase, unsigned long ulTimer);
extern void TimerConfigure(unsigned long ulBase, unsigned long ulConfig);
extern void TimerControlLevel(unsigned long ulBase, unsigned long ulTimer,
                              tBoolean bInvert);
extern void TimerControlTrigger(unsigned long ulBase, unsigned long ulTimer,
                                tBoolean bEnable);
extern void TimerControlEvent(unsigned long ulBase, unsigned long ulTimer,
                              unsigned long ulEvent);
extern void TimerControlStall(unsigned long ulBase, unsigned long ulTimer,
                              tBoolean bStall);
extern void TimerControlWaitOnTrigger(unsigned long ulBase,
                                      unsigned long ulTimer,
                                      tBoolean bWait);
extern void TimerRTCEnable(unsigned long ulBase);
extern void TimerRTCDisable(unsigned long ulBase);
extern void TimerPrescaleSet(unsigned long ulBase, unsigned long ulTimer,
                             unsigned long ulValue);
extern unsigned long TimerPrescaleGet(unsigned long ulBase,
                                      unsigned long ulTimer);
extern void TimerPrescaleMatchSet(unsigned long ulBase, unsigned long ulTimer,
                                  unsigned long ulValue);
extern unsigned long TimerPrescaleMatchGet(unsigned long ulBase,
                                           unsigned long ulTimer);
extern void TimerLoadSet(unsigned long ulBase, unsigned long ulTimer,
                         unsigned long ulValue);
extern unsigned long TimerLoadGet(unsigned long ulBase, unsigned long ulTimer);
extern void TimerLoadSet64(unsigned long ulBase, unsigned long long ullValue);
extern unsigned long long TimerLoadGet64(unsigned long ulBase);
extern unsigned long TimerValueGet(unsigned long ulBase,
                                   unsigned long ulTimer);
extern unsigned long long TimerValueGet64(unsigned long ulBase);
extern void TimerMatchSet(unsigned long ulBase, unsigned long ulTimer,
                          unsigned long ulValue);
extern unsigned long TimerMatchGet(unsigned long ulBase,
                                   unsigned long ulTimer);
extern void TimerMatchSet64(unsigned long ulBase, unsigned long long ullValue);
extern unsigned long long TimerMatchGet64(unsigned long ulBase);
extern void TimerIntRegister(unsigned long ulBase, unsigned long ulTimer,
                             void (*pfnHandler)(void));
extern void TimerIntUnregister(unsigned long ulBase, unsigned long ulTimer);
extern void TimerIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void TimerIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long TimerIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void TimerIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void TimerSynchronize(unsigned long ulBase, unsigned long ulTimers);

//*****************************************************************************
//
// TimerQuiesce() has been deprecated.  SysCtlPeripheralReset() should be used
// instead to return the timer to its reset state.
//
//*****************************************************************************
#ifndef DEPRECATED
extern void TimerQuiesce(unsigned long ulBase);
#endif

//*****************************************************************************
//
// These values for TimerConfigure have been deprecated.
//
//*****************************************************************************
#ifndef DEPRECATED
#define TIMER_CFG_32_BIT_OS      0x00000021  // 32-bit one-shot timer
#define TIMER_CFG_32_BIT_OS_UP   0x00000031  // 32-bit one-shot up-count timer
#define TIMER_CFG_32_BIT_PER     0x00000022  // 32-bit periodic timer
#define TIMER_CFG_32_BIT_PER_UP  0x00000032  // 32-bit periodic up-count timer
#define TIMER_CFG_32_RTC         0x01000000  // 32-bit RTC timer
#define TIMER_CFG_16_BIT_PAIR    0x04000000  // Two 16-bit timers
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __TIMER_H__
