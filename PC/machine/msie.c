#include "msie.h"

static void CVIFUNC DWebBrwsrEvnts2RegOnStatusTextChange_EventVTableFunc (void *thisPtr,
                                                                          BSTR text);

static void CVIFUNC DWebBrwsrEvnts2RegOnProgressChange_EventVTableFunc (void *thisPtr,
                                                                        long progress,
                                                                        long progressMax);

static void CVIFUNC DWebBrwsrEvnts2RegOnCommandStateChange_EventVTableFunc (void *thisPtr,
                                                                            long command,
                                                                            VBOOL enable);

static void CVIFUNC DWebBrwsrEvnts2RegOnDownloadBegin_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvnts2RegOnDownloadComplete_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvnts2RegOnTitleChange_EventVTableFunc (void *thisPtr,
                                                                     BSTR text);

static void CVIFUNC DWebBrwsrEvnts2RegOnPropertyChange_EventVTableFunc (void *thisPtr,
                                                                        BSTR szProperty);

static void CVIFUNC DWebBrwsrEvnts2RegOnBeforeNavigate2_EventVTableFunc (void *thisPtr,
                                                                         LPDISPATCH pDisp,
                                                                         VARIANT *URL,
                                                                         VARIANT *flags,
                                                                         VARIANT *targetFrameName,
                                                                         VARIANT *postData,
                                                                         VARIANT *headers,
                                                                         VBOOL *cancel);

static void CVIFUNC DWebBrwsrEvnts2RegOnNewWindow2_EventVTableFunc (void *thisPtr,
                                                                    LPDISPATCH *ppDisp,
                                                                    VBOOL *cancel);

static void CVIFUNC DWebBrwsrEvnts2RegOnNavigateComplete2_EventVTableFunc (void *thisPtr,
                                                                           LPDISPATCH pDisp,
                                                                           VARIANT *URL);

static void CVIFUNC DWebBrwsrEvnts2RegOnDocumentComplete_EventVTableFunc (void *thisPtr,
                                                                          LPDISPATCH pDisp,
                                                                          VARIANT *URL);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnQuit_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnVisible_EventVTableFunc (void *thisPtr,
                                                                   VBOOL visible);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnToolBar_EventVTableFunc (void *thisPtr,
                                                                   VBOOL toolBar);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnMenuBar_EventVTableFunc (void *thisPtr,
                                                                   VBOOL menuBar);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnStatusBar_EventVTableFunc (void *thisPtr,
                                                                     VBOOL statusBar);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnFullScreen_EventVTableFunc (void *thisPtr,
                                                                      VBOOL fullScreen);

static void CVIFUNC DWebBrwsrEvnts2RegOnOnTheaterMode_EventVTableFunc (void *thisPtr,
                                                                       VBOOL theaterMode);

static void CVIFUNC DWebBrwsrEvntsRegOnBeforeNavigate_EventVTableFunc (void *thisPtr,
                                                                       BSTR URL,
                                                                       long flags,
                                                                       BSTR targetFrameName,
                                                                       VARIANT *postData,
                                                                       BSTR headers,
                                                                       VBOOL *cancel);

static void CVIFUNC DWebBrwsrEvntsRegOnNavigateComplete_EventVTableFunc (void *thisPtr,
                                                                         BSTR URL);

static void CVIFUNC DWebBrwsrEvntsRegOnStatusTextChange_EventVTableFunc (void *thisPtr,
                                                                         BSTR text);

static void CVIFUNC DWebBrwsrEvntsRegOnProgressChange_EventVTableFunc (void *thisPtr,
                                                                       long progress,
                                                                       long progressMax);

static void CVIFUNC DWebBrwsrEvntsRegOnDownloadComplete_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvntsRegOnCommandStateChange_EventVTableFunc (void *thisPtr,
                                                                           long command,
                                                                           VBOOL enable);

static void CVIFUNC DWebBrwsrEvntsRegOnDownloadBegin_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvntsRegOnNewWindow_EventVTableFunc (void *thisPtr,
                                                                  BSTR URL,
                                                                  long flags,
                                                                  BSTR targetFrameName,
                                                                  VARIANT *postData,
                                                                  BSTR headers,
                                                                  VBOOL *processed);

static void CVIFUNC DWebBrwsrEvntsRegOnTitleChange_EventVTableFunc (void *thisPtr,
                                                                    BSTR text);

static void CVIFUNC DWebBrwsrEvntsRegOnFrameBeforeNavigate_EventVTableFunc (void *thisPtr,
                                                                            BSTR URL,
                                                                            long flags,
                                                                            BSTR targetFrameName,
                                                                            VARIANT *postData,
                                                                            BSTR headers,
                                                                            VBOOL *cancel);

static void CVIFUNC DWebBrwsrEvntsRegOnFrameNavigateComplete_EventVTableFunc (void *thisPtr,
                                                                              BSTR URL);

static void CVIFUNC DWebBrwsrEvntsRegOnFrameNewWindow_EventVTableFunc (void *thisPtr,
                                                                       BSTR URL,
                                                                       long flags,
                                                                       BSTR targetFrameName,
                                                                       VARIANT *postData,
                                                                       BSTR headers,
                                                                       VBOOL *processed);

static void CVIFUNC DWebBrwsrEvntsRegOnQuit_EventVTableFunc (void *thisPtr,
                                                             VBOOL *cancel);

static void CVIFUNC DWebBrwsrEvntsRegOnWindowMove_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvntsRegOnWindowResize_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvntsRegOnWindowActivate_EventVTableFunc (void *thisPtr);

static void CVIFUNC DWebBrwsrEvntsRegOnPropertyChange_EventVTableFunc (void *thisPtr,
                                                                       BSTR property);

static void CVIFUNC DShellWindowsEvntsRegOnWindowRegistered_EventVTableFunc (void *thisPtr,
                                                                             long lCookie);

static void CVIFUNC DShellWindowsEvntsRegOnWindowRevoked_EventVTableFunc (void *thisPtr,
                                                                          long lCookie);

static void CVIFUNC _ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_EventVTableFunc (void *thisPtr,
                                                                                                 long cItems,
                                                                                                 long hItem,
                                                                                                 BSTR strName,
                                                                                                 BSTR strUrl,
                                                                                                 long cVisits,
                                                                                                 BSTR strDate,
                                                                                                 long fAvailableOffline);

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnStatusTextChange_CA_PARAMDATA[] =
    {
        {"text", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnProgressChange_CA_PARAMDATA[] =
    {
        {"progress", VT_I4},
        {"progressMax", VT_I4}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnCommandStateChange_CA_PARAMDATA[] =
    {
        {"command", VT_I4},
        {"enable", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnTitleChange_CA_PARAMDATA[] =
    {
        {"text", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnPropertyChange_CA_PARAMDATA[] =
    {
        {"szProperty", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnBeforeNavigate2_CA_PARAMDATA[] =
    {
        {"pDisp", VT_DISPATCH},
        {"URL", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"flags", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"targetFrameName", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"postData", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"headers", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"cancel", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnNewWindow2_CA_PARAMDATA[] =
    {
        {"ppDisp", VT_DISPATCH | VT_BYREF},
        {"cancel", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnNavigateComplete2_CA_PARAMDATA[] =
    {
        {"pDisp", VT_DISPATCH},
        {"URL", VT_VARIANT | VT_BYREF | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnDocumentComplete_CA_PARAMDATA[] =
    {
        {"pDisp", VT_DISPATCH},
        {"URL", VT_VARIANT | VT_BYREF | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnOnVisible_CA_PARAMDATA[] =
    {
        {"visible", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnOnToolBar_CA_PARAMDATA[] =
    {
        {"toolBar", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnOnMenuBar_CA_PARAMDATA[] =
    {
        {"menuBar", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnOnStatusBar_CA_PARAMDATA[] =
    {
        {"statusBar", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnOnFullScreen_CA_PARAMDATA[] =
    {
        {"fullScreen", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts2_RegOnOnTheaterMode_CA_PARAMDATA[] =
    {
        {"theaterMode", VT_BOOL}
    };

static CA_METHODDATA _DWebBrwsrEvnts2_CA_METHODDATA[] =
    {
        {"StatusTextChange", _DWebBrwsrEvnts2_RegOnStatusTextChange_CA_PARAMDATA, 102, 0, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"ProgressChange", _DWebBrwsrEvnts2_RegOnProgressChange_CA_PARAMDATA, 108, 1, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"CommandStateChange", _DWebBrwsrEvnts2_RegOnCommandStateChange_CA_PARAMDATA, 105, 2, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"DownloadBegin", NULL, 106, 3, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"DownloadComplete", NULL, 104, 4, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"TitleChange", _DWebBrwsrEvnts2_RegOnTitleChange_CA_PARAMDATA, 113, 5, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"PropertyChange", _DWebBrwsrEvnts2_RegOnPropertyChange_CA_PARAMDATA, 112, 6, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"BeforeNavigate2", _DWebBrwsrEvnts2_RegOnBeforeNavigate2_CA_PARAMDATA, 250, 7, CC_STDCALL, 7, DISPATCH_METHOD, VT_EMPTY},
        {"NewWindow2", _DWebBrwsrEvnts2_RegOnNewWindow2_CA_PARAMDATA, 251, 8, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"NavigateComplete2", _DWebBrwsrEvnts2_RegOnNavigateComplete2_CA_PARAMDATA, 252, 9, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"DocumentComplete", _DWebBrwsrEvnts2_RegOnDocumentComplete_CA_PARAMDATA, 259, 10, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"OnQuit", NULL, 253, 11, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"OnVisible", _DWebBrwsrEvnts2_RegOnOnVisible_CA_PARAMDATA, 254, 12, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"OnToolBar", _DWebBrwsrEvnts2_RegOnOnToolBar_CA_PARAMDATA, 255, 13, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"OnMenuBar", _DWebBrwsrEvnts2_RegOnOnMenuBar_CA_PARAMDATA, 256, 14, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"OnStatusBar", _DWebBrwsrEvnts2_RegOnOnStatusBar_CA_PARAMDATA, 257, 15, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"OnFullScreen", _DWebBrwsrEvnts2_RegOnOnFullScreen_CA_PARAMDATA, 258, 16, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"OnTheaterMode", _DWebBrwsrEvnts2_RegOnOnTheaterMode_CA_PARAMDATA, 260, 17, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY}
    };

static CA_INTERFACEDATA _DWebBrwsrEvnts2_CA_INTERFACEDATA =
    {
        _DWebBrwsrEvnts2_CA_METHODDATA,
        sizeof (_DWebBrwsrEvnts2_CA_METHODDATA) / sizeof (*_DWebBrwsrEvnts2_CA_METHODDATA)
    };

static void * _DWebBrwsrEvnts2_EventVTable[] =
    {
        DWebBrwsrEvnts2RegOnStatusTextChange_EventVTableFunc,
        DWebBrwsrEvnts2RegOnProgressChange_EventVTableFunc,
        DWebBrwsrEvnts2RegOnCommandStateChange_EventVTableFunc,
        DWebBrwsrEvnts2RegOnDownloadBegin_EventVTableFunc,
        DWebBrwsrEvnts2RegOnDownloadComplete_EventVTableFunc,
        DWebBrwsrEvnts2RegOnTitleChange_EventVTableFunc,
        DWebBrwsrEvnts2RegOnPropertyChange_EventVTableFunc,
        DWebBrwsrEvnts2RegOnBeforeNavigate2_EventVTableFunc,
        DWebBrwsrEvnts2RegOnNewWindow2_EventVTableFunc,
        DWebBrwsrEvnts2RegOnNavigateComplete2_EventVTableFunc,
        DWebBrwsrEvnts2RegOnDocumentComplete_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnQuit_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnVisible_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnToolBar_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnMenuBar_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnStatusBar_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnFullScreen_EventVTableFunc,
        DWebBrwsrEvnts2RegOnOnTheaterMode_EventVTableFunc
    };

static CAEventClassDefn _DWebBrwsrEvnts2_CAEventClassDefn =
    {
        20,
        &SHDocVw_IID_DWebBrwsrEvnts2,
        _DWebBrwsrEvnts2_EventVTable,
        &_DWebBrwsrEvnts2_CA_INTERFACEDATA,
        0
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnBeforeNavigate_CA_PARAMDATA[] =
    {
        {"URL", VT_BSTR},
        {"flags", VT_I4},
        {"targetFrameName", VT_BSTR},
        {"postData", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"headers", VT_BSTR},
        {"cancel", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnNavigateComplete_CA_PARAMDATA[] =
    {
        {"URL", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnStatusTextChange_CA_PARAMDATA[] =
    {
        {"text", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnProgressChange_CA_PARAMDATA[] =
    {
        {"progress", VT_I4},
        {"progressMax", VT_I4}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnCommandStateChange_CA_PARAMDATA[] =
    {
        {"command", VT_I4},
        {"enable", VT_BOOL}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnNewWindow_CA_PARAMDATA[] =
    {
        {"URL", VT_BSTR},
        {"flags", VT_I4},
        {"targetFrameName", VT_BSTR},
        {"postData", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"headers", VT_BSTR},
        {"processed", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnTitleChange_CA_PARAMDATA[] =
    {
        {"text", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnFrameBeforeNavigate_CA_PARAMDATA[] =
    {
        {"URL", VT_BSTR},
        {"flags", VT_I4},
        {"targetFrameName", VT_BSTR},
        {"postData", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"headers", VT_BSTR},
        {"cancel", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnFrameNavigateComplete_CA_PARAMDATA[] =
    {
        {"URL", VT_BSTR}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnFrameNewWindow_CA_PARAMDATA[] =
    {
        {"URL", VT_BSTR},
        {"flags", VT_I4},
        {"targetFrameName", VT_BSTR},
        {"postData", VT_VARIANT | VT_BYREF | VT_BYREF},
        {"headers", VT_BSTR},
        {"processed", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnQuit_CA_PARAMDATA[] =
    {
        {"cancel", VT_BOOL | VT_BYREF}
    };

static CA_PARAMDATA _DWebBrwsrEvnts_RegOnPropertyChange_CA_PARAMDATA[] =
    {
        {"property", VT_BSTR}
    };

static CA_METHODDATA _DWebBrwsrEvnts_CA_METHODDATA[] =
    {
        {"BeforeNavigate", _DWebBrwsrEvnts_RegOnBeforeNavigate_CA_PARAMDATA, 100, 0, CC_STDCALL, 6, DISPATCH_METHOD, VT_EMPTY},
        {"NavigateComplete", _DWebBrwsrEvnts_RegOnNavigateComplete_CA_PARAMDATA, 101, 1, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"StatusTextChange", _DWebBrwsrEvnts_RegOnStatusTextChange_CA_PARAMDATA, 102, 2, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"ProgressChange", _DWebBrwsrEvnts_RegOnProgressChange_CA_PARAMDATA, 108, 3, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"DownloadComplete", NULL, 104, 4, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"CommandStateChange", _DWebBrwsrEvnts_RegOnCommandStateChange_CA_PARAMDATA, 105, 5, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"DownloadBegin", NULL, 106, 6, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"NewWindow", _DWebBrwsrEvnts_RegOnNewWindow_CA_PARAMDATA, 107, 7, CC_STDCALL, 6, DISPATCH_METHOD, VT_EMPTY},
        {"TitleChange", _DWebBrwsrEvnts_RegOnTitleChange_CA_PARAMDATA, 113, 8, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"FrameBeforeNavigate", _DWebBrwsrEvnts_RegOnFrameBeforeNavigate_CA_PARAMDATA, 200, 9, CC_STDCALL, 6, DISPATCH_METHOD, VT_EMPTY},
        {"FrameNavigateComplete", _DWebBrwsrEvnts_RegOnFrameNavigateComplete_CA_PARAMDATA, 201, 10, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"FrameNewWindow", _DWebBrwsrEvnts_RegOnFrameNewWindow_CA_PARAMDATA, 204, 11, CC_STDCALL, 6, DISPATCH_METHOD, VT_EMPTY},
        {"Quit", _DWebBrwsrEvnts_RegOnQuit_CA_PARAMDATA, 103, 12, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"WindowMove", NULL, 109, 13, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"WindowResize", NULL, 110, 14, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"WindowActivate", NULL, 111, 15, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"PropertyChange", _DWebBrwsrEvnts_RegOnPropertyChange_CA_PARAMDATA, 112, 16, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY}
    };

static CA_INTERFACEDATA _DWebBrwsrEvnts_CA_INTERFACEDATA =
    {
        _DWebBrwsrEvnts_CA_METHODDATA,
        sizeof (_DWebBrwsrEvnts_CA_METHODDATA) / sizeof (*_DWebBrwsrEvnts_CA_METHODDATA)
    };

static void * _DWebBrwsrEvnts_EventVTable[] =
    {
        DWebBrwsrEvntsRegOnBeforeNavigate_EventVTableFunc,
        DWebBrwsrEvntsRegOnNavigateComplete_EventVTableFunc,
        DWebBrwsrEvntsRegOnStatusTextChange_EventVTableFunc,
        DWebBrwsrEvntsRegOnProgressChange_EventVTableFunc,
        DWebBrwsrEvntsRegOnDownloadComplete_EventVTableFunc,
        DWebBrwsrEvntsRegOnCommandStateChange_EventVTableFunc,
        DWebBrwsrEvntsRegOnDownloadBegin_EventVTableFunc,
        DWebBrwsrEvntsRegOnNewWindow_EventVTableFunc,
        DWebBrwsrEvntsRegOnTitleChange_EventVTableFunc,
        DWebBrwsrEvntsRegOnFrameBeforeNavigate_EventVTableFunc,
        DWebBrwsrEvntsRegOnFrameNavigateComplete_EventVTableFunc,
        DWebBrwsrEvntsRegOnFrameNewWindow_EventVTableFunc,
        DWebBrwsrEvntsRegOnQuit_EventVTableFunc,
        DWebBrwsrEvntsRegOnWindowMove_EventVTableFunc,
        DWebBrwsrEvntsRegOnWindowResize_EventVTableFunc,
        DWebBrwsrEvntsRegOnWindowActivate_EventVTableFunc,
        DWebBrwsrEvntsRegOnPropertyChange_EventVTableFunc
    };

static CAEventClassDefn _DWebBrwsrEvnts_CAEventClassDefn =
    {
        20,
        &SHDocVw_IID_DWebBrwsrEvnts,
        _DWebBrwsrEvnts_EventVTable,
        &_DWebBrwsrEvnts_CA_INTERFACEDATA,
        0
    };

static CA_PARAMDATA _DShellWindowsEvnts_RegOnWindowRegistered_CA_PARAMDATA[] =
    {
        {"lCookie", VT_I4}
    };

static CA_PARAMDATA _DShellWindowsEvnts_RegOnWindowRevoked_CA_PARAMDATA[] =
    {
        {"lCookie", VT_I4}
    };

static CA_METHODDATA _DShellWindowsEvnts_CA_METHODDATA[] =
    {
        {"WindowRegistered", _DShellWindowsEvnts_RegOnWindowRegistered_CA_PARAMDATA, 200, 0, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"WindowRevoked", _DShellWindowsEvnts_RegOnWindowRevoked_CA_PARAMDATA, 201, 1, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY}
    };

static CA_INTERFACEDATA _DShellWindowsEvnts_CA_INTERFACEDATA =
    {
        _DShellWindowsEvnts_CA_METHODDATA,
        sizeof (_DShellWindowsEvnts_CA_METHODDATA) / sizeof (*_DShellWindowsEvnts_CA_METHODDATA)
    };

static void * _DShellWindowsEvnts_EventVTable[] =
    {
        DShellWindowsEvntsRegOnWindowRegistered_EventVTableFunc,
        DShellWindowsEvntsRegOnWindowRevoked_EventVTableFunc
    };

static CAEventClassDefn _DShellWindowsEvnts_CAEventClassDefn =
    {
        20,
        &SHDocVw_IID_DShellWindowsEvnts,
        _DShellWindowsEvnts_EventVTable,
        &_DShellWindowsEvnts_CA_INTERFACEDATA,
        0
    };

static CA_PARAMDATA __ShellFavoritesNameSpaceEvents_RegOnFavoritesSelectionChange_CA_PARAMDATA[] =
    {
        {"cItems", VT_I4},
        {"hItem", VT_I4},
        {"strName", VT_BSTR},
        {"strUrl", VT_BSTR},
        {"cVisits", VT_I4},
        {"strDate", VT_BSTR},
        {"fAvailableOffline", VT_I4}
    };

static CA_METHODDATA __ShellFavoritesNameSpaceEvents_CA_METHODDATA[] =
    {
        {"FavoritesSelectionChange", __ShellFavoritesNameSpaceEvents_RegOnFavoritesSelectionChange_CA_PARAMDATA, 1, 0, CC_STDCALL, 7, DISPATCH_METHOD, VT_EMPTY}
    };

static CA_INTERFACEDATA __ShellFavoritesNameSpaceEvents_CA_INTERFACEDATA =
    {
        __ShellFavoritesNameSpaceEvents_CA_METHODDATA,
        sizeof (__ShellFavoritesNameSpaceEvents_CA_METHODDATA) / sizeof (*__ShellFavoritesNameSpaceEvents_CA_METHODDATA)
    };

static void * __ShellFavoritesNameSpaceEvents_EventVTable[] =
    {
        _ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_EventVTableFunc
    };

static CAEventClassDefn __ShellFavoritesNameSpaceEvents_CAEventClassDefn =
    {
        20,
        &SHDocVw_IID__ShellFavoritesNameSpaceEvents,
        __ShellFavoritesNameSpaceEvents_EventVTable,
        &__ShellFavoritesNameSpaceEvents_CA_INTERFACEDATA,
        0
    };

const IID SHDocVw_IID_IWebBrowser =
    {
        0xEAB22AC1, 0x30C1, 0x11CF, 0xA7, 0xEB, 0x0, 0x0, 0xC0, 0x5B, 0xAE, 0xB
    };

const IID SHDocVw_IID_IWebBrowser2 =
    {
        0xD30C1661, 0xCDAF, 0x11D0, 0x8A, 0x3E, 0x0, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E
    };

const IID SHDocVw_IID_IShellWindows =
    {
        0x85CB6900, 0x4D95, 0x11CF, 0x96, 0xC, 0x0, 0x80, 0xC7, 0xF4, 0xEE, 0x85
    };

const IID SHDocVw_IID_IShellUIHelper =
    {
        0x729FE2F8, 0x1EA8, 0x11D1, 0x8F, 0x85, 0x0, 0xC0, 0x4F, 0xC2, 0xFB, 0xE1
    };

const IID SHDocVw_IID_IShellFavoritesNameSpace =
    {
        0x55136804, 0xB2DE, 0x11D1, 0xB9, 0xF2, 0x0, 0xA0, 0xC9, 0x8B, 0xC5, 0x47
    };

const IID SHDocVw_IID_DWebBrwsrEvnts2 =
    {
        0x34A715A0, 0x6587, 0x11D0, 0x92, 0x4A, 0x0, 0x20, 0xAF, 0xC7, 0xAC, 0x4D
    };

const IID SHDocVw_IID_DWebBrwsrEvnts =
    {
        0xEAB22AC2, 0x30C1, 0x11CF, 0xA7, 0xEB, 0x0, 0x0, 0xC0, 0x5B, 0xAE, 0xB
    };

const IID SHDocVw_IID_DShellWindowsEvnts =
    {
        0xFE4106E0, 0x399A, 0x11D0, 0xA4, 0x8C, 0x0, 0xA0, 0xC9, 0xA, 0x8F, 0x39
    };

const IID SHDocVw_IID__ShellFavoritesNameSpaceEvents =
    {
        0x55136806, 0xB2DE, 0x11D1, 0xB9, 0xF2, 0x0, 0xA0, 0xC9, 0x8B, 0xC5, 0x47
    };

HRESULT CVIFUNC SHDocVw_GetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, void *value)
{
    HRESULT __result;

    __result = CA_PropertyGetEx (objectHandle, errorInfo, 0, propertyID,
                                 propertyType, value);

    return __result;
}

HRESULT CVIFUNC SHDocVw_SetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, ...)
{
    HRESULT __result;
    va_list args;

    va_start (args, propertyType);

    __result = CA_PropertySetVEx (objectHandle, errorInfo, 0, propertyID,
                                  propertyType, args);

    va_end (args);

    return __result;
}

HRESULT CVIFUNC SHDocVw_NewIWebBrowser (const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0xEAB22AC3, 0x30C1, 0x11CF, 0xA7, 0xEB, 0x0, 0x0, 0xC0, 0x5B,
                  0xAE, 0xB};

    __result = CA_CreateObjectByClassIdEx (&clsid, server,
                                           &SHDocVw_IID_IWebBrowser,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_OpenIWebBrowser (const char *fileName,
                                         const char *server,
                                         int supportMultithreading, LCID locale,
                                         int reserved, CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0xEAB22AC3, 0x30C1, 0x11CF, 0xA7, 0xEB, 0x0, 0x0, 0xC0, 0x5B,
                  0xAE, 0xB};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &SHDocVw_IID_IWebBrowser,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveIWebBrowser (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0xEAB22AC3, 0x30C1, 0x11CF, 0xA7, 0xEB, 0x0, 0x0, 0xC0, 0x5B,
                  0xAE, 0xB};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server,
                                              &SHDocVw_IID_IWebBrowser,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserGoBack (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x64, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserGoForward (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x65, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserGoHome (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x66, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserGoSearch (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x67, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserNavigate (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             const char *URL, VARIANT flags,
                                             VARIANT targetFrameName,
                                             VARIANT postData, VARIANT headers)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x68, CAVT_EMPTY,
                                  NULL, 5, __paramTypes, URL, &flags,
                                  &targetFrameName, &postData, &headers);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserRefresh (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0xFFFFFDDA,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserRefresh2 (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT level)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x69, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, &level);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowserStop (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser, 0x6A, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_NewWebBrowserIWebBrowser2 (const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x8856F961, 0x340A, 0x11D0, 0xA9, 0x6B, 0x0, 0xC0, 0x4F,
                  0xD7, 0x5, 0xA2};

    __result = CA_CreateObjectByClassIdEx (&clsid, server,
                                           &SHDocVw_IID_IWebBrowser2,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_OpenWebBrowserIWebBrowser2 (const char *fileName,
                                                    const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x8856F961, 0x340A, 0x11D0, 0xA9, 0x6B, 0x0, 0xC0, 0x4F,
                  0xD7, 0x5, 0xA2};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &SHDocVw_IID_IWebBrowser2,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveWebBrowserIWebBrowser2 (const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x8856F961, 0x340A, 0x11D0, 0xA9, 0x6B, 0x0, 0xC0, 0x4F,
                  0xD7, 0x5, 0xA2};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server,
                                              &SHDocVw_IID_IWebBrowser2,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_NewInternetExplorerIWebBrowser2 (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x2DF01, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46};

    __result = CA_CreateObjectByClassIdEx (&clsid, server,
                                           &SHDocVw_IID_IWebBrowser2,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_OpenInternetExplorerIWebBrowser2 (const char *fileName,
                                                          const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x2DF01, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &SHDocVw_IID_IWebBrowser2,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveInternetExplorerIWebBrowser2 (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x2DF01, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server,
                                              &SHDocVw_IID_IWebBrowser2,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoBack (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x64, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoForward (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x65, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoHome (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x66, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoSearch (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x67, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *URL, VARIANT flags,
                                              VARIANT targetFrameName,
                                              VARIANT postData, VARIANT headers)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x68, CAVT_EMPTY,
                                  NULL, 5, __paramTypes, URL, &flags,
                                  &targetFrameName, &postData, &headers);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0xFFFFFDDA,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh2 (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT level)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x69, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, &level);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Stop (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x6A, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Quit (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x12C, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2ClientToWindow (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pcx, long *pcy)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFIO,
                                   CAVT_LONG | CAVT_BYREFIO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x12D, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, pcx, pcy);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2PutProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *property,
                                                 VARIANT vtValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x12E, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, property, vtValue);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2GetProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *property,
                                                 VARIANT *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x12F,
                                  CAVT_VARIANT, returnValue, 1, __paramTypes,
                                  property);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate2 (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VARIANT URL,
                                               VARIANT flags,
                                               VARIANT targetFrameName,
                                               VARIANT postData, VARIANT headers)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x1F4, CAVT_EMPTY,
                                  NULL, 5, __paramTypes, &URL, &flags,
                                  &targetFrameName, &postData, &headers);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2QueryStatusWB (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum SHDocVwEnum_OLECMDID cmdID,
                                                   enum SHDocVwEnum_OLECMDF *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x1F5, CAVT_LONG,
                                  returnValue, 1, __paramTypes, cmdID);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2ExecWB (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum SHDocVwEnum_OLECMDID cmdID,
                                            enum SHDocVwEnum_OLECMDEXECOPT cmdexecopt,
                                            VARIANT pvaIn, VARIANT *pvaOut)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_LONG,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFIO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x1F6, CAVT_EMPTY,
                                  NULL, 4, __paramTypes, cmdID, cmdexecopt,
                                  &pvaIn, pvaOut);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IWebBrowser2ShowBrowserBar (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pvaClsid,
                                                    VARIANT pvarShow,
                                                    VARIANT pvarSize)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IWebBrowser2, 0x1F7, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, &pvaClsid, &pvarShow,
                                  &pvarSize);

    return __result;
}

HRESULT CVIFUNC SHDocVw_NewIShellWindows (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x9BA05972, 0xF6A8, 0x11CF, 0xA4, 0x42, 0x0, 0xA0, 0xC9, 0xA,
                  0x8F, 0x39};

    __result = CA_CreateObjectByClassIdEx (&clsid, server,
                                           &SHDocVw_IID_IShellWindows,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_OpenIShellWindows (const char *fileName,
                                           const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x9BA05972, 0xF6A8, 0x11CF, 0xA4, 0x42, 0x0, 0xA0, 0xC9, 0xA,
                  0x8F, 0x39};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &SHDocVw_IID_IShellWindows,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveIShellWindows (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x9BA05972, 0xF6A8, 0x11CF, 0xA4, 0x42, 0x0, 0xA0, 0xC9, 0xA,
                  0x8F, 0x39};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server,
                                              &SHDocVw_IID_IShellWindows,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index,
                                           CAObjHandle *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x0,
                                  CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
                                  index);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindows_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *returnValue)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0xFFFFFFFC,
                                  CAVT_UNKNOWN, returnValue, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsRegister (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CAObjHandle pid, long HWND,
                                               long swClass, long *plCookie)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_OBJHANDLE, CAVT_LONG, CAVT_LONG,
                                   CAVT_LONG | CAVT_BYREFO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020003,
                                  CAVT_EMPTY, NULL, 4, __paramTypes, pid, HWND,
                                  swClass, plCookie);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsRegisterPending (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long lThreadId,
                                                      VARIANT pvarloc,
                                                      VARIANT pvarlocRoot,
                                                      long swClass,
                                                      long *plCookie)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI, CAVT_LONG,
                                   CAVT_LONG | CAVT_BYREFO};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020004,
                                  CAVT_EMPTY, NULL, 5, __paramTypes, lThreadId,
                                  &pvarloc, &pvarlocRoot, swClass, plCookie);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsRevoke (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long lCookie)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020005,
                                  CAVT_EMPTY, NULL, 1, __paramTypes, lCookie);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsOnNavigate (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long lCookie, VARIANT pvarloc)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020006,
                                  CAVT_EMPTY, NULL, 2, __paramTypes, lCookie,
                                  &pvarloc);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsOnActivated (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long lCookie, VBOOL fActive)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020007,
                                  CAVT_EMPTY, NULL, 2, __paramTypes, lCookie,
                                  fActive);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsFindWindow (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT pvarloc,
                                                 VARIANT pvarlocRoot,
                                                 long swClass, long *pHWND,
                                                 long swfwOptions,
                                                 CAObjHandle *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI, CAVT_LONG,
                                   CAVT_LONG | CAVT_BYREFO, CAVT_LONG};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020008,
                                  CAVT_OBJHANDLE, returnValue, 5, __paramTypes,
                                  &pvarloc, &pvarlocRoot, swClass, pHWND,
                                  swfwOptions);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsOnCreated (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long lCookie, LPUNKNOWN punk)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_LONG, CAVT_UNKNOWN};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x60020009,
                                  CAVT_EMPTY, NULL, 2, __paramTypes, lCookie,
                                  punk);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellWindowsProcessAttachDetch (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL fAttach)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_BOOL};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellWindows, 0x6002000A,
                                  CAVT_EMPTY, NULL, 1, __paramTypes, fAttach);

    return __result;
}

HRESULT CVIFUNC SHDocVw_NewIShellUIHelper (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x64AB4BB7, 0x111E, 0x11D1, 0x8F, 0x79, 0x0, 0xC0, 0x4F,
                  0xC2, 0xFB, 0xE1};

    __result = CA_CreateObjectByClassIdEx (&clsid, server,
                                           &SHDocVw_IID_IShellUIHelper,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_OpenIShellUIHelper (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x64AB4BB7, 0x111E, 0x11D1, 0x8F, 0x79, 0x0, 0xC0, 0x4F,
                  0xC2, 0xFB, 0xE1};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &SHDocVw_IID_IShellUIHelper,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveIShellUIHelper (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x64AB4BB7, 0x111E, 0x11D1, 0x8F, 0x79, 0x0, 0xC0, 0x4F,
                  0xC2, 0xFB, 0xE1};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server,
                                              &SHDocVw_IID_IShellUIHelper,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperResetFrstBootMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x1, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperResetSafeMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x2, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperRefreshOfflnDsktp (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x3, CAVT_EMPTY,
                                  NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperAddFavorite (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *URL,
                                                   VARIANT title)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x4, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, URL, &title);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperAddChannel (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *URL)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x5, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, URL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperAddDsktpComponent (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *URL,
                                                         const char *type,
                                                         VARIANT left,
                                                         VARIANT top,
                                                         VARIANT width,
                                                         VARIANT height)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_CSTRING,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x6, CAVT_EMPTY,
                                  NULL, 6, __paramTypes, URL, type, &left,
                                  &top, &width, &height);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperIsSubscribed (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *URL,
                                                    VBOOL *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x7, CAVT_BOOL,
                                  returnValue, 1, __paramTypes, URL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperNavigateAndFind (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *URL,
                                                       const char *strQuery,
                                                       VARIANT varTargetFrame)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_CSTRING,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x8, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, URL, strQuery,
                                  &varTargetFrame);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperImportExportFavorites (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL fImport,
                                                             const char *strImpExpPath)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_BOOL, CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0x9, CAVT_EMPTY,
                                  NULL, 2, __paramTypes, fImport,
                                  strImpExpPath);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperAutoCompleteSaveForm (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT form)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0xA, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, &form);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperAutoScan (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *strSearch,
                                                const char *strFailureUrl,
                                                VARIANT pvarTargetFrame)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_CSTRING,
                                   CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0xB, CAVT_EMPTY,
                                  NULL, 3, __paramTypes, strSearch,
                                  strFailureUrl, &pvarTargetFrame);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperAutoCompleteAttach (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT reserved)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0xC, CAVT_EMPTY,
                                  NULL, 1, __paramTypes, &reserved);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellUIHelperShowBrowserUI (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *bstrName,
                                                     VARIANT pvarIn,
                                                     VARIANT *returnValue)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING, CAVT_VARIANT | CAVT_BYREFI};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellUIHelper, 0xD,
                                  CAVT_VARIANT, returnValue, 2, __paramTypes,
                                  bstrName, &pvarIn);

    return __result;
}

HRESULT CVIFUNC SHDocVw_NewIShellFavoritesNameSpace (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x55136805, 0xB2DE, 0x11D1, 0xB9, 0xF2, 0x0, 0xA0, 0xC9,
                  0x8B, 0xC5, 0x47};

    __result = CA_CreateObjectByClassIdEx (&clsid, server,
                                           &SHDocVw_IID_IShellFavoritesNameSpace,
                                           supportMultithreading, locale,
                                           reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_OpenIShellFavoritesNameSpace (const char *fileName,
                                                      const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x55136805, 0xB2DE, 0x11D1, 0xB9, 0xF2, 0x0, 0xA0, 0xC9,
                  0x8B, 0xC5, 0x47};

    __result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
                                                 &SHDocVw_IID_IShellFavoritesNameSpace,
                                                 supportMultithreading, locale,
                                                 reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_ActiveIShellFavoritesNameSpace (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle)
{
    HRESULT __result;
    GUID clsid = {0x55136805, 0xB2DE, 0x11D1, 0xB9, 0xF2, 0x0, 0xA0, 0xC9,
                  0x8B, 0xC5, 0x47};

    __result = CA_GetActiveObjectByClassIdEx (&clsid, server,
                                              &SHDocVw_IID_IShellFavoritesNameSpace,
                                              supportMultithreading, locale,
                                              reserved, objectHandle);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceMoveSelectionUp (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x1,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceMoveSelectionDown (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x2,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceResetSort (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x3,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceNewFolder (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x4,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceSynchronize (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x5,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceImport (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x6,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceExport (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x7,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceInvokeContextMenuCommand (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          const char *strCommand)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x8,
                                  CAVT_EMPTY, NULL, 1, __paramTypes,
                                  strCommand);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceMoveSelectionTo (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0x9,
                                  CAVT_EMPTY, NULL, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceCreateSubscriptionForSelection (CAObjHandle objectHandle,
                                                                                ERRORINFO *errorInfo,
                                                                                VBOOL *returnValue)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0xB,
                                  CAVT_BOOL, returnValue, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceDeleteSubscriptionForSelection (CAObjHandle objectHandle,
                                                                                ERRORINFO *errorInfo,
                                                                                VBOOL *returnValue)
{
    HRESULT __result;

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0xC,
                                  CAVT_BOOL, returnValue, 0, NULL);

    return __result;
}

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceSetRoot (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *bstrFullPath)
{
    HRESULT __result;
    unsigned int __paramTypes[] = {CAVT_CSTRING};

    __result = CA_MethodInvokeEx (objectHandle, errorInfo,
                                  &SHDocVw_IID_IShellFavoritesNameSpace, 0xD,
                                  CAVT_EMPTY, NULL, 1, __paramTypes,
                                  bstrFullPath);

    return __result;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnStatusTextChange_EventVTableFunc (void *thisPtr,
                                                                          BSTR text)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnStatusTextChange_CallbackType __callbackFunction;
    char * text__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (text, &text__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, text__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (text__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnProgressChange_EventVTableFunc (void *thisPtr,
                                                                        long progress,
                                                                        long progressMax)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnProgressChange_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 1, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, progress,
                                       progressMax);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnCommandStateChange_EventVTableFunc (void *thisPtr,
                                                                            long command,
                                                                            VBOOL enable)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnCommandStateChange_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 2, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, command,
                                       enable);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnDownloadBegin_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnDownloadBegin_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 3, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnDownloadComplete_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnDownloadComplete_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 4, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnTitleChange_EventVTableFunc (void *thisPtr,
                                                                     BSTR text)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnTitleChange_CallbackType __callbackFunction;
    char * text__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 5, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (text, &text__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, text__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (text__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnPropertyChange_EventVTableFunc (void *thisPtr,
                                                                        BSTR szProperty)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnPropertyChange_CallbackType __callbackFunction;
    char * szProperty__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 6, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (szProperty, &szProperty__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData,
                                       szProperty__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (szProperty__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnBeforeNavigate2_EventVTableFunc (void *thisPtr,
                                                                         LPDISPATCH pDisp,
                                                                         VARIANT *URL,
                                                                         VARIANT *flags,
                                                                         VARIANT *targetFrameName,
                                                                         VARIANT *postData,
                                                                         VARIANT *headers,
                                                                         VBOOL *cancel)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnBeforeNavigate2_CallbackType __callbackFunction;
    CAObjHandle pDisp__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 7, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_CreateObjHandleFromInterface (pDisp, &IID_IDispatch, 0,
                                                     LOCALE_NEUTRAL, 0, 1,
                                                     &pDisp__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, pDisp__CType,
                                       URL, flags, targetFrameName, postData, headers,
                                       cancel);
    
        __caErrChk (__result);
        
        }
Error:
    CA_DiscardObjHandle (pDisp__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnNewWindow2_EventVTableFunc (void *thisPtr,
                                                                    LPDISPATCH *ppDisp,
                                                                    VBOOL *cancel)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnNewWindow2_CallbackType __callbackFunction;
    CAObjHandle ppDisp__CType = 0;
    LPDISPATCH ppDisp__AutoType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 8, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_CreateObjHandleFromInterface (*ppDisp, &IID_IDispatch, 0,
                                                     LOCALE_NEUTRAL, 0, 0,
                                                     &ppDisp__CType));
        *ppDisp = 0;
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, &ppDisp__CType,
                                       cancel);
    
        __caErrChk (__result);
    
        __caErrChk (CA_GetInterfaceFromObjHandle (ppDisp__CType, &IID_IDispatch, 1,
                                                  &ppDisp__AutoType, NULL));
        *ppDisp = ppDisp__AutoType;
        ppDisp__AutoType = 0;
        
        }
Error:
    CA_DiscardObjHandle (ppDisp__CType);
    if (ppDisp__AutoType)
        ppDisp__AutoType->lpVtbl->Release (ppDisp__AutoType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnNavigateComplete2_EventVTableFunc (void *thisPtr,
                                                                           LPDISPATCH pDisp,
                                                                           VARIANT *URL)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnNavigateComplete2_CallbackType __callbackFunction;
    CAObjHandle pDisp__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 9, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_CreateObjHandleFromInterface (pDisp, &IID_IDispatch, 0,
                                                     LOCALE_NEUTRAL, 0, 1,
                                                     &pDisp__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, pDisp__CType,
                                       URL);
    
        __caErrChk (__result);
        
        }
Error:
    CA_DiscardObjHandle (pDisp__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnDocumentComplete_EventVTableFunc (void *thisPtr,
                                                                          LPDISPATCH pDisp,
                                                                          VARIANT *URL)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnDocumentComplete_CallbackType __callbackFunction;
    CAObjHandle pDisp__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 10, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_CreateObjHandleFromInterface (pDisp, &IID_IDispatch, 0,
                                                     LOCALE_NEUTRAL, 0, 1,
                                                     &pDisp__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, pDisp__CType,
                                       URL);
    
        __caErrChk (__result);
        
        }
Error:
    CA_DiscardObjHandle (pDisp__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnQuit_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnQuit_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 11, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnVisible_EventVTableFunc (void *thisPtr,
                                                                   VBOOL visible)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnVisible_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 12, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, visible);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnToolBar_EventVTableFunc (void *thisPtr,
                                                                   VBOOL toolBar)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnToolBar_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 13, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, toolBar);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnMenuBar_EventVTableFunc (void *thisPtr,
                                                                   VBOOL menuBar)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnMenuBar_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 14, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, menuBar);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnStatusBar_EventVTableFunc (void *thisPtr,
                                                                     VBOOL statusBar)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnStatusBar_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 15, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, statusBar);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnFullScreen_EventVTableFunc (void *thisPtr,
                                                                      VBOOL fullScreen)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnFullScreen_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 16, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, fullScreen);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvnts2RegOnOnTheaterMode_EventVTableFunc (void *thisPtr,
                                                                       VBOOL theaterMode)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvnts2RegOnOnTheaterMode_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 17, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, theaterMode);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnBeforeNavigate_EventVTableFunc (void *thisPtr,
                                                                       BSTR URL,
                                                                       long flags,
                                                                       BSTR targetFrameName,
                                                                       VARIANT *postData,
                                                                       BSTR headers,
                                                                       VBOOL *cancel)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnBeforeNavigate_CallbackType __callbackFunction;
    char * URL__CType = 0;
    char * targetFrameName__CType = 0;
    char * headers__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (URL, &URL__CType));
        __caErrChk (CA_BSTRGetCString (targetFrameName, &targetFrameName__CType));
        __caErrChk (CA_BSTRGetCString (headers, &headers__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, URL__CType,
                                       flags, targetFrameName__CType, postData,
                                       headers__CType, cancel);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (URL__CType);
    CA_FreeMemory (targetFrameName__CType);
    CA_FreeMemory (headers__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnNavigateComplete_EventVTableFunc (void *thisPtr,
                                                                         BSTR URL)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnNavigateComplete_CallbackType __callbackFunction;
    char * URL__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 1, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (URL, &URL__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, URL__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (URL__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnStatusTextChange_EventVTableFunc (void *thisPtr,
                                                                         BSTR text)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnStatusTextChange_CallbackType __callbackFunction;
    char * text__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 2, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (text, &text__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, text__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (text__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnProgressChange_EventVTableFunc (void *thisPtr,
                                                                       long progress,
                                                                       long progressMax)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnProgressChange_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 3, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, progress,
                                       progressMax);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnDownloadComplete_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnDownloadComplete_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 4, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnCommandStateChange_EventVTableFunc (void *thisPtr,
                                                                           long command,
                                                                           VBOOL enable)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnCommandStateChange_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 5, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, command,
                                       enable);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnDownloadBegin_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnDownloadBegin_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 6, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnNewWindow_EventVTableFunc (void *thisPtr,
                                                                  BSTR URL,
                                                                  long flags,
                                                                  BSTR targetFrameName,
                                                                  VARIANT *postData,
                                                                  BSTR headers,
                                                                  VBOOL *processed)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnNewWindow_CallbackType __callbackFunction;
    char * URL__CType = 0;
    char * targetFrameName__CType = 0;
    char * headers__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 7, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (URL, &URL__CType));
        __caErrChk (CA_BSTRGetCString (targetFrameName, &targetFrameName__CType));
        __caErrChk (CA_BSTRGetCString (headers, &headers__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, URL__CType,
                                       flags, targetFrameName__CType, postData,
                                       headers__CType, processed);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (URL__CType);
    CA_FreeMemory (targetFrameName__CType);
    CA_FreeMemory (headers__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnTitleChange_EventVTableFunc (void *thisPtr,
                                                                    BSTR text)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnTitleChange_CallbackType __callbackFunction;
    char * text__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 8, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (text, &text__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, text__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (text__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnFrameBeforeNavigate_EventVTableFunc (void *thisPtr,
                                                                            BSTR URL,
                                                                            long flags,
                                                                            BSTR targetFrameName,
                                                                            VARIANT *postData,
                                                                            BSTR headers,
                                                                            VBOOL *cancel)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnFrameBeforeNavigate_CallbackType __callbackFunction;
    char * URL__CType = 0;
    char * targetFrameName__CType = 0;
    char * headers__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 9, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (URL, &URL__CType));
        __caErrChk (CA_BSTRGetCString (targetFrameName, &targetFrameName__CType));
        __caErrChk (CA_BSTRGetCString (headers, &headers__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, URL__CType,
                                       flags, targetFrameName__CType, postData,
                                       headers__CType, cancel);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (URL__CType);
    CA_FreeMemory (targetFrameName__CType);
    CA_FreeMemory (headers__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnFrameNavigateComplete_EventVTableFunc (void *thisPtr,
                                                                              BSTR URL)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnFrameNavigateComplete_CallbackType __callbackFunction;
    char * URL__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 10, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (URL, &URL__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, URL__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (URL__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnFrameNewWindow_EventVTableFunc (void *thisPtr,
                                                                       BSTR URL,
                                                                       long flags,
                                                                       BSTR targetFrameName,
                                                                       VARIANT *postData,
                                                                       BSTR headers,
                                                                       VBOOL *processed)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnFrameNewWindow_CallbackType __callbackFunction;
    char * URL__CType = 0;
    char * targetFrameName__CType = 0;
    char * headers__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 11, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (URL, &URL__CType));
        __caErrChk (CA_BSTRGetCString (targetFrameName, &targetFrameName__CType));
        __caErrChk (CA_BSTRGetCString (headers, &headers__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, URL__CType,
                                       flags, targetFrameName__CType, postData,
                                       headers__CType, processed);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (URL__CType);
    CA_FreeMemory (targetFrameName__CType);
    CA_FreeMemory (headers__CType);

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnQuit_EventVTableFunc (void *thisPtr,
                                                             VBOOL *cancel)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnQuit_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 12, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, cancel);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnWindowMove_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnWindowMove_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 13, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnWindowResize_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnWindowResize_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 14, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnWindowActivate_EventVTableFunc (void *thisPtr)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnWindowActivate_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 15, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DWebBrwsrEvntsRegOnPropertyChange_EventVTableFunc (void *thisPtr,
                                                                       BSTR property)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DWebBrwsrEvntsRegOnPropertyChange_CallbackType __callbackFunction;
    char * property__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 16, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (property, &property__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData,
                                       property__CType);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (property__CType);

    return;
}

static void CVIFUNC DShellWindowsEvntsRegOnWindowRegistered_EventVTableFunc (void *thisPtr,
                                                                             long lCookie)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DShellWindowsEvntsRegOnWindowRegistered_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, lCookie);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC DShellWindowsEvntsRegOnWindowRevoked_EventVTableFunc (void *thisPtr,
                                                                          long lCookie)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    DShellWindowsEvntsRegOnWindowRevoked_CallbackType __callbackFunction;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 1, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, lCookie);
    
        __caErrChk (__result);
        
        }
Error:

    return;
}

static void CVIFUNC _ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_EventVTableFunc (void *thisPtr,
                                                                                                 long cItems,
                                                                                                 long hItem,
                                                                                                 BSTR strName,
                                                                                                 BSTR strUrl,
                                                                                                 long cVisits,
                                                                                                 BSTR strDate,
                                                                                                 long fAvailableOffline)
{
    HRESULT __result;
    void * __callbackData;
    CAObjHandle __serverObjHandle;
    _ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_CallbackType __callbackFunction;
    char * strName__CType = 0;
    char * strUrl__CType = 0;
    char * strDate__CType = 0;
    
    

    __caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
                                     &__callbackData, &__serverObjHandle));

    if (__callbackFunction != NULL)
        {
        __caErrChk (CA_BSTRGetCString (strName, &strName__CType));
        __caErrChk (CA_BSTRGetCString (strUrl, &strUrl__CType));
        __caErrChk (CA_BSTRGetCString (strDate, &strDate__CType));
    
        __result = __callbackFunction (__serverObjHandle, __callbackData, cItems, hItem,
                                       strName__CType, strUrl__CType, cVisits,
                                       strDate__CType, fAvailableOffline);
    
        __caErrChk (__result);
        
        }
Error:
    CA_FreeMemory (strName__CType);
    CA_FreeMemory (strUrl__CType);
    CA_FreeMemory (strDate__CType);

    return;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnStatusTextChange (CAObjHandle serverObject,
                                                              DWebBrwsrEvnts2RegOnStatusTextChange_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 0,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnProgressChange (CAObjHandle serverObject,
                                                            DWebBrwsrEvnts2RegOnProgressChange_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 1,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnCommandStateChange (CAObjHandle serverObject,
                                                                DWebBrwsrEvnts2RegOnCommandStateChange_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 2,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnDownloadBegin (CAObjHandle serverObject,
                                                           DWebBrwsrEvnts2RegOnDownloadBegin_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 3,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnDownloadComplete (CAObjHandle serverObject,
                                                              DWebBrwsrEvnts2RegOnDownloadComplete_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 4,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnTitleChange (CAObjHandle serverObject,
                                                         DWebBrwsrEvnts2RegOnTitleChange_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 5,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnPropertyChange (CAObjHandle serverObject,
                                                            DWebBrwsrEvnts2RegOnPropertyChange_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 6,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnBeforeNavigate2 (CAObjHandle serverObject,
                                                             DWebBrwsrEvnts2RegOnBeforeNavigate2_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 7,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnNewWindow2 (CAObjHandle serverObject,
                                                        DWebBrwsrEvnts2RegOnNewWindow2_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 8,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnNavigateComplete2 (CAObjHandle serverObject,
                                                               DWebBrwsrEvnts2RegOnNavigateComplete2_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn, 9,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnDocumentComplete (CAObjHandle serverObject,
                                                              DWebBrwsrEvnts2RegOnDocumentComplete_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         10, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnQuit (CAObjHandle serverObject,
                                                    DWebBrwsrEvnts2RegOnOnQuit_CallbackType callbackFunction,
                                                    void *callbackData,
                                                    int enableCallbacks,
                                                    int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         11, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnVisible (CAObjHandle serverObject,
                                                       DWebBrwsrEvnts2RegOnOnVisible_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         12, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnToolBar (CAObjHandle serverObject,
                                                       DWebBrwsrEvnts2RegOnOnToolBar_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         13, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnMenuBar (CAObjHandle serverObject,
                                                       DWebBrwsrEvnts2RegOnOnMenuBar_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         14, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnStatusBar (CAObjHandle serverObject,
                                                         DWebBrwsrEvnts2RegOnOnStatusBar_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         15, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnFullScreen (CAObjHandle serverObject,
                                                          DWebBrwsrEvnts2RegOnOnFullScreen_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         16, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnTheaterMode (CAObjHandle serverObject,
                                                           DWebBrwsrEvnts2RegOnOnTheaterMode_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts2_CAEventClassDefn,
                                         17, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnBeforeNavigate (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnBeforeNavigate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 0,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnNavigateComplete (CAObjHandle serverObject,
                                                             DWebBrwsrEvntsRegOnNavigateComplete_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 1,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnStatusTextChange (CAObjHandle serverObject,
                                                             DWebBrwsrEvntsRegOnStatusTextChange_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 2,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnProgressChange (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnProgressChange_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 3,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnDownloadComplete (CAObjHandle serverObject,
                                                             DWebBrwsrEvntsRegOnDownloadComplete_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 4,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnCommandStateChange (CAObjHandle serverObject,
                                                               DWebBrwsrEvntsRegOnCommandStateChange_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 5,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnDownloadBegin (CAObjHandle serverObject,
                                                          DWebBrwsrEvntsRegOnDownloadBegin_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 6,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnNewWindow (CAObjHandle serverObject,
                                                      DWebBrwsrEvntsRegOnNewWindow_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 7,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnTitleChange (CAObjHandle serverObject,
                                                        DWebBrwsrEvntsRegOnTitleChange_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 8,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnFrameBeforeNavigate (CAObjHandle serverObject,
                                                                DWebBrwsrEvntsRegOnFrameBeforeNavigate_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 9,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnFrameNavigateComplete (CAObjHandle serverObject,
                                                                  DWebBrwsrEvntsRegOnFrameNavigateComplete_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 10,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnFrameNewWindow (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnFrameNewWindow_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 11,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnQuit (CAObjHandle serverObject,
                                                 DWebBrwsrEvntsRegOnQuit_CallbackType callbackFunction,
                                                 void *callbackData,
                                                 int enableCallbacks,
                                                 int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 12,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnWindowMove (CAObjHandle serverObject,
                                                       DWebBrwsrEvntsRegOnWindowMove_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 13,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnWindowResize (CAObjHandle serverObject,
                                                         DWebBrwsrEvntsRegOnWindowResize_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 14,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnWindowActivate (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnWindowActivate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 15,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnPropertyChange (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnPropertyChange_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DWebBrwsrEvnts_CAEventClassDefn, 16,
                                         callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DShellWindowsEvntsRegOnWindowRegistered (CAObjHandle serverObject,
                                                                 DShellWindowsEvntsRegOnWindowRegistered_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DShellWindowsEvnts_CAEventClassDefn,
                                         0, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw_DShellWindowsEvntsRegOnWindowRevoked (CAObjHandle serverObject,
                                                              DShellWindowsEvntsRegOnWindowRevoked_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &_DShellWindowsEvnts_CAEventClassDefn,
                                         1, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}

HRESULT CVIFUNC SHDocVw__ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange (CAObjHandle serverObject,
                                                                                     _ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_CallbackType callbackFunction,
                                                                                     void *callbackData,
                                                                                     int enableCallbacks,
                                                                                     int *callbackId)
{
    HRESULT __result;

    __result = CA_RegisterEventCallback (serverObject,
                                         &__ShellFavoritesNameSpaceEvents_CAEventClassDefn,
                                         0, callbackFunction, callbackData,
                                         enableCallbacks, callbackId);

    return __result;
}
