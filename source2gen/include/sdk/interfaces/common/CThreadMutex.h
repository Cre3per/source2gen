// Copyright (C) 2024 neverlosecc
// See end of file for extended copyright information.
#pragma once

#include <shared/platform.h>
#include <cstddef>
#include <cstdint>

#ifdef _WIN32
typedef std::uint32_t ThreadId_t;
#else
typedef std::uint64_t ThreadId_t;
#endif

constexpr auto kTtSizeofCriticalsection = 40;

class CThreadMutex {
public:
    std::byte m_CriticalSection[kTtSizeofCriticalsection];

    // Debugging (always herge to allow mixed debug/release builds w/o changing size)
    ThreadId_t m_currentOwnerID;
    std::uint16_t m_lockCount;
    bool m_bTrace;
    const char* m_pDebugName;
};
// static_assert(sizeof(CThreadMutex) == 0x30 + sizeof(ThreadId_t) + sizeof(char*));
static_assert(sizeof(CThreadMutex) == platform_specific{.windows = 0x38, .linux = 0x40});

// source2gen - Source2 games SDK generator
// Copyright 2024 neverlosecc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
