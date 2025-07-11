// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Devices_Power_H
#define WINRT_Windows_Devices_Power_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.210505.3"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.210505.3"
#include "winrt/Windows.Devices.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.System.Power.2.h"
#include "winrt/impl/Windows.Devices.Power.2.h"
namespace winrt::impl
{
    template <typename D> WINRT_IMPL_AUTO(hstring) consume_Windows_Devices_Power_IBattery<D>::DeviceId() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBattery)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Devices::Power::BatteryReport) consume_Windows_Devices_Power_IBattery<D>::GetReport() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBattery)->GetReport(&result));
        return winrt::Windows::Devices::Power::BatteryReport{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::event_token) consume_Windows_Devices_Power_IBattery<D>::ReportUpdated(winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Devices::Power::Battery, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBattery)->add_ReportUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Power_IBattery<D>::ReportUpdated_revoker consume_Windows_Devices_Power_IBattery<D>::ReportUpdated(auto_revoke_t, winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Devices::Power::Battery, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ReportUpdated_revoker>(this, ReportUpdated(handler));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Windows_Devices_Power_IBattery<D>::ReportUpdated(winrt::event_token const& token) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBattery)->remove_ReportUpdated(impl::bind_in(token)));
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::ChargeRateInMilliwatts() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryReport)->get_ChargeRateInMilliwatts(&value));
        return winrt::Windows::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::DesignCapacityInMilliwattHours() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryReport)->get_DesignCapacityInMilliwattHours(&value));
        return winrt::Windows::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::FullChargeCapacityInMilliwattHours() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryReport)->get_FullChargeCapacityInMilliwattHours(&value));
        return winrt::Windows::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::IReference<int32_t>) consume_Windows_Devices_Power_IBatteryReport<D>::RemainingCapacityInMilliwattHours() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryReport)->get_RemainingCapacityInMilliwattHours(&value));
        return winrt::Windows::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::System::Power::BatteryStatus) consume_Windows_Devices_Power_IBatteryReport<D>::Status() const
    {
        winrt::Windows::System::Power::BatteryStatus value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryReport)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Devices::Power::Battery) consume_Windows_Devices_Power_IBatteryStatics<D>::AggregateBattery() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryStatics)->get_AggregateBattery(&result));
        return winrt::Windows::Devices::Power::Battery{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Power::Battery>) consume_Windows_Devices_Power_IBatteryStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryStatics)->FromIdAsync(*(void**)(&deviceId), &result));
        return winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Power::Battery>{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(hstring) consume_Windows_Devices_Power_IBatteryStatics<D>::GetDeviceSelector() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IBatteryStatics)->GetDeviceSelector(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(double) consume_Windows_Devices_Power_IPowerGridData<D>::Severity() const
    {
        double value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridData)->get_Severity(&value));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(bool) consume_Windows_Devices_Power_IPowerGridData<D>::IsLowUserExperienceImpact() const
    {
        bool value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridData)->get_IsLowUserExperienceImpact(&value));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::DateTime) consume_Windows_Devices_Power_IPowerGridForecast<D>::StartTime() const
    {
        winrt::Windows::Foundation::DateTime value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridForecast)->get_StartTime(put_abi(value)));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::TimeSpan) consume_Windows_Devices_Power_IPowerGridForecast<D>::BlockDuration() const
    {
        winrt::Windows::Foundation::TimeSpan value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridForecast)->get_BlockDuration(put_abi(value)));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Power::PowerGridData>) consume_Windows_Devices_Power_IPowerGridForecast<D>::Forecast() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridForecast)->get_Forecast(&value));
        return winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Power::PowerGridData>{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Devices::Power::PowerGridForecast) consume_Windows_Devices_Power_IPowerGridForecastStatics<D>::GetForecast() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridForecastStatics)->GetForecast(&result));
        return winrt::Windows::Devices::Power::PowerGridForecast{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::event_token) consume_Windows_Devices_Power_IPowerGridForecastStatics<D>::ForecastUpdated(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridForecastStatics)->add_ForecastUpdated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Power_IPowerGridForecastStatics<D>::ForecastUpdated_revoker consume_Windows_Devices_Power_IPowerGridForecastStatics<D>::ForecastUpdated(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ForecastUpdated_revoker>(this, ForecastUpdated(handler));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Windows_Devices_Power_IPowerGridForecastStatics<D>::ForecastUpdated(winrt::event_token const& token) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(winrt::Windows::Devices::Power::IPowerGridForecastStatics)->remove_ForecastUpdated(impl::bind_in(token)));
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Devices::Power::IBattery> : produce_base<D, winrt::Windows::Devices::Power::IBattery>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetReport(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::Devices::Power::BatteryReport>(this->shim().GetReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ReportUpdated(void* handler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().ReportUpdated(*reinterpret_cast<winrt::Windows::Foundation::TypedEventHandler<winrt::Windows::Devices::Power::Battery, winrt::Windows::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ReportUpdated(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportUpdated(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Devices::Power::IBatteryReport> : produce_base<D, winrt::Windows::Devices::Power::IBatteryReport>
    {
        int32_t __stdcall get_ChargeRateInMilliwatts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::IReference<int32_t>>(this->shim().ChargeRateInMilliwatts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesignCapacityInMilliwattHours(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::IReference<int32_t>>(this->shim().DesignCapacityInMilliwattHours());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FullChargeCapacityInMilliwattHours(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::IReference<int32_t>>(this->shim().FullChargeCapacityInMilliwattHours());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemainingCapacityInMilliwattHours(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::IReference<int32_t>>(this->shim().RemainingCapacityInMilliwattHours());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::System::Power::BatteryStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Devices::Power::IBatteryStatics> : produce_base<D, winrt::Windows::Devices::Power::IBatteryStatics>
    {
        int32_t __stdcall get_AggregateBattery(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::Devices::Power::Battery>(this->shim().AggregateBattery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Power::Battery>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Devices::Power::IPowerGridData> : produce_base<D, winrt::Windows::Devices::Power::IPowerGridData>
    {
        int32_t __stdcall get_Severity(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Severity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsLowUserExperienceImpact(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsLowUserExperienceImpact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Devices::Power::IPowerGridForecast> : produce_base<D, winrt::Windows::Devices::Power::IPowerGridForecast>
    {
        int32_t __stdcall get_StartTime(int64_t* value) noexcept final try
        {
            zero_abi<winrt::Windows::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::DateTime>(this->shim().StartTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BlockDuration(int64_t* value) noexcept final try
        {
            zero_abi<winrt::Windows::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::TimeSpan>(this->shim().BlockDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Forecast(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Power::PowerGridData>>(this->shim().Forecast());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Devices::Power::IPowerGridForecastStatics> : produce_base<D, winrt::Windows::Devices::Power::IPowerGridForecastStatics>
    {
        int32_t __stdcall GetForecast(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::Devices::Power::PowerGridForecast>(this->shim().GetForecast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ForecastUpdated(void* handler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().ForecastUpdated(*reinterpret_cast<winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ForecastUpdated(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForecastUpdated(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
WINRT_EXPORT namespace winrt::Windows::Devices::Power
{
    inline auto Battery::AggregateBattery()
    {
        return impl::call_factory_cast<winrt::Windows::Devices::Power::Battery(*)(IBatteryStatics const&), Battery, IBatteryStatics>([](IBatteryStatics const& f) { return f.AggregateBattery(); });
    }
    inline auto Battery::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<Battery, IBatteryStatics>([&](IBatteryStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto Battery::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IBatteryStatics const&), Battery, IBatteryStatics>([](IBatteryStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto PowerGridForecast::GetForecast()
    {
        return impl::call_factory_cast<winrt::Windows::Devices::Power::PowerGridForecast(*)(IPowerGridForecastStatics const&), PowerGridForecast, IPowerGridForecastStatics>([](IPowerGridForecastStatics const& f) { return f.GetForecast(); });
    }
    inline auto PowerGridForecast::ForecastUpdated(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<PowerGridForecast, IPowerGridForecastStatics>([&](IPowerGridForecastStatics const& f) { return f.ForecastUpdated(handler); });
    }
    inline PowerGridForecast::ForecastUpdated_revoker PowerGridForecast::ForecastUpdated(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<PowerGridForecast, winrt::Windows::Devices::Power::IPowerGridForecastStatics>();
        return { f, f.ForecastUpdated(handler) };
    }
    inline auto PowerGridForecast::ForecastUpdated(winrt::event_token const& token)
    {
        impl::call_factory<PowerGridForecast, IPowerGridForecastStatics>([&](IPowerGridForecastStatics const& f) { return f.ForecastUpdated(token); });
    }
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Windows::Devices::Power::IBattery> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::IBatteryReport> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::IBatteryStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::IPowerGridData> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::IPowerGridForecast> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::IPowerGridForecastStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::Battery> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::BatteryReport> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::PowerGridData> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Devices::Power::PowerGridForecast> : winrt::impl::hash_base {};
#endif
}
#endif
