#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PaneThemeTransitionMRE::implementation
{
}




void winrt::PaneThemeTransitionMRE::implementation::MainWindow::ToggleSwitch_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (LeftGrid().Children().Size() == 0U)
    {
        BaseGrid().Children().Append(RightRect());
        RightGrid2().Children().Append(RightRect2());
        LeftGrid().Children().Append(LeftRect());
        BottomGrid().Children().Append(BottomRect());
    }
    else
    {
        uint32_t index{};
        winrt::check_bool(BaseGrid().Children().IndexOf(RightRect(), index));
        BaseGrid().Children().RemoveAt(index);
        RightGrid2().Children().ReplaceAll({});
        LeftGrid().Children().ReplaceAll({});
        BottomGrid().Children().ReplaceAll({});
    }
}
