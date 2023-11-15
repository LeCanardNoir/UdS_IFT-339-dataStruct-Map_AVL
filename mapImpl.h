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

///////////////////////////////////////////////////////////////////////////
// lower_bound O(log n)

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::lower_bound(const Tclef& c) const
{
    return iterator(nullptr);
}

///////////////////////////////////////////////////////////////////////////
//erase a partir d'une position

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::erase(iterator i)
{
    assert(i!=end());
    erase(i++->first);
    return i;
}

///////////////////////////////////////////////////////////////////////////
//insert avec indice

template <typename Tclef, typename Tvaleur>
typename map<Tclef, Tvaleur>::iterator map<Tclef, Tvaleur>::insert(iterator j, const Tclef& c, const Tvaleur& val)
{
    return insert(c).first;
}

///////////////////////////////////////////////////////////////////////////
// gestion de l'equilibre de l'arbre


//effectuer une rotation simple de la gauche vers la droite
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_gauche_droite(noeud*& p)
{
    size_t h1 = p->m_gauche->m_gauche->m_indice;
    size_t h2 = p->m_gauche->m_droite->m_indice;
    size_t h3 = p->m_droite->m_indice;
    size_t ia = h1 - h2;
    size_t ib = (h1 + max(0, -ia) + 1) - h3;
    size_t nib = -ia - max(0, -ia) - 1 + ib;
    size_t nia = ia - max(0, -nib) - 1;

    std::swap(p->m_contenu, p->m_gauche->m_contenu);
    std::swap(p->m_gauche, p->m_droite);
    std::swap(p->m_gauche->m_parent, p->m_droite->m_gauche->m_parent);
    std::swap(p->m_gauche, p->m_droite->m_gauche);
    std::swap(p->m_droite->m_gauche, p->m_droite->m_droite);

    p->m_indice = nia;
    p->m_droite->m_indice = nib;
}

//effectuer une rotation simple de la droite vers la gauche
template <typename Tclef, typename Tvaleur>
void map<Tclef, Tvaleur>::rotation_droite_gauche(noeud*& p)
{
}


#endif /* mapImpl_h */
