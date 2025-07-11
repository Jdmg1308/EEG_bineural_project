// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_ApplicationModel_PackageExtensions_1_H
#define WINRT_Windows_ApplicationModel_PackageExtensions_1_H
#include "winrt/impl/Windows.ApplicationModel.PackageExtensions.0.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::PackageExtensions
{
    struct __declspec(empty_bases) IPackageExtension :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtension>
    {
        IPackageExtension(std::nullptr_t = nullptr) noexcept {}
        IPackageExtension(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtension(IPackageExtension const&) noexcept = default;
        IPackageExtension(IPackageExtension&&) noexcept = default;
        IPackageExtension& operator=(IPackageExtension const&) & noexcept = default;
        IPackageExtension& operator=(IPackageExtension&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionCatalog :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionCatalog>
    {
        IPackageExtensionCatalog(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionCatalog(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionCatalog(IPackageExtensionCatalog const&) noexcept = default;
        IPackageExtensionCatalog(IPackageExtensionCatalog&&) noexcept = default;
        IPackageExtensionCatalog& operator=(IPackageExtensionCatalog const&) & noexcept = default;
        IPackageExtensionCatalog& operator=(IPackageExtensionCatalog&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionCatalogStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionCatalogStatics>
    {
        IPackageExtensionCatalogStatics(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionCatalogStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionCatalogStatics(IPackageExtensionCatalogStatics const&) noexcept = default;
        IPackageExtensionCatalogStatics(IPackageExtensionCatalogStatics&&) noexcept = default;
        IPackageExtensionCatalogStatics& operator=(IPackageExtensionCatalogStatics const&) & noexcept = default;
        IPackageExtensionCatalogStatics& operator=(IPackageExtensionCatalogStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionPackageInstalledEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionPackageInstalledEventArgs>
    {
        IPackageExtensionPackageInstalledEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionPackageInstalledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionPackageInstalledEventArgs(IPackageExtensionPackageInstalledEventArgs const&) noexcept = default;
        IPackageExtensionPackageInstalledEventArgs(IPackageExtensionPackageInstalledEventArgs&&) noexcept = default;
        IPackageExtensionPackageInstalledEventArgs& operator=(IPackageExtensionPackageInstalledEventArgs const&) & noexcept = default;
        IPackageExtensionPackageInstalledEventArgs& operator=(IPackageExtensionPackageInstalledEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionPackageStatusChangedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionPackageStatusChangedEventArgs>
    {
        IPackageExtensionPackageStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionPackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionPackageStatusChangedEventArgs(IPackageExtensionPackageStatusChangedEventArgs const&) noexcept = default;
        IPackageExtensionPackageStatusChangedEventArgs(IPackageExtensionPackageStatusChangedEventArgs&&) noexcept = default;
        IPackageExtensionPackageStatusChangedEventArgs& operator=(IPackageExtensionPackageStatusChangedEventArgs const&) & noexcept = default;
        IPackageExtensionPackageStatusChangedEventArgs& operator=(IPackageExtensionPackageStatusChangedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionPackageUninstallingEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionPackageUninstallingEventArgs>
    {
        IPackageExtensionPackageUninstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionPackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionPackageUninstallingEventArgs(IPackageExtensionPackageUninstallingEventArgs const&) noexcept = default;
        IPackageExtensionPackageUninstallingEventArgs(IPackageExtensionPackageUninstallingEventArgs&&) noexcept = default;
        IPackageExtensionPackageUninstallingEventArgs& operator=(IPackageExtensionPackageUninstallingEventArgs const&) & noexcept = default;
        IPackageExtensionPackageUninstallingEventArgs& operator=(IPackageExtensionPackageUninstallingEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionPackageUpdatedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionPackageUpdatedEventArgs>
    {
        IPackageExtensionPackageUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionPackageUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionPackageUpdatedEventArgs(IPackageExtensionPackageUpdatedEventArgs const&) noexcept = default;
        IPackageExtensionPackageUpdatedEventArgs(IPackageExtensionPackageUpdatedEventArgs&&) noexcept = default;
        IPackageExtensionPackageUpdatedEventArgs& operator=(IPackageExtensionPackageUpdatedEventArgs const&) & noexcept = default;
        IPackageExtensionPackageUpdatedEventArgs& operator=(IPackageExtensionPackageUpdatedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPackageExtensionPackageUpdatingEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPackageExtensionPackageUpdatingEventArgs>
    {
        IPackageExtensionPackageUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPackageExtensionPackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPackageExtensionPackageUpdatingEventArgs(IPackageExtensionPackageUpdatingEventArgs const&) noexcept = default;
        IPackageExtensionPackageUpdatingEventArgs(IPackageExtensionPackageUpdatingEventArgs&&) noexcept = default;
        IPackageExtensionPackageUpdatingEventArgs& operator=(IPackageExtensionPackageUpdatingEventArgs const&) & noexcept = default;
        IPackageExtensionPackageUpdatingEventArgs& operator=(IPackageExtensionPackageUpdatingEventArgs&&) & noexcept = default;
    };
}
#endif
