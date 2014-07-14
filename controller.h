#ifndef MVC_CONTROLLER_H
#define MVC_CONTROLLER_H


#include <gtkmm.h>

class Model;

class Controller {
public:
   Controller( Model* );
   void nextButtonClicked();
   void resetButtonClicked();
private:
   Model *model_;
}; // Controller


#endif

