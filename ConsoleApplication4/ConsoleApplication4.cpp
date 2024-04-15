/*******************************************************************/
/*                    Algorithm de Dijkstra's                      */
/*                          By Maxime66410                         */
/*     Point de départ et d'arriver choisie par l'utilisateur      */
/*******************************************************************/
#include <queue> // Librairie pour la file de priorité
#include <stack> // Librairie pour la pile
#include <unordered_map> // Librairie pour la table de hachage
#include "Nodes.h" // Librairie pour les noeuds

// Algorithme de Dijkstra
void dijkstra(Nodes* start, Nodes* end) {
    std::unordered_map<Nodes*, int> dist; // Table de hachage pour les distances
    std::unordered_map<Nodes*, Nodes*> prev; // Table de hachage pour les noeuds précédents
    std::priority_queue<std::pair<int, Nodes*>, std::vector<std::pair<int, Nodes*>>, std::greater<std::pair<int, Nodes*>>> pq; // File de priorité pour les noeuds

    dist[start] = 0; // Initialisation de la distance du point de départ à 0
    pq.push({0, start}); // Ajout du point de départ dans la file de priorité

    // Boucle pour trouver le chemin le plus court entre le point de départ et d'arriver
    while (!pq.empty()) {
        Nodes* u = pq.top().second; // Récupération du noeud avec la plus petite distance
        int d = pq.top().first; // Récupération de la distance du noeud
        pq.pop(); // Suppression du noeud de la file de priorité

        if (u == end) break; // Arrêt de la boucle si le noeud est le point d'arriver

        // Boucle pour trouver le chemin le plus court entre le point de départ et d'arriver
        for (std::pair<Nodes*, int> neighbor : u->getNeighbors()) {
            Nodes* v = neighbor.first; // Récupération du voisin du noeud
            int weight = neighbor.second; // Récupération du poids du voisin
            
            // Vérification si la distance du voisin est plus grande que la distance du noeud plus le poids du voisin
            if (dist.find(v) == dist.end() || dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight; // Ajout de la distance du voisin dans la table de hachage
                prev[v] = u; // Ajout du noeud précédent dans la table de hachage
                pq.push({dist[v], v}); // Ajout du voisin dans la file de priorité
            }
        }
    }

    // Affichage du chemin le plus court entre le point de départ et d'arriver
    if (prev.find(end) == prev.end()) {
        std::cout << "Pas de chemin trouver entre " << start->getName() << " et " << end->getName() << std::endl;
        return;
    }

    std::stack<Nodes*> path; // Pile pour le chemin le plus court
    Nodes* current = end; // Initialisation du noeud courant avec le point d'arriver

    // Boucle pour trouver le chemin le plus court entre le point de départ et d'arriver
    while (current != nullptr) {
        path.push(current); // Ajout du noeud courant dans la pile
        current = prev[current]; // Récupération du noeud précédent
    }

    // Affichage du chemin le plus court entre le point de départ et d'arriver
    std::cout << "Chemin le plus court de " << start->getName() << " a " << end->getName() << " : ";
    
    // La boucle s'arrête si la pile est vide
    while (!path.empty()) {
        std::cout << path.top()->getName() << " (" << dist[path.top()] << ") -> ";
        path.pop(); // Suppression du noeud de la pile
    }
    std::cout << "Point d'arriver " << end->getName() << std::endl;

    // Suppression des variables
    dist.clear();
    prev.clear();
    while (!pq.empty()) pq.pop();
}

int main(int argc, char* argv[])
{
    // Initialisation des noeuds
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

    // Initialisation des voisins de chaque noeud
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

    // Ajout des noeuds dans le vecteur graphs
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

    // Demande à l'utilisateur de choisir le point de départ et d'arriver pour l'algorithme de Dijkstra
    char start, end;
    std::cout << std::endl << "Entrez le point de depart : ";
    std::cin >> start;
    std::cout << "Point de depart : " << start << std::endl;
    std::cout << "Entrez le point d'arriver : ";
    std::cin >> end;

    // Trouver le nodes start et end et les sauvegarder dans les variables startNode et endNode
    Nodes* startNode = nullptr;
    Nodes* endNode = nullptr;
    for (Nodes* n : graphs) {
        if (n->getName() == start) startNode = n;
        if (n->getName() == end) endNode = n;
    }

    // Algorithme de Dijkstra
    dijkstra(startNode, endNode);

    // Fin du programme
    return 0;
}

// Version 1 de l'algorithme de Dijkstra
/*
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

    // Algorithme de Dijkstra pour trouver le plus court chemin entre le point de départ et d'arriver choisi par l'utilisateur et affichage du résultat du chemin le plus court, enregistrer le chemin le plus court dans shortestPath
    while(!unvisited.empty())
    {
        current = unvisited[0].first;
        weight = unvisited[0].second;
        shortestPath.emplace_back(current, weight);
        visited.emplace_back(current, weight);
        unvisited.erase(unvisited.begin());

        if(current->getName() == end)
        {
            // Affichage du chemin le plus court
            std::cout << "Chemin le plus court : ";
            for(std::pair<Nodes*, int> p : shortestPath)
            {
                std::cout << p.first->getName() << " ";
            }
            break;
        }

        for(std::pair<Nodes*, int> p : current->getNeighbors())
        {
            bool isVisited = false;
            for(std::pair<Nodes*, int> v : visited)
            {
                if(p.first == v.first)
                {
                    isVisited = true;
                    break;
                }
            }

            if(!isVisited)
            {
                bool isUnvisited = false;
                for(std::pair<Nodes*, int> u : unvisited)
                {
                    if(p.first == u.first)
                    {
                        isUnvisited = true;
                        break;
                    }
                }

                if(isUnvisited)
                {
                    for(std::pair<Nodes*, int>& u : unvisited)
                    {
                        if(p.first == u.first)
                        {
                            if(u.second > weight + p.second)
                            {
                                u.second = weight + p.second;
                            }
                        }
                    }
                }
                else
                {
                    unvisited.emplace_back(p.first, weight + p.second);
                }
            }
        }
    }
    
    
    // Suppression des vecteurs
    shortestPath.clear();
    unvisited.clear();
    visited.clear();
    graphs.clear();

    // Suppression des variables
    weight = 0;
*/