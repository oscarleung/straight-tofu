#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include "DeckGUI.h"
#include <iostream>

View::View(Controller *c, Model *m) : model_(m), controller_(c), mainBox(false, 1), playerBox(true, 1), table("Cards on the table"), p1("Player 1"), p2("Player 2"), p3("Player 3"), p4("Player 4"), p1Box(true, 10), p2Box(true, 10), p3Box(true, 10), p4Box(true, 10), hand("Your hand"), panels(true,10), handBox(true, 1), butBox(false, 1), start_button( "Start new game with seed:" ), end_button( "End current game" ), tableBox(true,5){
    
	blankCard.set(deck.null());
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
	for(int j=0;j<4;j++){
		for(int i=0;i<13;i++){
            rows[j].add(tableCards[j][i]);
            tableCards[j][i].set(deck.null());
		}
	}
	for(int z=0;z<4;z++){
        tableBox.add(rows[z]);
	}
	table.add(tableBox);
	// player section
	for(int p=0;p<4;p++)
	{
		pRage[p].set_label("Human");
        pPoint[p].set_text("0 points");
        pDiscard[p].set_text("0 discards");
	}
	mainBox.add(playerBox);
	playerBox.add(p1);
	p1.add(p1Box);
	p1Box.add(pRage[0]);
	p1Box.add(pPoint[0]);
	p1Box.add(pDiscard[0]);
	playerBox.add(p2);
	p2.add(p2Box);
	p2Box.add(pRage[1]);
	p2Box.add(pPoint[1]);
	p2Box.add(pDiscard[1]);
	playerBox.add(p3);
	p3.add(p3Box);
	p3Box.add(pRage[2]);
	p3Box.add(pPoint[2]);
	p3Box.add(pDiscard[2]);
	playerBox.add(p4);
	p4.add(p4Box);
	p4Box.add(pRage[3]);
	p4Box.add(pPoint[3]);
	p4Box.add(pDiscard[3]);
    
	// area for your hand
	mainBox.add(hand);
	hand.add(handBox);
	for(int l=0;l<13;l++)
	{
		handBox.add(handButtons[l]);
		handButtons[l].set_image(handCards[l]);
		handCards[l].set(deck.null());
	}
	// Associate button "clicked" events with local onButtonClicked() method defined below.
	start_button.signal_clicked().connect( sigc::mem_fun( *this, &View::startButtonClicked ) );
	end_button.signal_clicked().connect( sigc::mem_fun( *this, &View::endButtonClicked ) );
	pRage[0].signal_clicked().connect( sigc::mem_fun( *this, &View::p1RageButtonClicked ) );
	pRage[1].signal_clicked().connect( sigc::mem_fun( *this, &View::p2RageButtonClicked ) );
	pRage[2].signal_clicked().connect( sigc::mem_fun( *this, &View::p3RageButtonClicked ) );
	pRage[3].signal_clicked().connect( sigc::mem_fun( *this, &View::p4RageButtonClicked ) );
	handButtons[0].signal_clicked().connect( sigc::mem_fun( *this, &View::hand1ButtonClicked ) );
	handButtons[1].signal_clicked().connect( sigc::mem_fun( *this, &View::hand2ButtonClicked ) );
	handButtons[2].signal_clicked().connect( sigc::mem_fun( *this, &View::hand3ButtonClicked ) );
	handButtons[3].signal_clicked().connect( sigc::mem_fun( *this, &View::hand4ButtonClicked ) );
	handButtons[4].signal_clicked().connect( sigc::mem_fun( *this, &View::hand5ButtonClicked ) );
	handButtons[5].signal_clicked().connect( sigc::mem_fun( *this, &View::hand6ButtonClicked ) );
	handButtons[6].signal_clicked().connect( sigc::mem_fun( *this, &View::hand7ButtonClicked ) );
	handButtons[7].signal_clicked().connect( sigc::mem_fun( *this, &View::hand8ButtonClicked ) );
	handButtons[8].signal_clicked().connect( sigc::mem_fun( *this, &View::hand9ButtonClicked ) );
	handButtons[9].signal_clicked().connect( sigc::mem_fun( *this, &View::hand10ButtonClicked ) );
	handButtons[10].signal_clicked().connect( sigc::mem_fun( *this, &View::hand11ButtonClicked ) );
	handButtons[11].signal_clicked().connect( sigc::mem_fun( *this, &View::hand12ButtonClicked ) );
	handButtons[12].signal_clicked().connect( sigc::mem_fun( *this, &View::hand13ButtonClicked ) );
	
	
	// The final step is to display the buttons (they display themselves)
	show_all();
    
	// Register view as observer of model
	model_->subscribe(this);
    
} // View::View

View::~View() {}
void View::reset()
{
	start_button.set_sensitive(true);
	for(int p=0;p<4;p++)
	{
		pRage[p].set_sensitive(true);
		pRage[p].set_label("Human");
        pPoint[p].set_text("0 points");
        pDiscard[p].set_text("0 discards");
	}
	for(int l=0;l<13;l++)
	{
		handCards[l].set(deck.null());
	}
	for(int j=0;j<4;j++){
		for(int i=0;i<13;i++){
            rows[j].add(tableCards[j][i]);
            tableCards[j][i].set(deck.null());
		}
	}
}

void View::update() {
    if (model_->roundOver()) {
        // get the score ... calculate... return
        string output;
        for (int i=0; i<4; i++)
        {
            int roundScore = model_->calcScore(i);
            int newScore = model_->getScore(i);
            vector<Card> temp = model_->getDiscard(i);
	    int player = i+1;
	    int oldScore = newScore-roundScore;
            output.append("Player "+ to_string(player) +"'s discards: ");
            for (int j=0; j<temp.size(); j++)
            {
                //output.append(temp.at(j));
            }
            output.append("\nPlayer " + to_string(player) + "'s score: " + to_string(oldScore) + " + ");
	    output.append(to_string(roundScore) + " = " + to_string(newScore) + "\n");
        }
        Gtk::MessageDialog dialog(*this, output);
        dialog.run();
        return;
    }
	if(model_->getActivePlayer()==-1)
	{
		reset();
		return;
	}
	vector<Card> valid=model_->getActivePlayerValid();
	vector<Card> hand=model_->getActivePlayerHand();
	vector<Card> table=model_->getCardsInPlay();
	vector<int> scores=model_->getScores();
	vector<int> discards=model_->getDiscards();
	for(int i=0;i<hand.size();i++)
	{
		handCards[i].set(deck.image(hand[i].getRank(),hand[i].getSuit()));
	}
	for(int j=hand.size();j<13;j++)
	{
		handCards[j].set(deck.null());
		handButtons[j].set_sensitive(false);
	}
	if(valid.size()==0)
	{
		for(int k=0;k<hand.size();k++)
		{
			handButtons[k].set_sensitive(true);
		}
	}
	else
	{
		for(int k=0;k<hand.size();k++)
		{
			handButtons[k].set_sensitive(false);
			for(int l=0;l<valid.size();l++)
			{
				if(valid[l]==hand[k])
					handButtons[k].set_sensitive(true);
			}
		}
		
	}
	//update table
	for(int m=0;m<table.size();m++)
	{
		tableCards[(int)(table[m].getSuit())][(int)(table[m].getRank())].set(deck.image(table[m].getRank(),table[m].getSuit()));
	}
	for(int n=0;n<4;n++)
	{
		pRage[n].set_sensitive(false);
		pPoint[n].set_text(to_string(scores[n])+" points");
		pDiscard[n].set_text(to_string(discards[n])+" discards");
	}
	pRage[model_->getActivePlayer()].set_sensitive(true);
}

void View::startButtonClicked() {
	char playerType[4];
	for(int i=0;i<4;i++)
	{
        pRage[i].set_label("Rage!");
        pRage[i].set_sensitive(false);
        playerType[i]=(pRage[i].get_label()=="Human"?'h':'c');
	}
	start_button.set_sensitive(false);
    controller_->startButtonClicked(playerType);
	int player = model_->getActivePlayer();
    Gtk::MessageDialog dialog(*this, "A new round begins. It's player "+ to_string(player) +"'s turn to play.");
    dialog.run();
}
void View::endButtonClicked() {
    start_button.set_sensitive(true);
    for(int i=0;i<4;i++)
	{
        pRage[i].set_label("Human");
        pPoint[i].set_text("0 points");
        pDiscard[i].set_text("0 discards");
        pRage[i].set_sensitive(true);
	}
    // clear middle table
    for(int j=0;j<4;j++){
		for(int i=0;i<13;i++){
            tableCards[j][i].set(deck.null());
		}
	}
    for(int l=0;l<13;l++)
	{
		handCards[l].set(deck.null());
        handButtons[l].set_sensitive(false);
	}
}

void View::p1RageButtonClicked() {
	if(pRage[0].get_label()=="Human")
		pRage[0].set_label("Computer");
	else if(pRage[0].get_label()=="Computer")
		pRage[0].set_label("Human");
    else
        controller_->rageButtonClicked();
	
}
void View::p2RageButtonClicked() {
	if(pRage[1].get_label()=="Human")
		pRage[1].set_label("Computer");
	else if(pRage[1].get_label()=="Computer")
		pRage[1].set_label("Human");
	else
	    controller_->rageButtonClicked();
}
void View::p3RageButtonClicked() {
	if(pRage[2].get_label()=="Human")
		pRage[2].set_label("Computer");
	else if(pRage[2].get_label()=="Computer")
		pRage[2].set_label("Human");
	else
	    controller_->rageButtonClicked();
}
void View::p4RageButtonClicked() {
	if(pRage[3].get_label()=="Human")
		pRage[3].set_label("Computer");
	else if(pRage[3].get_label()=="Computer")
		pRage[3].set_label("Human");
	else
	    controller_->rageButtonClicked();
}
void View::hand1ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[0]);
}
void View::hand2ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[1]);
}
void View::hand3ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[2]);
}
void View::hand4ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[3]);
}
void View::hand5ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[4]);
}
void View::hand6ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[5]);
}
void View::hand7ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[6]);
}
void View::hand8ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[7]);
}
void View::hand9ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[8]);
}
void View::hand10ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[9]);
}
void View::hand11ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[10]);
}
void View::hand12ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[11]);
}
void View::hand13ButtonClicked() {
	vector<Card> hand=model_->getActivePlayerHand();
    controller_->handButtonClicked(hand[12]);
}
