/*******************************************************************/
/*                    Algorithm de Dijkstra's                      */
/*                          By Maxime66410                         */
/*     Point de départ et d'arriver choisie par l'utilisateur      */
/*******************************************************************/
#include "Nodes.h"

int main(int argc, char* argv[])
{
    std::vector<Nodes*> graphs;
    Nodes A('A');
    Nodes B('B');
    Nodes C('C');
    Nodes D('D');
    Nodes E('E');
    Nodes F('F');
    Nodes G('G');
    Nodes H('H');
    Nodes I('I');
    Nodes J('J');

    A.addNeighbor(&B, 85);
    A.addNeighbor(&C, 217);
    A.addNeighbor(&E, 173);

    B.addNeighbor(&F, 80);

    C.addNeighbor(&G, 186);
    C.addNeighbor(&H, 103);

    D.addNeighbor(&H, 183);

    E.addNeighbor(&J, 502);

    F.addNeighbor(&I, 250);

    H.addNeighbor(&J, 167);

    I.addNeighbor(&J, 84);

    graphs.emplace_back(&A);
    graphs.emplace_back(&B);
    graphs.emplace_back(&C);
    graphs.emplace_back(&D);
    graphs.emplace_back(&E);
    graphs.emplace_back(&F);
    graphs.emplace_back(&G);
    graphs.emplace_back(&H);
    graphs.emplace_back(&I);
    graphs.emplace_back(&J);

    // Affichage des voisins de chaque noeud
    for(Nodes* n : graphs)
    {
        n->showNeighbors();
        std::cout << std::endl;
    }

    // Demande à l'utilisateur de choisir le point de départ et d'arriver pour l'algorithme de Dijkstra
    char start, end;
    std::cout << "Liste des points : ";
    for(Nodes* n : graphs)
    {
        std::cout << n->getName() << " ";
    }
    
    std::cout << std::endl << "Entrez le point de depart : ";
    std::cin >> start;
    std::cout << "Point de depart : " << start << std::endl;
    std::cout << "Entrez le point d'arriver : ";
    std::cin >> end;

    // Algorithme de Dijkstra
    std::vector<std::pair<Nodes*, int>> shortestPath;
    std::vector<std::pair<Nodes*, int>> unvisited;
    std::vector<std::pair<Nodes*, int>> visited;
    Nodes* current = nullptr;
    Nodes* startNode = nullptr;
    Nodes* endNode = nullptr;
    int weight = 0;

    // Initialisation de l'algorithme
    for(Nodes* n : graphs)
    {
        if(n->getName() == start)
        {
            startNode = n;
            unvisited.emplace_back(n, 0);
        }
        else
        {
            unvisited.emplace_back(n, graphs.size());
        }
    }

    // Algorithme
    while(!unvisited.empty())
    {
        current = unvisited[0].first;
        weight = unvisited[0].second;
        unvisited.erase(unvisited.begin());
        visited.emplace_back(current, weight);

        for(std::pair<Nodes*, int> p : current->getNeighbors())
        {
            if(p.first->getName() == end)
            {
                endNode = p.first;
                break;
            }
            else
            {
                for(std::pair<Nodes*, int> u : unvisited)
                {
                    if(u.first == p.first)
                    {
                        if(u.second > weight + p.second)
                        {
                            u.second = weight + p.second;
                        }
                    }
                }
            }
        }
    }

    // Affichage du chemin le plus court
    std::cout << "Chemin le plus court : ";
    for(std::pair<Nodes*, int> p : visited)
    {
        if(p.first == endNode)
        {
            std::cout << p.first->getName() << " (" << p.second << ")";
            break;
        }
    }
    
    // Suppression des vecteurs
    shortestPath.clear();
    unvisited.clear();
    visited.clear();
    graphs.clear();

    // Suppression des variables
    weight = 0;

    // Fin du programme
    return 0;
}