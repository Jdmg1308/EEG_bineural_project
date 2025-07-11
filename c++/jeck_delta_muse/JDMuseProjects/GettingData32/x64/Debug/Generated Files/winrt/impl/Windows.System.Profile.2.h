// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_System_Profile_2_H
#define WINRT_Windows_System_Profile_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.System.Profile.1.h"
WINRT_EXPORT namespace winrt::Windows::System::Profile
{
    struct AnalyticsInfo
    {
        AnalyticsInfo() = delete;
        [[nodiscard]] static auto VersionInfo();
        [[nodiscard]] static auto DeviceForm();
        static auto GetSystemPropertiesAsync(param::async_iterable<hstring> const& attributeNames);
    };
    struct __declspec(empty_bases) AnalyticsVersionInfo : winrt::Windows::System::Profile::IAnalyticsVersionInfo,
        impl::require<AnalyticsVersionInfo, winrt::Windows::System::Profile::IAnalyticsVersionInfo2>
    {
        AnalyticsVersionInfo(std::nullptr_t) noexcept {}
        AnalyticsVersionInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::Profile::IAnalyticsVersionInfo(ptr, take_ownership_from_abi) {}
        AnalyticsVersionInfo(AnalyticsVersionInfo const&) noexcept = default;
        AnalyticsVersionInfo(AnalyticsVersionInfo&&) noexcept = default;
        AnalyticsVersionInfo& operator=(AnalyticsVersionInfo const&) & noexcept = default;
        AnalyticsVersionInfo& operator=(AnalyticsVersionInfo&&) & noexcept = default;
    };
    struct AppApplicability
    {
        AppApplicability() = delete;
        static auto GetUnsupportedAppRequirements(param::iterable<hstring> const& capabilities);
    };
    struct EducationSettings
    {
        EducationSettings() = delete;
        [[nodiscard]] static auto IsEducationEnvironment();
    };
    struct HardwareIdentification
    {
        HardwareIdentification() = delete;
        static auto GetPackageSpecificToken(winrt::Windows::Storage::Streams::IBuffer const& nonce);
    };
    struct __declspec(empty_bases) HardwareToken : winrt::Windows::System::Profile::IHardwareToken
    {
        HardwareToken(std::nullptr_t) noexcept {}
        HardwareToken(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::Profile::IHardwareToken(ptr, take_ownership_from_abi) {}
        HardwareToken(HardwareToken const&) noexcept = default;
        HardwareToken(HardwareToken&&) noexcept = default;
        HardwareToken& operator=(HardwareToken const&) & noexcept = default;
        HardwareToken& operator=(HardwareToken&&) & noexcept = default;
    };
    struct KnownRetailInfoProperties
    {
        KnownRetailInfoProperties() = delete;
        [[nodiscard]] static auto RetailAccessCode();
        [[nodiscard]] static auto ManufacturerName();
        [[nodiscard]] static auto ModelName();
        [[nodiscard]] static auto DisplayModelName();
        [[nodiscard]] static auto Price();
        [[nodiscard]] static auto IsFeatured();
        [[nodiscard]] static auto FormFactor();
        [[nodiscard]] static auto ScreenSize();
        [[nodiscard]] static auto Weight();
        [[nodiscard]] static auto DisplayDescription();
        [[nodiscard]] static auto BatteryLifeDescription();
        [[nodiscard]] static auto ProcessorDescription();
        [[nodiscard]] static auto Memory();
        [[nodiscard]] static auto StorageDescription();
        [[nodiscard]] static auto GraphicsDescription();
        [[nodiscard]] static auto FrontCameraDescription();
        [[nodiscard]] static auto RearCameraDescription();
        [[nodiscard]] static auto HasNfc();
        [[nodiscard]] static auto HasSdSlot();
        [[nodiscard]] static auto HasOpticalDrive();
        [[nodiscard]] static auto IsOfficeInstalled();
        [[nodiscard]] static auto WindowsEdition();
    };
    struct PlatformAutomaticAppSignInManager
    {
        PlatformAutomaticAppSignInManager() = delete;
        [[nodiscard]] static auto Policy();
    };
    struct PlatformDiagnosticsAndUsageDataSettings
    {
        PlatformDiagnosticsAndUsageDataSettings() = delete;
        [[nodiscard]] static auto CollectionLevel();
        static auto CollectionLevelChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        using CollectionLevelChanged_revoker = impl::factory_event_revoker<winrt::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics, &impl::abi_t<winrt::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>::remove_CollectionLevelChanged>;
        [[nodiscard]] static CollectionLevelChanged_revoker CollectionLevelChanged(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static auto CollectionLevelChanged(winrt::event_token const& token);
        static auto CanCollectDiagnostics(winrt::Windows::System::Profile::PlatformDataCollectionLevel const& level);
    };
    struct RetailInfo
    {
        RetailInfo() = delete;
        [[nodiscard]] static auto IsDemoModeEnabled();
        [[nodiscard]] static auto Properties();
    };
    struct SharedModeSettings
    {
        SharedModeSettings() = delete;
        [[nodiscard]] static auto IsEnabled();
        [[nodiscard]] static auto ShouldAvoidLocalStorage();
    };
    struct SmartAppControlPolicy
    {
        SmartAppControlPolicy() = delete;
        [[nodiscard]] static auto IsEnabled();
        static auto Changed(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        using Changed_revoker = impl::factory_event_revoker<winrt::Windows::System::Profile::ISmartAppControlPolicyStatics, &impl::abi_t<winrt::Windows::System::Profile::ISmartAppControlPolicyStatics>::remove_Changed>;
        [[nodiscard]] static Changed_revoker Changed(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static auto Changed(winrt::event_token const& token);
    };
    struct SystemIdentification
    {
        SystemIdentification() = delete;
        static auto GetSystemIdForPublisher();
        static auto GetSystemIdForUser(winrt::Windows::System::User const& user);
    };
    struct __declspec(empty_bases) SystemIdentificationInfo : winrt::Windows::System::Profile::ISystemIdentificationInfo
    {
        SystemIdentificationInfo(std::nullptr_t) noexcept {}
        SystemIdentificationInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::Profile::ISystemIdentificationInfo(ptr, take_ownership_from_abi) {}
        SystemIdentificationInfo(SystemIdentificationInfo const&) noexcept = default;
        SystemIdentificationInfo(SystemIdentificationInfo&&) noexcept = default;
        SystemIdentificationInfo& operator=(SystemIdentificationInfo const&) & noexcept = default;
        SystemIdentificationInfo& operator=(SystemIdentificationInfo&&) & noexcept = default;
    };
    struct SystemSetupInfo
    {
        SystemSetupInfo() = delete;
        [[nodiscard]] static auto OutOfBoxExperienceState();
        static auto OutOfBoxExperienceStateChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        using OutOfBoxExperienceStateChanged_revoker = impl::factory_event_revoker<winrt::Windows::System::Profile::ISystemSetupInfoStatics, &impl::abi_t<winrt::Windows::System::Profile::ISystemSetupInfoStatics>::remove_OutOfBoxExperienceStateChanged>;
        [[nodiscard]] static OutOfBoxExperienceStateChanged_revoker OutOfBoxExperienceStateChanged(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static auto OutOfBoxExperienceStateChanged(winrt::event_token const& token);
    };
    struct __declspec(empty_bases) UnsupportedAppRequirement : winrt::Windows::System::Profile::IUnsupportedAppRequirement
    {
        UnsupportedAppRequirement(std::nullptr_t) noexcept {}
        UnsupportedAppRequirement(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::Profile::IUnsupportedAppRequirement(ptr, take_ownership_from_abi) {}
        UnsupportedAppRequirement(UnsupportedAppRequirement const&) noexcept = default;
        UnsupportedAppRequirement(UnsupportedAppRequirement&&) noexcept = default;
        UnsupportedAppRequirement& operator=(UnsupportedAppRequirement const&) & noexcept = default;
        UnsupportedAppRequirement& operator=(UnsupportedAppRequirement&&) & noexcept = default;
    };
    struct WindowsIntegrityPolicy
    {
        WindowsIntegrityPolicy() = delete;
        [[nodiscard]] static auto IsEnabled();
        [[nodiscard]] static auto IsEnabledForTrial();
        [[nodiscard]] static auto CanDisable();
        [[nodiscard]] static auto IsDisableSupported();
        static auto PolicyChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        using PolicyChanged_revoker = impl::factory_event_revoker<winrt::Windows::System::Profile::IWindowsIntegrityPolicyStatics, &impl::abi_t<winrt::Windows::System::Profile::IWindowsIntegrityPolicyStatics>::remove_PolicyChanged>;
        [[nodiscard]] static PolicyChanged_revoker PolicyChanged(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static auto PolicyChanged(winrt::event_token const& token);
    };
}
#endif
