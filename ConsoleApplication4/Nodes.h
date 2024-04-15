#pragma once
#include <vector>
#include <iostream>

class Nodes
{
public:
    Nodes(); // Constructeur par défaut
    Nodes(char); // Constructeur avec un paramètre
    Nodes(char, const std::vector<std::pair<Nodes*, int>>&); // Constructeur avec deux paramètres
    Nodes(char, Nodes*, int); // Constructeur avec trois paramètres
    ~Nodes(); // Destructeur
    
    std::vector<std::pair<Nodes*, int>> getNeighbors() const; // Retourne les voisins
    
    void addNeighbor(Nodes*, int); // Ajoute un voisin
    void addNeighbor(std::vector<std::pair<Nodes*, int>>); // Ajoute plusieurs voisins
    void removeNeighbor(Nodes*); // Supprime un voisin
    void removeAllNeighbors(); // Supprime tous les voisins
    void showNeighbors(); // Affiche les voisins

    char getName() const; // Retourne le nom
    void setName(char); // Modifie le nom

private:
    char name_; // Nom du noeud
    std::vector<std::pair<Nodes*, int>> neighbors_; // Voisins du noeud
};
