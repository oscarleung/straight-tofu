#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>
#include "Card.h"

class Model;

class Controller {
public:
    Controller( Model* );
    void startButtonClicked(char []);
    void endButtonClicked();
    void rageButtonClicked();
    void handButtonClicked(Card c);
    
private:
    Model *model_;
}; // Controller


#endif

