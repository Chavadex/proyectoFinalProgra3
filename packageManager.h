//
// Created by Salvador Cruz on 15/01/2025.
//

#ifndef PACKAGEMANAGER_H
#define PACKAGEMANAGER_H

#include <iostream>
#include <string>
#include "package.h"

class packageManager {

public:
    packageManager();

    void obtainData();

    int getId() const;

private:
    int id_package, priorityLevel, trackingCode;
    std::string addressRecipient, recipient, sender, addressSender, nombrePaquete;
    float deliveryDistance;
};



#endif //PACKAGEMANAGER_H
