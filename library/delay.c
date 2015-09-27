#include "delay.h"

TIM_HandleTypeDef htim5;

unsigned int delayTicks;
unsigned int delayClock; // Timer clock source in MHz

static unsigned int uScounter = 0;

void delayInit(void) {
	delayClock = DL_CLOCK_MHZ;
	
	__TIM5_CLK_ENABLE();
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 0;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 0xffffffff;
  HAL_TIM_Base_Init(&htim5);

	HAL_TIM_Base_Start(&htim5);
};


void delayNS(int ns) {
	unsigned int begin = TIM5->CNT;
	unsigned int ticks = ns * delayClock / 1000;
	while (TIM5->CNT - begin < ticks) {
	};
}

void delayUS(int us) {
	unsigned int begin = TIM5->CNT;
	unsigned int ticks = us * delayClock;
	while (TIM5->CNT - begin < ticks) {
	};
}

void delayMS(int ms) {
	unsigned int begin = TIM5->CNT;
	unsigned int ticks = ms * delayClock * 1000;
	while (TIM5->CNT - begin < ticks) {
	};
}

void startCountUS(void) {
	uScounter = TIM5->CNT;
}

int endCountUS(void) {
	return (TIM5->CNT - uScounter) / delayClock;
}
