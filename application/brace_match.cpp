/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/22
 */

#include <iostream>
#include "Stack.h"
#include "Vector.h"

using namespace algorithm::dataStruct;

const char BRACE[] = {'{', '}', '(', ')', '[', ']'};
const int BRACE_NUM = 6;

int in_brace(char t) {
    for (int i = 0; i < BRACE_NUM; ++i) {
        if (t == BRACE[i]) return i;
    }
    return -1;
}

bool match(char* context) {
    if (!context) return true;
    Stack<char> s;
    while (*context) {
        int index = in_brace(*context);
        if (index != -1) {
            if (index&1) {
                if (s.empty()) {
                    return false;
                } else {
                    char match = BRACE[index - 1];
                    if (match == s.top()) {
                        s.pop();
                    }
                }
            } else {
                s.push(*context);
            }
        }
        context++;
    }
    return s.empty();
}

int main() {
    char* text = "hll{}[]()";
    if (match(text)) {
        std::cout << "match success" << std::endl;
    } else {
        std::cout << "match failed" << std::endl;
    }
    return 0;
}



//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

