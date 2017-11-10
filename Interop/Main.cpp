#include "pch.h"

template <typename T>
T^ to_cx(winrt::Windows::Foundation::IUnknown const& from)
{
    return safe_cast<T^>(reinterpret_cast<Platform::Object^>(winrt::get_abi(from)));
}

template <typename T>
T from_cx(Platform::Object^ from)
{
    T to{ nullptr };

    winrt::check_hresult(reinterpret_cast<::IUnknown*>(from)->QueryInterface(winrt::guid_of<T>(),
                                                                             reinterpret_cast<void**>(winrt::put_abi(to))));

    return to;
}

template <typename T>
T from_abi(::IUnknown* from)
{
    T to{ nullptr };

    winrt::check_hresult(from->QueryInterface(winrt::guid_of<T>(),
                                              reinterpret_cast<void**>(winrt::put_abi(to))));

    return to;
}

namespace cx
{
    using namespace Windows::Foundation;
}

namespace winrt
{
    using namespace Windows::Foundation;
}

namespace abi
{
    using namespace ABI::Windows::Foundation;
};

void sample()
{
    winrt::Uri cpp(L"http://moderncpp.com/");
    printf("C++/WinRT: %ls\n", cpp.Domain().c_str());

    cx::Uri ^ cx = to_cx<cx::Uri>(cpp);
    printf("C++/CX: %ls\n", cx->Domain->Data());

    winrt::com_ptr<abi::IUriRuntimeClass> ptr = cpp.as<abi::IUriRuntimeClass>();
    winrt::hstring domain;
    winrt::check_hresult(ptr->get_Domain(put_abi(domain)));
    printf("ABI: %ls\n", domain.c_str());

    winrt::Uri cpp_from_cx = from_cx<winrt::Uri>(cx);
    WINRT_ASSERT(cpp.Domain() == cpp_from_cx.Domain());
    WINRT_ASSERT(cpp == cpp_from_cx);

    winrt::Uri cpp_from_abi = from_abi<winrt::Uri>(ptr.get());
    WINRT_ASSERT(cpp.Domain() == cpp_from_abi.Domain());
    WINRT_ASSERT(cpp == cpp_from_abi);
}

int main()
{
    winrt::init_apartment();

    sample();
}
