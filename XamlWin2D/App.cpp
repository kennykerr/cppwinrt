#include "pch.h"

using namespace winrt;

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Text;
using namespace Microsoft::Graphics::Canvas::UI::Xaml;

struct App : ApplicationT<App>
{
    void OnLaunched(LaunchActivatedEventArgs const &)
    {
        CanvasTextFormat format;
        format.HorizontalAlignment(CanvasHorizontalAlignment::Center);
        format.VerticalAlignment(CanvasVerticalAlignment::Center);
        format.FontSize(72.0f);
        format.FontFamily(L"Segoe UI Semibold");

        CanvasControl control;

        control.Draw([=](CanvasControl const& sender, CanvasDrawEventArgs const& args)
        {
            float2 size = sender.Size();
            float2 center{ size.x / 2.0f, size.y / 2.0f };
            Rect bounds{ 0.0f, 0.0f, size.x, size.y };

            CanvasDrawingSession session = args.DrawingSession();

            session.FillEllipse(center, center.x - 50.0f, center.y - 50.0f, Colors::Black());
            session.DrawText(L"Win2D with\nC++/WinRT!", bounds, Colors::Orange(), format);
        });

        Window window = Window::Current();
        window.Content(control);
        window.Activate();
    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    Application::Start([](auto &&) { make<App>(); });
}
