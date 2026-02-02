#pragma once
#include <iostream>


class Point {
private:
    double x;
    double y;

public:
    // Constructeur sans paramètres (origine)
    Point();

    // Constructeur avec deux réels
    Point(double x, double y);

    //constructeur de recopie
    Point(const Point& p);


    // Accesseurs
    double getX() const; //modifie pas l 'état de l'objet mais le renvoit juste
    double getY() const;


    double mutX(double x); 
    double mutY(double y);

    // Méthodes translater (surcharge)
    void translater(double dx, double dy);
    void translater(const Point& p);



    void operator+=(const Point& p);
};


std::ostream& operator<<(std::ostream& cout, const Point& p);

std::ostream& operator<<(std::ostream& cout, const  Forme& p);


class Forme {

private:
    
Point centre;



public:


Forme(const Point& p);

void operator+=(const Point& p);

void translater(const Point& p);

Point getCentre() const;

virtual void perimetre()=0;

virtual void surface()=0;



//En C++, une fonction virtuelle est une fonction membre d’une classe qui peut être redéfinie (surchargée) dans une classe dérivée, et dont l’appel est résolu au moment de l’exécution (dynamique), pas au moment de la compilation.

//Autrement dit, elle permet le polymorphisme, c’est-à-dire que l’on peut appeler une fonction sur un objet via un pointeur ou une référence à la classe de base, et obtenir le comportement de la classe dérivée correspondante.

};





class Cercle : Forme {






};


class Rectangle : Forme {






};

class Carre : Forme {






};























/*Appel résolu = quand le compilateur ou le programme décide quelle fonction exécuter

Quand tu écris objet.fonction(), le programme doit savoir quelle version de la fonction utiliser.

Résolution à la compilation (appel statique) : le compilateur décide tout de suite quelle fonction appeler.

Résolution à l’exécution (appel dynamique) : le programme attend de savoir le type réel de l’objet à ce moment-là pour choisir la fonction.*/








/*  ❌ const Point& p → CE N’EST PAS un pointeur

👉 C’est une référence.

const Point& p = p1;


p est un alias de p1

pas de *

pas de nullptr

on écrit p.x ou p.getX()*/

/*Différence entre pointeur et référence
🟢 1️⃣ La référence (&)

👉 Un autre nom pour un objet existant

Point p1(1,2);
Point& r = p1;

Caractéristiques

❌ pas NULL

❌ ne peut pas changer de cible

❌ pas de *

✔ accès direct : r.getX()

✔ syntaxe simple

✔ plus sûre

👉 r et p1 sont le même objet

🔵 2️⃣ Le pointeur (*)

👉 Une variable qui contient une adresse

Point p1(1,2);
Point* p = &p1;

Caractéristiques

✔ peut être nullptr

✔ peut changer de cible

✔ nécessite * ou ->

❌ syntaxe plus lourde

❌ plus d’erreurs possibles

Une référence ne crée PAS un nouvel objet.
👉 Elle désigne exactement la même zone mémoire qu’un autre objet.
Accès :

p->getX();
(*p).getX();

⚔️ Comparaison directe
Critère	Référence (&)	Pointeur (*)
Peut être NULL	❌	✔
Peut changer de cible	❌	✔
Doit être initialisé	✔	❌
Syntaxe	simple	lourde
Sécurité	+++	+
Utilisation TP	très fréquente	plus rare */


/*Point a(1,1);
Point b(2,2);

Point& r = a;
Point* p = &a;

r = b;    // ⚠️ copie b dans a (ne change PAS la référence)
p = &b;   / */










/*Excellente question — c’est très important en C++ 👍
On décortique calmement 👇

const Point& p : ça veut dire quoi exactement ?

C’est un paramètre passé par référence constante.

On le coupe en 3 morceaux :

1️⃣ Point

👉 le type de l’objet (un point)

2️⃣ & (référence)

👉 on ne fait PAS une copie de l’objet
👉 on travaille directement avec l’objet existant

Sans référence :

void f(Point p);   // copie du Point (plus lent)


Avec référence :

void f(Point& p);  // pas de copie (plus rapide)

3️⃣ const

👉 interdit de modifier l’objet à l’intérieur de la fonction

void f(const Point& p) {
    // p.x = 5; ❌ INTERDIT
    // p.translater(1,2); ❌ si la méthode n’est pas const
}

🔍 Pourquoi on utilise const Point& ici ?

Dans ta méthode :

void translater(const Point& p);

✔ Avantages

1️⃣ Pas de copie → plus rapide
2️⃣ Sécurité → on garantit qu’on ne modifie pas p
3️⃣ Bonne pratique C++ standard

💥 Comparaison concrète
❌ Mauvais (copie inutile)
void translater(Point p) {
    x += p.getX();
    y += p.getY();
}


👉 Crée une copie du point

❌ Dangereux (modifiable)
void translater(Point& p) {
    p.translater(1,1); // 😱 modifie l’argument !
}

✅ Parfait
void translater(const Point& p) {
    x += p.getX();
    y += p.getY();
}

🧠 Règle d’or à retenir (pour le TP)

👉 Objet passé en paramètre + lecture seule → const &

Exemples :

bool equals(const Point& p) const;
Point operator+(const Point& p) const;


Si tu veux, je peux te faire un mémo spécial TP avec :

quand utiliser const

quand utiliser &

erreurs classiques à éviter*/
































