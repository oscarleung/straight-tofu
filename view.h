#ifndef MVC_VIEW_H
#define MVC_VIEW_H

#include <gtkmm.h>
#include "DeckGUI.h"
#include "observer.h"

class Controller;
class Model;


class View : public Gtk::Window, public Observer {
public:
        View( Controller*, Model* );
	virtual ~View();
	virtual void update();	// Observer Pattern: concrete update() method

private:
	// Observer Pattern: to access Model accessors without having to downcast subject
	Model *model_;
	
	// Strategy Pattern member (plus signal handlers)
	Controller *controller_;

	// Card Images
	DeckGUI deck;

	// Member widgets:
	
	Gtk::Frame table, p1, p2, p3, p4, hand;
	Gtk::VBox panels, mainBox, p1Box, p2Box, p3Box, p4Box;      // Main window divided into two vertical panels
	Gtk::HBox butBox, playerBox, handBox;      // Vertical boxes for stacking buttons horizontally
	Gtk::Button start_button;
	Gtk::Button end_button;
	Gtk::Button p1Rage, p2Rage, p3Rage, p4Rage;
	Gtk::Image card;
	Gtk::Entry seedEntry;
	Gtk::Label p1Point, p1Discard, p2Point, p2Discard, p3Point, p3Discard, p4Point, p4Discard;
	// Signal handlers:
	void startButtonClicked();
	void endButtonClicked();

}; // View

#endif
