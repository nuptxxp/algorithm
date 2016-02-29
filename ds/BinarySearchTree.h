/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/29
 */
#ifndef ALGORITHM__BINARYSEARCHTREE_H_
#define ALGORITHM__BINARYSEARCHTREE_H_

#include "BinaryTree.h"

namespace algorithm
{

namespace dataStruct
{

template<typename Object>
class BinarySearchTree : public BinaryTree<Object>{
    public:
        int search(const Object& v) {
            return search(this->root, v);
        }
        BinaryNode<Object>* insert(const Object& v) {
            return this->root = insert(this->root, v);
        }
        int remove(const Object& v) {
            return remove(this->root, v);
        }
        void print() {
            std::cout << "binary Search tree data\n";
            print(this->root);
            std::cout << std::endl;
        }
        ~BinarySearchTree() {
        }
    private:
        BinaryNode<Object>* insert(BinaryNode<Object>* r, const Object& v) {
            if (r) {
                if (v == r->val) {
                    r->count++;
                } else if (v < r->val) {
                    r->left = insert(r->left, v);
                } else {
                    r->right = insert(r->right, v);
                }
            } else {
                r = new BinaryNode<Object>(v);
            }
            return r;
        }
        int search(BinaryNode<Object>* r, const Object& v) {
            if (r) {
                if (v == r->val) {
                    return r->count;
                } else if (v < r->val) {
                    return search(r->left, v);
                } else {
                    return search(r->right, v);
                }
            }
            return 0;
        }
        int remove(BinaryNode<Object>* r, const Object& v) {
            if (r) {
                if (v == r->val) {
                    int tmp = r->count;
                    r->count = 0;
                    return tmp;
                } else if (v < r->val) {
                    return remove(r->left, v);
                } else {
                    return remove(r->right, v);
                }
            }
            return 0;
        }
        void print(BinaryNode<Object>* r) {
            if (r) {
                print(r->left);
                for (int i = 0; i < r->count; ++i) {
                    std::cout << r->val << " ";
                }
                print(r->right);
            }
        }
};

}

}

#endif
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

