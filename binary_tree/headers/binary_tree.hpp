#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include "arena.hpp"

template <typename T>
struct Node {
    Node* m_parent_np;
    Node* m_left_child_np;
    Node* m_right_child_np;

    T m_value;

    void v_assignValue(T _value);
    Node* np_createNode(T _value);



    Node(T _value) {
        m_value = _value;
        m_parent_np = nullptr;
        m_left_child_np = nullptr;
        m_right_child_np = nullptr;

        std::cout << "Node w/type = " << typeid(T).name() << " was created\n";
        std::cout << "Node w/value = " << m_value << " was created\n";
    }
};

#endif // _BINARY_TREE_