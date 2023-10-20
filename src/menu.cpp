#include "sendcommand.h"
#include <ncurses.h>

void HAL_USER::print_menu_cleanup(MENU *my_menu, ITEM **items, int num_items) {
    unpost_menu(my_menu);
    free_menu(my_menu);
    for (int i = 0; i < num_items; ++i)
        free_item(items[i]);
}

void HAL_USER::print_menu(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    int num_items = 4;
    ITEM **items = (ITEM **)calloc(num_items + 1, sizeof(ITEM *));
    items[0] = new_item("Init", "");
    items[1] = new_item("Start recording", "");
    items[2] = new_item("Stop recording", "");
    items[3] = new_item("exit", "");
    items[num_items] = nullptr;

    int height = 6, width = 20;
    int start_y = (LINES - height) / 2;  // 居中计算
    int start_x = (COLS - width) / 2;   // 居中计算
    MENU *menu = new_menu(items);
    set_menu_win(menu, stdscr);
    set_menu_sub(menu, derwin(stdscr, height, width, start_y, start_x));
    post_menu(menu);
    refresh();

    int ch;
    int selected = 0;

    while ((ch = getch()) != 27) {  // 27 is ASCII code for Escape key
        switch (ch) {
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                selected = item_index(current_item(menu));
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                selected = item_index(current_item(menu));
                break;
            case 10:  // Enter key
                if (selected == num_items - 1) 
                {
                    // 退出选项
                    print_menu_cleanup(menu, items, num_items);
                    endwin();
                    return; // 退出程序
                }
                else 
                {
                    // clear();
                    // mvprintw(0, 0, "You chose Option %d", selected + 1);
                    if (setcontrol_command.count(selected) == 1) 
                    {
                        (this->*setcontrol_command.at(selected))();
					} 
                    else 
                    {
                        // mvprintw(11, 0, "Selected %d", selected);
                    }
                    getch();  // Wait for user input before exiting
                }
                break;
        }
    }

    print_menu_cleanup(menu, items, num_items);
    endwin();
}

