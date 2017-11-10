#include "pch.h"
#include "Button.h"

namespace winrt::Component::implementation
{
    hstring Button::Text()
    {
        return L"text";
    }

    void Button::Show()
    {
        WINRT_TRACE("Button::Show()\n");
    }

    hstring Button::ToString()
    {
        throw hresult_not_implemented(L"ToString");
    }
}
