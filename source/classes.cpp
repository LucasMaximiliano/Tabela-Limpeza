#include "classes.h"

// NODE =============================================================================================

Ciclic_list_node::Ciclic_list_node()
{
    quarto = "none";
    next = this;
}

Ciclic_list_node::Ciclic_list_node(const std::string quarto_val, Ciclic_list_node* next_val)
{
    quarto = quarto_val;
    next = next_val;
}

void Ciclic_list_node::set_quarto(const std::string quarto_val)
{
    quarto = quarto_val;
}

void Ciclic_list_node::set_next(Ciclic_list_node* next_val)
{
    next = next_val;
}

std::string Ciclic_list_node::get_quarto()
{
    return quarto;
}

Ciclic_list_node* Ciclic_list_node::get_next()
{
    return next;
}

Ciclic_list_node::~Ciclic_list_node()
{
}

// LIST =============================================================================================

Ciclic_list::Ciclic_list(Ciclic_list_node* anchor_val)
{
    anchor = anchor_val;
}

// Inserir obj logo antes de anchor
void Ciclic_list::pushback(Ciclic_list_node& new_node)
{
    Ciclic_list_node* temp = anchor;
    if(temp==NULL)  return;
    while(temp->get_next()!=anchor)
        temp = temp->get_next();
    temp->set_next(&new_node);
    new_node.set_next(anchor);
}

void Ciclic_list::print_list()
{
    Ciclic_list_node* temp = anchor;
    if(temp==NULL)  return;
    int count = 1;
    do {
        std::cout << "Quarto" << count << " : " << temp->get_quarto() << std::endl;
        temp = temp->get_next();
        count++;
    } while(temp!=anchor);

}

Ciclic_list_node* Ciclic_list::get_anchor()
{
    return anchor;
}

Ciclic_list::~Ciclic_list()
{
}
