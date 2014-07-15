#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include <iostream>

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), table("Cards on the table"), p1("Player 1"), p2("Player 2"), p3("Player 3"), p4("Player 4"), hand("Your hand"), panels(true,10), butBox(true, 10), start_button( "Start new game with seed:" ), end_button( "End current game" ), rage_button("rage!"),  card(deck.null()) {

	// Sets some properties of the window.
        set_title( "Straights" );
	set_border_width( 100 );
	add(table);
	table.add( panels );	
	// Add panels to the window

	// Add button box and card image to the panels
	panels.add( butBox );
	panels.add( card );
	card.set( deck.null() );

	// Add buttons to the box (a container). Buttons initially invisible
	butBox.add( start_button );
	butBox.add( end_button );
	add(p1);

	// Associate button "clicked" events with local onButtonClicked() method defined below.
	start_button.signal_clicked().connect( sigc::mem_fun( *this, &View::startButtonClicked ) );
	end_button.signal_clicked().connect( sigc::mem_fun( *this, &View::endButtonClicked ) );
	
	
	// The final step is to display the buttons (they display themselves)
	show_all();

	// Register view as observer of model
	model_->subscribe(this);

} // View::View

View::~View() {}


void View::update() {
  //Suit suit = model_->suit();
  //Rank face = model_->face();
  /*if ( suit == NOSUIT ) 
    card.set( deck.null() );
  else
    card.set( deck.image(face, suit) );
*/
}

void View::startButtonClicked() {
  controller_->startButtonClicked();
} // View::startButtonClicked

void View::endButtonClicked() {
  controller_->endButtonClicked();
} // View::endButtonClicked
