/**
  ******************************************************************************
  * @file    wifi_thread.c
  * @author  Sprankle
  * @brief   Thread for processing wifi interface
  ******************************************************************************
*/

#include "remote_comm_task.h"
#include <wifi.h>
#include <cmsis_os.h>
#include "es_wifi_conf.h"

extern Remote_Socket_t Socket_0_conf;

void RemoteCommTask(void const * argument)
{
	uint8_t TxData[60];
	uint16_t Datalen;
	int count = 0;
	int errors = 0;


	WIFI_Status_t WifiStatus = WIFI_STATUS_ERROR;

	// Wait for ES_WIFI to finish boot
	osDelay(500);

	while (1)
	{
		// Repeat connect sequence until we get good connection
		while (WifiStatus != WIFI_STATUS_OK)
		{
			if (WIFI_Init() != WIFI_STATUS_OK) {break;}

			if (WIFI_Connect(Socket_0_conf.SSID, Socket_0_conf.Password, Socket_0_conf.ecn) != WIFI_STATUS_OK) {break;}

			if (WIFI_OpenClientConnection(Socket_0_conf.SocketNumber, WIFI_UDP_PROTOCOL, "UDP_CLIENT", Socket_0_conf.RemoteIP, Socket_0_conf.RemotePort, 0) != WIFI_STATUS_OK) {break;}

			WifiStatus = WIFI_STATUS_OK;
		}

		// Loop until connection is lost
		while (WifiStatus == WIFI_STATUS_OK)
		{
			count++;

			sprintf((char*)TxData, "S3=30\r\r\nCount = %5d\r\n Error = %d5", count, errors);

//			SEGGER_SYSVIEW_PrintfHost("Start Send");
			WifiStatus = WIFI_SendData(Socket_0_conf.SocketNumber, TxData, sizeof(TxData), &Datalen, Socket_0_conf.WifiWriteTimeout);
//			SEGGER_SYSVIEW_PrintfHost("End Send");

			osDelay(10);
		}

	}
}
