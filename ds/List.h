/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/18
 */

#ifndef ALGORITHM__LIST_H_
#define ALGORITHM__LIST_H_

#include <iostream>

namespace algorithm
{

namespace dataStruct
{

template<typename Object>
class List {
    public:
        struct Node {
            Object data;
            Node* prev;
            Node* next;
            Node(const Object& d = Object(), Node* p = NULL, Node* n = NULL) {
                data = d;
                prev = p;
                next = n;
            }
        };
        class iterator {
            public:
                iterator(Node* p = NULL) {
                    current = p;
                }
                ~iterator() {
                }
                Object& operator*() const {
                    return retrieve();
                }
                const iterator& operator++() {
                    current = current->next;
                    return *this;
                }
                const iterator& operator++(int) {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }
                const iterator& operator--() {
                    current = current->prev;
                    return *this;
                }
                const iterator& operator--(int) {
                    iterator old = *this;
                    --(*this);
                    return old;
                }
                bool operator==(const iterator& others) const {
                    return current == others.current;
                }
                bool operator!=(const iterator& others) const {
                    return current != others.current;
                }
            protected:
                Node* current;
                Object& retrieve() const {
                    return current->data;
                }
                friend class List<Object>;
        };
        List() {
            init();
        }
        List(const List& other) {
            init();
            operator=(other);
        }
        ~List() {
            clear();
        }
        const List& operator=(const List& other) {
            if (this == &other) {
                return *this;
            }
            clear();
            for(iterator it = other.begin(); it != other.end(); ++it) {
                push_back(*it); 
            }
            return *this;
        }
        iterator begin() const{
            return iterator(head->next);
        }
        iterator end() const{
            return iterator(tail);
        }
        int size() {
            return _size;
        }
        bool empty() {
            return _size == 0;
        }
        Object& front() {
            return *begin();
        }
        Object& back() {
            return *(--end());
        }
        void push_front(const Object& x) {
            insert(begin(), x);
        }
        void push_back(const Object& x) {
            insert(end(), x);
        }
        void pop_front() {
            if (size() > 0) {
                erase(begin());
            }
        }
        void pop_back() {
            if (size() > 0) {
                erase(--end());
            }
        }
        void clear() {
            while (!empty()) {
                pop_front();
            }
        }
        iterator insert(iterator itr, const Object& x) {
            Node* c = itr.current;
            if (c->prev != NULL) {
                _size ++;
                Node* t = new Node(x, c->prev, c);
                return iterator(c->prev = c->prev->next = t);
            } 
            return iterator();
        }
        void erase(iterator itr) {
            Node* c = itr.current;
            if (c) {
                _size --;
                c->prev->next = c->next;
                c->next->prev = c->prev;
                delete c;
            }
        }
        void reverse() {
            Node* c = head;
            while (c) {
                Node* n = c->next;
                c->next = c->prev;
                c->prev = n;
                c = n;
            }
            // swap head tail
            c = head;
            head = tail;
            tail = c;
        }
    private:
        int _size;
        Node* head;
        Node* tail;
        void init() {
            _size = 0;
            head = new Node();
            tail = new Node();
            head->next = tail;
            head->prev = NULL;
            tail->prev = head;
            tail->next = NULL;
        }
        void goStep(Node* p, int step) {
            if (step <= 0) return;
            while (step-- && p) p = p->next;
            return p;
        }

};

}// end for namespace dataStruct

}// end for namespace algorithm

#endif

//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

