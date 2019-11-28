// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "Views/CalculatorProgrammerRadixOperators.g.h"
#include "Converters/VisibilityNegationConverter.h"
#include "CalcViewModel/StandardCalculatorViewModel.h"

namespace CalculatorApp
{
    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class CalculatorProgrammerRadixOperators sealed
    {
    public:
        CalculatorProgrammerRadixOperators();

        property CalculatorApp::ViewModel::StandardCalculatorViewModel^ Model
        {
            CalculatorApp::ViewModel::StandardCalculatorViewModel^ get() {
                return static_cast<CalculatorApp::ViewModel::StandardCalculatorViewModel^>(this->DataContext);
            }
        }

        property bool IsErrorVisualState {
            bool get();
            void set(bool value);
        }

        DEPENDENCY_PROPERTY_OWNER(CalculatorProgrammerRadixOperators);

    private:
        void Shift_Clicked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void SetVisibilityBinding(Windows::UI::Xaml::FrameworkElement^ element, Platform::String^ path, Windows::UI::Xaml::Data::IValueConverter^ converter);
        void OnLoaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void OnUnloaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void ProgModeRadixChange();
        void OnViewModelPropertyChanged(Platform::Object^ sender, Windows::UI::Xaml::Data::PropertyChangedEventArgs ^ e);

        bool m_isErrorVisualState;
        Windows::Foundation::EventRegistrationToken m_progModeRadixChangeToken;
        Windows::Foundation::EventRegistrationToken m_propertyChangedToken;
    };
}
