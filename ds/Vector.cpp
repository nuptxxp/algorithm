/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/18
 */

#include <iostream>
#include <assert.h>
using namespace std;

namespace algorithm
{

template <typename Object>
class Vector {
    public:
        explicit Vector(int initSize = 0) {
            initSize = initSize < 0 ? 0 : initSize;
            _size = 0;
            _capacity = initSize + SPARE_CAPACITY;
            objects = new Object[_capacity];
        }
        Vector(const Vector& others) {
            operator=(others);
        }
        ~Vector() {
            delete [] objects;
        }
        const Vector& operator=(const Vector& others) {
            if (this != &others) {
                delete [] objects;
                _size = others.size();
                _capacity = others.capacity();
                objects = new Object[_capacity];
                for (int i = 0; i < _size; ++i) {
                    objects[i] = others.objects[i];
                }
            }
            return *this;
        }
        void resize(int newSize) {
            if (newSize >= _capacity) {
                reserve(_capacity * 2 + 1);
            }
            _size = newSize;
        }
        void reserve(int newCapacity) {
            if (_size > newCapacity) {
                return;
            }
            Object* old = objects;
            objects = new Object[newCapacity];
            for (int i =0; i < size(); ++i) {
                objects[i] = old[i];
            }
            _capacity = newCapacity;
            delete [] old;
        }
        Object& operator[](int index) {
            return objects[index];
        }
        bool empty() const {
            return size() == 0;
        }

        int size() const {
            return _size;
        }

        int capacity() const {
            return _capacity;
        }

        void push_back(const Object& v) {
            if (_size == _capacity) {
                reserve(_capacity * 2 + 1);
            }
            objects[_size ++] = v;
        }

        void pop_back() {
            if (_size > 0) {
                _size --;
            }
        }

        const Object& back() const {
            return objects[_size -1];
        }

        typedef Object* iterator;

        iterator begin() {
            return &objects[0];
        }

        iterator Vector<Object>::end() {
            return &objects[_size];
        }

        enum {
            SPARE_CAPACITY = 16,
        };
    private:
        int _size;
        int _capacity;
        Object* objects;
};

}

typedef algorithm::Vector<int> Vector;
int main()
{
    Vector v1;
    Vector v2(10);
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
    return 0;
}
//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

