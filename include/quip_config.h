/* for the unix version, this file includes autoconf's config.h... */

#ifndef _QUIP_CONFIG_H_
#define _QUIP_CONFIG_H_

#ifdef BUILD_FOR_IOS
#define SCROLLABLE_QUIP_VIEW

#define BUILD_FOR_OBJC
#define QUIP_APPLICATION_TYPE		UIApplication
#define QUIP_NAV_CONTROLLER_TYPE	UINavigationController
#define QUIP_NAV_ITEM_TYPE		UINavigationItem
#define QUIP_VIEW_CONTROLLER_TYPE	UIViewController

#ifdef SCROLLABLE_QUIP_VIEW
#define QUIP_VIEW_TYPE			UIScrollView
#else // ! SCROLLABLE_QUIP_VIEW
#define QUIP_VIEW_TYPE			UIView
#endif // ! SCROLLABLE_QUIP_VIEW

#define QUIP_IMAGE_VIEW_TYPE		UIImageView
#define QUIP_IMAGE_TYPE			UIImage
#define QUIP_ALERT_OBJ_TYPE		UIAlertView
#define QUIP_COLOR_TYPE			UIColor
#include "ios_config.h"
#else // !BUILD_FOR IOS

#ifdef BUILD_FOR_WINDOWS
#include "win_config.h"
#else /* ! BUILD_FOR_WINDOWS && ! BUILD_FOR_IOS */

#ifdef BUILD_FOR_MACOS

#ifndef BUILD_FOR_MACOS_APP
#define BUILD_FOR_CMD_LINE
#endif // ! BUILD_FOR_MACOS_APP

#define BUILD_FOR_OBJC
#define QUIP_APPLICATION_TYPE		NSApplication
#define QUIP_NAV_CONTROLLER_TYPE	NSViewController
#define QUIP_NAV_ITEM_TYPE		NSObject
//#define QUIP_VIEW_CONTROLLER_TYPE	quipWindowController
#define QUIP_VIEW_CONTROLLER_TYPE	NSViewController
#define QUIP_VIEW_TYPE			NSView
#define QUIP_IMAGE_VIEW_TYPE		NSImageView
#define QUIP_IMAGE_TYPE			NSImage
#define QUIP_ALERT_OBJ_TYPE		NSAlert
#define QUIP_COLOR_TYPE			NSColor
#include "mac_config.h"

#else /* ! BUILD_FOR_MACOS && ! BUILD_FOR_WINDOWS && ! BUILD_FOR_IOS */

#include "config.h"
#define BUILD_FOR_CMD_LINE

#endif /* ! BUILD_FOR_MACOS */
#endif /* ! BUILD_FOR_WINDOWS */
#endif /* ! BUILD_FOR IOS */

#ifdef HAVE_LIBAVFORMAT
#ifdef HAVE_LIBAVCODEC
#define HAVE_AVI_SUPPORT
#endif // HAVE_LIBAVCODEC
#endif // HAVE_LIBAVFORMAT

#ifdef HAVE_CUDA
#define HAVE_GPU
#endif // HAVE_CUDA

#ifdef HAVE_OPENCL
#define HAVE_GPU
#endif // HAVE_CUDA

/*#define USE_GETBUF */

#define HAVE_MORPH		/* flood fill? */

// use uintptr_t instead?
//#define int_for_addr	long
#define int_for_addr	uintptr_t

// define HAVE_ANY_GPU if we have CUDA -or- OpenCL

#ifdef HAVE_OPENCL
#define HAVE_ANY_GPU
#else // ! HAVE_OPENCL
#ifdef HAVE_CUDA
#define HAVE_ANY_GPU
#else // ! HAVE_CUDA
#undef HAVE_ANY_GPU
#endif // ! HAVE_CUDA
#endif // ! HAVE_OPENCL


#endif /* ! _QUIP_CONFIG_H_ */


