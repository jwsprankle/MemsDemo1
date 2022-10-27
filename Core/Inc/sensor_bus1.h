#ifndef SENSOR_BUS1_H
#define SENSOR_BUS1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bsp_Lsm6dsl.h"
#include "bsp_lis3mdl.h"


// Note: add note about time limit on pRawData
typedef void (*AccGyroCallback_t)(GYRO_ACC_t * pRawData, uint16_t numItems);
typedef void (*MagCallback_t)(LIS3MDL_AxesRaw_t * pRawData, uint16_t numItems);


extern void SensorBus1_Init(AccGyroCallback_t pAccGyroCB, MagCallback_t pMagCB);
extern void SensorBus1_Start(void);
extern void SensorBus1_DMA_CallBack(void);
extern void SensorBus1_Gyro_ACC_Intr(void);
extern void SensorBus1_Mag_Intr(void);



#ifdef __cplusplus
}
#endif
#endif

