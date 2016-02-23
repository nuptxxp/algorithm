/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/22
 */

#include <iostream>
#include <fstream>
#include "Stack.h"

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
            if (index&1) { // if } , ) , ]
                if (s.empty()) { // no {, (, [ found
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

char* read_from_file(const char* filename, int *len) {
    char* data;
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        *len = 0;
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    *len = ftell(fp);
    data = new char[(*len) + 1];
    rewind(fp);
    *len = fread(data, sizeof(char), *len, fp);
    data[*len] = '\0';
    fclose(fp);
    return data;
}

int main(int argc, char* argv[]) {
    char* filename = NULL;
    if (argc != 2) {
        std::cout << "args filename necessery!" << std::endl;
        return 1;
    } else {
        filename = argv[1];
    }
    int length = 0;
    char* text = read_from_file(filename, &length);
    if (!text) {
        std::cout << "file can't open or empty!" << std::endl;
        return 1;
    }
    if (match(text)) {
        std::cout << "match success" << std::endl;
    } else {
        std::cout << "match failed" << std::endl;
    }
    return 0;
}



//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

