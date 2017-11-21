// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Foundation.0.h"
#include "winrt/impl/Component.0.h"

WINRT_EXPORT namespace winrt::Component {

struct WINRT_EBO IButton :
    Windows::Foundation::IInspectable,
    impl::consume_t<IButton>
{
    IButton(std::nullptr_t = nullptr) noexcept {}
};

struct WINRT_EBO IButton2 :
    Windows::Foundation::IInspectable,
    impl::consume_t<IButton2>
{
    IButton2(std::nullptr_t = nullptr) noexcept {}
};

}
