/*
 * Copyright (c) 2021, Andreas Kling <kling@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/HTML/Window.h>

namespace Web::NavigationTiming {

class PerformanceTiming final : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(PerformanceTiming, Bindings::PlatformObject);
    JS_DECLARE_ALLOCATOR(PerformanceTiming);

public:
    using AllowOwnPtr = TrueType;

    ~PerformanceTiming();

    // https://www.w3.org/TR/navigation-timing/#dom-performancetiming-navigationstart
    // This attribute must return the time immediately after the user agent finishes prompting to unload the previous document. If there is no previous document, this attribute must return the same value as fetchStart.
    u64 navigation_start() { return m_navigation_start.value_or(fetch_start()); }
    void set_navigation_start(u64 time) { m_navigation_start = time; }

    u64 unload_event_start() { return m_unload_event_start; }
    void set_unload_event_start(u64 time) { m_unload_event_start = time; }

    u64 unload_event_end() { return m_unload_event_end; }
    void set_unload_event_end(u64 time) { m_unload_event_end = time; }

    u64 redirect_start() { return 0; }
    u64 redirect_end() { return 0; }

    u64 fetch_start() { return m_fetch_start; }
    void set_fetch_start(u64 time) { m_fetch_start = time; }

    u64 domain_lookup_start() { return 0; }
    u64 domain_lookup_end() { return 0; }
    u64 connect_start() { return 0; }
    u64 connect_end() { return 0; }
    u64 secure_connection_start() { return 0; }
    u64 request_start() { return 0; }
    u64 response_start() { return 0; }
    u64 response_end() { return 0; }
    u64 dom_loading() { return 0; }
    u64 dom_interactive() { return 0; }
    u64 dom_content_loaded_event_start() { return 0; }
    u64 dom_content_loaded_event_end() { return 0; }
    u64 dom_complete() { return 0; }
    u64 load_event_start() { return 0; }
    u64 load_event_end() { return 0; }

private:
    explicit PerformanceTiming(JS::Realm&);

    virtual void initialize(JS::Realm&) override;

    Optional<u64> m_navigation_start;
    u64 m_unload_event_start { 0 };
    u64 m_unload_event_end { 0 };
    u64 m_fetch_start { 0 };
};

}
