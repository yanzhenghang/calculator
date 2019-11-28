// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "CalcManager/Header Files/ICalcDisplay.h"

namespace CalculatorApp
{
    // Callback interface to be implemented by the CalculatorManager
    class CalculatorDisplay: public ICalcDisplay
    {
    public:
        CalculatorDisplay();
        void SetCallback(Platform::WeakReference callbackReference);
        void SetHistoryCallback(Platform::WeakReference callbackReference);

    private:
        void SetPrimaryDisplay(_In_ const std::wstring& displayString, _In_ bool isError) override;
        void SetIsInError(bool isError) override;
        void SetExpressionDisplay(_Inout_ std::shared_ptr<CalculatorVector<std::pair<std::wstring, int>>> const &tokens, _Inout_ std::shared_ptr<CalculatorVector<std::shared_ptr<IExpressionCommand>>> const &commands) override;
        void SetMemorizedNumbers(_In_ const std::vector<std::wstring>& memorizedNumbers) override;
        void OnHistoryItemAdded(_In_ unsigned int addedItemIndex) override;
        void SetParenDisplayText(_In_ const std::wstring& parenthesisCount) override;
        void OnNoRightParenAdded() override;
        void MaxDigitsReached() override;
        void BinaryOperatorReceived() override;
        void MemoryItemChanged(unsigned int indexOfMemory) override;

    private:
        Platform::WeakReference m_callbackReference;
        Platform::WeakReference m_historyCallbackReference;
    };
}
