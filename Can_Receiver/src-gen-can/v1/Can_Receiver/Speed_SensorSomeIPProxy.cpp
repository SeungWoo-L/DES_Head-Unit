/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/Can_Receiver/Speed_SensorSomeIPProxy.hpp>

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
namespace Can_Receiver {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createSpeed_SensorSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< Speed_SensorSomeIPProxy>(_address, _connection);
}

void initializeSpeed_SensorSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:Can_Receiver.Speed_Sensor:v1_0:Speed_Sensor",
        0x3000, 0x55f0, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "Can_Receiver.Speed_Sensor:v1_0",
        &createSpeed_SensorSomeIPProxy);
}

INITIALIZER(registerSpeed_SensorSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeSpeed_SensorSomeIPProxy);
}

Speed_SensorSomeIPProxy::Speed_SensorSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          speed_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x8150), CommonAPI::SomeIP::event_id_t(0x8150), CommonAPI::SomeIP::method_id_t(0x3101), false, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE, false, CommonAPI::SomeIP::method_id_t(0x3102), false, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint32_t>* >(nullptr)),
          rpm_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x81b4), CommonAPI::SomeIP::event_id_t(0x81b4), CommonAPI::SomeIP::method_id_t(0x3201), false, CommonAPI::SomeIP::reliability_type_e::RT_UNRELIABLE, false, CommonAPI::SomeIP::method_id_t(0x3202), false, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint32_t>* >(nullptr))
{
}

Speed_SensorSomeIPProxy::~Speed_SensorSomeIPProxy() {
    completed_.set_value();
}

Speed_SensorSomeIPProxy::SpeedAttribute& Speed_SensorSomeIPProxy::getSpeedAttribute() {
    return speed_;
}
Speed_SensorSomeIPProxy::RpmAttribute& Speed_SensorSomeIPProxy::getRpmAttribute() {
    return rpm_;
}


void Speed_SensorSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> Speed_SensorSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace Can_Receiver
} // namespace v1
