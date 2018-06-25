//
// Created by nadav on 22/06/2018.
//

#ifndef PART2_STREAM_H
#define PART2_STREAM_H

#include <functional>
#include <vector>


template <typename T >
class Stream{
public:
    std::function<std::vector<T*>()> func; //vector chosen cause it's cool

    template <typename TContainer>
    Stream(TContainer& container){
        //auto temp = container;
        std::vector<T*> v(container.size());
        std::copy(container.begin(), container.end(), v.begin());
        func = [v](){
            return v; //TODO: take care of std::map and
        };
    }

    template <typename TContainer>
    static Stream of(TContainer& container){
        return Stream(container);
    }
};
#endif //PART2_STREAM_H
