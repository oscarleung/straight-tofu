#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}


void Controller::startButtonClicked(char playerType[],int seed) {
    model_->seed(seed);
    model_->initPlayers(playerType);
}

void Controller::rageButtonClicked() {
    model_->rageCurrentPlayer();        // convert player to computer
    model_->progressUntilHuman();       // process all following computer moves
}

void Controller::handButtonClicked(Card c) {
	model_->play(c);                    // human player plays card
	model_->progressUntilHuman();       // process all following computer moves
}
