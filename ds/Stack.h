/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/22
 */
#ifndef ALGORITHM__STACK_H_
#define ALGORITHM__STACK_H_

#include "Vector.h"

namespace algorithm
{

namespace dataStruct
{

template<typename Object>
class Stack {
    public:
        Stack() {
        }
        Stack(const Stack& s) {
            int size = s.v.size();
            v.resize(size);
            for (int i = size - 1; i >= 0; ++i) {
                v[i] = s.v[i];
            }
        }
        ~Stack() {
        }
        const Object& top() {
            return v[v.size()-1];
        }
        void pop() {
            v.pop_back();
        }
        void push(const Object& t) {
            v.push_back(t);
        }
        bool empty() {
            return v.size() == 0;
        }
        int size() {
            return v.size();
        }
        void clear() {
            v.clear();
        }
    private:
        Vector<Object> v;

};

}

}


#endif
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

