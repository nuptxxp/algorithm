/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/22
 */
#ifndef ALGORITHM__QUEUE_H_
#define ALGORITHM__QUEUE_H_

#include "List.h"

namespace algorithm
{

namespace dataStruct
{

template<typename Object>
class Queue {
    public:
        Queue() {
        }
        ~Queue() {
        }
        Object& front() {
            return q.front();
        }
        bool empty() {
            return q.empty();
        }
        void pop() {
            q.pop_front();
        }
        void push(const Object& d) {
            q.push_back(d);
        }

    private:
        List<Object> q;
};

}

}

#endif
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

