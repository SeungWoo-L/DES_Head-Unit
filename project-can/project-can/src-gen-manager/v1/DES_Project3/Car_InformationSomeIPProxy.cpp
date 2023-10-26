/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/DES_Project3/Car_InformationSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace DES_Project3 {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createCar_InformationSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< Car_InformationSomeIPProxy>(_address, _connection);
}

void initializeCar_InformationSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:DES_Project3.Car_Information:v1_0:Car_Information",
        0x5000, 0x5604, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "DES_Project3.Car_Information:v1_0",
        &createCar_InformationSomeIPProxy);
}

INITIALIZER(registerCar_InformationSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeCar_InformationSomeIPProxy);
}

Car_InformationSomeIPProxy::Car_InformationSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          battery_(*this, CommonAPI::SomeIP::eventgroup_id_t(0xd740), CommonAPI::SomeIP::event_id_t(0xd740), CommonAPI::SomeIP::method_id_t(0x5101), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x5102), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)),
          voltage_(*this, CommonAPI::SomeIP::eventgroup_id_t(0xd7a4), CommonAPI::SomeIP::event_id_t(0xd7a4), CommonAPI::SomeIP::method_id_t(0x5201), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x5202), true, static_cast< CommonAPI::EmptyDeployment* >(nullptr)),
          current_(*this, CommonAPI::SomeIP::eventgroup_id_t(0xd808), CommonAPI::SomeIP::event_id_t(0xd808), CommonAPI::SomeIP::method_id_t(0x5301), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x5302), true, static_cast< CommonAPI::EmptyDeployment* >(nullptr)),
          powerConsumption_(*this, CommonAPI::SomeIP::eventgroup_id_t(0xd86c), CommonAPI::SomeIP::event_id_t(0xd86c), CommonAPI::SomeIP::method_id_t(0x5401), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x5402), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr))
{
}

Car_InformationSomeIPProxy::~Car_InformationSomeIPProxy() {
    completed_.set_value();
}

Car_InformationSomeIPProxy::BatteryAttribute& Car_InformationSomeIPProxy::getBatteryAttribute() {
    return battery_;
}
Car_InformationSomeIPProxy::VoltageAttribute& Car_InformationSomeIPProxy::getVoltageAttribute() {
    return voltage_;
}
Car_InformationSomeIPProxy::CurrentAttribute& Car_InformationSomeIPProxy::getCurrentAttribute() {
    return current_;
}
Car_InformationSomeIPProxy::PowerConsumptionAttribute& Car_InformationSomeIPProxy::getPowerConsumptionAttribute() {
    return powerConsumption_;
}


void Car_InformationSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> Car_InformationSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace DES_Project3
} // namespace v1
