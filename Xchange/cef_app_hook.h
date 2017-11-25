// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef CEF_TESTS_CEFSIMPLE_SIMPLE_APP_H_
#define CEF_TESTS_CEFSIMPLE_SIMPLE_APP_H_

#include "include/cef_app.h"

// Implement application-level callbacks for the browser process.
class CefAppHook : public CefApp, public CefBrowserProcessHandler, public CefRenderProcessHandler {
 public:
  CefAppHook();

  // CefApp methods:
  virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
      OVERRIDE {
    return this;
  }

  /*
  virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler()
	  OVERRIDE {
	  return this;
  }*/

  // CefBrowserProcessHandler methods:
  virtual void OnContextInitialized() OVERRIDE;
  
  /*
  //By implementing this via the render handler we will be doing UI blocking work, may not be the best mechanism but a temporary solution
  virtual bool OnBeforeNavigation(CefRefPtr<CefBrowser> browser,
	  CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request,
	  NavigationType navigation_type, bool is_redirect)  OVERRIDE;
  */

 private:
  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(CefAppHook);
};

#endif  // CEF_TESTS_CEFSIMPLE_SIMPLE_APP_H_
