#include "pch.h"
#include "winrt/Component.h"

using namespace winrt;

using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;
using namespace Component;

struct App : implements<App, IFrameworkViewSource, IFrameworkView>
{
    void TestButton()
    {
        Button button;
        hstring text = button.Text();
        WINRT_ASSERT(text == L"text");

        button.Show();

        try
        {
            button.ToString();
            WINRT_ASSERT(false);
        }
        catch (hresult_not_implemented const& e)
        {
            WINRT_ASSERT(e.message() == L"ToString");
        }
    }

    IFrameworkView CreateView()
    {
        TestButton();

        return *this;
    }

    void Initialize(CoreApplicationView const&)
    {
    }

    void Load(hstring const&)
    {
    }

    void Uninitialize()
    {
    }

    void Run()
    {
        CoreWindow window = CoreWindow::GetForCurrentThread();
        window.Activate();

        CoreDispatcher dispatcher = window.Dispatcher();
        dispatcher.ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
    }

    void SetWindow(CoreWindow const&)
    {
    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    CoreApplication::Run(App());
}
