// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

WINRT_EXPORT namespace winrt::Component {

struct IButton;
struct Button;

}

namespace winrt::impl {

template <> struct category<Component::IButton>{ using type = interface_category; };
template <> struct category<Component::Button>{ using type = class_category; };
template <> struct name<Component::IButton>{ static constexpr auto & value{ L"Component.IButton" }; };
template <> struct name<Component::Button>{ static constexpr auto & value{ L"Component.Button" }; };
template <> struct guid<Component::IButton>{ static constexpr GUID value{ 0x461C8806,0x8BC2,0x4622,{ 0x8E,0xAC,0xB5,0x47,0xC3,0x9F,0x86,0x7E } }; };
template <> struct default_interface<Component::Button>{ using type = Component::IButton; };

template <typename D>
struct consume_Component_IButton
{
    hstring Text() const noexcept;
};
template <> struct consume<Component::IButton> { template <typename D> using type = consume_Component_IButton<D>; };

template <> struct abi<Component::IButton>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Text(HSTRING* value) = 0;
};};

}
