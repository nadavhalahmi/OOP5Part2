//
// Created by nadav on 22/06/2018.
//

#ifndef PART2_STREAM_H
#define PART2_STREAM_H

#include <functional>
#include <vector>
#include <algorithm>
#include <map>

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
            return v;
        };
        return s;
    }

    template <typename S>
    static Stream of(std::map<S,T*> m){
        Stream s;
        std::vector<T*> v;
        for(auto a : m){
            v.push_back(a.second);
        }
        s.func = [v](){
            return v;
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
            bool found = false;
            std::vector<T*> new_v;
            for(auto toAdd : curr){
                for(auto added : new_v) {
                    if (equals(toAdd, added)) {
                        found = true;
                    }
                }
                if(!found)
                    new_v.push_back(toAdd);
                found = false;
            }
            return new_v;
        };
        return *this;
    }

    Stream distinct(){
        return distinct([](const T* a, const T* b){return *a==*b;});
    }

    Stream sorted(std::function<bool(const T*, const T*)> comp){
        std::function<std::vector<T*>()> old_func = func;
        func = [comp, old_func](){
            auto curr = old_func();
            std::sort(curr.begin(), curr.end(), comp);
            return curr;
        };
        return *this;
    }

    Stream sorted(){
        return sorted([](const T* a, const T* b){return *a < *b;});
    }

    template <typename TContainer>
    TContainer collect() {
        std::vector<T*> retVector = func();
        TContainer retContainer = TContainer(retVector.begin(), retVector.end());
        return retContainer;
    }

    void forEach(std::function<void(T*)> f){
        std::vector<T*> retVector = func();
        for(auto val : retVector)
            f(val);
    }

    T* reduceAux(T* init, std::function<T*(const T*, const T*)> f, int i, std::vector<T*> vec) {
        if(i==0){
            return f(init, vec[i]);
        }
        return f(vec[i], reduceAux(init, f, i-1, vec));
    }

    T* reduce(T* init, std::function<T*(const T*, const T*)> f){
        std::vector<T*> retVector = func();
        return reduceAux(init, f, retVector.size()-1, retVector);
    }

    T* min(){
        std::vector<T*> retVector = func();
        T* min_val = retVector[0]; //assuming it has elements according to facebook
        for(auto val : retVector)
            if(*val < *min_val)
                min_val = val;
        return min_val;
    }

    T* max(){
        std::vector<T*> retVector = func();
        T* max_val = retVector[0]; //assuming it has elements according to facebook
        for(auto val : retVector)
            if(!(*val < *max_val))
                max_val = val;
        return max_val;
    }

    int count() {
        std::vector<T *> retVector = func();
        return retVector.size();
    }

    bool anyMatch(std::function<bool(const T*)> pred){
        std::vector<T *> retVector = func();
        for(auto val : retVector)
            if(pred(val))
                return true;
        return false;
    }

    bool allMatch(std::function<bool(const T*)> pred){
        std::vector<T *> retVector = func();
        for(auto val : retVector)
            if(!pred(val))
                return false;
        return true;
    }

    T* findFirst(std::function<bool(const T*)> pred){
        std::vector<T *> retVector = func();
        for(auto val : retVector)
            if(pred(val))
                return val;
        return nullptr;
    }
};
#endif //PART2_STREAM_H
