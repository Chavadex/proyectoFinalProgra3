//
// Created by Salvador Cruz on 13/01/2025.
//

#include "package.h"

package::package(int packageID, std::string addresRecipient, std::string recipient, std::string sender, std::string addresSender, int priorityLevel, int trackingCode, float deliveryDistance)
    : packageID(packageID), addressRecipient(addresRecipient), recipient(recipient), sender(sender), addressSender(addresSender), priorityLevel(priorityLevel), trackingCode(trackingCode), deliveryDistance(deliveryDistance){}

package::~package() {
        //Destructor
}

package::package() {}


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

void package::createPackage()  {
    std::cout << "Para agregar un paquete por favor ingresa los siguientes datos" << std::endl;


    std::cout << "Inserta el ID: " << std::endl;
    std::cin >> packageID;
    std::cin.ignore();


    std::cout << "Inserta la direccion de entrega" << std::endl;
    std::getline(std::cin, addressRecipient);


    std::cout << "Inserta el nombre del destinatario: " << std::endl;
    std::getline(std::cin, recipient);


    std::cout << "Ingresa direccion de origen: " << std::endl;
    std::getline(std::cin, addressSender);


    std::cout << "Ingresa el nombre del remitente: " << std::endl;
    std::getline(std::cin, sender);


    std::cout << "Ingresa el nivel de prioridad: " << std::endl;
    std::cin >> priorityLevel;
    std::cin.ignore();


    std::cout << "Ingresa el codigo de rastreo: " << std::endl;
    std::cin >> trackingCode;
    std::cin.ignore();


    std::cout << "Ingresa la distancia de entrega: " << std::endl;
    std::cin >> deliveryDistance;
    std::cin.ignore();

    package newPackage(packageID, addressRecipient, recipient, addressSender, sender, priorityLevel, trackingCode, deliveryDistance);
}



