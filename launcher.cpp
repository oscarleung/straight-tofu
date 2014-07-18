#include <gtkmm.h>
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
	return 0;
}

