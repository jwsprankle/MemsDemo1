/*
 * debug_analyzer.c
 *
 *  Created on: Aug 29, 2022
 *      Author: jwspr
 */


#include "debug_analyzer.h"
#include "main.h"

void DebugExtAnalyzerPulse1(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer1_GPIO_Port, ExtAnalyzer1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ExtAnalyzer1_GPIO_Port, ExtAnalyzer1_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerSet1(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer1_GPIO_Port, ExtAnalyzer1_Pin, GPIO_PIN_SET);
}


void DebugExtAnalyzerReset1(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer1_GPIO_Port, ExtAnalyzer1_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerPulse2(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer2_GPIO_Port, ExtAnalyzer2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ExtAnalyzer2_GPIO_Port, ExtAnalyzer2_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerSet2(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer2_GPIO_Port, ExtAnalyzer2_Pin, GPIO_PIN_SET);
}


void DebugExtAnalyzerReset2(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer2_GPIO_Port, ExtAnalyzer2_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerPulse3(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer3_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerSet3(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer3_Pin, GPIO_PIN_SET);
}


void DebugExtAnalyzerReset3(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer3_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerPulse4(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer4_Pin, GPIO_PIN_RESET);
}


void DebugExtAnalyzerSet4(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer4_Pin, GPIO_PIN_SET);
}


void DebugExtAnalyzerReset4(void)
{
		HAL_GPIO_WritePin(ExtAnalyzer3_GPIO_Port, ExtAnalyzer4_Pin, GPIO_PIN_RESET);
}



