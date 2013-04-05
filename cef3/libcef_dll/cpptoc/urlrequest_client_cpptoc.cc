// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/urlrequest_client_cpptoc.h"
#include "libcef_dll/ctocpp/urlrequest_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK urlrequest_client_on_request_complete(
    struct _cef_urlrequest_client_t* self, cef_urlrequest_t* request) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return;

  // Execute
  CefURLRequestClientCppToC::Get(self)->OnRequestComplete(
      CefURLRequestCToCpp::Wrap(request));
}

void CEF_CALLBACK urlrequest_client_on_upload_progress(
    struct _cef_urlrequest_client_t* self, cef_urlrequest_t* request,
    uint64 current, uint64 total) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return;

  // Execute
  CefURLRequestClientCppToC::Get(self)->OnUploadProgress(
      CefURLRequestCToCpp::Wrap(request),
      current,
      total);
}

void CEF_CALLBACK urlrequest_client_on_download_progress(
    struct _cef_urlrequest_client_t* self, cef_urlrequest_t* request,
    uint64 current, uint64 total) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return;

  // Execute
  CefURLRequestClientCppToC::Get(self)->OnDownloadProgress(
      CefURLRequestCToCpp::Wrap(request),
      current,
      total);
}

void CEF_CALLBACK urlrequest_client_on_download_data(
    struct _cef_urlrequest_client_t* self, cef_urlrequest_t* request,
    const void* data, size_t data_length) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: request; type: refptr_diff
  DCHECK(request);
  if (!request)
    return;
  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return;

  // Execute
  CefURLRequestClientCppToC::Get(self)->OnDownloadData(
      CefURLRequestCToCpp::Wrap(request),
      data,
      data_length);
}


// CONSTRUCTOR - Do not edit by hand.

CefURLRequestClientCppToC::CefURLRequestClientCppToC(CefURLRequestClient* cls)
    : CefCppToC<CefURLRequestClientCppToC, CefURLRequestClient,
        cef_urlrequest_client_t>(cls) {
  struct_.struct_.on_request_complete = urlrequest_client_on_request_complete;
  struct_.struct_.on_upload_progress = urlrequest_client_on_upload_progress;
  struct_.struct_.on_download_progress = urlrequest_client_on_download_progress;
  struct_.struct_.on_download_data = urlrequest_client_on_download_data;
}

#ifndef NDEBUG
template<> long CefCppToC<CefURLRequestClientCppToC, CefURLRequestClient,
    cef_urlrequest_client_t>::DebugObjCt = 0;
#endif

