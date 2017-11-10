// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

WINRT_EXPORT namespace winrt::Component {

struct IButton;
struct IButton2;
struct Button;

}

namespace winrt::impl {

template <> struct category<Component::IButton>{ using type = interface_category; };
template <> struct category<Component::IButton2>{ using type = interface_category; };
template <> struct category<Component::Button>{ using type = class_category; };
template <> struct name<Component::IButton>{ static constexpr auto & value{ L"Component.IButton" }; };
template <> struct name<Component::IButton2>{ static constexpr auto & value{ L"Component.IButton2" }; };
template <> struct name<Component::Button>{ static constexpr auto & value{ L"Component.Button" }; };
template <> struct guid<Component::IButton>{ static constexpr GUID value{ 0x461C8806,0x8BC2,0x4622,{ 0x8E,0xAC,0xB5,0x47,0xC3,0x9F,0x86,0x7E } }; };
template <> struct guid<Component::IButton2>{ static constexpr GUID value{ 0xD3235252,0x4081,0x4CC8,{ 0xB0,0xE0,0x8C,0x76,0x91,0x81,0x38,0x45 } }; };
template <> struct default_interface<Component::Button>{ using type = Component::IButton; };

template <typename D>
struct consume_Component_IButton
{
    hstring Text() const;
};
template <> struct consume<Component::IButton> { template <typename D> using type = consume_Component_IButton<D>; };

template <typename D>
struct consume_Component_IButton2
{
    void Show() const;
};
template <> struct consume<Component::IButton2> { template <typename D> using type = consume_Component_IButton2<D>; };

template <> struct abi<Component::IButton>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall get_Text(HSTRING* value) = 0;
};};

template <> struct abi<Component::IButton2>{ struct type : ::IInspectable
{
    virtual HRESULT __stdcall Show() = 0;
};};

}
