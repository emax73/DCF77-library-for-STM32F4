/**
  ******************************************************************************
  * @file    dcf77.h
  * @author  Maxim Enbaev
  * @version V2.0
  * @date    28-September-2015
  * @brief   This file provides header of dcf77 signal reception library for STM32F4 microcontrollers
  ******************************************************************************
  * @attention
  * 
  * The MIT License (MIT)
  * Copyright (c) 2016 Maxim Enbaev emax@cosmostat.com
  * 
  * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
  * and associated documentation files (the "Software"), to deal in the Software without restriction,
  * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
  * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
  * subject to the following conditions:
  * 
  * The above copyright notice and this permission notice shall be included in all copies or substantial portions
  * of the Software.
  * 
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
  * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  * 
  * 
  ******************************************************************************
  */

#ifndef __DCF77_H
#define __DCF77_H

#include <stdbool.h>
#include <stdint.h>

#include "pins.h"
#include "time2.h"

#define DCF77_PIN_POLARITY false // true - Positive DCF77 signal / false - Inverse signal 
#define DCF77_TEST false // false - Real Signal / true - Test signal 
#define DCF77_TEST_NOISE 75 // % of test noise 

extern int dcf77timeZone;	//Time Zone: Latvia +2
extern bool dcf77dst;			//Day Saving Time: Latvia 1

extern int dcf77level; // 0 - Weak, 3 - Excellent
extern int dcf77levelPercent; // 0% - Weak, 100% - Excellent

extern int dcf77sync_ms; // ms of begin sec sync
extern int dcf77min59sync; // sec of 59 sec sync

extern int dcf77syncPercent; // Sync Max above Average
extern int dcf77minSyncPercent; // Min sync Max above Average

extern time2_t dcf77timeOk; // Received DCF77 time or zero
extern time2_t dcf77timeOk_msec; // Received DCF77 time msec
extern time2_t dcf77timeOkReceived; // Time of ok receiving DCF77 signal

extern struct tm dcf77timeOk_tm;

#define DCF77_RECEIVED (30 * 60 * 60) //Period for received signal in sec
extern bool dcf77received; //True if DCF77 had received in last daynight

#define DCF77_MSEC_PER_DAY_UNKNOWN -100001
#define DCF77_MSEC_PER_DAY_SHORT_PERIOD -100002
#define DCF77_MSEC_PER_DAY_MAXIMUM 60000
extern int dcf77msec_per_day; // Correction msec per daynight
extern int dcf77startSec; // Seconds from start to first result

extern int dcf77testCnt; // Test Counters
extern int dcf77testCnt1;
extern int dcf77testCnt2;
extern int dcf77testCnt3;
extern int dcf77testCnt4;

extern int last_good_night;

extern int dcf77secUs; // uSec counter
extern int dcf77minUs; // uSec counter

void dcf77init(void); // initialisation
void dcf77msTask(void); // 1 ms task of DCF77 receiving
void dcf77TaskLong(void); // 100 ms long task of DCF77 receiving

void dcf77timeReceived(time2_t now, struct tm * now_tm);			//msec callback - time received
void dcf77timeReceivedLong(time2_t now, int msec, struct tm * now_tm);	//lond duration calback - time received

#endif
