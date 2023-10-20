#ifndef SENDCOMMAND_H
#define SENDCOMMAND_H
#include <iostream>
#include <mutex>
#include <ncurses.h>
#include <menu.h>
#include <unordered_map>
#include "data.h"
#include "camera_event_capture_hal.h"
using namespace cockpit::hal::camera_event_capture_hal;
using namespace JSON_data;
class HAL_USER {
public:
    // 在这里添加 HAL_USER 的成员和其他函数

    // 示例函数
    bool execute_send();
    void print_menu();
    // 获取单例实例的静态方法
    static HAL_USER& instance() {
        static HAL_USER instance;  // Meyer's Singleton
        return instance;
    }
    
protected:
    void print_menu_cleanup(MENU *my_menu, ITEM **items, int num_items);

    void setcontrol_init()
    {
        ControlInfo control = { ControlCommand::kInit, 0U, 10000U };
        ApiFlags apiflags{ ApiFlags::kBlock };
        SetControl(control, apiflags);
    }
    void setcontrol_start()
    {
        ControlInfo control = { ControlCommand::kStart, 0U, 10000U };
        ApiFlags apiflags{ ApiFlags::kBlock };
        SetControl(control, apiflags);
    }
    void setcontrol_stop()
    {
        ApiFlags apiflags{ ApiFlags::kBlock };
        ControlInfo control_2{ ControlCommand::kStop, 0U, 10000U };
	    SetControl(control_2, apiflags);
    }
private:
    
    // 将构造函数和析构函数声明为私有，确保只能通过 instance() 获取单例
    HAL_USER() {
        // 在这里添加初始化逻辑
        std::cout << "HAL_USER instance created." << std::endl;
    }

    ~HAL_USER() {
        // 在这里添加清理逻辑
        std::cout << "HAL_USER instance destroyed." << std::endl;
    }
    // 禁用拷贝构造函数和赋值运算符
    HAL_USER(const HAL_USER&) = delete;
    HAL_USER& operator=(const HAL_USER&) = delete;

    using user_command = void (HAL_USER::*)();
    
    std::unordered_map<int32_t,user_command> setcontrol_command=
    {{0,&HAL_USER::setcontrol_init},
     {1,&HAL_USER::setcontrol_start},
     {2,&HAL_USER::setcontrol_stop}};
    // system(sendSetControl_param_start.c_str());


};



#endif