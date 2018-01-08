#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Component;

int main()
{
    init_apartment();

    puts("Desktop Bridge");

    // Call OS WinRT component:
    Uri uri(L"https://moderncpp.com/");
    printf("%ls\n", uri.Domain().c_str());

    try
    {
        // Call third party WinRT component:
        Button button;
        printf("%ls\n", button.Text().c_str());
    }
    catch (hresult_error const& e)
    {
        printf("You need to launch via the Package app. :)\n");
        printf("%ls\n", e.message().c_str());
    }
}
