--- chrome/browser/ui/managed_ui.cc.orig	2023-08-18 10:26:52 UTC
+++ chrome/browser/ui/managed_ui.cc
@@ -95,7 +95,7 @@ bool ShouldDisplayManagedByParentUi(Profile* profile) 
   return false;
 #else
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // The EnableManagedByParentUiOnDesktop flag depends on
   // EnableSupervisionOnDesktopAndIOS.
   DCHECK(
