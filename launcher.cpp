#include <gtkmm.h>
#include "Game.h"
#include "model.h"
#include "controller.h"
#include "view.h"
using namespace std;

int main(int argc, char* argv[])
{
    
    Gtk::Main  kit( argc, argv );         // Initialize gtkmm with the command line arguments, as appropriate.
	Model model;
    Controller controller( &model );
    View view( &controller, &model );
	Gtk::Main::run( view );               // Show the window and return when it is closed.
   
    // old game launched
    Game straightsgame;
    if (argc == 2) {
        straightsgame.start((atoi(argv[1])));
    }
    else {
        straightsgame.start();
    }
    
	return 0;
}

