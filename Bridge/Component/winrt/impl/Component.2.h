// C++/WinRT v1.0.171013.2
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/impl/Component.1.h"

WINRT_EXPORT namespace winrt::Component {

}

namespace winrt::impl {

}

WINRT_EXPORT namespace winrt::Component {

struct WINRT_EBO Button :
    Component::IButton
{
    Button(std::nullptr_t) noexcept {}
    Button();
};

}
