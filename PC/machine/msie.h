#ifndef _SHDOCVW_H
#define _SHDOCVW_H

#if defined(INCLUDE_AFTER_WINDOWS_H) && !defined(_INC_WINDOWS)
#error  This header must be included before utility.h and formatio.h
#error  because it includes cviauto.h which includes Windows SDK headers.
#endif /* INCLUDE_AFTER_WINDOWS_H */

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Object Name: IWebBrowser */
#define SHDocVw_IWebBrowserApplication       0x000000C8
#define SHDocVw_IWebBrowserParent            0x000000C9
#define SHDocVw_IWebBrowserContainer         0x000000CA
#define SHDocVw_IWebBrowserDocument          0x000000CB
#define SHDocVw_IWebBrowserTopLevelContainer 0x000000CC
#define SHDocVw_IWebBrowserType              0x000000CD
#define SHDocVw_IWebBrowserLeft              0x000000CE
#define SHDocVw_IWebBrowserTop               0x000000CF
#define SHDocVw_IWebBrowserWidth             0x000000D0
#define SHDocVw_IWebBrowserHeight            0x000000D1
#define SHDocVw_IWebBrowserLocationName      0x000000D2
#define SHDocVw_IWebBrowserLocationURL       0x000000D3
#define SHDocVw_IWebBrowserBusy              0x000000D4
/* NICDBLD_END> Object Name: IWebBrowser */

/* NICDBLD_BEGIN> Object Name: IWebBrowser2 */
#define SHDocVw_IWebBrowser2ReadyState           0xFFFFFDF3
#define SHDocVw_IWebBrowser2HWND                 0xFFFFFDFD
#define SHDocVw_IWebBrowser2Name                 0x00000000
#define SHDocVw_IWebBrowser2Application          0x000000C8
#define SHDocVw_IWebBrowser2Parent               0x000000C9
#define SHDocVw_IWebBrowser2Container            0x000000CA
#define SHDocVw_IWebBrowser2Document             0x000000CB
#define SHDocVw_IWebBrowser2TopLevelContainer    0x000000CC
#define SHDocVw_IWebBrowser2Type                 0x000000CD
#define SHDocVw_IWebBrowser2Left                 0x000000CE
#define SHDocVw_IWebBrowser2Top                  0x000000CF
#define SHDocVw_IWebBrowser2Width                0x000000D0
#define SHDocVw_IWebBrowser2Height               0x000000D1
#define SHDocVw_IWebBrowser2LocationName         0x000000D2
#define SHDocVw_IWebBrowser2LocationURL          0x000000D3
#define SHDocVw_IWebBrowser2Busy                 0x000000D4
#define SHDocVw_IWebBrowser2FullName             0x00000190
#define SHDocVw_IWebBrowser2Path                 0x00000191
#define SHDocVw_IWebBrowser2Visible              0x00000192
#define SHDocVw_IWebBrowser2StatusBar            0x00000193
#define SHDocVw_IWebBrowser2StatusText           0x00000194
#define SHDocVw_IWebBrowser2ToolBar              0x00000195
#define SHDocVw_IWebBrowser2MenuBar              0x00000196
#define SHDocVw_IWebBrowser2FullScreen           0x00000197
#define SHDocVw_IWebBrowser2Offline              0x00000226
#define SHDocVw_IWebBrowser2Silent               0x00000227
#define SHDocVw_IWebBrowser2RegisterAsBrowser    0x00000228
#define SHDocVw_IWebBrowser2RegisterAsDropTarget 0x00000229
#define SHDocVw_IWebBrowser2TheaterMode          0x0000022A
#define SHDocVw_IWebBrowser2AddressBar           0x0000022B
#define SHDocVw_IWebBrowser2Resizable            0x0000022C
/* NICDBLD_END> Object Name: IWebBrowser2 */

/* NICDBLD_BEGIN> Object Name: IShellWindows */
#define SHDocVw_IShellWindowsCount 0x60020000
/* NICDBLD_END> Object Name: IShellWindows */

/* NICDBLD_BEGIN> Object Name: IShellFavoritesNameSpace */
#define SHDocVw_IShellFavoritesNameSpaceFOfflinePackInstalled 0x0000000A
/* NICDBLD_END> Object Name: IShellFavoritesNameSpace */
/* NICDBLD_END> ActiveX Automation Properties */

/* NICDBLD_BEGIN> Type Library Specific Types */
enum SHDocVwEnum_OLECMDID
{
    SHDocVwConst_OLECMDID_OPEN = 1,
    SHDocVwConst_OLECMDID_NEW = 2,
    SHDocVwConst_OLECMDID_SAVE = 3,
    SHDocVwConst_OLECMDID_SAVEAS = 4,
    SHDocVwConst_OLECMDID_SAVECOPYAS = 5,
    SHDocVwConst_OLECMDID_PRINT = 6,
    SHDocVwConst_OLECMDID_PRINTPREVIEW = 7,
    SHDocVwConst_OLECMDID_PAGESETUP = 8,
    SHDocVwConst_OLECMDID_SPELL = 9,
    SHDocVwConst_OLECMDID_PROPERTIES = 10,
    SHDocVwConst_OLECMDID_CUT = 11,
    SHDocVwConst_OLECMDID_COPY = 12,
    SHDocVwConst_OLECMDID_PASTE = 13,
    SHDocVwConst_OLECMDID_PASTESPECIAL = 14,
    SHDocVwConst_OLECMDID_UNDO = 15,
    SHDocVwConst_OLECMDID_REDO = 16,
    SHDocVwConst_OLECMDID_SELECTALL = 17,
    SHDocVwConst_OLECMDID_CLEARSELECTION = 18,
    SHDocVwConst_OLECMDID_ZOOM = 19,
    SHDocVwConst_OLECMDID_GETZOOMRANGE = 20,
    SHDocVwConst_OLECMDID_UPDATECOMMANDS = 21,
    SHDocVwConst_OLECMDID_REFRESH = 22,
    SHDocVwConst_OLECMDID_STOP = 23,
    SHDocVwConst_OLECMDID_HIDETOOLBARS = 24,
    SHDocVwConst_OLECMDID_SETPROGRESSMAX = 25,
    SHDocVwConst_OLECMDID_SETPROGRESSPOS = 26,
    SHDocVwConst_OLECMDID_SETPROGRESSTEXT = 27,
    SHDocVwConst_OLECMDID_SETTITLE = 28,
    SHDocVwConst_OLECMDID_SETDOWNLOADSTATE = 29,
    SHDocVwConst_OLECMDID_STOPDOWNLOAD = 30,
    SHDocVwConst_OLECMDID_ONTOOLBARACTIVATED = 31,
    SHDocVwConst_OLECMDID_FIND = 32,
    SHDocVwConst_OLECMDID_DELETE = 33,
    SHDocVwConst_OLECMDID_HTTPEQUIV = 34,
    SHDocVwConst_OLECMDID_HTTPEQUIV_DONE = 35,
    SHDocVwConst_OLECMDID_ENABLE_INTERACTION = 36,
    SHDocVwConst_OLECMDID_ONUNLOAD = 37,
    SHDocVwConst_OLECMDID_PROPERTYBAG2 = 38,
    SHDocVwConst_OLECMDID_PREREFRESH = 39,
    SHDocVwConst_OLECMDID_SHOWSCRIPTERROR = 40,
    SHDocVwConst_OLECMDID_SHOWMESSAGE = 41,
    SHDocVwConst_OLECMDID_SHOWFIND = 42,
    SHDocVwConst_OLECMDID_SHOWPAGESETUP = 43,
    SHDocVwConst_OLECMDID_SHOWPRINT = 44,
    SHDocVwConst_OLECMDID_CLOSE = 45,
    SHDocVwConst_OLECMDID_ALLOWUILESSSAVEAS = 46,
    SHDocVwConst_OLECMDID_DONTDOWNLOADCSS = 47,
    _SHDocVw_OLECMDIDForceSizeToFourBytes = 0xFFFFFFFF
};
enum SHDocVwEnum_OLECMDF
{
    SHDocVwConst_OLECMDF_SUPPORTED = 1,
    SHDocVwConst_OLECMDF_ENABLED = 2,
    SHDocVwConst_OLECMDF_LATCHED = 4,
    SHDocVwConst_OLECMDF_NINCHED = 8,
    SHDocVwConst_OLECMDF_INVISIBLE = 16,
    SHDocVwConst_OLECMDF_DEFHIDEONCTXTMENU = 32,
    _SHDocVw_OLECMDFForceSizeToFourBytes = 0xFFFFFFFF
};
enum SHDocVwEnum_OLECMDEXECOPT
{
    SHDocVwConst_OLECMDEXECOPT_DODEFAULT = 0,
    SHDocVwConst_OLECMDEXECOPT_PROMPTUSER = 1,
    SHDocVwConst_OLECMDEXECOPT_DONTPROMPTUSER = 2,
    SHDocVwConst_OLECMDEXECOPT_SHOWHELP = 3,
    _SHDocVw_OLECMDEXECOPTForceSizeToFourBytes = 0xFFFFFFFF
};
enum SHDocVwEnum_tagREADYSTATE
{
    SHDocVwConst_READYSTATE_UNINITIALIZED = 0,
    SHDocVwConst_READYSTATE_LOADING = 1,
    SHDocVwConst_READYSTATE_LOADED = 2,
    SHDocVwConst_READYSTATE_INTERACTIVE = 3,
    SHDocVwConst_READYSTATE_COMPLETE = 4,
    _SHDocVw_tagREADYSTATEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SHDocVwEnum_CommandStateChangeConstants
{
    SHDocVwConst_CSC_UPDATECOMMANDS = -1,
    SHDocVwConst_CSC_NAVIGATEFORWARD = 1,
    SHDocVwConst_CSC_NAVIGATEBACK = 2,
    _SHDocVw_CommandStateChangeConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SHDocVwEnum_ShellWindowTypeConstants
{
    SHDocVwConst_SWC_EXPLORER = 0,
    SHDocVwConst_SWC_BROWSER = 1,
    SHDocVwConst_SWC_3RDPARTY = 2,
    SHDocVwConst_SWC_CALLBACK = 4,
    _SHDocVw_ShellWindowTypeConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SHDocVwEnum_ShellWindowFindWindowOptions
{
    SHDocVwConst_SWFO_NEEDDISPATCH = 1,
    SHDocVwConst_SWFO_INCLUDEPENDING = 2,
    SHDocVwConst_SWFO_COOKIEPASSED = 4,
    _SHDocVw_ShellWindowFindWindowOptionsForceSizeToFourBytes = 0xFFFFFFFF
};
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnStatusTextChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData,
                                                                                  char *text);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnProgressChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long  progress,
                                                                                long  progressMax);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnCommandStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long  command,
                                                                                    VBOOL  enable);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnDownloadBegin_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnDownloadComplete_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnTitleChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             char *text);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnPropertyChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                char *szProperty);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnBeforeNavigate2_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 CAObjHandle  pDisp,
                                                                                 VARIANT *URL,
                                                                                 VARIANT *flags,
                                                                                 VARIANT *targetFrameName,
                                                                                 VARIANT *postData,
                                                                                 VARIANT *headers,
                                                                                 VBOOL *cancel);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnNewWindow2_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            CAObjHandle *ppDisp,
                                                                            VBOOL *cancel);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnNavigateComplete2_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   CAObjHandle  pDisp,
                                                                                   VARIANT *URL);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnDocumentComplete_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData,
                                                                                  CAObjHandle  pDisp,
                                                                                  VARIANT *URL);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnQuit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnVisible_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           VBOOL  visible);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnToolBar_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           VBOOL  toolBar);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnMenuBar_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           VBOOL  menuBar);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnStatusBar_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             VBOOL  statusBar);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnFullScreen_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              VBOOL  fullScreen);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvnts2RegOnOnTheaterMode_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               VBOOL  theaterMode);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnBeforeNavigate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               char *URL,
                                                                               long  flags,
                                                                               char *targetFrameName,
                                                                               VARIANT *postData,
                                                                               char *headers,
                                                                               VBOOL *cancel);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnNavigateComplete_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 char *URL);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnStatusTextChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 char *text);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnProgressChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  progress,
                                                                               long  progressMax);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnDownloadComplete_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnCommandStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   long  command,
                                                                                   VBOOL  enable);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnDownloadBegin_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnNewWindow_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          char *URL,
                                                                          long  flags,
                                                                          char *targetFrameName,
                                                                          VARIANT *postData,
                                                                          char *headers,
                                                                          VBOOL *processed);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnTitleChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            char *text);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnFrameBeforeNavigate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    char *URL,
                                                                                    long  flags,
                                                                                    char *targetFrameName,
                                                                                    VARIANT *postData,
                                                                                    char *headers,
                                                                                    VBOOL *cancel);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnFrameNavigateComplete_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                      void *caCallbackData,
                                                                                      char *URL);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnFrameNewWindow_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               char *URL,
                                                                               long  flags,
                                                                               char *targetFrameName,
                                                                               VARIANT *postData,
                                                                               char *headers,
                                                                               VBOOL *processed);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnQuit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                     void *caCallbackData,
                                                                     VBOOL *cancel);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnWindowMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnWindowResize_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnWindowActivate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData);
typedef HRESULT (CVICALLBACK *DWebBrwsrEvntsRegOnPropertyChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               char *property);
typedef HRESULT (CVICALLBACK *DShellWindowsEvntsRegOnWindowRegistered_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                     void *caCallbackData,
                                                                                     long  lCookie);
typedef HRESULT (CVICALLBACK *DShellWindowsEvntsRegOnWindowRevoked_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData,
                                                                                  long  lCookie);
typedef HRESULT (CVICALLBACK *_ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                                         void *caCallbackData,
                                                                                                         long  cItems,
                                                                                                         long  hItem,
                                                                                                         char *strName,
                                                                                                         char *strUrl,
                                                                                                         long  cVisits,
                                                                                                         char *strDate,
                                                                                                         long  fAvailableOffline);
/* NICDBLD_END> Type Library Specific Types */

extern const IID SHDocVw_IID_IWebBrowser;
extern const IID SHDocVw_IID_IWebBrowser2;
extern const IID SHDocVw_IID_IShellWindows;
extern const IID SHDocVw_IID_IShellUIHelper;
extern const IID SHDocVw_IID_IShellFavoritesNameSpace;
extern const IID SHDocVw_IID_DWebBrwsrEvnts2;
extern const IID SHDocVw_IID_DWebBrwsrEvnts;
extern const IID SHDocVw_IID_DShellWindowsEvnts;
extern const IID SHDocVw_IID__ShellFavoritesNameSpaceEvents;

HRESULT CVIFUNC SHDocVw_GetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, void *value);

HRESULT CVIFUNC SHDocVw_SetProperty (CAObjHandle objectHandle,
                                     ERRORINFO *errorInfo,
                                     unsigned int propertyID,
                                     unsigned int propertyType, ...);

HRESULT CVIFUNC SHDocVw_NewIWebBrowser (const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenIWebBrowser (const char *fileName,
                                         const char *server,
                                         int supportMultithreading, LCID locale,
                                         int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveIWebBrowser (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_IWebBrowserGoBack (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowserGoForward (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowserGoHome (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowserGoSearch (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowserNavigate (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             const char *URL, VARIANT flags,
                                             VARIANT targetFrameName,
                                             VARIANT postData, VARIANT headers);

HRESULT CVIFUNC SHDocVw_IWebBrowserRefresh (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowserRefresh2 (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT level);

HRESULT CVIFUNC SHDocVw_IWebBrowserStop (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_NewWebBrowserIWebBrowser2 (const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenWebBrowserIWebBrowser2 (const char *fileName,
                                                    const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveWebBrowserIWebBrowser2 (const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_NewInternetExplorerIWebBrowser2 (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenInternetExplorerIWebBrowser2 (const char *fileName,
                                                          const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveInternetExplorerIWebBrowser2 (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoBack (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoForward (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoHome (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GoSearch (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *URL, VARIANT flags,
                                              VARIANT targetFrameName,
                                              VARIANT postData, VARIANT headers);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Refresh2 (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT level);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Stop (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Quit (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IWebBrowser2ClientToWindow (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pcx, long *pcy);

HRESULT CVIFUNC SHDocVw_IWebBrowser2PutProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *property,
                                                 VARIANT vtValue);

HRESULT CVIFUNC SHDocVw_IWebBrowser2GetProperty (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *property,
                                                 VARIANT *returnValue);

HRESULT CVIFUNC SHDocVw_IWebBrowser2Navigate2 (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, VARIANT URL,
                                               VARIANT flags,
                                               VARIANT targetFrameName,
                                               VARIANT postData, VARIANT headers);

HRESULT CVIFUNC SHDocVw_IWebBrowser2QueryStatusWB (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum SHDocVwEnum_OLECMDID cmdID,
                                                   enum SHDocVwEnum_OLECMDF *returnValue);

HRESULT CVIFUNC SHDocVw_IWebBrowser2ExecWB (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            enum SHDocVwEnum_OLECMDID cmdID,
                                            enum SHDocVwEnum_OLECMDEXECOPT cmdexecopt,
                                            VARIANT pvaIn, VARIANT *pvaOut);

HRESULT CVIFUNC SHDocVw_IWebBrowser2ShowBrowserBar (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pvaClsid,
                                                    VARIANT pvarShow,
                                                    VARIANT pvarSize);

HRESULT CVIFUNC SHDocVw_NewIShellWindows (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenIShellWindows (const char *fileName,
                                           const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveIShellWindows (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_IShellWindowsItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT index,
                                           CAObjHandle *returnValue);

HRESULT CVIFUNC SHDocVw_IShellWindows_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *returnValue);

HRESULT CVIFUNC SHDocVw_IShellWindowsRegister (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CAObjHandle pid, long HWND,
                                               long swClass, long *plCookie);

HRESULT CVIFUNC SHDocVw_IShellWindowsRegisterPending (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long lThreadId,
                                                      VARIANT pvarloc,
                                                      VARIANT pvarlocRoot,
                                                      long swClass,
                                                      long *plCookie);

HRESULT CVIFUNC SHDocVw_IShellWindowsRevoke (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, long lCookie);

HRESULT CVIFUNC SHDocVw_IShellWindowsOnNavigate (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long lCookie, VARIANT pvarloc);

HRESULT CVIFUNC SHDocVw_IShellWindowsOnActivated (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long lCookie, VBOOL fActive);

HRESULT CVIFUNC SHDocVw_IShellWindowsFindWindow (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT pvarloc,
                                                 VARIANT pvarlocRoot,
                                                 long swClass, long *pHWND,
                                                 long swfwOptions,
                                                 CAObjHandle *returnValue);

HRESULT CVIFUNC SHDocVw_IShellWindowsOnCreated (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                long lCookie, LPUNKNOWN punk);

HRESULT CVIFUNC SHDocVw_IShellWindowsProcessAttachDetch (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL fAttach);

HRESULT CVIFUNC SHDocVw_NewIShellUIHelper (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenIShellUIHelper (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveIShellUIHelper (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_IShellUIHelperResetFrstBootMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellUIHelperResetSafeMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellUIHelperRefreshOfflnDsktp (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellUIHelperAddFavorite (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *URL,
                                                   VARIANT title);

HRESULT CVIFUNC SHDocVw_IShellUIHelperAddChannel (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *URL);

HRESULT CVIFUNC SHDocVw_IShellUIHelperAddDsktpComponent (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *URL,
                                                         const char *type,
                                                         VARIANT left,
                                                         VARIANT top,
                                                         VARIANT width,
                                                         VARIANT height);

HRESULT CVIFUNC SHDocVw_IShellUIHelperIsSubscribed (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *URL,
                                                    VBOOL *returnValue);

HRESULT CVIFUNC SHDocVw_IShellUIHelperNavigateAndFind (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *URL,
                                                       const char *strQuery,
                                                       VARIANT varTargetFrame);

HRESULT CVIFUNC SHDocVw_IShellUIHelperImportExportFavorites (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL fImport,
                                                             const char *strImpExpPath);

HRESULT CVIFUNC SHDocVw_IShellUIHelperAutoCompleteSaveForm (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT form);

HRESULT CVIFUNC SHDocVw_IShellUIHelperAutoScan (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *strSearch,
                                                const char *strFailureUrl,
                                                VARIANT pvarTargetFrame);

HRESULT CVIFUNC SHDocVw_IShellUIHelperAutoCompleteAttach (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT reserved);

HRESULT CVIFUNC SHDocVw_IShellUIHelperShowBrowserUI (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *bstrName,
                                                     VARIANT pvarIn,
                                                     VARIANT *returnValue);

HRESULT CVIFUNC SHDocVw_NewIShellFavoritesNameSpace (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_OpenIShellFavoritesNameSpace (const char *fileName,
                                                      const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_ActiveIShellFavoritesNameSpace (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceMoveSelectionUp (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceMoveSelectionDown (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceResetSort (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceNewFolder (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceSynchronize (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceImport (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceExport (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceInvokeContextMenuCommand (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          const char *strCommand);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceMoveSelectionTo (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceCreateSubscriptionForSelection (CAObjHandle objectHandle,
                                                                                ERRORINFO *errorInfo,
                                                                                VBOOL *returnValue);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceDeleteSubscriptionForSelection (CAObjHandle objectHandle,
                                                                                ERRORINFO *errorInfo,
                                                                                VBOOL *returnValue);

HRESULT CVIFUNC SHDocVw_IShellFavoritesNameSpaceSetRoot (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *bstrFullPath);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnStatusTextChange (CAObjHandle serverObject,
                                                              DWebBrwsrEvnts2RegOnStatusTextChange_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnProgressChange (CAObjHandle serverObject,
                                                            DWebBrwsrEvnts2RegOnProgressChange_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnCommandStateChange (CAObjHandle serverObject,
                                                                DWebBrwsrEvnts2RegOnCommandStateChange_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnDownloadBegin (CAObjHandle serverObject,
                                                           DWebBrwsrEvnts2RegOnDownloadBegin_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnDownloadComplete (CAObjHandle serverObject,
                                                              DWebBrwsrEvnts2RegOnDownloadComplete_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnTitleChange (CAObjHandle serverObject,
                                                         DWebBrwsrEvnts2RegOnTitleChange_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnPropertyChange (CAObjHandle serverObject,
                                                            DWebBrwsrEvnts2RegOnPropertyChange_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnBeforeNavigate2 (CAObjHandle serverObject,
                                                             DWebBrwsrEvnts2RegOnBeforeNavigate2_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnNewWindow2 (CAObjHandle serverObject,
                                                        DWebBrwsrEvnts2RegOnNewWindow2_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnNavigateComplete2 (CAObjHandle serverObject,
                                                               DWebBrwsrEvnts2RegOnNavigateComplete2_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnDocumentComplete (CAObjHandle serverObject,
                                                              DWebBrwsrEvnts2RegOnDocumentComplete_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnQuit (CAObjHandle serverObject,
                                                    DWebBrwsrEvnts2RegOnOnQuit_CallbackType callbackFunction,
                                                    void *callbackData,
                                                    int enableCallbacks,
                                                    int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnVisible (CAObjHandle serverObject,
                                                       DWebBrwsrEvnts2RegOnOnVisible_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnToolBar (CAObjHandle serverObject,
                                                       DWebBrwsrEvnts2RegOnOnToolBar_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnMenuBar (CAObjHandle serverObject,
                                                       DWebBrwsrEvnts2RegOnOnMenuBar_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnStatusBar (CAObjHandle serverObject,
                                                         DWebBrwsrEvnts2RegOnOnStatusBar_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnFullScreen (CAObjHandle serverObject,
                                                          DWebBrwsrEvnts2RegOnOnFullScreen_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvnts2RegOnOnTheaterMode (CAObjHandle serverObject,
                                                           DWebBrwsrEvnts2RegOnOnTheaterMode_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnBeforeNavigate (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnBeforeNavigate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnNavigateComplete (CAObjHandle serverObject,
                                                             DWebBrwsrEvntsRegOnNavigateComplete_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnStatusTextChange (CAObjHandle serverObject,
                                                             DWebBrwsrEvntsRegOnStatusTextChange_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnProgressChange (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnProgressChange_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnDownloadComplete (CAObjHandle serverObject,
                                                             DWebBrwsrEvntsRegOnDownloadComplete_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnCommandStateChange (CAObjHandle serverObject,
                                                               DWebBrwsrEvntsRegOnCommandStateChange_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnDownloadBegin (CAObjHandle serverObject,
                                                          DWebBrwsrEvntsRegOnDownloadBegin_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnNewWindow (CAObjHandle serverObject,
                                                      DWebBrwsrEvntsRegOnNewWindow_CallbackType callbackFunction,
                                                      void *callbackData,
                                                      int enableCallbacks,
                                                      int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnTitleChange (CAObjHandle serverObject,
                                                        DWebBrwsrEvntsRegOnTitleChange_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnFrameBeforeNavigate (CAObjHandle serverObject,
                                                                DWebBrwsrEvntsRegOnFrameBeforeNavigate_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnFrameNavigateComplete (CAObjHandle serverObject,
                                                                  DWebBrwsrEvntsRegOnFrameNavigateComplete_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnFrameNewWindow (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnFrameNewWindow_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnQuit (CAObjHandle serverObject,
                                                 DWebBrwsrEvntsRegOnQuit_CallbackType callbackFunction,
                                                 void *callbackData,
                                                 int enableCallbacks,
                                                 int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnWindowMove (CAObjHandle serverObject,
                                                       DWebBrwsrEvntsRegOnWindowMove_CallbackType callbackFunction,
                                                       void *callbackData,
                                                       int enableCallbacks,
                                                       int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnWindowResize (CAObjHandle serverObject,
                                                         DWebBrwsrEvntsRegOnWindowResize_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnWindowActivate (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnWindowActivate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DWebBrwsrEvntsRegOnPropertyChange (CAObjHandle serverObject,
                                                           DWebBrwsrEvntsRegOnPropertyChange_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SHDocVw_DShellWindowsEvntsRegOnWindowRegistered (CAObjHandle serverObject,
                                                                 DShellWindowsEvntsRegOnWindowRegistered_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC SHDocVw_DShellWindowsEvntsRegOnWindowRevoked (CAObjHandle serverObject,
                                                              DShellWindowsEvntsRegOnWindowRevoked_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC SHDocVw__ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange (CAObjHandle serverObject,
                                                                                     _ShellFavoritesNameSpaceEventsRegOnFavoritesSelectionChange_CallbackType callbackFunction,
                                                                                     void *callbackData,
                                                                                     int enableCallbacks,
                                                                                     int *callbackId);
#ifdef __cplusplus
    }
#endif
#endif /* _SHDOCVW_H */
