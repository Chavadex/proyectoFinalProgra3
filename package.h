//
// Created by Salvador Cruz on 13/01/2025.
//

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class package {
public:
    package(int packageID, std::string addresRecipient, std::string recipient, std::string sender, std::string addresSender, int priorityLevel, int trackingCode, float deliveryDistance);
    ~package();

    std::string getAddressRecipient() const;

    std::string getRecipient() const;

    std::string getSender() const;

    std::string getAddresSender() const;

    int getPriorityLevel() const;

    int getTrackingCode() const;

    int getPackageID() const;

    float getDeliveryDistance() const;

    void setAddressRecipient(std::string addressRecipient);

    void setRecipient(std::string recipient);

    void setSender(std::string sender);

    void setAddressSender(std::string addressSender);

    void setPiorityLevel(int priorityLevel);

    void setTrackingCode(int trackingCode);

    void setDeliveryDistance(float deliveryDistance);

    void setPackageID(int packageID);

private:
    int packageID;
    std::string addressRecipient;
    std::string recipient;
    std::string sender;
    std::string addressSender;
    int priorityLevel;
    int trackingCode;
    float deliveryDistance;

};



#endif //PACKAGE_H
