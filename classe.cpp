#include "classe.h"
#include <iostream>




// Point à l'origine
Point::Point() 
{
  this->x = 0.0;

  this->y = 0.0;


}

// Point avec coordonnées
Point::Point(double x, double y)

{
    this->x = x;

} //p.transalate pour trabsalter sur un point

// constrcuteur dee recopie 
Point::Point(const Point& p)  { 

this-> x = p.x;

this->y= p.y;

}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

void Point::translater(double dx, double dy) {

    this->x += dx;
    this->y += dy;
}

void Point::translater(const Point& p) {
   *this+= p;
    
}

double Point::mutX(double x)  {
     this->x=x;
}

double Point::mutY(double y)  {
    this->y=y;
}


std::ostream& operator<<(std::ostream& cout, const Point& p) { //getteur operateur externe
    cout << "(" << p.getX() << ", " << p.getY()<< ")";
    return cout; 
}


void Point :: operator+=(const Point& p){

 this->x+=p.x;

 this->y+=p.y;


}


Forme::Forme(const Point& p)
{

  this->centre=p;

  
}

void Forme :: operator+=(const Point& p){

 this->centre.translater(p);
  
 
 
}



void Forme :: translater(const Point& p){

 *this+=p;
  
 
 
}

std::ostream& operator<<(std::ostream& cout, const Forme& p) { //getteur operateur externe
    cout << "(" << p.getCentre() << ", " << p.getCentre()<< ")";
    return cout; 
}

Point Forme::getCentre() const {
    return this->centre;
}





/*this : qu’est-ce que c’est ?

this est un pointeur implicite disponible dans toutes les méthodes non statiques d’une classe.

Il pointe vers l’objet courant qui appelle la méthode ou le constructeur.**/