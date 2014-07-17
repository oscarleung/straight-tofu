#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}


void Controller::startButtonClicked(char playerType[]) {
     model_->initPlayers(playerType);
} 


void Controller::endButtonClicked() {
     //model_->end();
} 

void Controller::rageButtonClicked() {
    model_->rageCurrentPlayer();
}

void Controller::handButtonClicked(Card c) {
	model_->play(c);
}
