#ifndef MBEDTLS_CHECK_TARGET_CAPABILITIES_H
#define MBEDTLS_CHECK_TARGET_CAPABILITIES_H

#if defined(DEVICE_ETHERNET)
#else

#   if defined(MBEDTLS_NET_C)
#       warning "Networking enabled, but not supported by the target"
#   endif

#endif /* defined(DEVICE_ETHERNET) */

#if defined(DEVICE_RTC)
#else

#   if defined(MBEDTLS_HAVE_TIME) || \
       defined(MBEDTLS_HAVE_TIME_DATE)
#       warning "Date and time enabled, but RTC is not supported by the target"
#   endif

#endif /* defined(DEVICE_RTC) */

#if defined(DEVICE_TRNG)
#else
#endif /* defined(DEVICE_TRNG) */

#endif /* MBEDTLS_CHECK_TARGET_CAPABILITIES_H */
