//
//  mapImpl.h
//
//  Auteur : Jean Goulet
//  Copyleft  2017 UdeS
//
//  Modifie par : Vincent Ducharme, Hiver 2018
//
//  Devoir fait par
//     Coéquipier 1 :
//     Coéquipier 2 :

#ifndef mapImpl_h
#define mapImpl_h

#include <algorithm>
#include <iostream>

///////////////////////////////////////////////////////////////////////////
// lower_bound O(log n)

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::lower_bound(const Tclef& c) const
{
    noeud* n = m_apres->m_gauche;
    noeud* lower = m_apres;

    while (n != nullptr) {
        if (n->m_contenu->first < c)
            n = n->m_droite;
        else
        {
            lower = n;
            n = n->m_gauche;
        }
    }

    return iterator(lower);
}

///////////////////////////////////////////////////////////////////////////
//erase a partir d'une position

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::erase(iterator i)
{
    assert(i!=end());

    noeud* aRemplacer = i.m_courant;
    if (!aRemplacer) return ++i;

    noeud* p = aRemplacer->m_parent;
    Tclef c = (*i).first;

    if (p == m_apres) {
        enlever_gauche(c, p, aRemplacer);
        return ++i;
    }

    if (c < p->m_contenu->first) 
        enlever_gauche(c, p, aRemplacer);

    if (p->m_contenu->first < c)
        enlever_droite(c, p, aRemplacer);

    return ++i;
}

///////////////////////////////////////////////////////////////////////////
//insert avec indice

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::insert(iterator j, const Tclef& c, const Tvaleur& val)
{
    iterator retour;
    insert(c, val, j.m_courant, retour);
    return j;
}

///////////////////////////////////////////////////////////////////////////
// gestion de l'equilibre de l'arbre


//effectuer une rotation simple de la gauche vers la droite
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_gauche_droite(noeud*& p)
{
    if (!p) return;
    if (!p->m_gauche) return;

    noeud* nTop = p->m_gauche;

    int ia = nTop->m_indice;
    int ib = p->m_indice;
    int nib = ib - ia - std::max(0, -ia) - 1;
    int nia = ia - std::max(0, -nib) - 1;

    p->m_indice = nib;
    nTop->m_indice = nia;

    p->m_gauche = nTop->m_droite;
    nTop->m_droite = p;

    nTop->m_parent = p->m_parent;
    p->m_parent = nTop;

    if (p->m_gauche)
        p->m_gauche->m_parent = p;

    p = nTop;
}

//effectuer une rotation simple de la droite vers la gauche
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_droite_gauche(noeud*& p)
{

    if (!p) return;
    if (!p->m_droite) return;

    noeud* nTop = p->m_droite;

    int ia = p->m_indice;
    int ib = nTop->m_indice;

    //int nib = 1+ std::max(1+std::max(0,ib)+ia, -ib);
    //int nia = 1 + std::max(0, ib) + ia - ib;
    int nia = ia + 1 + std::max(ib, 0) - ib;
    int nib = 2 + std::max(0, -nia) + std::max(ib, 0) + ia;

    p->m_indice = nia;
    nTop->m_indice = nib;

    p->m_droite = nTop->m_gauche;
    nTop->m_gauche = p;

    nTop->m_parent = p->m_parent;
    p->m_parent = nTop;

    if (p->m_droite)
        p->m_droite->m_parent = p;

    p = nTop;

}


#endif /* mapImpl_h */
