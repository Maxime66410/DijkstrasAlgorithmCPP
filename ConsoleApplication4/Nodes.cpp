#include "Nodes.h"

Nodes::Nodes() = default; // Constructeur par défaut

// Constructeur avec un paramètre
Nodes::Nodes(char na)
{
    setName(na);
}

// Constructeur avec deux paramètres
Nodes::Nodes(char na, const std::vector<std::pair<Nodes*, int>>& n)
{
    setName(na);
    neighbors_ = n;
}

// Constructeur avec trois paramètres
Nodes::Nodes(char na, Nodes* n, int w)
{
    setName(na);
    addNeighbor(n, w);
}

Nodes::~Nodes() = default; // Destructeur

// Retourne les voisins
std::vector<std::pair<Nodes*, int>> Nodes::getNeighbors() const
{
    return neighbors_;
}

// Ajoute un voisin
void Nodes::addNeighbor(Nodes* n, int w)
{
    neighbors_.emplace_back(n, w);
    n->neighbors_.emplace_back(this, w);
}

// Ajoute plusieurs voisins
void Nodes::addNeighbor(std::vector<std::pair<Nodes*, int>> n)
{
    for(std::pair<Nodes*, int> p : n)
    {
        neighbors_.emplace_back(p);
        p.first->addNeighbor(this, p.second);
    }
}

// Supprime un voisin
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

// Supprime tous les voisins
void Nodes::removeAllNeighbors()
{
    neighbors_.clear();
}

// Affiche les voisins
void Nodes::showNeighbors()
{
    std::cout << getName() << " : {" << std::endl;
    for(std::pair<Nodes*, int> p : neighbors_)
    {
        std::cout << "(" << p.first->getName() << " ; " << p.second << ")" << std::endl;
    }
    std::cout << "}" << std::endl;
}

// Retourne le nom
char Nodes::getName() const
{
    return name_;
}

// Modifie le nom
void Nodes::setName(char name)
{
    name_ = name;
}