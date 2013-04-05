// Copyright (c) 2013 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_JSDIALOG_HANDLER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_JSDIALOG_HANDLER_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"


///
// Callback structure used for asynchronous continuation of JavaScript dialog
// requests.
///
typedef struct _cef_jsdialog_callback_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Continue the JS dialog request. Set |success| to true (1) if the OK button
  // was pressed. The |user_input| value should be specified for prompt dialogs.
  ///
  void (CEF_CALLBACK *cont)(struct _cef_jsdialog_callback_t* self, int success,
      const cef_string_t* user_input);
} cef_jsdialog_callback_t;


///
// Implement this structure to handle events related to JavaScript dialogs. The
// functions of this structure will be called on the UI thread.
///
typedef struct _cef_jsdialog_handler_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Called to run a JavaScript dialog. The |default_prompt_text| value will be
  // specified for prompt dialogs only. Set |suppress_message| to true (1) and
  // return false (0) to suppress the message (suppressing messages is
  // preferable to immediately executing the callback as this is used to detect
  // presumably malicious behavior like spamming alert messages in
  // onbeforeunload). Set |suppress_message| to false (0) and return false (0)
  // to use the default implementation (the default implementation will show one
  // modal dialog at a time and suppress any additional dialog requests until
  // the displayed dialog is dismissed). Return true (1) if the application will
  // use a custom dialog or if the callback has been executed immediately.
  // Custom dialogs may be either modal or modeless. If a custom dialog is used
  // the application must execute |callback| once the custom dialog is
  // dismissed.
  ///
  int (CEF_CALLBACK *on_jsdialog)(struct _cef_jsdialog_handler_t* self,
      struct _cef_browser_t* browser, const cef_string_t* origin_url,
      const cef_string_t* accept_lang, enum cef_jsdialog_type_t dialog_type,
      const cef_string_t* message_text,
      const cef_string_t* default_prompt_text,
      struct _cef_jsdialog_callback_t* callback, int* suppress_message);

  ///
  // Called to run a dialog asking the user if they want to leave a page. Return
  // false (0) to use the default dialog implementation. Return true (1) if the
  // application will use a custom dialog or if the callback has been executed
  // immediately. Custom dialogs may be either modal or modeless. If a custom
  // dialog is used the application must execute |callback| once the custom
  // dialog is dismissed.
  ///
  int (CEF_CALLBACK *on_before_unload_dialog)(
      struct _cef_jsdialog_handler_t* self, struct _cef_browser_t* browser,
      const cef_string_t* message_text, int is_reload,
      struct _cef_jsdialog_callback_t* callback);

  ///
  // Called to cancel any pending dialogs and reset any saved dialog state. Will
  // be called due to events like page navigation irregardless of whether any
  // dialogs are currently pending.
  ///
  void (CEF_CALLBACK *on_reset_dialog_state)(
      struct _cef_jsdialog_handler_t* self, struct _cef_browser_t* browser);
} cef_jsdialog_handler_t;


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_JSDIALOG_HANDLER_CAPI_H_
