#pragma once

#define DEVICE_NAME L"\\\\.\\SecScanGuard"

#define AUTH_KEY FIND_UR_SELF_KEY_HERE

// IOCTL codes
#define IOCTL_GET_MODULE    0x22200C
#define IOCTL_READ_MEM      0x222010
#define IOCTL_WRITE_MEM     0x222014
#define IOCTL_READ_PHYS     0x226008
#define IOCTL_MOUSE         0x22A004
 
// Function codes
#define FUNC_GET_MODULE     0x803
#define FUNC_READ_MEM       0x804
#define FUNC_WRITE_MEM      0x805
#define FUNC_READ_PHYS      0x1802
#define FUNC_MOUSE          0x2801
