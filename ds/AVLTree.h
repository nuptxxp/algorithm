/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/29
 */
#ifndef ALGORITHM__AVLTREE_H_
#define ALGORITHM__AVLTREE_H_

#include "BinaryTree.h"

namespace algorithm
{

namespace dataStruct
{

template<typename Object>
class AVLTree : public BinaryTree<Object>{
    public:
        int search(const Object& v) {
            return 0;
        }
        BinaryNode<Object>* insert(const Object& v) {
            return NULL;
        }
        int remove(const Object& v) {
            return 0;
        }
        ~AVLTree() {
        }
};

}

}

#endif
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

