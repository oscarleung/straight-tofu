#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}


void Controller::startButtonClicked(char playerType[],int seed) {
    model_->seed(seed);
    model_->initPlayers(playerType);
}


void Controller::endButtonClicked() {
    //model_->end();
}

void Controller::rageButtonClicked() {
    model_->rageCurrentPlayer();
    model_->progressUntilHuman();
}

void Controller::handButtonClicked(Card c) {
	model_->play(c);
	model_->progressUntilHuman();
}
