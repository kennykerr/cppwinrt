#pragma once

#include "Button.g.h"

namespace winrt::Component::implementation
{
    struct Button : ButtonT<Button>
    {
        Button() = default;

        hstring Text();
        void Show();
        hstring ToString();
    };
}

namespace winrt::Component::factory_implementation
{
    struct Button : ButtonT<Button, implementation::Button>
    {
    };
}
