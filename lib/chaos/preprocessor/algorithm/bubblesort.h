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
# ifndef CHAOS_PREPROCESSOR_SANDBOX_BUBBLESORT_H
# define CHAOS_PREPROCESSOR_SANDBOX_BUBBLESORT_H
#
# include <chaos/preprocessor/algorithm/size.h>
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_BUBBLESORT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BUBBLESORT(pred, ...) CHAOS_PP_BUBBLESORT_S(CHAOS_PP_STATE(), pred, __VA_ARGS__)
#    define CHAOS_PP_BUBBLESORT_ CHAOS_PP_LAMBDA(CHAOS_PP_BUBBLESORT_ID)()
# else
#    define CHAOS_PP_BUBBLESORT(pred, g, data) CHAOS_PP_BUBBLESORT_S(CHAOS_PP_STATE(), pred, g, data)
# endif
#
# define CHAOS_PP_BUBBLESORT_ID() CHAOS_PP_BUBBLESORT
#
# /* CHAOS_PP_BUBBLESORT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BUBBLESORT_S(s, pred, ...) \
        CHAOS_IP_BUBBLESORT_U(s, pred, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_BUBBLESORT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_BUBBLESORT_S_ID)()
# else
#    define CHAOS_PP_BUBBLESORT_S(s, pred, g, data) CHAOS_IP_BUBBLESORT_U(s, pred, g, (data))
# endif
#
# define CHAOS_PP_BUBBLESORT_S_ID() CHAOS_PP_BUBBLESORT_S
#
# define CHAOS_IP_BUBBLESORT_U(s, pred, g, pd) \
    CHAOS_IP_BUBBLESORT_1( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), \
        CHAOS_PP_TYPEOF(g), g, CHAOS_PP_SIZE(g), pd \
    ) \
    /**/
# define CHAOS_IP_BUBBLESORT_INDIRECT(n) CHAOS_IP_BUBBLESORT_ ## n
# define CHAOS_IP_BUBBLESORT_1(_, s, pred, _p, type, g, size, pd) \
    CHAOS_PP_IF _(size)( \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_BUBBLESORT_INDIRECT _(1)( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_NEXT(s), pred, _p, type, \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_BUBBLESORT_2 _( \
                CHAOS_PP_NEXT(s), pred, _p, type, g, CHAOS_PP_DEC(size), pd \
            )), \
            CHAOS_PP_DEC(size), pd \
        )), \
        g \
    ) \
    /**/
# define CHAOS_IP_BUBBLESORT_2(s, pred, _p, type, g, size, pd) \
    CHAOS_PP_IF(size)( \
        CHAOS_IP_BUBBLESORT_3, g CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), s, pred, _p, type, (CHAOS_PP_HEAD(g)), CHAOS_PP_TAIL(g), CHAOS_PP_DEC(size), pd) \
    /**/
# define CHAOS_IP_BUBBLESORT_3(_, s, pred, _p, type, first, rest, size, pd) \
    CHAOS_PP_IIF _(_p()(s, pred, CHAOS_PP_ITEM(type, CHAOS_PP_REM first) CHAOS_PP_COMMA() CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(rest)) CHAOS_PP_EXPOSE(pd)))( \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_BUBBLESORT_INDIRECT _(2)( \
                CHAOS_PP_NEXT(s), pred, _p, type, rest, size, pd \
            )), \
            CHAOS_PP_REM first \
        ), \
        CHAOS_PP_CONS _( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_BUBBLESORT_INDIRECT _(2)( \
                CHAOS_PP_NEXT(s), pred, _p, type, CHAOS_PP_CONS _(CHAOS_PP_TAIL _(rest), CHAOS_PP_REM first), size, pd \
            )), \
            CHAOS_PP_HEAD _(rest) \
        ) \
    ) \
    /**/
#
# endif
