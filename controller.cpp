#include "controller.h"
#include "model.h"


Controller::Controller(Model *m) : model_(m) {}


void Controller::startButtonClicked() {
     model_->start();
} 


void Controller::endButtonClicked() {
     model_->end();
} 

void Controller::rageButtonClicked() {
    model_->rageCurrentPlayer();
}

void Controller::hand1ButtonClicked() {
}
void Controller::hand2ButtonClicked() {
}
void Controller::hand3ButtonClicked() {
}
void Controller::hand4ButtonClicked() {
}
void Controller::hand5ButtonClicked() {
}
void Controller::hand6ButtonClicked() {
}
void Controller::hand7ButtonClicked() {
}
void Controller::hand8ButtonClicked() {
}
void Controller::hand9ButtonClicked() {
}
void Controller::hand10ButtonClicked() {
}
void Controller::hand11ButtonClicked() {
}
void Controller::hand12ButtonClicked() {
}
void Controller::hand13ButtonClicked() {
}