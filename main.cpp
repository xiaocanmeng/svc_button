#include <iostream>
#include "sendcommand.h"

int main(int argc,char** argv)
{   
 
    // int32_t control = 0;
    // 使用 HAL_USER 的单例
    HAL_USER& halInstance = HAL_USER::instance();
    // halInstance.execute_send();
    halInstance.print_menu();
  
   
    return 0;
}


