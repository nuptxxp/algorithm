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
            insert(this->root, v);
            return this->root;
        }
        int remove(const Object& v) {
            return 0;
        }
        ~AVLTree() {
        }
        void insert(BinaryNode<Object>* &r, const Object& v) {
            if (r) {
                if (v < r->val) {
                    insert(r->left, v);
                    if (height(r->left) - height(r->right) == 2) {
                        if (v < r->left->val) {
                            LL(r);
                        } else {
                            LR(r);
                        }
                    }
                } else if (v > r->val) {
                    insert(r->right, v);
                    if (height(r->right) - height(r->left) == 2) {
                        if (v < r->right->val) {
                            RL(r);
                        } else {
                            RR(r);
                        }
                    }
                } else {
                    r->count ++;
                }
            } else {
                r = new BinaryNode<Object>(v);
            }
        }
    private:
        void LL(BinaryNode<Object>* &r) {
            if (r) {
                BinaryNode<Object>* &k1 = r->left;
                BinaryNode<Object>* &k2 = k1->right;
                r->left = k2;
                k1->right = r;
                r->height = max(height(r->left), height(r->right)) + 1;
                k1->height = max(height(k1->left), height(k1->right)) + 1;
                r = k1;
            }
        }
        void RR(BinaryNode<Object>* &r) {
            if (r) {
                BinaryNode<Object>* &k1 = r->right;
                BinaryNode<Object>* &k2 = k1->left;;
                r->right = k2;
                k1->left = r;
                r->height = max(height(r->left), height(r->right)) + 1;
                k1->height = max(height(k1->left), height(k1->right)) + 1;
                r = k1;
            }
        }
        void LR(BinaryNode<Object>* &r) {
            if (r) {
                RR(r->left);
                LL(r);
            }
        }
        void RL(BinaryNode<Object>* &r) {
            if (r) {
                LL(r->right);
                RR(r);
            }
        }
};

}

}

#endif
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

