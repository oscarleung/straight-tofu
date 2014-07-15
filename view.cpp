#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include <iostream>

// Creates buttons with labels. Sets butBox elements to have the same size, 
// with 10 pixels between widgets
View::View(Controller *c, Model *m) : model_(m), controller_(c), mainBox(true, 10), playerBox(true, 10), table("Cards on the table"), p1("Player 1"), p2("Player 2"), p3("Player 3"), p4("Player 4"), p1Box(true, 5), p2Box(true, 10), p3Box(true, 10), p4Box(true, 10), hand("Your hand"), panels(true,10), handBox(true, 10), butBox(true, 10), start_button( "Start new game with seed:" ), end_button( "End current game" ), p1Rage("Rage!"), p2Rage("Rage!"), p3Rage("Rage!"), p4Rage("Rage!"), p1Point("0 points"), p1Discard("0 discards"), p2Point("0 points"), p2Discard("0discards"), p3Point("0 points"), p3Discard("0 discards"), p4Point("0 points"), p4Discard("0 discards"), card(deck.null()) {

	// Sets some properties of the window.
        set_title( "Straights" );
	set_border_width( 10 );
	add(mainBox);
	mainBox.add(butBox);
	butBox.add(start_button);

	seedEntry.set_max_length(10);
	seedEntry.select_region(0, seedEntry.get_text_length());
	butBox.add(seedEntry);
	butBox.add(end_button);

	// middle table
	mainBox.add(table);
	table.add(card);
	card.set(deck.null());
	
	// player section
	mainBox.add(playerBox);
	playerBox.add(p1);
	p1.add(p1Box);
	p1Box.add(p1Rage);
	p1Box.add(p1Point);
	p1Box.add(p1Discard);
	playerBox.add(p2);
	p2.add(p2Box);
	p2Box.add(p2Rage);
	p2Box.add(p2Point);
	p2Box.add(p2Discard);
	playerBox.add(p3);
	p3.add(p3Box);
	p3Box.add(p3Rage);
	p3Box.add(p3Point);
	p3Box.add(p3Discard);
	hand.add(card);
	playerBox.add(p4);
	p4.add(p4Box);
	p4Box.add(p4Rage);
	p4Box.add(p4Point);
	p4Box.add(p4Discard);

	// area for your hand
	mainBox.add(handBox);
	handBox.add(hand);
	
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
