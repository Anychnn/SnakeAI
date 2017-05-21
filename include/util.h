//
// Created by Administrator on 2017/5/18.
//

#ifndef SNAKEAI_UTIL_H
#define SNAKEAI_UTIL_H


#include <thread>
#include <mingw.thread.h>
#include <random>
#include <time.h>
namespace util {
    inline void sleep(const long ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    /**
     * 坐标变换opengl的坐标系  -1 ~ 1
     * @param x
     * @return
     */
    inline float coordinateXConversion(const int x, const int colCnt) {
        return -1 + (2.0 * (x - 1.0)) / colCnt;
    }

    inline float coordinateYConversion(const int y, const int rowCnt) {
        return -1 + (2.0 * (y - 1.0)) / rowCnt;
    }

    template<typename RandEngine=std::default_random_engine>
    class Random {
    public:
        ~Random() {}
        static Random<> *getInstance() {
            static Random<> instance;
            return &instance;
        }

        double nextDouble(const double min = 0, const double max = 1) {
            static std::default_random_engine e(2);
            return std::uniform_real_distribution<double>(min, max)(e);
        }

        int nextInt(const int min, const int max) {
            static std::default_random_engine e(1);
            return std::uniform_int_distribution<int>(min, max)(e);
        }

    private:
        RandEngine engine;
    };
};


#endif //SNAKEAI_UTIL_H
