/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_DES_PROJECT3_HU_SOMEIP_STUB_ADAPTER_HPP_
#define V1_DES_PROJECT3_HU_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/DES_Project3/HUStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace DES_Project3 {

template <typename _Stub = ::v1::DES_Project3::HUStub, typename... _Stubs>
class HUSomeIPStubAdapterInternal
    : public virtual HUStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< HUSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> HUSomeIPStubAdapterHelper;

    ~HUSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        HUSomeIPStubAdapterHelper::deinit();
    }

    void fireGearSelectionAttributeChanged(const std::string &_value);
    
    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::DES_Project3::HUStub,
        CommonAPI::Version
    > getHUInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::DES_Project3::HUStub,
        std::string,
        CommonAPI::SomeIP::StringDeployment
    > getGearSelectionAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::DES_Project3::HUStub,
        std::string,
        CommonAPI::SomeIP::StringDeployment
    > setGearSelectionAttributeStubDispatcher;
    
    HUSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        HUSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< HUStub>(_stub)),
        getHUInterfaceVersionStubDispatcher(&HUStub::lockInterfaceVersionAttribute, &HUStub::getInterfaceVersion, false, true),
        getGearSelectionAttributeStubDispatcher(
            &::v1::DES_Project3::HUStub::lockGearSelectionAttribute,
            &::v1::DES_Project3::HUStub::getGearSelectionAttribute,
            false,
            _stub->hasElement(0)),
        setGearSelectionAttributeStubDispatcher(
            &::v1::DES_Project3::HUStub::lockGearSelectionAttribute,
            &::v1::DES_Project3::HUStub::getGearSelectionAttribute,
            &HUStubRemoteEvent::onRemoteSetGearSelectionAttribute,
            &HUStubRemoteEvent::onRemoteGearSelectionAttributeChanged,
            &HUStubAdapter::fireGearSelectionAttributeChanged,
            false,
            _stub->hasElement(0))
    {
        HUSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2201) }, &getGearSelectionAttributeStubDispatcher );
        HUSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2202) }, &setGearSelectionAttributeStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>(0xFFFF, 0xFFFFFFFF, 0xFFFFFFFF);

        // Provided events/fields
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0xcbec)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0xcbec), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireGearSelectionAttributeChanged(std::dynamic_pointer_cast< ::v1::DES_Project3::HUStub>(_stub)->getGearSelectionAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void HUSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireGearSelectionAttributeChanged(const std::string &_value) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deployedValue(_value, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0xcbec),
        false,
        deployedValue
    );
}


template <typename _Stub, typename... _Stubs>
void HUSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void HUSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::DES_Project3::HUStub, typename... _Stubs>
class HUSomeIPStubAdapter
    : public HUSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    HUSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          HUSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace DES_Project3
} // namespace v1

#endif // V1_DES_PROJECT3_HU_SOMEIP_STUB_ADAPTER_HPP_
