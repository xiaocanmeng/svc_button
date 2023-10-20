#include "sendcommand.h"
#include <iostream>
#include <ncurses.h>
bool HAL_USER::execute_send()
{
    bool res =  false;
    ApiFlags apiflags{ ApiFlags::kBlock };
	ControlInfo control_4{ ControlCommand::kCommSet, 0U, 10000U };
	SetControl(control_4, apiflags);
    uint32_t camera_error{ 0U };
	uint32_t camera_connect_status{ 9U };
	uint32_t part_connect_status{ 0U };
	uint8_t device_error{ 0U };
	Configuration config{ 16383U, 33U, Audio::kOn, BitRate::k1Mbps, BitRate::k1Mbps, 0U };
	ControlInfo control_1{ ControlCommand::kStart, 0U, 10000U };
	SetDeviceInfo(camera_error, camera_connect_status, part_connect_status, device_error, apiflags);

	SetConfiguration(config, apiflags);
	SetControl(control_1, apiflags);
   

 return res;
}