

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
 /* Compiler settings for appinfo.idl:
     Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622
     protocol : all , ms_ext, c_ext, robust
     error checks: allocation ref bounds_check enum stub_data
     VC __declspec() decoration level:
          __declspec(uuid()), __declspec(selectany), __declspec(novtable)
          DECLSPEC_UUID(), MIDL_INTERFACE()
 */
 /* @@MIDL_FILE_HEADING(  ) */



 /* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __appinfo_h_h__
#define __appinfo_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef __DefaultIfName_INTERFACE_DEFINED__
#define __DefaultIfName_INTERFACE_DEFINED__

    /* interface DefaultIfName */
    /* [version][uuid] */

    typedef struct Struct_14_t
    {
        long StructMember0;
        long StructMember1;
    } 	Struct_14_t;

    typedef struct Struct_22_t
    {
        /* [string][unique] */ wchar_t* StructMember0;
        long StructMember1;
        long StructMember2;
        long StructMember3;
        long StructMember4;
        long StructMember5;
        long StructMember6;
        long StructMember7;
        long StructMember8;
        short StructMember9;
        struct Struct_14_t StructMember10;
    } 	Struct_22_t;

    typedef struct Struct_56_t
    {
        unsigned __int3264 StructMember0;
        unsigned __int3264 StructMember1;
        long StructMember2;
        long StructMember3;
    } 	Struct_56_t;

    typedef struct Struct_84_t
    {
        long StructMember0;
        short StructMember1;
        short StructMember2;
        byte StructMember3[8];
    } 	Struct_84_t;

    #define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)

    EXTERN_DLL_EXPORT long Proc0_RAiLaunchAdminProcess(
        /* [in] */ handle_t IDL_handle,
        /* [string][unique][in] */ wchar_t* arg_2,
        /* [string][unique][in] */ wchar_t* arg_3,
        /* [in] */ long arg_4,
        /* [in] */ long arg_5,
        /* [string][in] */ wchar_t* arg_6,
        /* [string][in] */ wchar_t* arg_7,
        /* [in] */ struct Struct_22_t* arg_8,
        /* [in] */ unsigned __int3264 arg_9,
        /* [in] */ long arg_10,
        /* [out] */ struct Struct_56_t* arg_11,
        /* [out] */ long* arg_12);

    
    extern RPC_IF_HANDLE DefaultIfName_v1_0_c_ifspec;
    extern RPC_IF_HANDLE DefaultIfName_v1_0_s_ifspec;
#endif /* __DefaultIfName_INTERFACE_DEFINED__ */

    /* Additional Prototypes for ALL interfaces */

    /* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


