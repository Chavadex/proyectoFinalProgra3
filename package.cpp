//
// Created by Salvador Cruz on 13/01/2025.
//

#include "package.h"

package::package(int packageID, std::string addresRecipient, std::string recipient, std::string sender, std::string addresSender, int priorityLevel, int trackingCode, float deliveryDistance)
    : packageID(packageID), addressRecipient(addresRecipient), recipient(recipient), sender(sender), addressSender(addresSender), priorityLevel(priorityLevel), trackingCode(trackingCode), deliveryDistance(deliveryDistance){}

package::~package() {
        //Destructor
}

std::string package::getAddressRecipient() const {
    return addressRecipient;
}

std::string package::getRecipient() const {
    return recipient;
}

std::string package::getSender() const {
    return sender;
}

std::string package::getAddresSender() const{
    return addressSender;
}

int package::getPriorityLevel() const {
    return priorityLevel;
}

int package::getTrackingCode() const {
    return trackingCode;
}

float package::getDeliveryDistance() const{
    return deliveryDistance;
}

int package::getPackageID() const {
    return packageID;
}


void package::setAddressRecipient(std::string addressRecipient) {
    this->addressRecipient = addressRecipient;
}

void package::setRecipient(std::string recipient) {
    this -> recipient = recipient;
}

void package::setSender(std::string sender) {
    this->sender = sender;
}

void package::setAddressSender(std::string addressSender) {
    this -> addressSender = addressSender;
}

void package::setPiorityLevel(int priorityLevel) {
    this -> priorityLevel = priorityLevel;
}

void package::setTrackingCode(int trackingCode) {
    this->trackingCode = trackingCode;
}

void package::setDeliveryDistance(float deliveryDistance) {
    this->deliveryDistance = deliveryDistance;
}

void package::setPackageID(int packageID) {
    this->packageID = packageID;
}


