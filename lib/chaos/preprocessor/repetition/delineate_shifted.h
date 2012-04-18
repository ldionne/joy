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
# ifndef CHAOS_PREPROCESSOR_REPETITION_DELINEATE_SHIFTED_H
# define CHAOS_PREPROCESSOR_REPETITION_DELINEATE_SHIFTED_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DELINEATE_SHIFTED */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_SHIFTED(count, sep, ...) CHAOS_PP_DELINEATE_SHIFTED_S(CHAOS_PP_STATE(), count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_SHIFTED_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_SHIFTED_ID)()
# else
#    define CHAOS_PP_DELINEATE_SHIFTED(count, sep, macro, data) CHAOS_PP_DELINEATE_SHIFTED_S(CHAOS_PP_STATE(), count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_SHIFTED_ID() CHAOS_PP_DELINEATE_SHIFTED
#
# /* CHAOS_PP_DELINEATE_SHIFTED_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_SHIFTED_S(s, count, sep, ...) \
        CHAOS_IP_DELINEATE_SHIFTED_U(s, count, sep, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_DELINEATE_SHIFTED_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_SHIFTED_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_SHIFTED_S(s, count, sep, macro, data) CHAOS_IP_DELINEATE_SHIFTED_U(s, count, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_SHIFTED_S_ID() CHAOS_PP_DELINEATE_SHIFTED_S
#
# define CHAOS_IP_DELINEATE_SHIFTED_U(s, count, sep, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_SHIFTED_I( \
        s, CHAOS_PP_NEXT(s), CHAOS_PP_DEC(count), CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_SHIFTED_INDIRECT() CHAOS_IP_DELINEATE_SHIFTED_I
# define CHAOS_IP_DELINEATE_SHIFTED_I(s, o, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_IF(count)( \
        CHAOS_IP_DELINEATE_SHIFTED_II, CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), o, count, sep, ss, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_SHIFTED_II(_, s, o, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_DELINEATE_SHIFTED_INDIRECT _()( \
        s, o, CHAOS_PP_DEC(count), ss, ss, macro, _m, pd \
    )) \
    _m()(o, macro, count CHAOS_PP_EXPOSE(pd)) sep() \
    /**/
#
# endif
