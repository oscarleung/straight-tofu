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
	Gtk::VBox panels, mainBox, p1Box, p2Box, p3Box, p4Box,tableBox;      // Main window divided into two vertical panels
	Gtk::HBox rows[4];
	Gtk::HBox butBox, playerBox, handBox,;      // Vertical boxes for stacking buttons horizontally
	Gtk::Button handButtons[13];
	Gtk::Image handCards[13];
	Gtk::Button start_button;
	Gtk::Button end_button;
	Gtk::Button pRage[4];
	Gtk::Image tableCards[4][13];
	Gtk::Image blankCard;
	Gtk::Entry seedEntry;
	Gtk::Label pPoint[4];
    Gtk::Label pDiscard[4];
    
    // Signal handlers:
	void startButtonClicked();
	void endButtonClicked();
    void p1RageButtonClicked();
    void p2RageButtonClicked();
    void p3RageButtonClicked();
    void p4RageButtonClicked();
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

}; // View

#endif
