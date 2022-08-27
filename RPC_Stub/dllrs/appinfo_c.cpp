#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>
#include "pch.h"
#include "appinfo_h.h"

#define TYPE_FORMAT_STRING_SIZE   97                                
#define PROC_FORMAT_STRING_SIZE   427                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _appinfo_MIDL_TYPE_FORMAT_STRING
{
    short          Pad;
    unsigned char  Format[TYPE_FORMAT_STRING_SIZE];
} appinfo_MIDL_TYPE_FORMAT_STRING;

typedef struct _appinfo_MIDL_PROC_FORMAT_STRING
{
    short          Pad;
    unsigned char  Format[PROC_FORMAT_STRING_SIZE];
} appinfo_MIDL_PROC_FORMAT_STRING;

typedef struct _appinfo_MIDL_EXPR_FORMAT_STRING
{
    long          Pad;
    unsigned char  Format[EXPR_FORMAT_STRING_SIZE];
} appinfo_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax =
{ {0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0} };

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax =
{ {0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0} };



extern const appinfo_MIDL_TYPE_FORMAT_STRING appinfo__MIDL_TypeFormatString;
extern const appinfo_MIDL_PROC_FORMAT_STRING appinfo__MIDL_ProcFormatString;
extern const appinfo_MIDL_EXPR_FORMAT_STRING appinfo__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: DefaultIfName, ver. 1.0,
   GUID={0x201ef99a,0x7fa0,0x444c,{0x93,0x99,0x19,0xba,0x84,0xf1,0x2a,0x1a}} */

extern const MIDL_STUBLESS_PROXY_INFO DefaultIfName_ProxyInfo;


static const RPC_CLIENT_INTERFACE DefaultIfName___RpcClientInterface =
{
sizeof(RPC_CLIENT_INTERFACE),
{{0x201ef99a,0x7fa0,0x444c,{0x93,0x99,0x19,0xba,0x84,0xf1,0x2a,0x1a}},{1,0}},
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
0,
0,
0,
0,
&DefaultIfName_ProxyInfo,
0x02000000
};
RPC_IF_HANDLE DefaultIfName_v1_0_c_ifspec = (RPC_IF_HANDLE)&DefaultIfName___RpcClientInterface;

extern const MIDL_STUB_DESC DefaultIfName_StubDesc;

static RPC_BINDING_HANDLE DefaultIfName__MIDL_AutoBindHandle;

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
    /* [out] */ long* arg_12)
{

    CLIENT_CALL_RETURN _RetVal;

    RPC_STATUS status;
    RPC_WSTR StringBinding;
    RPC_BINDING_HANDLE Binding;

    status = RpcStringBindingCompose(
        (RPC_WSTR)L"201ef99a-7fa0-444c-9399-19ba84f12a1a",                       // Interface's GUID, will be handled by NdrClientCall
        (RPC_WSTR)L"ncalrpc",      // Protocol sequence
        (RPC_WSTR)L"", // Network address
        (RPC_WSTR)L"", // Endpoint
        NULL,                       // No options here
        &StringBinding              // Output string binding
    );

    status = RpcBindingFromStringBinding(
        StringBinding,              // Previously created string binding
        &Binding                    // Output binding handle
    );

    status = RpcStringFree(
        &StringBinding              // Previously created string binding
    );

    _RetVal = NdrClientCall3(
        (PMIDL_STUBLESS_PROXY_INFO)&DefaultIfName_ProxyInfo,
        0,
        0,
        Binding,
        arg_2,
        arg_3,
        arg_4,
        arg_5,
        arg_6,
        arg_7,
        arg_8,
        arg_9,
        arg_10,
        arg_11,
        arg_12);

    return (long)_RetVal.Simple;

}

static const appinfo_MIDL_PROC_FORMAT_STRING appinfo__MIDL_ProcFormatString =
{
    0,
    {

        /* Procedure Proc0_RAiLaunchAdminProcess */

                0x0,		/* 0 */
                0x48,		/* Old Flags:  */
                /*  2 */	NdrFcLong(0x0),	/* 0 */
                /*  6 */	NdrFcShort(0x0),	/* 0 */
                /*  8 */	NdrFcShort(0x68),	/* X64 Stack size/offset = 104 */
                /* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
                            0x0,		/* 0 */
                            /* 12 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                            /* 14 */	NdrFcShort(0x20),	/* 32 */
                            /* 16 */	NdrFcShort(0x24),	/* 36 */
                            /* 18 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
                                        0xc,		/* 12 */
                                        /* 20 */	0xa,		/* 10 */
                                                    0x1,		/* Ext Flags:  new corr desc, */
                                                    /* 22 */	NdrFcShort(0x0),	/* 0 */
                                                    /* 24 */	NdrFcShort(0x0),	/* 0 */
                                                    /* 26 */	NdrFcShort(0x0),	/* 0 */
                                                    /* 28 */	NdrFcShort(0x0),	/* 0 */

                                                        /* Parameter arg_2 */

                                                        /* 30 */	NdrFcShort(0xb),	/* Flags:  must size, must free, in, */
                                                        /* 32 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                        /* 34 */	NdrFcShort(0x2),	/* Type Offset=2 */

                                                            /* Parameter arg_3 */

                                                            /* 36 */	NdrFcShort(0xb),	/* Flags:  must size, must free, in, */
                                                            /* 38 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                            /* 40 */	NdrFcShort(0x2),	/* Type Offset=2 */

                                                                /* Parameter arg_4 */

                                                                /* 42 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                /* 44 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                /* 46 */	0x8,		/* FC_LONG */
                                                                            0x0,		/* 0 */

                                                                    /* Parameter arg_5 */

                                                                    /* 48 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                    /* 50 */	NdrFcShort(0x20),	/* X64 Stack size/offset = 32 */
                                                                    /* 52 */	0x8,		/* FC_LONG */
                                                                                0x0,		/* 0 */

                                                                        /* Parameter arg_6 */

                                                                        /* 54 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                        /* 56 */	NdrFcShort(0x28),	/* X64 Stack size/offset = 40 */
                                                                        /* 58 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                            /* Parameter arg_7 */

                                                                            /* 60 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                            /* 62 */	NdrFcShort(0x30),	/* X64 Stack size/offset = 48 */
                                                                            /* 64 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                /* Parameter arg_8 */

                                                                                /* 66 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                /* 68 */	NdrFcShort(0x38),	/* X64 Stack size/offset = 56 */
                                                                                /* 70 */	NdrFcShort(0x16),	/* Type Offset=22 */

                                                                                    /* Parameter arg_9 */

                                                                                    /* 72 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                    /* 74 */	NdrFcShort(0x40),	/* X64 Stack size/offset = 64 */
                                                                                    /* 76 */	0xb9,		/* FC_UINT3264 */
                                                                                                0x0,		/* 0 */

                                                                                        /* Parameter arg_10 */

                                                                                        /* 78 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                        /* 80 */	NdrFcShort(0x48),	/* X64 Stack size/offset = 72 */
                                                                                        /* 82 */	0x8,		/* FC_LONG */
                                                                                                    0x0,		/* 0 */

                                                                                            /* Parameter arg_11 */

                                                                                            /* 84 */	NdrFcShort(0x6113),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
                                                                                            /* 86 */	NdrFcShort(0x50),	/* X64 Stack size/offset = 80 */
                                                                                            /* 88 */	NdrFcShort(0x38),	/* Type Offset=56 */

                                                                                                /* Parameter arg_12 */

                                                                                                /* 90 */	NdrFcShort(0x2150),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
                                                                                                /* 92 */	NdrFcShort(0x58),	/* X64 Stack size/offset = 88 */
                                                                                                /* 94 */	0x8,		/* FC_LONG */
                                                                                                            0x0,		/* 0 */

                                                                                                    /* Return value */

                                                                                                    /* 96 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                    /* 98 */	NdrFcShort(0x60),	/* X64 Stack size/offset = 96 */
                                                                                                    /* 100 */	0x8,		/* FC_LONG */
                                                                                                                0x0,		/* 0 */

                                                                                                        /* Procedure Proc1_RAiProcessRunOnce */

                                                                                                        /* 102 */	0x0,		/* 0 */
                                                                                                                    0x48,		/* Old Flags:  */
                                                                                                                    /* 104 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                    /* 108 */	NdrFcShort(0x1),	/* 1 */
                                                                                                                    /* 110 */	NdrFcShort(0x20),	/* X64 Stack size/offset = 32 */
                                                                                                                    /* 112 */	0x32,		/* FC_BIND_PRIMITIVE */
                                                                                                                                0x0,		/* 0 */
                                                                                                                                /* 114 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                                                                                                                                /* 116 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                /* 118 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                /* 120 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
                                                                                                                                            0x3,		/* 3 */
                                                                                                                                            /* 122 */	0xa,		/* 10 */
                                                                                                                                                        0x1,		/* Ext Flags:  new corr desc, */
                                                                                                                                                        /* 124 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                        /* 126 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                        /* 128 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                        /* 130 */	NdrFcShort(0x0),	/* 0 */

                                                                                                                                                            /* Parameter arg_1 */

                                                                                                                                                            /* 132 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                            /* 134 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                                                                                                                            /* 136 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                /* Parameter arg_2 */

                                                                                                                                                                /* 138 */	NdrFcShort(0x6113),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
                                                                                                                                                                /* 140 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                                                                                                                                /* 142 */	NdrFcShort(0x38),	/* Type Offset=56 */

                                                                                                                                                                    /* Return value */

                                                                                                                                                                    /* 144 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                                                                                    /* 146 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                                                                                                                    /* 148 */	0x8,		/* FC_LONG */
                                                                                                                                                                                0x0,		/* 0 */

                                                                                                                                                                        /* Procedure Proc2_RAiLogonWithSmartCardCreds */

                                                                                                                                                                        /* 150 */	0x0,		/* 0 */
                                                                                                                                                                                    0x48,		/* Old Flags:  */
                                                                                                                                                                                    /* 152 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                                                                                    /* 156 */	NdrFcShort(0x2),	/* 2 */
                                                                                                                                                                                    /* 158 */	NdrFcShort(0x28),	/* X64 Stack size/offset = 40 */
                                                                                                                                                                                    /* 160 */	0x32,		/* FC_BIND_PRIMITIVE */
                                                                                                                                                                                                0x0,		/* 0 */
                                                                                                                                                                                                /* 162 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                                                                                                                                                                                                /* 164 */	NdrFcShort(0x10),	/* 16 */
                                                                                                                                                                                                /* 166 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                /* 168 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
                                                                                                                                                                                                            0x4,		/* 4 */
                                                                                                                                                                                                            /* 170 */	0xa,		/* 10 */
                                                                                                                                                                                                                        0x1,		/* Ext Flags:  new corr desc, */
                                                                                                                                                                                                                        /* 172 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                        /* 174 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                        /* 176 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                        /* 178 */	NdrFcShort(0x0),	/* 0 */

                                                                                                                                                                                                                            /* Parameter arg_2 */

                                                                                                                                                                                                                            /* 180 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                            /* 182 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                                                                                                                                                                                            /* 184 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                        0x0,		/* 0 */

                                                                                                                                                                                                                                /* Parameter arg_3 */

                                                                                                                                                                                                                                /* 186 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                                                                                                /* 188 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                                                                                                                                                                                                /* 190 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                                                                                    /* Parameter arg_4 */

                                                                                                                                                                                                                                    /* 192 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                    /* 194 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                                                                                                                                                                                    /* 196 */	0xb9,		/* FC_UINT3264 */
                                                                                                                                                                                                                                                0x0,		/* 0 */

                                                                                                                                                                                                                                        /* Return value */

                                                                                                                                                                                                                                        /* 198 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                                                                                                                                                        /* 200 */	NdrFcShort(0x20),	/* X64 Stack size/offset = 32 */
                                                                                                                                                                                                                                        /* 202 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                    0x0,		/* 0 */

                                                                                                                                                                                                                                            /* Procedure Proc3_RAiOverrideDesktopPromptPolicy */

                                                                                                                                                                                                                                            /* 204 */	0x0,		/* 0 */
                                                                                                                                                                                                                                                        0x48,		/* Old Flags:  */
                                                                                                                                                                                                                                                        /* 206 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                                                                                                                                                        /* 210 */	NdrFcShort(0x3),	/* 3 */
                                                                                                                                                                                                                                                        /* 212 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                                                                                                                                                                                                                        /* 214 */	0x32,		/* FC_BIND_PRIMITIVE */
                                                                                                                                                                                                                                                                    0x0,		/* 0 */
                                                                                                                                                                                                                                                                    /* 216 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                                                                                                                                                                                                                                                                    /* 218 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                    /* 220 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                                                                    /* 222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
                                                                                                                                                                                                                                                                                0x1,		/* 1 */
                                                                                                                                                                                                                                                                                /* 224 */	0xa,		/* 10 */
                                                                                                                                                                                                                                                                                            0x1,		/* Ext Flags:  new corr desc, */
                                                                                                                                                                                                                                                                                            /* 226 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                            /* 228 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                            /* 230 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                            /* 232 */	NdrFcShort(0x0),	/* 0 */

                                                                                                                                                                                                                                                                                                /* Return value */

                                                                                                                                                                                                                                                                                                /* 234 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                                                                                                                                                                                                                /* 236 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                                                                                                                                                                                                                                                                /* 238 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                            0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                    /* Procedure Proc4_RAiDisableElevationForSession */

                                                                                                                                                                                                                                                                                                    /* 240 */	0x0,		/* 0 */
                                                                                                                                                                                                                                                                                                                0x48,		/* Old Flags:  */
                                                                                                                                                                                                                                                                                                                /* 242 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                /* 246 */	NdrFcShort(0x4),	/* 4 */
                                                                                                                                                                                                                                                                                                                /* 248 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                                                                                                                                                                                                                                                                /* 250 */	0x32,		/* FC_BIND_PRIMITIVE */
                                                                                                                                                                                                                                                                                                                            0x0,		/* 0 */
                                                                                                                                                                                                                                                                                                                            /* 252 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                                                                                                                                                                                                                                                                                                                            /* 254 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                                                                                                                            /* 256 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                                                                                                                            /* 258 */	0x44,		/* Oi2 Flags:  has return, has ext, */
                                                                                                                                                                                                                                                                                                                                        0x2,		/* 2 */
                                                                                                                                                                                                                                                                                                                                        /* 260 */	0xa,		/* 10 */
                                                                                                                                                                                                                                                                                                                                                    0x1,		/* Ext Flags:  new corr desc, */
                                                                                                                                                                                                                                                                                                                                                    /* 262 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                    /* 264 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                    /* 266 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                    /* 268 */	NdrFcShort(0x0),	/* 0 */

                                                                                                                                                                                                                                                                                                                                                        /* Parameter arg_1 */

                                                                                                                                                                                                                                                                                                                                                        /* 270 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                        /* 272 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                                                                                                                                                                                                                                                                                                                        /* 274 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                    0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                            /* Return value */

                                                                                                                                                                                                                                                                                                                                                            /* 276 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                                                                                                                                                                                                                                                                            /* 278 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                                                                                                                                                                                                                                                                                                                            /* 280 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                        0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                /* Procedure Proc5_RAiEnableElevationForSession */

                                                                                                                                                                                                                                                                                                                                                                /* 282 */	0x0,		/* 0 */
                                                                                                                                                                                                                                                                                                                                                                            0x48,		/* Old Flags:  */
                                                                                                                                                                                                                                                                                                                                                                            /* 284 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                            /* 288 */	NdrFcShort(0x5),	/* 5 */
                                                                                                                                                                                                                                                                                                                                                                            /* 290 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                                                                                                                                                                                                                                                                                                                            /* 292 */	0x32,		/* FC_BIND_PRIMITIVE */
                                                                                                                                                                                                                                                                                                                                                                                        0x0,		/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                        /* 294 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                                                                                                                                                                                                                                                                                                                                                                                        /* 296 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                                                                                                                                                                                        /* 298 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                                                                                                                                                                                        /* 300 */	0x44,		/* Oi2 Flags:  has return, has ext, */
                                                                                                                                                                                                                                                                                                                                                                                                    0x2,		/* 2 */
                                                                                                                                                                                                                                                                                                                                                                                                    /* 302 */	0xa,		/* 10 */
                                                                                                                                                                                                                                                                                                                                                                                                                0x1,		/* Ext Flags:  new corr desc, */
                                                                                                                                                                                                                                                                                                                                                                                                                /* 304 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                /* 306 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                /* 308 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                /* 310 */	NdrFcShort(0x0),	/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                    /* Parameter arg_1 */

                                                                                                                                                                                                                                                                                                                                                                                                                    /* 312 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                    /* 314 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                                                                                                                                                                                                                                                                                                                                                                                    /* 316 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                        /* Return value */

                                                                                                                                                                                                                                                                                                                                                                                                                        /* 318 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                        /* 320 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                                                                                                                                                                                                                                                                                                                                                                                        /* 322 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                    0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                            /* Procedure Proc6_RAiForceElevationPromptForCOM */

                                                                                                                                                                                                                                                                                                                                                                                                                            /* 324 */	0x0,		/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                        0x48,		/* Old Flags:  */
                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 326 */	NdrFcLong(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 330 */	NdrFcShort(0x6),	/* 6 */
                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 332 */	NdrFcShort(0x68),	/* X64 Stack size/offset = 104 */
                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 334 */	0x32,		/* FC_BIND_PRIMITIVE */
                                                                                                                                                                                                                                                                                                                                                                                                                                                    0x0,		/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 336 */	NdrFcShort(0x0),	/* X64 Stack size/offset = 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 338 */	NdrFcShort(0x6c),	/* 108 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 340 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 342 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                0xc,		/* 12 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 344 */	0xa,		/* 10 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            0x1,		/* Ext Flags:  new corr desc, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 346 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 348 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 350 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 352 */	NdrFcShort(0x0),	/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* Parameter arg_2 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 354 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 356 */	NdrFcShort(0x8),	/* X64 Stack size/offset = 8 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 358 */	0xb9,		/* FC_UINT3264 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* Parameter arg_3 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 360 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 362 */	NdrFcShort(0x10),	/* X64 Stack size/offset = 16 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 364 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* Parameter arg_4 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 366 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 368 */	NdrFcShort(0x18),	/* X64 Stack size/offset = 24 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 370 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Parameter arg_5 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 372 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 374 */	NdrFcShort(0x20),	/* X64 Stack size/offset = 32 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 376 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* Parameter arg_6 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 378 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 380 */	NdrFcShort(0x28),	/* X64 Stack size/offset = 40 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 382 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* Parameter arg_7 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 384 */	NdrFcShort(0x10a),	/* Flags:  must free, in, simple ref, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 386 */	NdrFcShort(0x30),	/* X64 Stack size/offset = 48 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 388 */	NdrFcShort(0x54),	/* Type Offset=84 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* Parameter arg_8 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 390 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 392 */	NdrFcShort(0x38),	/* X64 Stack size/offset = 56 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 394 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Parameter arg_9 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 396 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 398 */	NdrFcShort(0x40),	/* X64 Stack size/offset = 64 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 400 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* Parameter arg_10 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 402 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 404 */	NdrFcShort(0x48),	/* X64 Stack size/offset = 72 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /* 406 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* Parameter arg_11 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 408 */	NdrFcShort(0x10b),	/* Flags:  must size, must free, in, simple ref, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 410 */	NdrFcShort(0x50),	/* X64 Stack size/offset = 80 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* 412 */	NdrFcShort(0x8),	/* Type Offset=8 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* Parameter arg_12 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 414 */	NdrFcShort(0x48),	/* Flags:  in, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 416 */	NdrFcShort(0x58),	/* X64 Stack size/offset = 88 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /* 418 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Return value */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 420 */	NdrFcShort(0x70),	/* Flags:  out, return, base type, */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 422 */	NdrFcShort(0x60),	/* X64 Stack size/offset = 96 */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* 424 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        0x0,		/* 0 */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        0x0
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    }
};

static const appinfo_MIDL_TYPE_FORMAT_STRING appinfo__MIDL_TypeFormatString =
{
    0,
    {
        NdrFcShort(0x0),	/* 0 */
/*  2 */
            0x12, 0x8,	/* FC_UP [simple_pointer] */
/*  4 */
            0x25,		/* FC_C_WSTRING */
            0x5c,		/* FC_PAD */
/*  6 */
            0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  8 */
            0x25,		/* FC_C_WSTRING */
            0x5c,		/* FC_PAD */
/* 10 */
            0x11, 0x0,	/* FC_RP */
            /* 12 */	NdrFcShort(0xa),	/* Offset= 10 (22) */
            /* 14 */
                        0x15,		/* FC_STRUCT */
                        0x3,		/* 3 */
                        /* 16 */	NdrFcShort(0x8),	/* 8 */
                        /* 18 */	0x8,		/* FC_LONG */
                                    0x8,		/* FC_LONG */
                                    /* 20 */	0x5c,		/* FC_PAD */
                                                0x5b,		/* FC_END */
                                    /* 22 */
                                                0x1a,		/* FC_BOGUS_STRUCT */
                                                0x3,		/* 3 */
                                                /* 24 */	NdrFcShort(0x38),	/* 56 */
                                                /* 26 */	NdrFcShort(0x0),	/* 0 */
                                                /* 28 */	NdrFcShort(0x14),	/* Offset= 20 (48) */
                                                /* 30 */	0x36,		/* FC_POINTER */
                                                            0x8,		/* FC_LONG */
                                                            /* 32 */	0x8,		/* FC_LONG */
                                                                        0x8,		/* FC_LONG */
                                                                        /* 34 */	0x8,		/* FC_LONG */
                                                                                    0x8,		/* FC_LONG */
                                                                                    /* 36 */	0x8,		/* FC_LONG */
                                                                                                0x8,		/* FC_LONG */
                                                                                                /* 38 */	0x8,		/* FC_LONG */
                                                                                                            0x6,		/* FC_SHORT */
                                                                                                            /* 40 */	0x3e,		/* FC_STRUCTPAD2 */
                                                                                                                        0x4c,		/* FC_EMBEDDED_COMPLEX */
                                                                                                                        /* 42 */	0x0,		/* 0 */
                                                                                                                                    NdrFcShort(0xffe3),	/* Offset= -29 (14) */
                                                                                                                                    0x40,		/* FC_STRUCTPAD4 */
                                                                                                                                    /* 46 */	0x5c,		/* FC_PAD */
                                                                                                                                                0x5b,		/* FC_END */
                                                                                                                                    /* 48 */
                                                                                                                                                0x12, 0x8,	/* FC_UP [simple_pointer] */
                                                                                                                                    /* 50 */
                                                                                                                                                0x25,		/* FC_C_WSTRING */
                                                                                                                                                0x5c,		/* FC_PAD */
                                                                                                                                    /* 52 */
                                                                                                                                                0x11, 0x4,	/* FC_RP [alloced_on_stack] */
                                                                                                                                                /* 54 */	NdrFcShort(0x2),	/* Offset= 2 (56) */
                                                                                                                                                /* 56 */
                                                                                                                                                            0x1a,		/* FC_BOGUS_STRUCT */
                                                                                                                                                            0x3,		/* 3 */
                                                                                                                                                            /* 58 */	NdrFcShort(0x18),	/* 24 */
                                                                                                                                                            /* 60 */	NdrFcShort(0x0),	/* 0 */
                                                                                                                                                            /* 62 */	NdrFcShort(0x0),	/* Offset= 0 (62) */
                                                                                                                                                            /* 64 */	0xb9,		/* FC_UINT3264 */
                                                                                                                                                                        0xb9,		/* FC_UINT3264 */
                                                                                                                                                                        /* 66 */	0x8,		/* FC_LONG */
                                                                                                                                                                                    0x8,		/* FC_LONG */
                                                                                                                                                                                    /* 68 */	0x5c,		/* FC_PAD */
                                                                                                                                                                                                0x5b,		/* FC_END */
                                                                                                                                                                                    /* 70 */
                                                                                                                                                                                                0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
                                                                                                                                                                                                /* 72 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                            0x5c,		/* FC_PAD */
                                                                                                                                                                                                /* 74 */
                                                                                                                                                                                                            0x11, 0x0,	/* FC_RP */
                                                                                                                                                                                                            /* 76 */	NdrFcShort(0x8),	/* Offset= 8 (84) */
                                                                                                                                                                                                            /* 78 */
                                                                                                                                                                                                                        0x1d,		/* FC_SMFARRAY */
                                                                                                                                                                                                                        0x0,		/* 0 */
                                                                                                                                                                                                                        /* 80 */	NdrFcShort(0x8),	/* 8 */
                                                                                                                                                                                                                        /* 82 */	0x1,		/* FC_BYTE */
                                                                                                                                                                                                                                    0x5b,		/* FC_END */
                                                                                                                                                                                                                        /* 84 */
                                                                                                                                                                                                                                    0x15,		/* FC_STRUCT */
                                                                                                                                                                                                                                    0x3,		/* 3 */
                                                                                                                                                                                                                                    /* 86 */	NdrFcShort(0x10),	/* 16 */
                                                                                                                                                                                                                                    /* 88 */	0x8,		/* FC_LONG */
                                                                                                                                                                                                                                                0x6,		/* FC_SHORT */
                                                                                                                                                                                                                                                /* 90 */	0x6,		/* FC_SHORT */
                                                                                                                                                                                                                                                            0x4c,		/* FC_EMBEDDED_COMPLEX */
                                                                                                                                                                                                                                                            /* 92 */	0x0,		/* 0 */
                                                                                                                                                                                                                                                                        NdrFcShort(0xfff1),	/* Offset= -15 (78) */
                                                                                                                                                                                                                                                                        0x5b,		/* FC_END */

                                                                                                                                                                                                                                                                        0x0
                                                                                                                                                                                                                                                                    }
};

static const unsigned short DefaultIfName_FormatStringOffsetTable[] =
{
0,
102,
150,
204,
240,
282,
324
};




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

#include "ndr64types.h"
#include "pshpack8.h"


typedef
NDR64_FORMAT_CHAR
__midl_frag61_t;
extern const __midl_frag61_t __midl_frag61;

typedef
struct _NDR64_CONFORMANT_STRING_FORMAT
    __midl_frag59_t;
extern const __midl_frag59_t __midl_frag59;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag58_t;
extern const __midl_frag58_t __midl_frag58;

typedef
struct
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag51_t;
extern const __midl_frag51_t __midl_frag51;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag50_t;
extern const __midl_frag50_t __midl_frag50;

typedef
NDR64_FORMAT_CHAR
__midl_frag44_t;
extern const __midl_frag44_t __midl_frag44;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
    struct _NDR64_PARAM_FORMAT frag9;
    struct _NDR64_PARAM_FORMAT frag10;
    struct _NDR64_PARAM_FORMAT frag11;
    struct _NDR64_PARAM_FORMAT frag12;
    struct _NDR64_PARAM_FORMAT frag13;
    struct _NDR64_PARAM_FORMAT frag14;
}
__midl_frag43_t;
extern const __midl_frag43_t __midl_frag43;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
}
__midl_frag40_t;
extern const __midl_frag40_t __midl_frag40;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
}
__midl_frag35_t;
extern const __midl_frag35_t __midl_frag35;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
}
__midl_frag29_t;
extern const __midl_frag29_t __midl_frag29;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag27_t;
extern const __midl_frag27_t __midl_frag27;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
}
__midl_frag24_t;
extern const __midl_frag24_t __midl_frag24;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag21_t;
extern const __midl_frag21_t __midl_frag21;

typedef
struct
{
    struct _NDR64_STRUCTURE_HEADER_FORMAT frag1;
}
__midl_frag20_t;
extern const __midl_frag20_t __midl_frag20;

typedef
struct
{
    struct _NDR64_POINTER_FORMAT frag1;
}
__midl_frag16_t;
extern const __midl_frag16_t __midl_frag16;

typedef
struct
{
    struct _NDR64_BOGUS_STRUCTURE_HEADER_FORMAT frag1;
    struct
    {
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag1;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag2;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag3;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag4;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag5;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag6;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag7;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag8;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag9;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag10;
        struct _NDR64_MEMPAD_FORMAT frag11;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag12;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag13;
        struct _NDR64_MEMPAD_FORMAT frag14;
        struct _NDR64_BUFFER_ALIGN_FORMAT frag15;
        struct _NDR64_SIMPLE_MEMBER_FORMAT frag16;
    } frag2;
}
__midl_frag14_t;
extern const __midl_frag14_t __midl_frag14;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag13_t;
extern const __midl_frag13_t __midl_frag13;

typedef
struct _NDR64_POINTER_FORMAT
    __midl_frag5_t;
extern const __midl_frag5_t __midl_frag5;

typedef
struct
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
    struct _NDR64_PARAM_FORMAT frag6;
    struct _NDR64_PARAM_FORMAT frag7;
    struct _NDR64_PARAM_FORMAT frag8;
    struct _NDR64_PARAM_FORMAT frag9;
    struct _NDR64_PARAM_FORMAT frag10;
    struct _NDR64_PARAM_FORMAT frag11;
    struct _NDR64_PARAM_FORMAT frag12;
    struct _NDR64_PARAM_FORMAT frag13;
    struct _NDR64_PARAM_FORMAT frag14;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag61_t __midl_frag61 =
0x5    /* FC64_INT32 */;

static const __midl_frag59_t __midl_frag59 =
{
    /* *wchar_t */
        {
        /* *wchar_t */
            0x64,    /* FC64_CONF_WCHAR_STRING */
            {
        /* *wchar_t */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT16)2 /* 0x2 */
    }
};

static const __midl_frag58_t __midl_frag58 =
{
    /* *wchar_t */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag59
};

static const __midl_frag51_t __midl_frag51 =
{
    /* Struct_84_t */
        {
        /* Struct_84_t */
            0x30,    /* FC64_STRUCT */
            (NDR64_UINT8)3 /* 0x3 */,
            {
        /* Struct_84_t */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT32)16 /* 0x10 */
    }
};

static const __midl_frag50_t __midl_frag50 =
{
    /* *Struct_84_t */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag51
};

static const __midl_frag44_t __midl_frag44 =
0x7    /* FC64_INT64 */;

static const __midl_frag43_t __midl_frag43 =
{
    /* Proc6_RAiForceElevationPromptForCOM */
        {
        /* Proc6_RAiForceElevationPromptForCOM */      /* procedure Proc6_RAiForceElevationPromptForCOM */
            (NDR64_UINT32)17563712 /* 0x10c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, HasExtensions */
            (NDR64_UINT32)104 /* 0x68 */ ,  /* Stack size */
            (NDR64_UINT32)120 /* 0x78 */,
            (NDR64_UINT32)8 /* 0x8 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)12 /* 0xc */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* arg_2 */      /* parameter arg_2 */
                    &__midl_frag44,
                    {
        /* arg_2 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    {
        /* arg_3 */      /* parameter arg_3 */
            &__midl_frag61,
            {
        /* arg_3 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    {
        /* arg_4 */      /* parameter arg_4 */
            &__midl_frag61,
            {
        /* arg_4 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    {
        /* arg_5 */      /* parameter arg_5 */
            &__midl_frag61,
            {
        /* arg_5 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    {
        /* arg_6 */      /* parameter arg_6 */
            &__midl_frag59,
            {
        /* arg_6 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    {
        /* arg_7 */      /* parameter arg_7 */
            &__midl_frag51,
            {
        /* arg_7 */
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    },
    {
        /* arg_8 */      /* parameter arg_8 */
            &__midl_frag59,
            {
        /* arg_8 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        56 /* 0x38 */,   /* Stack offset */
    },
    {
        /* arg_9 */      /* parameter arg_9 */
            &__midl_frag59,
            {
        /* arg_9 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        64 /* 0x40 */,   /* Stack offset */
    },
    {
        /* arg_10 */      /* parameter arg_10 */
            &__midl_frag59,
            {
        /* arg_10 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        72 /* 0x48 */,   /* Stack offset */
    },
    {
        /* arg_11 */      /* parameter arg_11 */
            &__midl_frag59,
            {
        /* arg_11 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        80 /* 0x50 */,   /* Stack offset */
    },
    {
        /* arg_12 */      /* parameter arg_12 */
            &__midl_frag61,
            {
        /* arg_12 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        88 /* 0x58 */,   /* Stack offset */
    },
    {
        /* long */      /* parameter long */
            &__midl_frag61,
            {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        96 /* 0x60 */,   /* Stack offset */
    }
};

static const __midl_frag40_t __midl_frag40 =
{
    /* Proc5_RAiEnableElevationForSession */
        {
        /* Proc5_RAiEnableElevationForSession */      /* procedure Proc5_RAiEnableElevationForSession */
            (NDR64_UINT32)17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
            (NDR64_UINT32)24 /* 0x18 */ ,  /* Stack size */
            (NDR64_UINT32)8 /* 0x8 */,
            (NDR64_UINT32)8 /* 0x8 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)2 /* 0x2 */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* arg_1 */      /* parameter arg_1 */
                    &__midl_frag61,
                    {
        /* arg_1 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    {
        /* long */      /* parameter long */
            &__midl_frag61,
            {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    }
};

static const __midl_frag35_t __midl_frag35 =
{
    /* Proc3_RAiOverrideDesktopPromptPolicy */
        {
        /* Proc3_RAiOverrideDesktopPromptPolicy */      /* procedure Proc3_RAiOverrideDesktopPromptPolicy */
            (NDR64_UINT32)17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
            (NDR64_UINT32)16 /* 0x10 */ ,  /* Stack size */
            (NDR64_UINT32)0 /* 0x0 */,
            (NDR64_UINT32)8 /* 0x8 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)1 /* 0x1 */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* long */      /* parameter long */
                    &__midl_frag61,
                    {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    }
};

static const __midl_frag29_t __midl_frag29 =
{
    /* Proc2_RAiLogonWithSmartCardCreds */
        {
        /* Proc2_RAiLogonWithSmartCardCreds */      /* procedure Proc2_RAiLogonWithSmartCardCreds */
            (NDR64_UINT32)17563712 /* 0x10c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, HasExtensions */
            (NDR64_UINT32)40 /* 0x28 */ ,  /* Stack size */
            (NDR64_UINT32)24 /* 0x18 */,
            (NDR64_UINT32)8 /* 0x8 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)4 /* 0x4 */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* arg_2 */      /* parameter arg_2 */
                    &__midl_frag61,
                    {
        /* arg_2 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    {
        /* arg_3 */      /* parameter arg_3 */
            &__midl_frag59,
            {
        /* arg_3 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    {
        /* arg_4 */      /* parameter arg_4 */
            &__midl_frag44,
            {
        /* arg_4 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    {
        /* long */      /* parameter long */
            &__midl_frag61,
            {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    }
};

static const __midl_frag27_t __midl_frag27 =
{
    /* *Struct_56_t */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)4 /* 0x4 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag20
};

static const __midl_frag24_t __midl_frag24 =
{
    /* Proc1_RAiProcessRunOnce */
        {
        /* Proc1_RAiProcessRunOnce */      /* procedure Proc1_RAiProcessRunOnce */
            (NDR64_UINT32)17563712 /* 0x10c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, HasExtensions */
            (NDR64_UINT32)32 /* 0x20 */ ,  /* Stack size */
            (NDR64_UINT32)0 /* 0x0 */,
            (NDR64_UINT32)72 /* 0x48 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)3 /* 0x3 */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* arg_1 */      /* parameter arg_1 */
                    &__midl_frag59,
                    {
        /* arg_1 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    {
        /* arg_2 */      /* parameter arg_2 */
            &__midl_frag20,
            {
        /* arg_2 */
            0,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            1
        },    /* MustFree, [out], SimpleRef, UseCache */
        (NDR64_UINT16)0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    {
        /* long */      /* parameter long */
            &__midl_frag61,
            {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    }
};

static const __midl_frag21_t __midl_frag21 =
{
    /* *long */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)12 /* 0xc */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag61
};

static const __midl_frag20_t __midl_frag20 =
{
    /* Struct_56_t */
        {
        /* Struct_56_t */
            0x30,    /* FC64_STRUCT */
            (NDR64_UINT8)7 /* 0x7 */,
            {
        /* Struct_56_t */
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT32)24 /* 0x18 */
    }
};

static const __midl_frag16_t __midl_frag16 =
{
    /*  */
        {
        /* *wchar_t */
            0x21,    /* FC64_UP */
            (NDR64_UINT8)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            &__midl_frag59
        }
};

static const __midl_frag14_t __midl_frag14 =
{
    /* Struct_22_t */
        {
        /* Struct_22_t */
            0x35,    /* FC64_FORCED_BOGUS_STRUCT */
            (NDR64_UINT8)7 /* 0x7 */,
            {
        /* Struct_22_t */
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            0
        },
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT32)56 /* 0x38 */,
        0,
        0,
        &__midl_frag16,
    },
    {
        /*  */
            {
            /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                0x14,    /* FC64_POINTER */
                (NDR64_UINT8)0 /* 0x0 */,
                (NDR64_UINT16)0 /* 0x0 */,
                (NDR64_UINT32)0 /* 0x0 */
            },
            {
                /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                    0x5,    /* FC64_INT32 */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT16)0 /* 0x0 */,
                    (NDR64_UINT32)0 /* 0x0 */
                },
                {
                    /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                        0x5,    /* FC64_INT32 */
                        (NDR64_UINT8)0 /* 0x0 */,
                        (NDR64_UINT16)0 /* 0x0 */,
                        (NDR64_UINT32)0 /* 0x0 */
                    },
                    {
                        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                            0x5,    /* FC64_INT32 */
                            (NDR64_UINT8)0 /* 0x0 */,
                            (NDR64_UINT16)0 /* 0x0 */,
                            (NDR64_UINT32)0 /* 0x0 */
                        },
                        {
                            /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                0x5,    /* FC64_INT32 */
                                (NDR64_UINT8)0 /* 0x0 */,
                                (NDR64_UINT16)0 /* 0x0 */,
                                (NDR64_UINT32)0 /* 0x0 */
                            },
                            {
                                /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                    0x5,    /* FC64_INT32 */
                                    (NDR64_UINT8)0 /* 0x0 */,
                                    (NDR64_UINT16)0 /* 0x0 */,
                                    (NDR64_UINT32)0 /* 0x0 */
                                },
                                {
                                    /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                        0x5,    /* FC64_INT32 */
                                        (NDR64_UINT8)0 /* 0x0 */,
                                        (NDR64_UINT16)0 /* 0x0 */,
                                        (NDR64_UINT32)0 /* 0x0 */
                                    },
                                    {
                                        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                            0x5,    /* FC64_INT32 */
                                            (NDR64_UINT8)0 /* 0x0 */,
                                            (NDR64_UINT16)0 /* 0x0 */,
                                            (NDR64_UINT32)0 /* 0x0 */
                                        },
                                        {
                                            /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                                0x5,    /* FC64_INT32 */
                                                (NDR64_UINT8)0 /* 0x0 */,
                                                (NDR64_UINT16)0 /* 0x0 */,
                                                (NDR64_UINT32)0 /* 0x0 */
                                            },
                                            {
                                                /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                                    0x4,    /* FC64_INT16 */
                                                    (NDR64_UINT8)0 /* 0x0 */,
                                                    (NDR64_UINT16)0 /* 0x0 */,
                                                    (NDR64_UINT32)0 /* 0x0 */
                                                },
                                                {
                                                    /* struct _NDR64_MEMPAD_FORMAT */
                                                        0x90,    /* FC64_STRUCTPADN */
                                                        (NDR64_UINT8)0 /* 0x0 */,
                                                        (NDR64_UINT16)2 /* 0x2 */,
                                                        (NDR64_UINT32)0 /* 0x0 */
                                                    },
                                                    {
                                                        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                                            0x5,    /* FC64_INT32 */
                                                            (NDR64_UINT8)0 /* 0x0 */,
                                                            (NDR64_UINT16)0 /* 0x0 */,
                                                            (NDR64_UINT32)0 /* 0x0 */
                                                        },
                                                        {
                                                            /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                                                0x5,    /* FC64_INT32 */
                                                                (NDR64_UINT8)0 /* 0x0 */,
                                                                (NDR64_UINT16)0 /* 0x0 */,
                                                                (NDR64_UINT32)0 /* 0x0 */
                                                            },
                                                            {
                                                                /* struct _NDR64_MEMPAD_FORMAT */
                                                                    0x90,    /* FC64_STRUCTPADN */
                                                                    (NDR64_UINT8)0 /* 0x0 */,
                                                                    (NDR64_UINT16)4 /* 0x4 */,
                                                                    (NDR64_UINT32)0 /* 0x0 */
                                                                },
                                                                {
                                                                    /* Struct_22_t */
                                                                        0x92,    /* FC64_BUFFER_ALIGN */
                                                                        (NDR64_UINT8)7 /* 0x7 */,
                                                                        (NDR64_UINT16)0 /* 0x0 */,
                                                                        (NDR64_UINT32)0 /* 0x0 */
                                                                    },
                                                                    {
                                                                        /* struct _NDR64_SIMPLE_MEMBER_FORMAT */
                                                                            0x93,    /* FC64_END */
                                                                            (NDR64_UINT8)0 /* 0x0 */,
                                                                            (NDR64_UINT16)0 /* 0x0 */,
                                                                            (NDR64_UINT32)0 /* 0x0 */
                                                                        }
                                                                    }
};

static const __midl_frag13_t __midl_frag13 =
{
    /* *Struct_22_t */
        0x20,    /* FC64_RP */
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag14
};

static const __midl_frag5_t __midl_frag5 =
{
    /* *wchar_t */
        0x21,    /* FC64_UP */
        (NDR64_UINT8)0 /* 0x0 */,
        (NDR64_UINT16)0 /* 0x0 */,
        &__midl_frag59
};

static const __midl_frag2_t __midl_frag2 =
{
    /* Proc0_RAiLaunchAdminProcess */
        {
        /* Proc0_RAiLaunchAdminProcess */      /* procedure Proc0_RAiLaunchAdminProcess */
            (NDR64_UINT32)17563712 /* 0x10c0040 */,    /* explicit handle */ /* IsIntrepreted, ClientMustSize, HasReturn, HasExtensions */
            (NDR64_UINT32)104 /* 0x68 */ ,  /* Stack size */
            (NDR64_UINT32)40 /* 0x28 */,
            (NDR64_UINT32)104 /* 0x68 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)0 /* 0x0 */,
            (NDR64_UINT16)12 /* 0xc */,
            (NDR64_UINT16)8 /* 0x8 */
        },
        {
            /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                {
                /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
                    0x72,    /* FC64_BIND_PRIMITIVE */
                    (NDR64_UINT8)0 /* 0x0 */,
                    0 /* 0x0 */,   /* Stack offset */
                    (NDR64_UINT8)0 /* 0x0 */,
                    (NDR64_UINT8)0 /* 0x0 */
                },
                (NDR64_UINT16)0 /* 0x0 */      /* Notify index */
            },
            {
                /* arg_2 */      /* parameter arg_2 */
                    &__midl_frag5,
                    {
        /* arg_2 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in] */
        (NDR64_UINT16)0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    {
        /* arg_3 */      /* parameter arg_3 */
            &__midl_frag5,
            {
        /* arg_3 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in] */
        (NDR64_UINT16)0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    {
        /* arg_4 */      /* parameter arg_4 */
            &__midl_frag61,
            {
        /* arg_4 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    },
    {
        /* arg_5 */      /* parameter arg_5 */
            &__midl_frag61,
            {
        /* arg_5 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        32 /* 0x20 */,   /* Stack offset */
    },
    {
        /* arg_6 */      /* parameter arg_6 */
            &__midl_frag59,
            {
        /* arg_6 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        40 /* 0x28 */,   /* Stack offset */
    },
    {
        /* arg_7 */      /* parameter arg_7 */
            &__midl_frag59,
            {
        /* arg_7 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        48 /* 0x30 */,   /* Stack offset */
    },
    {
        /* arg_8 */      /* parameter arg_8 */
            &__midl_frag14,
            {
        /* arg_8 */
            1,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* MustSize, MustFree, [in], SimpleRef */
        (NDR64_UINT16)0 /* 0x0 */,
        56 /* 0x38 */,   /* Stack offset */
    },
    {
        /* arg_9 */      /* parameter arg_9 */
            &__midl_frag44,
            {
        /* arg_9 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        64 /* 0x40 */,   /* Stack offset */
    },
    {
        /* arg_10 */      /* parameter arg_10 */
            &__midl_frag61,
            {
        /* arg_10 */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        72 /* 0x48 */,   /* Stack offset */
    },
    {
        /* arg_11 */      /* parameter arg_11 */
            &__midl_frag20,
            {
        /* arg_11 */
            0,
            1,
            0,
            0,
            1,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            1
        },    /* MustFree, [out], SimpleRef, UseCache */
        (NDR64_UINT16)0 /* 0x0 */,
        80 /* 0x50 */,   /* Stack offset */
    },
    {
        /* arg_12 */      /* parameter arg_12 */
            &__midl_frag61,
            {
        /* arg_12 */
            0,
            0,
            0,
            0,
            1,
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            1
        },    /* [out], Basetype, SimpleRef, UseCache */
        (NDR64_UINT16)0 /* 0x0 */,
        88 /* 0x58 */,   /* Stack offset */
    },
    {
        /* long */      /* parameter long */
            &__midl_frag61,
            {
        /* long */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16)0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16)0 /* 0x0 */,
        96 /* 0x60 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32)0 /* 0x0 */;


#include "poppack.h"


static const FormatInfoRef DefaultIfName_Ndr64ProcTable[] =
{
&__midl_frag2,
&__midl_frag24,
&__midl_frag29,
&__midl_frag35,
&__midl_frag40,
&__midl_frag40,
&__midl_frag43
};


static const MIDL_STUB_DESC DefaultIfName_StubDesc =
{
(void*)&DefaultIfName___RpcClientInterface,
MIDL_user_allocate,
MIDL_user_free,
&DefaultIfName__MIDL_AutoBindHandle,
0,
0,
0,
0,
appinfo__MIDL_TypeFormatString.Format,
1, /* -error bounds_check flag */
0x60001, /* Ndr library version */
0,
0x801026e, /* MIDL Version 8.1.622 */
0,
0,
0,  /* notify & notify_flag routine table */
0x2000001, /* MIDL flag */
0, /* cs routines */
(void*)&DefaultIfName_ProxyInfo,   /* proxy/server info */
0
};

static const MIDL_SYNTAX_INFO DefaultIfName_SyntaxInfo[2] =
{
{
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
0,
appinfo__MIDL_ProcFormatString.Format,
DefaultIfName_FormatStringOffsetTable,
appinfo__MIDL_TypeFormatString.Format,
0,
0,
0
}
,{
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
0,
0 ,
(unsigned short*)DefaultIfName_Ndr64ProcTable,
0,
0,
0,
0
}
};

static const MIDL_STUBLESS_PROXY_INFO DefaultIfName_ProxyInfo =
{
&DefaultIfName_StubDesc,
appinfo__MIDL_ProcFormatString.Format,
DefaultIfName_FormatStringOffsetTable,
(RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
2,
(MIDL_SYNTAX_INFO*)DefaultIfName_SyntaxInfo

};

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#include "stdlib.h"
void __RPC_FAR* __RPC_USER midl_user_allocate(size_t cBytes)
{
    return((void __RPC_FAR*) malloc(cBytes));
}

void __RPC_USER midl_user_free(void __RPC_FAR* p)
{
    free(p);
}
