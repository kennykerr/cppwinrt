// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Component.1.h"

WINRT_EXPORT namespace winrt::Component {

struct WINRT_EBO Button :
    Component::IButton,
    impl::require<Button, Component::IButton2, Windows::Foundation::IStringable>
{
    Button(std::nullptr_t) noexcept {}
    Button();
};

}
