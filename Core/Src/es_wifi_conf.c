/*
 * es_wifi_conf.c
 *
 *  Created on: Oct 15, 2022
 *      Author: jwspr
 */


#include <wifi.h>
#include "es_wifi_conf.h"



Remote_Socket_t Socket_0_conf = {"NETGEAR45",			// Access Point SSID
						 	 	 "smoothcomet710",		// Access Point Password
								 WIFI_UDP_PROTOCOL,		// Protocol
								 0, 					// Socket enumeration
								 62510,					// Remote port number
								 {192,168,0,236},		// Remote IP address
								 WIFI_ECN_WPA2_PSK,		// Encoding
								 10000,					// Write timeout
								 10000};					// Read timeout
