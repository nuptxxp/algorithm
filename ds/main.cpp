/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/19
 */

#include <iostream>
#include <assert.h>
#include "Vector.h"
#include "List.h"

using namespace std;

typedef algorithm::dataStruct::Vector<int> Vector;
typedef algorithm::dataStruct::List<int> List;
int main()
{
    // test for Vector
    cout << "test Vector" << endl;
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
    v2.pop_back();
    assert(v2.back() == 8);
    int index = 0;
    for (Vector::iterator it = v2.begin(); it != v2.end(); ++it) {
        assert(*it == index);
        index ++;
    }


    // test for List
    cout << "-------------------------------------" << endl;
    cout << "test List" << endl;
    List l;
    for (int i = 0; i < 10; ++i) {
        l.push_back(i);
    }
    assert(l.front() == 0);
    assert(l.back() == 9);
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
    cout << *it << endl;
    cout << l.back() << endl;
    List l2 = l;
    l2.pop_front();
    cout << l2.front() << endl;
    cout << l.front() << endl;
    return 0;
}

//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

