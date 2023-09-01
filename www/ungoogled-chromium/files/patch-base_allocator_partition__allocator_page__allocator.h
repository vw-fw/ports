--- base/allocator/partition_allocator/page_allocator.h.orig	2023-08-18 10:26:52 UTC
+++ base/allocator/partition_allocator/page_allocator.h
@@ -245,7 +245,7 @@ void DecommitAndZeroSystemPages(void* address, size_t 
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
