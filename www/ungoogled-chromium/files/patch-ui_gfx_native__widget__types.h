--- ui/gfx/native_widget_types.h.orig	2023-08-18 10:26:52 UTC
+++ ui/gfx/native_widget_types.h
@@ -105,7 +105,7 @@ class SkBitmap;
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 extern "C" {
 struct _AtkObject;
 using AtkObject = struct _AtkObject;
@@ -223,7 +223,7 @@ using NativeViewAccessible = struct objc_object*;
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Linux doesn't have a native font type.
 using NativeViewAccessible = AtkObject*;
 #else