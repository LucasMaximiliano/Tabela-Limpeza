#ifndef _CLASSES_H_
#define _CLASSES_H_

#include <string>
#include <iostream>

// NODE =========================================================================================

class Ciclic_list_node
{
private:
    std::string room;
    Ciclic_list_node* next;
public:
    Ciclic_list_node();
    Ciclic_list_node(const std::string room_val, Ciclic_list_node* next_val);
    void set_room(const std::string room_val);
    void set_next(Ciclic_list_node* next_val);
    std::string get_room();
    Ciclic_list_node* get_next();
    ~Ciclic_list_node();
};

// LIST =========================================================================================

class Ciclic_list
{
private:
    Ciclic_list_node* anchor;
public:
    Ciclic_list(Ciclic_list_node* anchor_val = NULL);
    void pushback(Ciclic_list_node& new_node);
    void print_list();
    Ciclic_list_node* get_anchor();
    ~Ciclic_list();
};

#endif