#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>

class Model;

class Controller {
public:
    Controller( Model* );
    void startButtonClicked(char []);
    void endButtonClicked();
    void rageButtonClicked();
    void hand1ButtonClicked();
    void hand2ButtonClicked();
    void hand3ButtonClicked();
    void hand4ButtonClicked();
    void hand5ButtonClicked();
    void hand6ButtonClicked();
    void hand7ButtonClicked();
    void hand8ButtonClicked();
    void hand9ButtonClicked();
    void hand10ButtonClicked();
    void hand11ButtonClicked();
    void hand12ButtonClicked();
    void hand13ButtonClicked();
    
private:
    Model *model_;
}; // Controller


#endif

