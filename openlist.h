#ifndef OPENLIST_H
#define OPENLIST_H

#include "node.h"
#include "tinyxml2.h"
#include "tinyxml2.h"

#include <vector>

class OpenList {

public:
    OpenList();
    OpenList(int size_);

    ~OpenList();

    void resize(int size_);

    size_t get_size() const;
    bool is_empty() const;

    void put(Node* new_node);
    Node* get();
    bool top_key_less_than(Key cur_key);
    void remove_if(Node* item);

    tinyxml2::XMLElement *writeToXml(tinyxml2::XMLElement * element, tinyxml2::XMLNode *child) const;

private:
    std::list<Node*> *elements;
    int top_coord;
    size_t size;
    size_t height;
};

#endif // OPENLIST_H
