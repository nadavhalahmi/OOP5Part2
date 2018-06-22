//
// Created by nadav on 22/06/2018.
//

#ifndef PART2_STREAM_H
#define PART2_STREAM_H

#include <functional>
#include <vector>


template <typename T>
class Stream{
private:
    std::function<std::vector<T*>()> func; //vector chosen cause it's cool
    static std::vector<Stream<T>*> created; //contains all created streams for deletion later (TODO: initialize)

    template <typename TContainer>
    Stream<T>(TContainer& container){
        func = [container](){
            return std::vector<T*>(container.begin(),container.end()); //TODO: take care of std::map
        };
    }
public:
    template <typename TContainer>
    static Stream<T> of(TContainer& container){
        Stream<T>* pStream = new Stream<T>(container);
        created.push_back(pStream);
        return *pStream;
    }
};
#endif //PART2_STREAM_H
