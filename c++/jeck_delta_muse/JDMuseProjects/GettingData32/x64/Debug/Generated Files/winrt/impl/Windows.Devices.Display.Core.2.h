// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Devices_Display_Core_2_H
#define WINRT_Windows_Devices_Display_Core_2_H
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Foundation.Numerics.2.h"
#include "winrt/impl/Windows.Graphics.2.h"
#include "winrt/impl/Windows.Graphics.DirectX.2.h"
#include "winrt/impl/Windows.Graphics.DirectX.Direct3D11.2.h"
#include "winrt/impl/Windows.Devices.Display.Core.1.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Display::Core
{
    struct DisplayPresentationRate
    {
        winrt::Windows::Foundation::Numerics::Rational VerticalSyncRate;
        int32_t VerticalSyncsPerPresentation;
    };
    inline bool operator==(DisplayPresentationRate const& left, DisplayPresentationRate const& right) noexcept
    {
        return left.VerticalSyncRate == right.VerticalSyncRate && left.VerticalSyncsPerPresentation == right.VerticalSyncsPerPresentation;
    }
    inline bool operator!=(DisplayPresentationRate const& left, DisplayPresentationRate const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) DisplayAdapter : winrt::Windows::Devices::Display::Core::IDisplayAdapter,
        impl::require<DisplayAdapter, winrt::Windows::Devices::Display::Core::IDisplayAdapter2>
    {
        DisplayAdapter(std::nullptr_t) noexcept {}
        DisplayAdapter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayAdapter(ptr, take_ownership_from_abi) {}
        DisplayAdapter(DisplayAdapter const&) noexcept = default;
        DisplayAdapter(DisplayAdapter&&) noexcept = default;
        DisplayAdapter& operator=(DisplayAdapter const&) & noexcept = default;
        DisplayAdapter& operator=(DisplayAdapter&&) & noexcept = default;
        static auto FromId(winrt::Windows::Graphics::DisplayAdapterId const& id);
    };
    struct __declspec(empty_bases) DisplayDevice : winrt::Windows::Devices::Display::Core::IDisplayDevice,
        impl::require<DisplayDevice, winrt::Windows::Devices::Display::Core::IDisplayDevice2, winrt::Windows::Devices::Display::Core::IDisplayDeviceRenderAdapter>
    {
        DisplayDevice(std::nullptr_t) noexcept {}
        DisplayDevice(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayDevice(ptr, take_ownership_from_abi) {}
        DisplayDevice(DisplayDevice const&) noexcept = default;
        DisplayDevice(DisplayDevice&&) noexcept = default;
        DisplayDevice& operator=(DisplayDevice const&) & noexcept = default;
        DisplayDevice& operator=(DisplayDevice&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayFence : winrt::Windows::Devices::Display::Core::IDisplayFence
    {
        DisplayFence(std::nullptr_t) noexcept {}
        DisplayFence(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayFence(ptr, take_ownership_from_abi) {}
        DisplayFence(DisplayFence const&) noexcept = default;
        DisplayFence(DisplayFence&&) noexcept = default;
        DisplayFence& operator=(DisplayFence const&) & noexcept = default;
        DisplayFence& operator=(DisplayFence&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayManager : winrt::Windows::Devices::Display::Core::IDisplayManager,
        impl::require<DisplayManager, winrt::Windows::Devices::Display::Core::IDisplayManager2, winrt::Windows::Devices::Display::Core::IDisplayManager3, winrt::Windows::Foundation::IClosable>
    {
        DisplayManager(std::nullptr_t) noexcept {}
        DisplayManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayManager(ptr, take_ownership_from_abi) {}
        DisplayManager(DisplayManager const&) noexcept = default;
        DisplayManager(DisplayManager&&) noexcept = default;
        DisplayManager& operator=(DisplayManager const&) & noexcept = default;
        DisplayManager& operator=(DisplayManager&&) & noexcept = default;
        static auto Create(winrt::Windows::Devices::Display::Core::DisplayManagerOptions const& options);
    };
    struct __declspec(empty_bases) DisplayManagerChangedEventArgs : winrt::Windows::Devices::Display::Core::IDisplayManagerChangedEventArgs
    {
        DisplayManagerChangedEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayManagerChangedEventArgs(ptr, take_ownership_from_abi) {}
        DisplayManagerChangedEventArgs(DisplayManagerChangedEventArgs const&) noexcept = default;
        DisplayManagerChangedEventArgs(DisplayManagerChangedEventArgs&&) noexcept = default;
        DisplayManagerChangedEventArgs& operator=(DisplayManagerChangedEventArgs const&) & noexcept = default;
        DisplayManagerChangedEventArgs& operator=(DisplayManagerChangedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayManagerDisabledEventArgs : winrt::Windows::Devices::Display::Core::IDisplayManagerDisabledEventArgs
    {
        DisplayManagerDisabledEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerDisabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayManagerDisabledEventArgs(ptr, take_ownership_from_abi) {}
        DisplayManagerDisabledEventArgs(DisplayManagerDisabledEventArgs const&) noexcept = default;
        DisplayManagerDisabledEventArgs(DisplayManagerDisabledEventArgs&&) noexcept = default;
        DisplayManagerDisabledEventArgs& operator=(DisplayManagerDisabledEventArgs const&) & noexcept = default;
        DisplayManagerDisabledEventArgs& operator=(DisplayManagerDisabledEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayManagerEnabledEventArgs : winrt::Windows::Devices::Display::Core::IDisplayManagerEnabledEventArgs
    {
        DisplayManagerEnabledEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerEnabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayManagerEnabledEventArgs(ptr, take_ownership_from_abi) {}
        DisplayManagerEnabledEventArgs(DisplayManagerEnabledEventArgs const&) noexcept = default;
        DisplayManagerEnabledEventArgs(DisplayManagerEnabledEventArgs&&) noexcept = default;
        DisplayManagerEnabledEventArgs& operator=(DisplayManagerEnabledEventArgs const&) & noexcept = default;
        DisplayManagerEnabledEventArgs& operator=(DisplayManagerEnabledEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayManagerPathsFailedOrInvalidatedEventArgs : winrt::Windows::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs
    {
        DisplayManagerPathsFailedOrInvalidatedEventArgs(std::nullptr_t) noexcept {}
        DisplayManagerPathsFailedOrInvalidatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayManagerPathsFailedOrInvalidatedEventArgs(ptr, take_ownership_from_abi) {}
        DisplayManagerPathsFailedOrInvalidatedEventArgs(DisplayManagerPathsFailedOrInvalidatedEventArgs const&) noexcept = default;
        DisplayManagerPathsFailedOrInvalidatedEventArgs(DisplayManagerPathsFailedOrInvalidatedEventArgs&&) noexcept = default;
        DisplayManagerPathsFailedOrInvalidatedEventArgs& operator=(DisplayManagerPathsFailedOrInvalidatedEventArgs const&) & noexcept = default;
        DisplayManagerPathsFailedOrInvalidatedEventArgs& operator=(DisplayManagerPathsFailedOrInvalidatedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayManagerResultWithState : winrt::Windows::Devices::Display::Core::IDisplayManagerResultWithState
    {
        DisplayManagerResultWithState(std::nullptr_t) noexcept {}
        DisplayManagerResultWithState(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayManagerResultWithState(ptr, take_ownership_from_abi) {}
        DisplayManagerResultWithState(DisplayManagerResultWithState const&) noexcept = default;
        DisplayManagerResultWithState(DisplayManagerResultWithState&&) noexcept = default;
        DisplayManagerResultWithState& operator=(DisplayManagerResultWithState const&) & noexcept = default;
        DisplayManagerResultWithState& operator=(DisplayManagerResultWithState&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayModeInfo : winrt::Windows::Devices::Display::Core::IDisplayModeInfo,
        impl::require<DisplayModeInfo, winrt::Windows::Devices::Display::Core::IDisplayModeInfo2>
    {
        DisplayModeInfo(std::nullptr_t) noexcept {}
        DisplayModeInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayModeInfo(ptr, take_ownership_from_abi) {}
        DisplayModeInfo(DisplayModeInfo const&) noexcept = default;
        DisplayModeInfo(DisplayModeInfo&&) noexcept = default;
        DisplayModeInfo& operator=(DisplayModeInfo const&) & noexcept = default;
        DisplayModeInfo& operator=(DisplayModeInfo&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayMuxDevice : winrt::Windows::Devices::Display::Core::IDisplayMuxDevice,
        impl::require<DisplayMuxDevice, winrt::Windows::Foundation::IClosable>
    {
        DisplayMuxDevice(std::nullptr_t) noexcept {}
        DisplayMuxDevice(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayMuxDevice(ptr, take_ownership_from_abi) {}
        DisplayMuxDevice(DisplayMuxDevice const&) noexcept = default;
        DisplayMuxDevice(DisplayMuxDevice&&) noexcept = default;
        DisplayMuxDevice& operator=(DisplayMuxDevice const&) & noexcept = default;
        DisplayMuxDevice& operator=(DisplayMuxDevice&&) & noexcept = default;
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceInterfaceId);
    };
    struct __declspec(empty_bases) DisplayPath : winrt::Windows::Devices::Display::Core::IDisplayPath,
        impl::require<DisplayPath, winrt::Windows::Devices::Display::Core::IDisplayPath2>
    {
        DisplayPath(std::nullptr_t) noexcept {}
        DisplayPath(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayPath(ptr, take_ownership_from_abi) {}
        DisplayPath(DisplayPath const&) noexcept = default;
        DisplayPath(DisplayPath&&) noexcept = default;
        DisplayPath& operator=(DisplayPath const&) & noexcept = default;
        DisplayPath& operator=(DisplayPath&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayPrimaryDescription : winrt::Windows::Devices::Display::Core::IDisplayPrimaryDescription
    {
        DisplayPrimaryDescription(std::nullptr_t) noexcept {}
        DisplayPrimaryDescription(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayPrimaryDescription(ptr, take_ownership_from_abi) {}
        DisplayPrimaryDescription(uint32_t width, uint32_t height, winrt::Windows::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, winrt::Windows::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, winrt::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription);
        DisplayPrimaryDescription(DisplayPrimaryDescription const&) noexcept = default;
        DisplayPrimaryDescription(DisplayPrimaryDescription&&) noexcept = default;
        DisplayPrimaryDescription& operator=(DisplayPrimaryDescription const&) & noexcept = default;
        DisplayPrimaryDescription& operator=(DisplayPrimaryDescription&&) & noexcept = default;
        static auto CreateWithProperties(param::iterable<winrt::Windows::Foundation::Collections::IKeyValuePair<winrt::guid, winrt::Windows::Foundation::IInspectable>> const& extraProperties, uint32_t width, uint32_t height, winrt::Windows::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, winrt::Windows::Graphics::DirectX::DirectXColorSpace const& colorSpace, bool isStereo, winrt::Windows::Graphics::DirectX::Direct3D11::Direct3DMultisampleDescription const& multisampleDescription);
    };
    struct __declspec(empty_bases) DisplayScanout : winrt::Windows::Devices::Display::Core::IDisplayScanout
    {
        DisplayScanout(std::nullptr_t) noexcept {}
        DisplayScanout(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayScanout(ptr, take_ownership_from_abi) {}
        DisplayScanout(DisplayScanout const&) noexcept = default;
        DisplayScanout(DisplayScanout&&) noexcept = default;
        DisplayScanout& operator=(DisplayScanout const&) & noexcept = default;
        DisplayScanout& operator=(DisplayScanout&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplaySource : winrt::Windows::Devices::Display::Core::IDisplaySource,
        impl::require<DisplaySource, winrt::Windows::Devices::Display::Core::IDisplaySource2>
    {
        DisplaySource(std::nullptr_t) noexcept {}
        DisplaySource(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplaySource(ptr, take_ownership_from_abi) {}
        DisplaySource(DisplaySource const&) noexcept = default;
        DisplaySource(DisplaySource&&) noexcept = default;
        DisplaySource& operator=(DisplaySource const&) & noexcept = default;
        DisplaySource& operator=(DisplaySource&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayState : winrt::Windows::Devices::Display::Core::IDisplayState
    {
        DisplayState(std::nullptr_t) noexcept {}
        DisplayState(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayState(ptr, take_ownership_from_abi) {}
        DisplayState(DisplayState const&) noexcept = default;
        DisplayState(DisplayState&&) noexcept = default;
        DisplayState& operator=(DisplayState const&) & noexcept = default;
        DisplayState& operator=(DisplayState&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayStateOperationResult : winrt::Windows::Devices::Display::Core::IDisplayStateOperationResult
    {
        DisplayStateOperationResult(std::nullptr_t) noexcept {}
        DisplayStateOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayStateOperationResult(ptr, take_ownership_from_abi) {}
        DisplayStateOperationResult(DisplayStateOperationResult const&) noexcept = default;
        DisplayStateOperationResult(DisplayStateOperationResult&&) noexcept = default;
        DisplayStateOperationResult& operator=(DisplayStateOperationResult const&) & noexcept = default;
        DisplayStateOperationResult& operator=(DisplayStateOperationResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplaySurface : winrt::Windows::Devices::Display::Core::IDisplaySurface
    {
        DisplaySurface(std::nullptr_t) noexcept {}
        DisplaySurface(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplaySurface(ptr, take_ownership_from_abi) {}
        DisplaySurface(DisplaySurface const&) noexcept = default;
        DisplaySurface(DisplaySurface&&) noexcept = default;
        DisplaySurface& operator=(DisplaySurface const&) & noexcept = default;
        DisplaySurface& operator=(DisplaySurface&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayTarget : winrt::Windows::Devices::Display::Core::IDisplayTarget
    {
        DisplayTarget(std::nullptr_t) noexcept {}
        DisplayTarget(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayTarget(ptr, take_ownership_from_abi) {}
        DisplayTarget(DisplayTarget const&) noexcept = default;
        DisplayTarget(DisplayTarget&&) noexcept = default;
        DisplayTarget& operator=(DisplayTarget const&) & noexcept = default;
        DisplayTarget& operator=(DisplayTarget&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayTask : winrt::Windows::Devices::Display::Core::IDisplayTask,
        impl::require<DisplayTask, winrt::Windows::Devices::Display::Core::IDisplayTask2>
    {
        DisplayTask(std::nullptr_t) noexcept {}
        DisplayTask(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayTask(ptr, take_ownership_from_abi) {}
        DisplayTask(DisplayTask const&) noexcept = default;
        DisplayTask(DisplayTask&&) noexcept = default;
        DisplayTask& operator=(DisplayTask const&) & noexcept = default;
        DisplayTask& operator=(DisplayTask&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayTaskPool : winrt::Windows::Devices::Display::Core::IDisplayTaskPool,
        impl::require<DisplayTaskPool, winrt::Windows::Devices::Display::Core::IDisplayTaskPool2>
    {
        DisplayTaskPool(std::nullptr_t) noexcept {}
        DisplayTaskPool(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayTaskPool(ptr, take_ownership_from_abi) {}
        DisplayTaskPool(DisplayTaskPool const&) noexcept = default;
        DisplayTaskPool(DisplayTaskPool&&) noexcept = default;
        DisplayTaskPool& operator=(DisplayTaskPool const&) & noexcept = default;
        DisplayTaskPool& operator=(DisplayTaskPool&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayTaskResult : winrt::Windows::Devices::Display::Core::IDisplayTaskResult
    {
        DisplayTaskResult(std::nullptr_t) noexcept {}
        DisplayTaskResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayTaskResult(ptr, take_ownership_from_abi) {}
        DisplayTaskResult(DisplayTaskResult const&) noexcept = default;
        DisplayTaskResult(DisplayTaskResult&&) noexcept = default;
        DisplayTaskResult& operator=(DisplayTaskResult const&) & noexcept = default;
        DisplayTaskResult& operator=(DisplayTaskResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayView : winrt::Windows::Devices::Display::Core::IDisplayView
    {
        DisplayView(std::nullptr_t) noexcept {}
        DisplayView(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayView(ptr, take_ownership_from_abi) {}
        DisplayView(DisplayView const&) noexcept = default;
        DisplayView(DisplayView&&) noexcept = default;
        DisplayView& operator=(DisplayView const&) & noexcept = default;
        DisplayView& operator=(DisplayView&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DisplayWireFormat : winrt::Windows::Devices::Display::Core::IDisplayWireFormat
    {
        DisplayWireFormat(std::nullptr_t) noexcept {}
        DisplayWireFormat(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::Display::Core::IDisplayWireFormat(ptr, take_ownership_from_abi) {}
        DisplayWireFormat(winrt::Windows::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, winrt::Windows::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, winrt::Windows::Devices::Display::Core::DisplayWireFormatEotf const& eotf, winrt::Windows::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata);
        DisplayWireFormat(DisplayWireFormat const&) noexcept = default;
        DisplayWireFormat(DisplayWireFormat&&) noexcept = default;
        DisplayWireFormat& operator=(DisplayWireFormat const&) & noexcept = default;
        DisplayWireFormat& operator=(DisplayWireFormat&&) & noexcept = default;
        static auto CreateWithProperties(param::iterable<winrt::Windows::Foundation::Collections::IKeyValuePair<winrt::guid, winrt::Windows::Foundation::IInspectable>> const& extraProperties, winrt::Windows::Devices::Display::Core::DisplayWireFormatPixelEncoding const& pixelEncoding, int32_t bitsPerChannel, winrt::Windows::Devices::Display::Core::DisplayWireFormatColorSpace const& colorSpace, winrt::Windows::Devices::Display::Core::DisplayWireFormatEotf const& eotf, winrt::Windows::Devices::Display::Core::DisplayWireFormatHdrMetadata const& hdrMetadata);
    };
}
#endif
