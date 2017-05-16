//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_CONSOLE_H
#define SNAKEAI_CONSOLE_H

#include <string>
#include <windows.h>

enum ConsoleColorType{
    BLACK,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    WHITE
};

struct ConsoleColor{
    ConsoleColor(const ConsoleColorType foreColor_,
                const ConsoleColorType backColor_,
    const bool foreIntensified_=false,
    const bool backIntensified_=false);
    ConsoleColorType foreColor;
    ConsoleColorType backColor;
    bool foreIntensified;
    bool backIntensified;
};
class Console {
public:
    static void setCursor(const int x=0,const int y=0);
    static void clear();
    static void write(const std::string &str);
    static void writeWithColor(const std::string &str,const ConsoleColor &consoleColor);
    static char getch();

    static int kbhit();

private:
    static WORD setColor(const ConsoleColor &consoleColor);
    static void resetColor(const WORD attr);
};


#endif //SNAKEAI_CONSOLE_H
