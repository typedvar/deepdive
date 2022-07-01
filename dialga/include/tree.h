#pragma once

#include <vector>
#include <string>
#include <stack>

namespace dialga
{
    namespace containers
    {
        template <typename T>
        struct tree
        {
            using nodeStackT = std::stack<tree<T>*>;

            T* _data = nullptr; // default constructible
            tree<T>* _left = nullptr;
            tree<T>* _right = nullptr;

            tree<T>(T val)
                : _data(new T(val)) {}

            tree<T>() {}

            ~tree<T>()
            {
                delete _left;
                delete _right;
                delete _data;
            }

            tree<T>(tree<T>&& source)
                : _data(source._data)
                , _left(source._left)
                , _right(source._right)
            {
                source._data = nullptr;
                source._left = nullptr;
                source._right = nullptr;
            }

            tree<T>* insert(T val)
            {
                tree<T>* ret = this;

                if (!_data)
                {
                    _data = new T(val);
                }
                else
                {
                    if (val < *_data)
                    {
                        if (_left)
                        {
                            ret = _left->insert(val);
                        }
                        else
                        {
                            _left = new tree<T>(val);
                            ret = _left;
                        }
                    }
                    else if (*_data < val)
                    {
                        if (_right)
                        {
                            ret = _right->insert(val);
                        }
                        else
                        {
                            _right = new tree<T>(val);
                            ret = _right;
                        }
                    }
                }
                return ret;
            }

            void inOrder(std::vector<T>& out)
            {
                if (_left)
                {
                    _left->inOrder(out);
                }

                if (_data)
                {
                    out.push_back(*_data);
                }

                if (_right)
                {
                    _right->inOrder(out);
                }
            }

            void preOrder(std::vector<T>& out)
            {
                if (_data)
                {
                    out.push_back(*_data);
                }

                if (_left)
                {
                    _left->preOrder(out);
                }

                if (_right)
                {
                    _right->preOrder(out);
                }
            }

            void postOrder(std::vector<T>& out)
            {
                if (_left)
                {
                    _left->postOrder(out);
                }

                if (_right)
                {
                    _right->postOrder(out);
                }

                if (_data)
                {
                    out.push_back(*_data);
                }
            }

            void inOrderNoRec(std::vector<T>& out)
            {
                nodeStackT nodeStack;
                tree<T>* curr = this;
                bool done = false;

                while (!done)
                {
                    while (curr)
                    {
                        nodeStack.push(curr);
                        curr = curr->_left;
                    }

                    curr = nodeStack.top();
                    out.push_back(*(curr->_data));
                    curr = curr->_right;

                    nodeStack.pop();
                    if (!curr && nodeStack.empty())
                    {
                        done = true;
                    }
                }
            }

            tree<T>* balancedCreate(std::vector<T>& nodeVals, size_t start, size_t end)
            {
                tree<T>* ret = nullptr;

                if (end >= start)
                {
                    size_t diff = end - start;
                    // two or less nodes - create both
                    if (diff < 2)
                    {
                        tree<T>* nodeL = new tree<T>(nodeVals[start]);
                        if (end != start)
                        {
                            tree<T>* nodeR = new tree<T>(nodeVals[end]);
                            nodeL->_right = nodeR;
                        }
                        ret = nodeL;
                    }
                    else
                    {
                        size_t mid = (end - start) / 2 + start;
                        T val = nodeVals[mid];
                        ret = new tree<T>(val);

                        if (mid > 0)
                        {
                            tree<T>* left = balancedCreate(nodeVals, start, mid - 1);
                            tree<T>* right = balancedCreate(nodeVals, mid + 1, end);
                            ret->_left = left;
                            ret->_right = right;
                        }
                    }
                }
                return ret;
            }

            std::string toString(int level)
            {
                std::string ret;
                if (_data)
                {
                    std::stringstream ss;
                    ss << *_data;
                    ret = "(" + ss.str() + ")";
                }

                std::string indent;
                if (level > 0)
                {
                    indent = std::string(level - 1, ' ');
                    indent += "|_";
                }

                if (_left)
                {
                    ret += "\n";
                    ret += indent;
                    ret += "<L>";
                    ret += _left->toString(++level);
                }
                else
                {
                    ret += "\n";
                    ret += indent;
                    ret += "<L>";
                    ret += "(.)";
                }

                if (_right)
                {
                    ret += "\n";
                    ret += indent;
                    ret += "<R>";
                    ret += _right->toString(++level);
                }
                else
                {
                    ret += "\n";
                    ret += indent;
                    ret += "<R>";
                    ret += "(.)";
                }
                return ret;
            }

            tree<T>* balance()
            {
                tree<T>* ret = nullptr;
                std::vector<T> sortedVals;
                inOrder(sortedVals);
                if (!sortedVals.empty())
                {
                    ret = balancedCreate(sortedVals, 0, sortedVals.size() - 1);
                }
                return ret;
            }
        };
    }
}

// eof

