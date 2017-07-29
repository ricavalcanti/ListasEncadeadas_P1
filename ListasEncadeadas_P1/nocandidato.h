#include <iostream>
#include <cstring>
#include <sstream>
#include "candidato.h"

using namespace std;

class NoCandidato
{

public:
    Candidato *conteudo;
    NoCandidato *next;

    NoCandidato(Candidato *c, NoCandidato *n)
    {
        this-> conteudo = c;
        this-> next = n;
    }
    string toString()
    {
        stringstream stream;
        NoCandidato *aux = next;

        stream << conteudo->toString() << " -> ";
        while(aux != NULL)
        {
            stream << aux->conteudo->toString() << " -> ";
            aux = aux->next;
        }

        if(aux == NULL) stream << "0";

        return stream.str();
    }
};
