// Copyright (c) 2025-2026 Jimmy O'Rourke
// Licensed under and subject to the terms of the LICENSE file accompanying this distribution.
// Official repository: https://github.com/jimmyorourke/plotlypp

#pragma once

#if defined(_MSC_VER)
#define PLOTLYPP_DISABLE_WARNING_PUSH __pragma(warning(push))
#define PLOTLYPP_DISABLE_WARNING_POP __pragma(warning(pop))
#define PLOTLYPP_DISABLE_WARNING(warningNumber) __pragma(warning(disable : warningNumber))

// https://learn.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2026
#define PLOTLYPP_DISABLE_WARNING_OVERLENGTH_STRINGS

#elif defined(__GNUC__) || defined(__clang__)
#define PLOTLYPP_DO_PRAGMA(X) _Pragma(#X)
#define PLOTLYPP_DISABLE_WARNING_PUSH PLOTLYPP_DO_PRAGMA(GCC diagnostic push)
#define PLOTLYPP_DISABLE_WARNING_POP PLOTLYPP_DO_PRAGMA(GCC diagnostic pop)
#define PLOTLYPP_DISABLE_WARNING(warningName) PLOTLYPP_DO_PRAGMA(GCC diagnostic ignored warningName)

#define PLOTLYPP_DISABLE_WARNING_OVERLENGTH_STRINGS PLOTLYPP_DISABLE_WARNING("-Woverlength-strings")

#else
#define PLOTLYPP_DISABLE_WARNING_PUSH
#define PLOTLYPP_DISABLE_WARNING_POP

#define PLOTLYPP_DISABLE_WARNING_OVERLENGTH_STRINGS
#endif
