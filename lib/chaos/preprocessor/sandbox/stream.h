# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_SANDBOX_STREAM_H
# define CHAOS_PREPROCESSOR_SANDBOX_STREAM_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/list/core.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# if !!!!!0 // WARNING: REDEFINITION!
#    undef CHAOS_PP_LIST_TAIL
#    define CHAOS_PP_LIST_TAIL(list) CHAOS_IP_LIST_TAIL_SID(CHAOS_PP_SPLIT(1, CHAOS_PP_TUPLE_REM(2) list))
#    define CHAOS_IP_LIST_TAIL_SID(x) x
# endif
#
# /* CHAOS_PP_LIST_STREAM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LIST_STREAM(macro, ...) (macro(0, __VA_ARGS__), CHAOS_IP_LIST_STREAM_I(1, macro, __VA_ARGS__))
#    define CHAOS_PP_LIST_STREAM_ CHAOS_PP_LAMBDA(CHAOS_PP_LIST_STREAM_ID)()
#    define CHAOS_IP_LIST_STREAM_I(n, macro, ...) \
        CHAOS_PP_IIF_SHADOW(CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(CHAOS_IP_LIST_TAIL_SID(()))))( \
            (macro(n, __VA_ARGS__), CHAOS_IP_LIST_STREAM_INDIRECT CHAOS_PP_OBSTRUCT()()(CHAOS_PP_INC(n), macro, __VA_ARGS__)), \
            CHAOS_IP_LIST_STREAM_INDIRECT CHAOS_PP_OBSTRUCT()()(n, macro, __VA_ARGS__) \
        ) \
        /**/
# else
#    define CHAOS_PP_LIST_STREAM(macro, data) (macro(0, data), CHAOS_IP_LIST_STREAM_I(1, macro, data))
#    define CHAOS_IP_LIST_STREAM_I(n, macro, data) \
        CHAOS_PP_IIF_SHADOW(CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(CHAOS_IP_LIST_TAIL_SID(()))))( \
            (macro(n, data), CHAOS_IP_LIST_STREAM_INDIRECT CHAOS_PP_OBSTRUCT()()(CHAOS_PP_INC(n), macro, data)), \
            CHAOS_IP_LIST_STREAM_INDIRECT CHAOS_PP_OBSTRUCT()()(n, macro, data) \
        ) \
        /**/
# endif
#
# define CHAOS_PP_LIST_STREAM_ID() CHAOS_PP_LIST_STREAM
#
# define CHAOS_IP_LIST_STREAM_INDIRECT() CHAOS_IP_LIST_STREAM_I
#
# endif
