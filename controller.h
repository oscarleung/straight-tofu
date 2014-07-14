#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>

class Model;

class Controller {
public:
   Controller( Model* );
   void startButtonClicked();
   void endButtonClicked();
private:
   Model *model_;
}; // Controller


#endif

