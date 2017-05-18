//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_UTIL_H
#define SNAKEAI_UTIL_H


#include <thread>
#include <mingw.thread.h>

namespace util {
    inline void sleep(const long ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
};


#endif //SNAKEAI_UTIL_H
