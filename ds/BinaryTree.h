/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/29
 */
#ifndef ALGORITHM__BINARYTREE_H_
#define ALGORITHM__BINARYTREE_H_

#include <iostream>

namespace algorithm
{

namespace dataStruct
{

/*
 * Object should be compareable
 */
template<typename Object>
struct BinaryNode {
    BinaryNode* left;
    BinaryNode* right;
    Object val;
    int count;
    BinaryNode() {
        left = right = NULL;
        count = 0;
    }
    BinaryNode(const Object& v) {
        left = right = NULL;
        val = v;
        count = 1;
    }
};

template<typename Object>
class BinaryTree {
    public:
        BinaryTree() {
            root = NULL;
        }
        BinaryTree(const Object& v) {
            root = new BinaryNode<Object>(v);
        }
        BinaryTree(const BinaryTree& bt) {
            if (this == &bt) {
                return;
            }
            clearTree(root);
            root = copyTree(bt->root);
        }
        virtual ~BinaryTree() {
            clearTree(root);
        }
        virtual int search(const Object& v) = 0;
        virtual BinaryNode<Object>* insert(const Object& v) = 0;
        virtual int remove(const Object& v) = 0;
    protected:
        void clearTree(BinaryNode<Object>* r) {
            if (r) {
                if (r->left) {
                    clearTree(r->left);
                }
                if (r->right) {
                    clearTree(r->right);
                }
                delete r;
                r = NULL;
            }
        }
        void copyTree(BinaryNode<Object>* r) {
            if (r) {
                BinaryNode<Object>* t = new BinaryNode<Object>(r->val);
                t->left = copyTree(r->left);
                t->right = copyTree(r->rigth);
                return t;
            }
            return NULL;
        }
        BinaryNode<Object>* root;
};

}

}

#endif
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

