--- ui/base/test/skia_gold_pixel_diff.cc.orig	2023-07-16 15:47:57 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -104,7 +104,7 @@ const char* GetPlatformName() {
   return "macOS";
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return "lacros";