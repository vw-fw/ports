--- chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc.orig	2023-08-18 10:26:52 UTC
+++ chrome/browser/metrics/chrome_browser_main_extra_parts_metrics.cc
@@ -77,8 +77,10 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(__GLIBC__) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(__GLIBC__) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
+#if !BUILDFLAG(IS_BSD)
 #include <gnu/libc-version.h>
+#endif
 
 #include "base/linux_util.h"
 #include "base/strings/string_split.h"
@@ -107,7 +109,7 @@
 #include "chromeos/crosapi/cpp/crosapi_constants.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/metrics/pressure/pressure_metrics_reporter.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -116,7 +118,7 @@
 #include "components/user_manager/user_manager.h"
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/power_metrics/system_power_monitor.h"
 #endif
 
@@ -538,7 +540,7 @@ void RecordStartupMetrics() {
 
   // Record whether Chrome is the default browser or not.
   // Disabled on Linux due to hanging browser tests, see crbug.com/1216328.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   shell_integration::DefaultWebClientState default_state =
       shell_integration::GetDefaultBrowser();
   base::UmaHistogramEnumeration("DefaultBrowser.State", default_state,
@@ -812,11 +814,11 @@ void ChromeBrowserMainExtraPartsMetrics::PostBrowserSt
   }
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pressure_metrics_reporter_ = std::make_unique<PressureMetricsReporter>();
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::trace_event::TraceLog::GetInstance()->AddEnabledStateObserver(
       power_metrics::SystemPowerMonitor::GetInstance());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
