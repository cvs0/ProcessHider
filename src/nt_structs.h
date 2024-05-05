#pragma once

#include <winternl.h>

// Define the structure for system process information
typedef struct _SYSTEM_PROCESS_INFORMATION {
    ULONG NextEntryOffset;                  // Offset to the next process entry
    ULONG NumberOfThreads;                 // Number of threads in the process
    LARGE_INTEGER WorkingSetPrivateSize;    // Private working set size
    ULONG HardFaultCount;                   // Number of hard faults experienced by the process
    ULONG NumberOfThreadsHighWatermark;     // Peak number of threads for the process
    ULONGLONG CycleTime;                    // Total CPU cycle time for the process
    LARGE_INTEGER CreateTime;               // Process creation time
    LARGE_INTEGER UserTime;                 // Total user-mode CPU time for the process
    LARGE_INTEGER KernelTime;               // Total kernel-mode CPU time for the process
    UNICODE_STRING ImageName;               // Name of the process executable
    LONG BasePriority;                      // Base priority of the process
    PVOID UniqueProcessId;                  // Unique identifier for the process
    PVOID InheritedFromUniqueProcessId;     // Identifier of the parent process
    ULONG HandleCount;                      // Number of handles opened by the process
    ULONG SessionId;                        // Session identifier for the process
    ULONG_PTR UniqueProcessKey;             // Unique key for the process
    ULONG_PTR PeakVirtualSize;              // Peak virtual memory size used by the process
    ULONG_PTR VirtualSize;                  // Current virtual memory size used by the process
    ULONG PageFaultCount;                   // Number of page faults experienced by the process
    ULONG_PTR PeakWorkingSetSize;           // Peak working set size used by the process
    ULONG_PTR WorkingSetSize;               // Current working set size used by the process
    ULONG_PTR QuotaPeakPagedPoolUsage;      // Peak paged pool usage by the process
    ULONG_PTR QuotaPagedPoolUsage;          // Current paged pool usage by the process
    ULONG_PTR QuotaPeakNonPagedPoolUsage;   // Peak non-paged pool usage by the process
    ULONG_PTR QuotaNonPagedPoolUsage;       // Current non-paged pool usage by the process
    ULONG_PTR PagefileUsage;                // Current page file usage by the process
    ULONG_PTR PeakPagefileUsage;            // Peak page file usage by the process
    ULONG_PTR PrivatePageCount;             // Number of private pages used by the process
    LARGE_INTEGER ReadOperationCount;       // Total number of read operations performed by the process
    LARGE_INTEGER WriteOperationCount;      // Total number of write operations performed by the process
    LARGE_INTEGER OtherOperationCount;      // Total number of other operations performed by the process
    LARGE_INTEGER ReadTransferCount;        // Total number of bytes read by the process
    LARGE_INTEGER WriteTransferCount;       // Total number of bytes written by the process
    LARGE_INTEGER OtherTransferCount;       // Total number of bytes transferred by the process
} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

// Define the function pointer type for NtQuerySystemInformation
typedef NTSTATUS(WINAPI *PNT_QUERY_SYSTEM_INFORMATION)(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID SystemInformation,
    ULONG SystemInformationLength,
    PULONG ReturnLength
);
