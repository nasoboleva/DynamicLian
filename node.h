#ifndef NODE_H
#define NODE_H

#include <memory>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

struct circleNode
{
    int i, j;
    double heading;
    double cost;

    circleNode(): i(-1), j(-1), heading(-1), cost(0) {}
    circleNode(int i, int j, double cost): i(i), j(j), heading(-1), cost(cost) {}
    circleNode(int i, int j, double heading, double cost): i(i), j(j), heading(heading), cost(cost) {}
};

struct Key{
    double k1, k2;

    Key() : k1(std::numeric_limits<double>::infinity()), k2(std::numeric_limits<double>::infinity()) {}
    Key(double k1_, double k2_) : k1(k1_), k2(k2_) {}
    Key(const Key& other) : k1(other.k1), k2(other.k2) {}

    inline bool operator==(const Key& p) const {
        return k1 == p.k1 && k2 == p.k2;
    }
    inline bool operator!=(const Key& p) const {
        return !(*this == p);
    }
    inline bool operator<(const Key& p) const {
        return k1 < p.k1 || (k1 == p.k1 && k2 <= p.k2);
    }

    Key& operator=(const Key& other) {
        if (this == &other) {
            return *this;
        }
        k1 = other.k1;
        k2 = other.k2;
        return *this;
    }

};


class Node {
public:
    float rhs, g;
    Key key;
    //Cell cell;
    int i, j;

    Node *parent;

    int   radius;
    double angle;

    Node() : i(-1), j(-1), F(std::numeric_limits<float>::infinity()), g(std::numeric_limits<float>::infinity()), rhs(std::numeric_limits<float>::infinity()),
             parent(nullptr), radius(CN_PTD_D), angle(0) {}

    Node(int x, int y,  Node *parent_=nullptr, float g_=std::numeric_limits<float>::infinity(), float rhs_ = std::numeric_limits<float>::infinity(),
         float radius_=CN_PTD_D, double ang_=0) :
        i(x), j(y), g(g_), rhs(rhs_), radius(radius_), parent(parent_), angle(ang_) {
    }

    ~Node() {
        parent = nullptr;
    }

    inline Node& operator=(const Node& other) {
        i = other.i;
        j = other.j;
        F = other.F;
        g = other.g;
        parent = other.parent;
        angle = other.angle;
        radius = other.radius;
        key = other.key;
        return *this;
    }

    inline bool operator==(const Node& p) const {
            return i == p.i && j == p.j && parent->i == p.parent->i && parent->j == p.parent->j;
    }

    inline bool operator!=(const Node& p) const {
            return !(*this == p);
    }

    int convolution(int width) const {
            return i * width + j;
    }

    bool IsConsistent() const {
        return g == rhs;
    }
};

inline std::ostream& operator<< (std::ostream& out, const Node &next) {
    out << "(" << next.cell.x << "," << next.cell.y << "); ";
    return out;
}

#endif // NODE_H