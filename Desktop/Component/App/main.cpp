#include "pch.h"

extern "C"
{
    HRESULT __stdcall OS_RoGetActivationFactory(HSTRING classId, GUID const& iid, void** factory) noexcept;
}

#ifdef _M_IX86
#pragma comment(linker, "/alternatename:_OS_RoGetActivationFactory@12=_RoGetActivationFactory@12")
#else
#pragma comment(linker, "/alternatename:OS_RoGetActivationFactory=RoGetActivationFactory")
#endif

bool starts_with(std::wstring_view value, std::wstring_view match) noexcept
{
    return 0 == value.compare(0, match.size(), match);
}

HRESULT __stdcall WINRT_RoGetActivationFactory(HSTRING classId, GUID const& iid, void** factory) noexcept
{
    *factory = nullptr;
    std::wstring_view name{ WindowsGetStringRawBuffer(classId, nullptr), WindowsGetStringLen(classId) };
    HMODULE library{ nullptr };

    if (starts_with(name, L"Component."))
    {
        library = LoadLibraryW(L"Component.dll");
    }
    else
    {
        return OS_RoGetActivationFactory(classId, iid, factory);
    }

    if (!library)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    using DllGetActivationFactory = HRESULT __stdcall(HSTRING classId, void** factory);
    auto call = reinterpret_cast<DllGetActivationFactory*>(GetProcAddress(library, "DllGetActivationFactory"));

    if (!call)
    {
        HRESULT const hr = HRESULT_FROM_WIN32(GetLastError());
        WINRT_VERIFY(FreeLibrary(library));
        return hr;
    }

    winrt::com_ptr<winrt::Windows::Foundation::IActivationFactory> activation_factory;
    HRESULT const hr = call(classId, activation_factory.put_void());

    if (FAILED(hr))
    {
        WINRT_VERIFY(FreeLibrary(library));
        return hr;
    }

    if (iid != winrt::guid_of<winrt::Windows::Foundation::IActivationFactory>())
    {
        return activation_factory->QueryInterface(iid, factory);
    }

    *factory = activation_factory.detach();
    return S_OK;
}

using namespace winrt;
using namespace Windows::Foundation;
using namespace Component;

int main()
{
    init_apartment();

    printf("Call OS WinRT component:\n");
    Uri uri(L"https://moderncpp.com/");
    printf("%ls\n", uri.Domain().c_str());

    printf("\nCall third party WinRT component:\n");
    Button button;
    printf("%ls\n", button.Text().c_str());
}
