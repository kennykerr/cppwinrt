// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/base.h"

WINRT_WARNING_PUSH

static_assert(winrt::impl::make_constexpr_string(CPPWINRT_VERSION) == "1.0.171013.2", "Mismatched component and base headers.");
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/Component.2.h"

namespace winrt::impl {

template <typename D> hstring consume_Component_IButton<D>::Text() const noexcept
{
    hstring value{};
    check_terminate(WINRT_SHIM(Component::IButton)->get_Text(put_abi(value)));
    return value;
}

template <typename D>
struct produce<D, Component::IButton> : produce_base<D, Component::IButton>
{
    HRESULT __stdcall get_Text(HSTRING* value) noexcept final
    {
        typename D::abi_guard guard(this->shim());
        *value = detach_abi(this->shim().Text());
        return S_OK;
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

template<> struct hash<winrt::Component::Button> : 
    winrt::impl::impl_hash_unknown<winrt::Component::Button> {};

}

WINRT_WARNING_POP
