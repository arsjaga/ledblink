#include "main.h"
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  while (1)
  {
      gpio_set_pin(GPIOB, LED3, 1);
	  delay(1000);
      gpio_set_pin(GPIOB, LED3, 0);
	  delay(1000);
  }
}
