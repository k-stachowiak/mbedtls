/*
 *  Classic "Hello, world" demonstration program
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#include <stdio.h>
#define mbedtls_printf       printf
#define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif

#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5.h"
#endif

#if !defined(MBEDTLS_MD5_C)
int main( void )
{
    mbedtls_printf("MBEDTLS_MD5_C not defined.\n");
    return( 0 );
}
#else
int main( void )
{
    int i, ret;
    unsigned char digest[16];
    char str[] = "Hello, world!";

#if defined(MBEDTLS_PLATFORM_C)
    mbedtls_platform_context platform_ctx;
    if( mbedtls_platform_setup( &platform_ctx ) != 0 )
    {
        mbedtls_printf( "  Failed initializing platform.\n" );
        return( MBEDTLS_EXIT_FAILURE );
    }
#endif

    mbedtls_printf( "\n  MD5('%s') = ", str );

    if( ( ret = mbedtls_md5_ret( (unsigned char *) str, 13, digest ) ) != 0 )
    {
        ret = MBEDTLS_EXIT_FAILURE;
        goto exit;
    }
    else
        ret = MBEDTLS_EXIT_SUCCESS;

    for( i = 0; i < 16; i++ )
        mbedtls_printf( "%02x", digest[i] );

    mbedtls_printf( "\n\n" );

exit:
#if defined(MBEDTLS_PLATFORM_C)
    mbedtls_platform_teardown( &platform_ctx );
#endif
#if defined(_WIN32)
    mbedtls_printf( "  Press Enter to exit this program.\n" );
    fflush( stdout ); getchar();
#endif
    return( ret );
}
#endif /* MBEDTLS_MD5_C */
