#include "Nodes.h"

Nodes::Nodes() = default;

Nodes::Nodes(char na)
{
    setName(na);
}

Nodes::Nodes(char na, const std::vector<std::pair<Nodes*, int>>& n)
{
    setName(na);
    neighbors_ = n;
}

Nodes::Nodes(char na, Nodes* n, int w)
{
    setName(na);
    addNeighbor(n, w);
}

Nodes::~Nodes()
{
}

std::vector<std::pair<Nodes*, int>> Nodes::getNeighbors() const
{
    return neighbors_;
}

void Nodes::addNeighbor(Nodes* n, int w)
{
    neighbors_.emplace_back(n, w);
    n->neighbors_.emplace_back(this, w);
}

void Nodes::addNeighbor(std::vector<std::pair<Nodes*, int>> n)
{
    for(std::pair<Nodes*, int> p : n)
    {
        neighbors_.emplace_back(p);
        p.first->addNeighbor(this, p.second);
    }
}

void Nodes::removeNeighbor(Nodes* n)
{
    for(std::vector<std::pair<Nodes*, int>>::iterator it = neighbors_.begin(); it != neighbors_.end(); ++it)
    {
        if(it->first == n)
        {
            neighbors_.erase(it);
            break;
        }
    }
}

void Nodes::removeAllNeighbors()
{
    neighbors_.clear();
}

void Nodes::showNeighbors()
{
    std::cout << getName() << " : {" << std::endl;
    for(std::pair<Nodes*, int> p : neighbors_)
    {
        std::cout << "(" << p.first->getName() << " ; " << p.second << ")" << std::endl;
    }
    std::cout << "}" << std::endl;
}

char Nodes::getName() const
{
    return name_;
}

void Nodes::setName(char name)
{
    name_ = name;
}