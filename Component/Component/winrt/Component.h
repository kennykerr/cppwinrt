// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/base.h"

static_assert(winrt::impl::make_constexpr_string(CPPWINRT_VERSION) == "1.0.170906.1", "Mismatched component and base headers.");
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/complex_structs.h"
#include "winrt/impl/Component_complex_structs.h"

WINRT_WARNING_PUSH
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Component.2.h"

namespace winrt::impl {

template <typename D> hstring consume_Component_IButton<D>::Text() const
{
    hstring value{};
    check_hresult(WINRT_SHIM(Component::IButton)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void consume_Component_IButton2<D>::Show() const
{
    check_hresult(WINRT_SHIM(Component::IButton2)->Show());
}

template <typename D>
struct produce<D, Component::IButton> : produce_base<D, Component::IButton>
{
    HRESULT __stdcall get_Text(HSTRING* value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Component::IButton2> : produce_base<D, Component::IButton2>
{
    HRESULT __stdcall Show() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

WINRT_EXPORT namespace winrt::Component {

inline Button::Button() :
    Button(activate_instance<Button>())
{}

}

WINRT_EXPORT namespace std {

template<> struct hash<winrt::Component::IButton> : 
    winrt::impl::impl_hash_unknown<winrt::Component::IButton> {};

template<> struct hash<winrt::Component::IButton2> : 
    winrt::impl::impl_hash_unknown<winrt::Component::IButton2> {};

template<> struct hash<winrt::Component::Button> : 
    winrt::impl::impl_hash_unknown<winrt::Component::Button> {};

}

WINRT_WARNING_POP
