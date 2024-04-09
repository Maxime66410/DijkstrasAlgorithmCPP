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
    
    
    
    return 0;
}