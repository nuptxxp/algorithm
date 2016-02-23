/**
 * @author pengxiangxiong@baidu.com
 * @version 2016/02/23
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"
#include "List.h"

using namespace algorithm::dataStruct;

const int MAX_LINE_LENGTH = 10240;
// 10^0 ~ 9
const int tenFac[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
// operator about calculator
const char operators[] = {'(', ')', '+', '-', '*', '/', '%'};
const char operatorNums = 7;
// operator in stack and out stack priority
const int inPriority[] = {0, 0, 1, 2, 2, 2, 2};
const int outPriority[] = {3, 3, 1, 2, 2, 2, 2};
// char type
enum {
    NUMBER = 0,
    OPERATOR = 1,
    SPACE = 2,
    OTHERS = 3
};

inline int inOperator(char t) {
    for (int i = 0; i < operatorNums; ++i) {
        if (operators[i] == t) {
            return i;
        }
    }
    return -1;
}

int getType(char t) {
    if (t >= '0' && t <= '9') {
        return NUMBER;
    } else if (inOperator(t) != -1) {
        return OPERATOR;
    } else if (t == ' ' || t == '\n' || t == '\r') {
        return SPACE;
    }
    return OTHERS;
}

struct Token {
    Token(int n = 0) {
        num = n;
        type = NUMBER;
    } 
    Token(char t) {
        op = t;
        type = OPERATOR;
    }
    int num;
    char op;
    int type;
};

void print(const Vector<Token>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].type == NUMBER) {
            std::cout << v[i].num << " ";
        } else {
            std::cout << v[i].op << " ";
        }
    }
    std::cout << std::endl;
}

int getNumFromStack(Stack<char>& numStack) {
    int num = 0;
    int tenItr = 0;
    while (!numStack.empty()) {
        num += (numStack.top() - '0') * tenFac[tenItr++];
        numStack.pop();
    }
    return num;
}

Vector<Token> getToken(char *p) {
    Vector<Token> token;
    Stack<char> numStack;
    while (*p) {
        char t = *p;
        //std::cout << "t " << t << std::endl;
        int type = getType(t);
        if(type != NUMBER) {
            if (!numStack.empty()) {
                token.push_back(Token(getNumFromStack(numStack)));
            }
        }
        switch (type) {
            case NUMBER:
                numStack.push(t);
                break;
            case OPERATOR:
                token.push_back(Token(t)); 
                break;
            case SPACE:
                break;
            case OTHERS:
                throw std::invalid_argument("unrecorgnize charatctor");
                break;
            default:
                break;
        }
        p++;
    }
    if (!numStack.empty()) {
        token.push_back(Token(getNumFromStack(numStack)));
    }
    //std::cout << "token print \n";
    //print(token);
    return token;
}

List<Token> infixConvert(const Vector<Token>& infix) {
    List<Token> suffix;
    Stack<Token> ops;
    for (int i = 0; i < infix.size(); ++i) {
        Token t = infix[i];
        if (t.type == NUMBER) {
            suffix.push_back(t);
        } else {
            int index = inOperator(t.op);
            if (index != -1) {
                if (t.op == ')') {
                    bool foundMatchFlag = false;
                    while (!ops.empty()) {
                        if (ops.top().op != '(') {
                            suffix.push_back(ops.top());
                        } else {
                            foundMatchFlag = true;
                            ops.pop();
                            break;
                        }
                        ops.pop();
                    }
                    if (!foundMatchFlag) {
                        throw std::invalid_argument(") not match (");
                    }
                } else {
                    if (!ops.empty()) {
                        if (outPriority[index] > inPriority[inOperator(ops.top().op)]) {
                            ops.push(t);
                        } else {
                            suffix.push_back(ops.top());
                            ops.pop();
                            ops.push(t);
                        }
                    } else {
                        ops.push(t.op);
                    }
                }
            }
        }
    }
    while (!ops.empty()) {
        suffix.push_back(ops.top());
        ops.pop();
    }
    //std::cout << "suffix print \n";
    //print(suffix);
    return suffix;
}

/*
 * O(n * operators)
 * use list, when meet a operator, cal operator and lval rval and remove this 3 node and insert new node
 * By recursion, recursion end at no operator found
 *
 */
int calculator(List<Token>& v) {
    bool foundOp = false;
    for (List<Token>::iterator it = v.begin(); it != v.end(); ++it) {
        Token t = *it;
        if (t.type == OPERATOR) {
            foundOp = true;
            int ret = 0;
            // get rval iterator
            List<Token>::iterator rit = it;
            rit--;
            if (rit == v.begin()) {
                //std::cout << "line 186\n";
                throw std::runtime_error("no lval rval found");
            }
            Token rval = *rit;
            if (rval.type != NUMBER) {
                //std::cout << "line 191\n";
                throw std::runtime_error("no lval rval found");
            }
            // get lval iterator
            List<Token>::iterator lit = rit;
            lit--;
            Token lval = *lit;
            if (lval.type != NUMBER) {
                //std::cout << "line 202\n";
                throw std::runtime_error("no lval rval found");
            }
            switch (t.op) {
                case '+':
                    ret = lval.num + rval.num;
                    break;
                case '-':
                    ret = lval.num - rval.num;
                    break;
                case '*':
                    ret = lval.num * rval.num;
                    break;
                case '/':
                    if (rval.num == 0) {
                        throw std::runtime_error("dived by 0 error");
                    }
                    ret = lval.num / rval.num;
                    break;
                case '%':
                    if (rval.num == 0) {
                        throw std::runtime_error("dived by 0 error");
                    }
                    ret = lval.num % rval.num;
                    break;
                default:
                    throw std::runtime_error("unrecorgnize operator found");
            }
            List<Token>::iterator cit = it;
            ++it;
            v.erase(lit);
            v.erase(rit);
            v.erase(cit);
            v.insert(it, Token(ret));
            return calculator(v);
        }
    }
    if (!foundOp) {
        if (v.size() != 1) {
            throw std::runtime_error("last result error");
        }
        if (v.front().type != NUMBER) {
            throw std::runtime_error("last result error");
        }
    }
    return v.front().num;
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), stdin)) {
        try {
            List<Token> l = infixConvert(getToken(line));
            std :: cout << calculator(l) << '\n';
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid input argument: " << ia.what() << '\n';
        } catch (const std::runtime_error& ia) {
            std::cerr << "calculator error: " << ia.what() << '\n';
        }
    }
    return 0;
}



//vim: set expandtab ts=4 sw=4 sts=4 tw=100:

