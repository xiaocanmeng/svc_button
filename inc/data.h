#ifndef DATA_H
#define DATA_H

#include <string>
using namespace std;

// JSON 数据
namespace JSON_data
{
// std::string const command_cec_hal_test ="/opt/dc-ivi-pf/bin/service/cec_hal_svc/cec_hal_test";
std::string const command_cec_hal_test ="./test/cec_hal_test ";

std::string const SetConfiguration_param_4 =
	R"({"api": {"name": "SetConfiguration","version": "5.5.0"},"param":{"configuration":{"service_active": 16383,"record_configuration": 33,"audio_configuration":2,"bitrate_server":3,"bitrate_remote":3},"apiFlags": 0}})";
std::string const SetDeviceInfo_param_FCSH_PVM = R"({
    "api": 
    {
        "name": "SetDeviceInfo",
        "version": "5.5"
    },
    "param": 
    {
        "camera_error":0,
        "camera_connect_status":9,
        "part_connect_status":0,
        "device_error":0,
        "apiFlags":0
    }
})";
std::string const SetControl_param_commset	 = R"({
    "api": 
    {
        "name": "SetControl",
        "version": "5.5.0"
    },
    "param": 
    {
        "control":
        {
            "command" : 4,
            "timeout" : 800,
            "reserved": 0

        },
        "apiFlags": 0
    }
}
)";

std::string const SetControl_param_start = R"({
    "api":
    {
        "name": "SetControl",
        "version": "5.5.0"
    },
    "param":
    {
        "control":
        {
            "command" : 1,
            "timeout" : 0,
            "reserved": 0

        },
        "apiFlags":0
    }
}
)";

std::string const SetControl_param_stop = R"({
    "api":
    {
        "name": "SetControl",
        "version": "5.5.0"
    },
    "param":
    {
        "control":
        {
            "command" : 2,
            "timeout" : 0,
            "reserved": 0

        },
        "apiFlags":0
    }
}
)";

std::string const SetControl_param_init = R"({
    "api":
    {
        "name": "SetControl",
        "version": "5.5.0"
    },
    "param":
    {
        "control":
        {
            "command" : 0,
            "timeout" : 0,
            "reserved": 0

        },
        "apiFlags":0
    }
}
)";


}  // namespace JSON_data
#endif