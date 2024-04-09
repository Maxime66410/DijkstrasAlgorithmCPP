#pragma once
#include <vector>
#include <iostream>

class Nodes
{
public:
    Nodes();
    Nodes(char);
    Nodes(char, const std::vector<std::pair<Nodes*, int>>&);
    Nodes(char, Nodes*, int);
    ~Nodes();
    
    std::vector<std::pair<Nodes*, int>> getNeighbors() const;
    
    void addNeighbor(Nodes*, int);
    void addNeighbor(std::vector<std::pair<Nodes*, int>>);
    void removeNeighbor(Nodes*);
    void removeAllNeighbors();
    void showNeighbors();

    char getName() const;
    void setName(char);

private:
    char name_;
    std::vector<std::pair<Nodes*, int>> neighbors_;
};
