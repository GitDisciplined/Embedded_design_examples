
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************

#include "main.h"
#include "stdlib.h"
#include <string.h>

#define LCD_EN GPIO_PIN_7
#define LCD_RS GPIO_PIN_6
#define LCD_D4 GPIO_PIN_8
#define LCD_D5 GPIO_PIN_9
#define LCD_D6 GPIO_PIN_10
#define LCD_D7 GPIO_PIN_11



void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void enable_set(void);
void assign(uint8_t bits );
void send_command(uint8_t  cmd);
void send_data(unsigned char display);
void initialize();

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  initialize();

  send_data('W');
	send_data('E');
	send_data('L');
	send_data('C');
	send_data('O');
	send_data('M');
	send_data('E');
	send_data(' ');
	send_data('T');
	send_data('O');
	send_data(' ');

	send_data('B');
	send_data('I');
	send_data('L');
	send_data('A');
	send_data('B');

	HAL_Delay(10);

  while (1)
  {
    
  }
 
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();


  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6| GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11, GPIO_PIN_RESET);


                          
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

 
}


void enable_set(void)
{

HAL_GPIO_WritePin(GPIOA,LCD_EN,GPIO_PIN_SET);
HAL_Delay(1);
HAL_GPIO_WritePin(GPIOA,LCD_EN,GPIO_PIN_RESET);
HAL_Delay(1);

}


void assign(uint8_t bits )
{

HAL_GPIO_WritePin(GPIOA,LCD_D4,bits>>0 & 0x01);

HAL_GPIO_WritePin(GPIOA,LCD_D5,bits>>1 & 0x01);

HAL_GPIO_WritePin(GPIOA,LCD_D6,bits>>2 & 0x01);

HAL_GPIO_WritePin(GPIOA,LCD_D7,bits>>3 & 0x01);


}

void send_command(uint8_t  cmd)
{

HAL_GPIO_WritePin(GPIOA,LCD_RS,GPIO_PIN_RESET);
assign(cmd>>4);
enable_set();
assign(cmd & 0x0F);
enable_set();

}


void send_data(unsigned char display)
{

  HAL_GPIO_WritePin(GPIOA,LCD_RS,GPIO_PIN_SET);
  assign(display>>4);
  enable_set();
  assign(display & 0x0F);
  enable_set();

}


void initialize()
{
 HAL_Delay(20);

 send_command(0x03);
 HAL_Delay(5);
 send_command(0x03);
 HAL_Delay(5);

 send_command(0x03);
 HAL_Delay(5);


 send_command(0x02);
 send_command(0x0C);


 send_command(0x28);

 send_command(0x01);
 HAL_Delay(5);


}

void Error_Handler(void)
{
  
  __disable_irq();
  while (1)
  {
  }
 
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
  
}
#endif 
