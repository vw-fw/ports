--- chrome/browser/about_flags.cc.orig	2023-08-18 10:26:52 UTC
+++ chrome/browser/about_flags.cc
@@ -224,7 +224,7 @@
 #include "ui/ui_features.h"
 #include "url/url_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -320,7 +320,7 @@
 #include "device/vr/public/cpp/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
@@ -430,7 +430,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -1482,7 +1482,7 @@ const FeatureEntry::FeatureVariation kChromeRefresh202
      std::size(kChromeRefresh2023Level1), nullptr}};
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kShortcutBoostSearchAndUrl1414[] = {
     {"ShortcutBoostSearchScore", "1414"},
     {"ShortcutBoostUrlScore", "1414"}};
@@ -4971,13 +4971,13 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -5262,7 +5262,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(feed::kFeedDynamicColors)},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"following-feed-sidepanel", flag_descriptions::kFollowingFeedSidepanelName,
      flag_descriptions::kFollowingFeedSidepanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feed::kWebUiFeed)},
@@ -5928,7 +5928,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsAll, FEATURE_VALUE_TYPE(omnibox::kUseExistingAutocompleteClient)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"omnibox-domain-suggestions",
      flag_descriptions::kOmniboxDomainSuggestionsName,
      flag_descriptions::kOmniboxDomainSuggestionsDescription, kOsDesktop,
@@ -6687,7 +6687,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kParallelDownloadingDescription, kOsAll,
      FEATURE_VALUE_TYPE(download::features::kParallelDownloading)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-async-dns", flag_descriptions::kAsyncDnsName,
      flag_descriptions::kAsyncDnsDescription, kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAsyncDns)},
@@ -8377,7 +8377,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"quick-commands", flag_descriptions::kQuickCommandsName,
      flag_descriptions::kQuickCommandsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kQuickCommands)},
@@ -8638,7 +8638,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperPerDesk)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription,
      kOsCrOS | kOsLacros | kOsLinux,
@@ -8699,7 +8699,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9267,7 +9267,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     {"document-picture-in-picture-api",
      flag_descriptions::kDocumentPictureInPictureApiName,
      flag_descriptions::kDocumentPictureInPictureApiDescription,
@@ -9987,7 +9987,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWebUIOmniboxPopupDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(omnibox::kWebUIOmniboxPopup)},
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     {"webui-system-font", flag_descriptions::kWebUiSystemFontName,
      flag_descriptions::kWebUiSystemFontDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kWebUiSystemFont)},
@@ -10172,7 +10172,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"data-retention-policies-disable-sync-types-needed",
      flag_descriptions::kDataRetentionPoliciesDisableSyncTypesNeededName,
      flag_descriptions::kDataRetentionPoliciesDisableSyncTypesNeededDescription,
@@ -10580,7 +10580,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"camera-mic-preview", flag_descriptions::kCameraMicPreviewName,
      flag_descriptions::kCameraMicPreviewDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux | kOsFuchsia),
