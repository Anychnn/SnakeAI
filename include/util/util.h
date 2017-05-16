//
// Created by Administrator on 2017/5/13.
//

#ifndef SNAKEAI_UTIL_H
#define SNAKEAI_UTIL_H

#include <chrono>
#include <mingw.thread.h>
#include <sstream>
#include <iomanip>
#include <random>

namespace util {
    inline void sleep(const long ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    template<typename T>
    std::string toString(const T &obj) {
        std::ostringstream oss;
        oss << std::setiosflags(std::ios::fixed) << obj;
        return oss.str();
    }

    template<typename T>
    void swap(T &a, T &b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template<typename SizeType>
    SizeType getDistance(const SizeType ori, const SizeType x, const SizeType size) {
        return ori < x ? x - ori : (x + size) - ori;
    }

    template<typename RandEngine=std::default_random_engine>
    class Random {
    public:
        ~Random() {};

        static Random<> *getInstance() {
            static Random<> instance;
            return &instance;
        }

        double nextDouble(const double min = 0, const double max = 1) {
            return std::uniform_real_distribution<double>(min, max)(engine);
        }

        template<typename Integer>
        Integer nextInt(const Integer min, const Integer max) {
            return std::uniform_int_distribution<Integer>(min,max)(engine);
        }
        template<typename RanIt>
                void shuffle(RanIt beg,RanIt end){
            if(end-beg>1){
                std::size_t i=end-beg-1;
                for(RanIt it=end-1;it!=beg;--it,--i){
                    swap(*it,*(beg+nextInt<decltype(i)>(0,i)));
                }
            }
        }

    private:
        RandEngine engine;

        Random() : engine((unsigned) std::time(nullptr)) {}
    };

}


#endif //SNAKEAI_UTIL_H
