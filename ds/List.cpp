/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/18
 */

#include <iostream>

using namespace std;

namespace algorithm
{
    template<typename Object>
    class List {
        public:
            struct Node {
                Object v;
            };
            typedef List* iterator;
        private:
            int _size;
            Node* head;
            Node* tail;

    };
}


//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

