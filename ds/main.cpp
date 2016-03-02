/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/19
 */

#include <iostream>
#include <utility>
#include <assert.h>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"

using namespace std;

typedef algorithm::dataStruct::Vector<int> Vector;
typedef algorithm::dataStruct::List<int> List;
typedef algorithm::dataStruct::Stack<int> Stack;
typedef algorithm::dataStruct::Stack< pair<int, int> > PStack;
typedef algorithm::dataStruct::Queue< pair<int, int> > Queue;
typedef algorithm::dataStruct::BinarySearchTree<int> BinarySearchTree;
typedef algorithm::dataStruct::AVLTree<int> AVLTree;
int main()
{
    // test for Vector
    cout << "-------------------------------------" << endl;
    cout << "------------test Vector--------------" << endl;
    Vector v1(10);
    for (Vector::iterator it = v1.begin(); it != v1.end(); it++) {
        assert(*it == 0);
    }
    Vector v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(i);
    }
    Vector v3 = v2;
    assert(v3.size() == 10);
    v3.resize(20);
    assert(v3.size() == 20);
    assert(v3[2] == 2);
    assert(v2.back() == 9);
    v3[2] = 5;
    assert(v2[2] == 2);
    v2.pop_back();
    assert(v2.back() == 8);
    int index = 0;
    for (Vector::iterator it = v2.begin(); it != v2.end(); ++it) {
        assert(*it == index);
        index ++;
    }
    cout << "-----------test Vector ok------------" << endl;


    // test for List
    cout << "-------------------------------------" << endl;
    cout << "------------test List----------------" << endl;
    List l;
    assert(l.empty());
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }
    assert(l.front() == 0);
    assert(l.back() == 9);
    assert(l.size() == 10);
    assert(!l.empty());
    for (List::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    l.reverse();
    cout << "after reverse" << endl;
    for (List::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    List::iterator it = l.begin();
    it++;
    List::iterator it2 = it;
    it2++;
    l.erase(it2);
    l.erase(it);
    cout << *it << endl;
    cout << l.back() << endl;
    List l2 = l;
    l2.pop_front();
    cout << l2.front() << endl;
    cout << l.front() << endl;
    cout << "------------test List ok-------------" << endl;


    // test for stack
    cout << "-------------------------------------" << endl;
    cout << "------------test stack---------------" << endl;
    Stack s;
    s.push(1);
    s.push(5);
    s.push(9);
    Stack n = s;
    cout << "size: " << s.size() << " ele:";
    while (!s.empty()) {
        cout << " " << s.top();
        s.pop();
    }
    cout << endl;
    cout << "size: " << n.size() << " ele:";
    while (!n.empty()) {
        cout << " " << n.top();
        n.pop();
    }
    cout << endl;

    PStack ps;
    ps.push(pair<int,int>(1,2));
    ps.push(pair<int,int>(2,3));
    ps.push(pair<int,int>(3,4));
    while (!ps.empty()) {
        cout << ps.top().first << " " << ps.top().second << " ";
        ps.pop();
    }
    cout << endl;
    cout << "------------test stack ok------------" << endl;


    // test for queue
    cout << "test for queue" << endl;
    Queue q;
    q.push(pair<int,int>(1,2));
    q.push(pair<int,int>(2,3));
    while (!q.empty()) {
        cout << " " << q.front().first << " " << q.front().second << endl;
        q.pop();
    }


    // test for binary Tree
    cout << "-------------------------------------" << endl;
    cout << "-----------test binary tree ---------" << endl;
    BinarySearchTree BST;
    BST.insert(5);
    BST.insert(3);
    BST.insert(9);
    BST.insert(0);
    BST.insert(-1);
    BST.insert(-10);
    BST.insert(0);
    BST.print();
    assert(BST.search(0) == 2);
    assert(BST.search(-1) == 1);
    assert(BST.search(5) == 1);
    assert(BST.search(-2) == 0);
    assert(BST.search(12) == 0);
    assert(BST.remove(0) == 2);
    assert(BST.search(0) == 0);
    cout << "-----------test binary tree  end -----" << endl;

    // test for avl tree
    cout << "--------------------------------------" << endl;
    cout << "-----------test AVL tree -------------" << endl;
    AVLTree avlt;
    avlt.insert(5);
    avlt.insert(0);
    avlt.insert(-2);
    avlt.insert(-4);
    avlt.insert(-6);
    avlt.print();
    return 0;
}

//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

