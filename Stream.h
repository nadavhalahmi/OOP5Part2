//
// Created by nadav on 22/06/2018.
//

#ifndef PART2_STREAM_H
#define PART2_STREAM_H

#include <functional>
#include <vector>
#include <algorithm>

template <typename T >
class Stream{
public:
    std::function<std::vector<T*>()> func; //vector chosen cause it's cool

    template <typename TContainer>
    static Stream of(TContainer& container){
        Stream s;
        std::vector<T*> v(container.size());
        std::copy(container.begin(), container.end(), v.begin());
        s.func = [v](){
            return v; //TODO: take care of std::map and
        };
        return s;
    }

    Stream filter(std::function<bool(const T*)> pred){
        std::function<std::vector<T*>()> old_func = func;
        func = [pred, old_func](){
            auto curr = old_func();
            std::vector<T*> new_v;
            for(auto val : curr) {
                if (pred(val))
                    new_v.push_back(val);
            }
            return new_v;
        };
        return *this;
    }

    template <typename R>
    Stream<R> map(std::function<R*(const T*)> f){
        Stream<R> s;
        std::function<std::vector<T*>()> old_func = func;
        s.func = [f, old_func](){
            auto curr = old_func();
            std::vector<R*> new_v(curr.size());
            std::transform(curr.begin(), curr.end(),new_v.begin(), f);
            return new_v;
        };
        return s;
    }

    Stream distinct(std::function<bool(const T*, const T*)> equals){
        std::function<std::vector<T*>()> old_func = func;
        func = [equals, old_func](){
            auto curr = old_func();
            auto it = std::unique(curr.begin(), curr.end(), equals);
            curr.resize( std::distance(curr.begin(),it) );
            return curr;
        };
        return *this;
    }

    Stream distinct(){
        return distinct([](const T* a, const T* b){return *a==*b;});
    }

    Stream sorted(std::function<bool(const T*, const T*)> comp){
        
    }
    template <typename TContainer>
    TContainer collect() {
        std::vector<T*> retVector = func();
        TContainer retContainer = TContainer(retVector.begin(), retVector.end());
        return retContainer;
    }
};
#endif //PART2_STREAM_H
