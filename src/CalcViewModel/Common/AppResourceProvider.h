﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

namespace CalculatorApp
{
    class AppResourceProvider
    {
    public:
        static AppResourceProvider & GetInstance();
        Platform::String^ GetResourceString(_In_ Platform::String^ key);
        Platform::String^ GetCEngineString(_In_ Platform::String^ key);

    private:
        AppResourceProvider();
        Windows::ApplicationModel::Resources::ResourceLoader^ m_stringResLoader;
        Windows::ApplicationModel::Resources::ResourceLoader^ m_cEngineStringResLoader;
    };
}
