#include "pch.h"

using namespace winrt;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

struct App : ApplicationT<App>
{
    Button m_button{ nullptr };

    void OnLaunched(LaunchActivatedEventArgs const &)
    {
        m_button = Button();
        m_button.Content(box_value(L"Hello"));

        m_button.Click([&](IInspectable const& sender, RoutedEventArgs const&)
        {
            Button button = sender.as<Button>();
            WINRT_ASSERT(button == m_button);

            hstring value = unbox_value<hstring>(button.Content());
            button.Content(box_value(value + L" World"));
        });

        Window window = Window::Current();
        window.Content(m_button);
        window.Activate();
    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Application::Start([](auto &&) { make<App>(); });
}
